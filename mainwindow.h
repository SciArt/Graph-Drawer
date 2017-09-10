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

private slots:
    void on_actionShowToolbar_changed();

    void on_actionAdd_Edge_triggered();

private:
    Ui::MainWindow *ui;
    RenderArea *render_area;
};

#endif // MAINWINDOW_H
