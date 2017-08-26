#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QMouseEvent>

class QGraphicsScene;
class RenderArea;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
   /* void    mousePressEvent(QMouseEvent *event) override;
    void    mouseReleaseEvent(QMouseEvent *event) override;
    void    mouseDoubleClickEvent(QMouseEvent *event) override;*/

private slots:
    void on_actionShowToolbar_changed();

private:
    Ui::MainWindow *ui;
    RenderArea *render_area;
};

#endif // MAINWINDOW_H
