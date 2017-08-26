#ifndef NODE_H
#define NODE_H

#include <QGraphicsItem>
#include <QMouseEvent>

class Node : public QGraphicsItem
{
public:
    Node();
    ~Node();

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    bool Pressed;
protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);

};

#endif // NODE_H
