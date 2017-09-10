#ifndef EDGE_H
#define EDGE_H

#include <QGraphicsItem>
#include <QMouseEvent>
#include "node.h"

class Edge : public QGraphicsItem
{
public:
    Edge();
    ~Edge();

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    Node *node1;
    Node *node2;
};

#endif // EDGE_H
