#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);
    ui->monitorButton->setEnabled(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_monitorButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
    ui->monitorButton->setEnabled(false);

    ui->auxButton->setEnabled(true);
    ui->programButton->setEnabled(true);
    ui->helpButton->setEnabled(true);
}

void MainWindow::on_programButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
    ui->programButton->setEnabled(false);

    ui->monitorButton->setEnabled(true);
    ui->auxButton->setEnabled(true);
    ui->helpButton->setEnabled(true);
}

void MainWindow::on_auxButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
    ui->auxButton->setEnabled(false);

    ui->monitorButton->setEnabled(true);
    ui->programButton->setEnabled(true);
    ui->helpButton->setEnabled(true);
}

void MainWindow::on_helpButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
    ui->helpButton->setEnabled(false);

    ui->monitorButton->setEnabled(true);
    ui->programButton->setEnabled(true);
    ui->auxButton->setEnabled(true);
}


