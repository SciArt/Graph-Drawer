#ifndef RENDERAREA_H
#define RENDERAREA_H

#include <QWidget>
#include <QMouseEvent>

#include "node.h"
#include <vector>

class QGraphicsScene;
class QGraphicsView;

class RenderArea : public QWidget
{
    Q_OBJECT
public:
    explicit RenderArea(QWidget *parent = nullptr);
    ~RenderArea();

    QGraphicsScene* getGraphicsScene();

protected:
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);

private:
    QGraphicsScene *scene;
signals:

public slots:
};

#endif // RENDERAREA_H
