#include "node.h"
#include <QBrush>
#include <QPainter>

#include <iostream>

Node::Node()
{
    Pressed = false;
    setFlag(ItemIsMovable);
}

Node::~Node()
{
}

QRectF Node::boundingRect() const
{
    return QRectF(0,0,50,50);
}

void Node::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QRectF rec = boundingRect();
    QBrush brush(Qt::blue);

    if( Pressed )
    {
        brush.setColor(Qt::red);
    }
    painter->fillRect(rec, brush);
    painter->drawRect(rec);
}

void Node::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    Pressed = true;
    update();
    QGraphicsItem::mousePressEvent(event);
}

void Node::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    Pressed = false;
    update();
    QGraphicsItem::mouseReleaseEvent(event);
}
