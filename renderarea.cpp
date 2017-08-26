#include "renderarea.h"
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QLayout>
#include <iostream>

RenderArea::RenderArea(QWidget *parent) : QWidget(parent)
{
    scene = new QGraphicsScene(this);
    scene->setBackgroundBrush(QColor(255,255,255));
}

RenderArea::~RenderArea()
{
}

QGraphicsScene *RenderArea::getGraphicsScene()
{
    return scene;
}

void RenderArea::mousePressEvent(QMouseEvent *event)
{
    QWidget::mousePressEvent(event);
}

void RenderArea::mouseReleaseEvent(QMouseEvent *event)
{
    /*Node *node = new Node;
    scene->addItem( node )*/;
    //std::cout << "DZIALA" << std::endl;
    QWidget::mouseReleaseEvent(event);
}
