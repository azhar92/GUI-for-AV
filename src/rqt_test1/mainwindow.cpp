#include "rqt_test1/mainwindow.h"
#include "rqt_test1/ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    ui->label_2->setText("Autonomous");

}



void MainWindow::on_pushButton_2_clicked()
{
    ui->label_2->setText("Supervisory");
}

void MainWindow::on_pushButton_3_clicked()
{
    ui->label_2->setText("Manual");
}

void MainWindow::on_pushButton_4_clicked()
{
    ui->label_2->setText("Parked");
}
