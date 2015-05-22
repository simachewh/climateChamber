#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->stackedWidget->setCurrentIndex(0);
    ui->monitorButton->setEnabled(false);

//    QPalette palette = ui->c1Label->palette();
//    palette.setColor(ui->c1Label->backgroundRole(), Qt::yellow);
//    palette.setColor(ui->c1Label->foregroundRole(), Qt::yellow);
//    ui->c1Label->setPalette(palette);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_monitorButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
    ui->monitorButton->setEnabled(false);
    ui->titleLabel->setText("<h3>Monitor</h3>");

    ui->auxButton->setEnabled(true);
    ui->programButton->setEnabled(true);
    ui->helpButton->setEnabled(true);
}

void MainWindow::on_programButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
    ui->programButton->setEnabled(false);
    ui->titleLabel->setText("<h3>Program Set</h3>");

    ui->monitorButton->setEnabled(true);
    ui->auxButton->setEnabled(true);
    ui->helpButton->setEnabled(true);
}

void MainWindow::on_auxButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
    ui->auxButton->setEnabled(false);
    ui->titleLabel->setText("<h3>Aux Data</h3>");

    ui->monitorButton->setEnabled(true);
    ui->programButton->setEnabled(true);
    ui->helpButton->setEnabled(true);
}

void MainWindow::on_helpButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
    ui->helpButton->setEnabled(false);
    ui->titleLabel->setText("<h3>Help</h3>");

    ui->monitorButton->setEnabled(true);
    ui->programButton->setEnabled(true);
    ui->auxButton->setEnabled(true);
}


