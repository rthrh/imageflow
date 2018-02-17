#ifndef NODE_H
#define NODE_H

#include <QGraphicsItem>
#include <QList>

class Edge;
class GraphWidget;
class QGraphicsSceneMouseEvent;

class Node : public QGraphicsItem {
 public:
  Node(GraphWidget *graphWidget, int compID, std::string name, int nodeID);

  void addEdge(Edge *edge);
  QList<Edge *> edges() const;

  enum { Type = UserType + 1 };
  int type() const override { return Type; }

  void calculateForces();  // TODO: rename and clean this method
  bool advance();

  QRectF boundingRect() const override;
  QPainterPath shape() const override;
  void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
             QWidget *widget) override;
  bool setNameString(std::string);

 protected:
  QVariant itemChange(GraphicsItemChange change,
                      const QVariant &value) override;

  void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
  void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;

 private:
  QList<Edge *> edgeList;
  QPointF newPos;
  GraphWidget *graph;
  int _nodeID;
  int _compID;
  std::string _compName;
};

#endif  // NODE_H
