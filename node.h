#ifndef NODE_H
#define NODE_H

#include <QGraphicsItem>
//#include <QMouseEvent>

class MyGraphicsView;

class Node : public QGraphicsItem
{
public:
    Node();
    ~Node();

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    bool Pressed;

    void setPos(qreal x, qreal y);

    QVariant itemChange(GraphicsItemChange change, const QVariant &value);

    MyGraphicsView* graphicsView;
protected:

    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);

};

#endif // NODE_H
