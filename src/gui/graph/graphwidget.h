#ifndef GRAPHWIDGET_H
#define GRAPHWIDGET_H

#include <QGraphicsView>

class Node;

class GraphWidget : public QGraphicsView {
  Q_OBJECT

 public:
  GraphWidget(QWidget *parent = 0);

  void itemMoved();
  void setLastClickedNodeID(int nodeID);
  void setLastHoveredNodeID(int nodeID);
  bool makeConnection();

 public slots:
  void zoomIn();
  void zoomOut();
  void addNewNode(int compID, std::string name);

 protected:
  void keyPressEvent(QKeyEvent *event) override;
  void timerEvent(QTimerEvent *event) override;
#if QT_CONFIG(wheelevent)
  void wheelEvent(QWheelEvent *event) override;
#endif
  void drawBackground(QPainter *painter, const QRectF &rect) override;

  void scaleView(qreal scaleFactor);

 private:
  int timerId;
  Node *centerNode;
  QGraphicsScene *_scene;
  int _nodeID {1};
  int _lastRightClickedNodeID{0};
  int _lastRightHoveredNodeID{0};
};

#endif  // GRAPHWIDGET_H
