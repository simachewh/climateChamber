#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "status.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    Status *status = new Status();
    connect(status, SIGNAL(contentChanged(QString)), this, SLOT(updateLabel(QString)));
    status->openPort();
    int x;

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::updateLabel(QString text){
    //qDebug() << "from upodatelable: " << text;
    ui->testLabel->setText(text);
}
