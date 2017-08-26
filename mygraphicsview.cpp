#include "mygraphicsview.h"
#include <iostream>
#include <QMouseEvent>
#include <QGraphicsScene>
#include "node.h"

MyGraphicsView::MyGraphicsView(QWidget *parent) : QGraphicsView(parent)
{
    setAlignment(Qt::AlignTop|Qt::AlignLeft);
}

MyGraphicsView::~MyGraphicsView()
{

}

void MyGraphicsView::mouseReleaseEvent(QMouseEvent *event)
{
    if( event->button() == Qt::RightButton )
    {
        Node *node = new Node;
        node->setPos( event->x()-25, event->y()-25 );
        scene()->addItem(node);
    }
    QGraphicsView::mouseReleaseEvent(event);
}
