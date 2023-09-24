#include "mainwindow.h"
#include "ui_mainwindow.h"


#include <QMessageBox>
#include <Qfile>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->resize(width, height);
    this->setMaximumHeight(this->size().height());
    this->setMaximumWidth(this->size().width() + 300);
    sign_in = new Sign_in;
    sign_up = new Sign_up;
    this->setWindowTitle("Registration");
    ui->stackedWidget->setCurrentIndex(0);
    ui->stackedWidget->insertWidget(1, sign_in);
    ui->stackedWidget->insertWidget(2, sign_up);

    connect(sign_in, &Sign_in::signal_back, this, &MainWindow::back);
    connect(sign_up, &Sign_up::signal_back, this, &MainWindow::back);
    connect(sign_in, &Sign_in::signal_sign_up, this, &MainWindow::on_sing_up_clicked);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::back()
{
    ui->stackedWidget->setCurrentIndex(0);
    this->resize(width, height);
}

void MainWindow::on_sign_in_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
    this->resize(0, 0);
}

void MainWindow::on_sing_up_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
    this->resize(0, 0);
}

void MainWindow::on_exit_clicked()
{
    QApplication::exit();
}


