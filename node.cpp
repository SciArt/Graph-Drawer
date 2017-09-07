#include "node.h"
#include <QBrush>
#include <QPainter>

#include <QGraphicsScene>

#include <iostream>

Node::Node()
{
    Pressed = false;
    setFlag(ItemIsMovable);
    setFlag(ItemSendsGeometryChanges);
}

Node::~Node()
{
    std::cout << "Node deleted.\n";
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

    //painter->fillRect(scene()->sceneRect(), QBrush(Qt::green));
}

void Node::setPos(qreal x, qreal y)
{
    QGraphicsItem::setPos( x - boundingRect().width()/2.0, y - boundingRect().height()/2.0);
}

QVariant Node::itemChange(GraphicsItemChange change, const QVariant &value)
{
    if (change == ItemPositionChange && scene()) {
            // value is the new position.
            QPointF newPos = value.toPointF();
            QRectF rect = scene()->sceneRect();
            rect.setBottom(rect.bottom()-boundingRect().height()-1.0);
            rect.setRight(rect.right()-boundingRect().width()-1.0);
            if (!rect.contains(newPos)) {
                // Keep the item inside the scene rect.
                newPos.setX(qMin(rect.right(), qMax(newPos.x(), rect.left())));
                newPos.setY(qMin(rect.bottom(), qMax(newPos.y(), rect.top())));
                return newPos;
            }
        }
    return QGraphicsItem::itemChange(change, value);
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
