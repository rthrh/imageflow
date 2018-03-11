#include "graphwidget.h"
#include "edge.h"
#include "node.h"

#include <math.h>

#include <QKeyEvent>
#include <QDebug>

GraphWidget::GraphWidget(QWidget *parent) : QGraphicsView(parent), timerId(0) {
  _scene = new QGraphicsScene(this);
  _scene->setItemIndexMethod(QGraphicsScene::NoIndex);
  _scene->setSceneRect(-200, -200, 400, 400);
  setScene(_scene);
  setCacheMode(CacheBackground);
  setViewportUpdateMode(BoundingRectViewportUpdate);
  setRenderHint(QPainter::Antialiasing);
  setTransformationAnchor(AnchorUnderMouse);
  scale(qreal(0.8), qreal(0.8));
  setMinimumSize(400, 400);
  setWindowTitle(tr("Elastic Nodes"));

  // Node *node1 = new Node(this);
  // Node *node2 = new Node(this);
  // Node *node3 = new Node(this);

  //_scene->addItem(node1);
  //_scene->addItem(node2);
  //_scene->addItem(node3);

  //_scene->addItem(new Edge(node1, node2)); //draw line and create connection
  //_scene->addItem(new Edge(node1, node3));

  // node1->setPos(-50, -50);
  // node2->setPos(0, -50);
  // node3->setPos(50, -50);
}

void GraphWidget::itemMoved() {
  if (!timerId) timerId = startTimer(1000 / 25);
}

void GraphWidget::setLastClickedNodeID(int nodeID)
{
    _lastRightClickedNodeID = nodeID;
}

void GraphWidget::setLastHoveredNodeID(int nodeID)
{
    _lastRightHoveredNodeID = nodeID;

    if ((_lastRightClickedNodeID != 0) && (_lastRightHoveredNodeID != 0))
    {
        makeConnection();
    }
    else
    {


    }
}

bool GraphWidget::makeConnection()
{

    if (_lastRightClickedNodeID != _lastRightHoveredNodeID)
    {
        qDebug() << "trying to make connection from:" << _lastRightClickedNodeID << " to " << _lastRightHoveredNodeID;


    }

    setLastHoveredNodeID(0);
    setLastClickedNodeID(0);
}

void GraphWidget::keyPressEvent(QKeyEvent *event) {
  // TODO: make it custom
  switch (event->key()) {
    case Qt::Key_Up:
      centerNode->moveBy(0, -20);
      break;
    case Qt::Key_Down:
      centerNode->moveBy(0, 20);
      break;
    case Qt::Key_Left:
      centerNode->moveBy(-20, 0);
      break;
    case Qt::Key_Right:
      centerNode->moveBy(20, 0);
      break;
    case Qt::Key_Plus:
      zoomIn();
      break;
    case Qt::Key_Minus:
      zoomOut();
      break;
    case Qt::Key_Space:
    case Qt::Key_Enter:
      // shuffle();
      break;
    default:
      QGraphicsView::keyPressEvent(event);
  }
}

void GraphWidget::timerEvent(QTimerEvent *event) {
  Q_UNUSED(event);

  QList<Node *> nodes;
  foreach (QGraphicsItem *item, _scene->items()) {
    if (Node *node = qgraphicsitem_cast<Node *>(item)) nodes << node;
  }

  foreach (Node *node, nodes)
    node->calculateForces();

  bool itemsMoved = false;
  foreach (Node *node, nodes) {
    if (node->advance()) itemsMoved = true;
  }

  if (!itemsMoved) {
    killTimer(timerId);
    timerId = 0;
  }
}

#if QT_CONFIG(wheelevent)
void GraphWidget::wheelEvent(QWheelEvent *event) {
  scaleView(pow((double)2, -event->delta() / 240.0));
}
#endif

void GraphWidget::drawBackground(QPainter *painter, const QRectF &rect) {
  Q_UNUSED(rect);

  // Shadow
  QRectF sceneRect = this->sceneRect();
  QRectF rightShadow(sceneRect.right(), sceneRect.top() + 5, 5,
                     sceneRect.height());
  QRectF bottomShadow(sceneRect.left() + 5, sceneRect.bottom(),
                      sceneRect.width(), 5);
  if (rightShadow.intersects(rect) || rightShadow.contains(rect))
    painter->fillRect(rightShadow, Qt::darkGray);
  if (bottomShadow.intersects(rect) || bottomShadow.contains(rect))
    painter->fillRect(bottomShadow, Qt::darkGray);

  // Fill
  QLinearGradient gradient(sceneRect.topLeft(), sceneRect.bottomRight());
  gradient.setColorAt(0, Qt::white);
  gradient.setColorAt(1, Qt::lightGray);
  painter->fillRect(rect.intersected(sceneRect), gradient);
  painter->setBrush(Qt::NoBrush);
  painter->drawRect(sceneRect);

  // Text
  QRectF textRect(sceneRect.left() + 4, sceneRect.top() + 4,
                  sceneRect.width() - 4, sceneRect.height() - 4);
  QString message(tr("Graph Widget"));

  QFont font = painter->font();
  font.setBold(true);
  font.setPointSize(14);
  painter->setFont(font);
  painter->setPen(Qt::lightGray);
  painter->drawText(textRect.translated(2, 2), message);
  painter->setPen(Qt::black);
  painter->drawText(textRect, message);
}

void GraphWidget::scaleView(qreal scaleFactor) {
  qreal factor = transform()
                     .scale(scaleFactor, scaleFactor)
                     .mapRect(QRectF(0, 0, 1, 1))
                     .width();
  if (factor < 0.07 || factor > 100) return;

  scale(scaleFactor, scaleFactor);
}

// slots
void GraphWidget::zoomIn() { scaleView(qreal(1.2)); }

void GraphWidget::zoomOut() { scaleView(1 / qreal(1.2)); }

void GraphWidget::addNewNode(int compID, std::string name) {
  Node *node = new Node(this, compID, name, _nodeID++);
  // std::unique_ptr<Node> node = std::make_unique(Node(this, compID, name,
  // _nodeID++));

  _scene->addItem(node);
  node->setPos(-50, -50);
}
