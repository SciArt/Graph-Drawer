#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMouseEvent>

#include "QFile"
#include "QTextStream"
#include "QFileDialog"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->graphicsView->addAction(ui->actionAdd_Node_Context_menu);

    ui->toolBar->addAction(ui->actionShowToolbar);
    //ui->graphicsView->setMouseTracking(false);

    connect(ui->actionExit, SIGNAL(triggered()), QApplication::instance(), SLOT(quit()));

    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);

    scene->setBackgroundBrush(QColor(120,120,120));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
        scene->setBackgroundBrush(QColor(0,0,120));
}

void MainWindow::mouseReleaseEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
        scene->setBackgroundBrush(QColor(0,120,0));
}

void MainWindow::mouseDoubleClickEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
        scene->setBackgroundBrush(QColor(120,0,0));
}

/*
void MainWindow::m_save()
{
    QString fileName = QFileDialog::getSaveFileName(this,
            tr("Save File"), "",
            tr("text_file (*.txt);;All Files (*)"));
    QFile ffile(fileName);
    if(ffile.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        QTextStream out(&ffile);
        out << ui->textEdit->toPlainText();
        ui->textEdit->toPlainText();
        ffile.close();
    }
}

void MainWindow::m_load()
{
    QString fileName = QFileDialog::getOpenFileName(this,
            tr("Open File"), "",
            tr("text_file (*.txt);;All Files (*)"));
    QFile ffile(fileName);
    if(ffile.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QTextStream in(&ffile);
        ui->textEdit->insertPlainText(in.readAll());

        ffile.close();
    }
}
*/

void MainWindow::on_actionShowToolbar_changed()
{
    if( ui->actionShowToolbar->isChecked() )
    {
        ui->toolBar->show();
    }
    else
    {
        ui->toolBar->hide();
    }
}
