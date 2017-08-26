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
