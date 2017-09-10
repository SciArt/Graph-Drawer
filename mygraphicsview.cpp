#include "mygraphicsview.h"
#include <iostream>
#include <QMouseEvent>
#include <QGraphicsScene>
#include "node.h"

MyGraphicsView::MyGraphicsView(QWidget *parent) : QGraphicsView(parent)
{
    setAlignment(Qt::AlignTop|Qt::AlignLeft);
    setScene(new QGraphicsScene(this));
    scene()->setBackgroundBrush(QColor(255,255,255));
    setRenderHint(QPainter::Antialiasing);
    addEdge = false;

    node1 = nullptr;
    node2 = nullptr;

    graph.graphicsView = this;
}

MyGraphicsView::~MyGraphicsView()
{

}

void MyGraphicsView::createEdge(Node *node)
{
    if( addEdge )
    {
        if( node1 == nullptr )
        {
            node1 = node;
        }
        else if( node2 == nullptr && node != node1 )
        {
            node2 = node;
            Edge* edge = graph.addEdge(node1 , node2);
            scene()->addItem(edge);

            node1 = nullptr;
            node2 = nullptr;
        }
    }
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
    if( !addEdge )
    {
        if( event->button() == Qt::RightButton )
        {
            Node *node = graph.addNode();;
            node->setPos( event->x(), event->y() );
            scene()->addItem(node);
        }
    }
    QGraphicsView::mouseReleaseEvent(event);
}
