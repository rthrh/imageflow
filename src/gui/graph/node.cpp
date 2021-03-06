#include "node.h"
#include "edge.h"
#include "graphwidget.h"

#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QPainter>
#include <QStyleOption>

Node::Node(GraphWidget *graphWidget, int compID, std::string name, int nodeID)
    : graph(graphWidget), _compID(compID), _compName(name), _nodeID(nodeID) {
  setFlag(ItemIsMovable);
  setFlag(ItemSendsGeometryChanges);
  setCacheMode(DeviceCoordinateCache);
  setZValue(-1);
}

void Node::addEdge(Edge *edge) {
  edgeList << edge;
  edge->adjust();
}

QList<Edge *> Node::edges() const { return edgeList; }

void Node::calculateForces() {
  if (!scene() || scene()->mouseGrabberItem() == this) {
    newPos = pos();
    return;
  }

  QRectF sceneRect = scene()->sceneRect();
  newPos = pos() + QPointF(0, 0);

  newPos.setX(
      qMin(qMax(newPos.x(), sceneRect.left() + 10), sceneRect.right() - 10));
  newPos.setY(
      qMin(qMax(newPos.y(), sceneRect.top() + 10), sceneRect.bottom() - 10));
}

bool Node::advance() {
  if (newPos == pos()) return false;

  setPos(newPos);
  return true;
}

QRectF Node::boundingRect() const {
  qreal adjust = 2;

  // adjust size of a rect here
  // maybe define model factory here..
  return QRectF(-10 - adjust, -10 - adjust, 100 + adjust, 100 + adjust);
}

QPainterPath Node::shape() const {
  QPainterPath path;

  QRect rect{-10, -10, 144, 144};  // return polymorphic shape here

  path.addRect(std::move(rect));
  return path;
}

void Node::paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
                 QWidget *) {
  painter->setPen(Qt::NoPen);
  // painter->setBrush(Qt::darkGray);
  painter->drawRect(-7, -7, 144, 144);

  QRadialGradient gradient(-3, -3, 10);
  if (option->state & QStyle::State_Sunken) {
    gradient.setCenter(3, 3);
    gradient.setFocalPoint(3, 3);
    gradient.setColorAt(1, QColor(Qt::darkGray).light(120));
    gradient.setColorAt(0, QColor(Qt::gray).light(120));
  } else {
    gradient.setColorAt(0, Qt::darkGray);
    gradient.setColorAt(1, Qt::gray);
  }
  painter->setBrush(gradient);

  painter->setPen(QPen(Qt::black, 0));
  painter->drawRect(-10, -10, 144, 144);

  painter->setPen(QPen(Qt::white, 0));

  std::string str1 = std::to_string(_compID) + _compName;
  painter->drawText(0, 0, QString(str1.c_str()));  // remove that c_str() and
                                                   // make better conversion from
                                                   // std:string to QString
  std::string str2 = std::string("   nodeID: ") + std::to_string(_nodeID);
  painter->drawText(0, 15, QString(str2.c_str()));
}

bool Node::setNameString(std::string name) { _compName = name; }

QVariant Node::itemChange(GraphicsItemChange change, const QVariant &value) {
  switch (change) {
    case ItemPositionHasChanged:
      foreach (Edge *edge, edgeList)
        edge->adjust();
      graph->itemMoved();
      break;
    default:
      break;
  };

  return QGraphicsItem::itemChange(change, value);
}

void Node::mousePressEvent(QGraphicsSceneMouseEvent *event) {
  update();
  QGraphicsItem::mousePressEvent(event);
}

void Node::mouseReleaseEvent(QGraphicsSceneMouseEvent *event) {
  update();
  QGraphicsItem::mouseReleaseEvent(event);
}
