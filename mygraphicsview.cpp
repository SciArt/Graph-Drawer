#include "mygraphicsview.h"
#include <iostream>
#include <QMouseEvent>
#include <QGraphicsScene>
#include "node.h"

MyGraphicsView::MyGraphicsView(QWidget *parent) : QGraphicsView(parent)
{
    setAlignment(Qt::AlignTop|Qt::AlignLeft);
    setScene(new QGraphicsScene(this));
    scene()->setBackgroundBrush(QColor(0,255,255));
}

MyGraphicsView::~MyGraphicsView()
{

}

void MyGraphicsView::resizeEvent(QResizeEvent *event)
{
    /* IMPORTANT
     * GraphicsView has incorrect size BEFORE it will be show on screen.
     * AFTER first "drawing" on screen, it has correct size.
     * So this code MUST exists as it is the only place where scene acquires size
     * It also readjusts scene size when size of GraphicsView changes.
     */

    scene()->setSceneRect(geometry());
    QGraphicsView::resizeEvent(event);
}

void MyGraphicsView::mouseReleaseEvent(QMouseEvent *event)
{
    if( event->button() == Qt::RightButton )
    {
        Node *node = graph.addNode();;
        node->setPos( event->x(), event->y() );
        scene()->addItem(node);
    }
    QGraphicsView::mouseReleaseEvent(event);
}
