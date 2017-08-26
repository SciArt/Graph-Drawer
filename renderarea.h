#ifndef RENDERAREA_H
#define RENDERAREA_H

#include <QWidget>

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


private:
    QGraphicsScene* scene;

signals:

public slots:
};

#endif // RENDERAREA_H
