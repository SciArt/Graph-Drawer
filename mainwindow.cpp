#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "QFile"
#include "QTextStream"
#include "QFileDialog"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->actionExit, SIGNAL(triggered()), QApplication::instance(), SLOT(quit()));
}

MainWindow::~MainWindow()
{
    delete ui;
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
