#include "edge.h"

#include <QBrush>
#include <QPainter>

#include <QGraphicsScene>

#include <iostream>

Edge::Edge()
{
    setPos(0,0);
    setZValue(-1);
}

Edge::~Edge()
{
    std::cout << "Edge deleted.\n";
}

QRectF Edge::boundingRect() const
{
    return QRectF(0,0,1000,1000);
}

void Edge::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QBrush brush(Qt::black);
    QPen pen(brush,3);
    painter->setPen(pen);

    painter->drawLine( node1->pos().x()+12.5, node1->pos().y()+12.5, node2->pos().x()+12.5, node2->pos().y()+12.5 );
}
