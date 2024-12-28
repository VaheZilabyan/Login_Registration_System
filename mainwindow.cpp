#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QPushButton>
#include <QMessageBox>
#include <Qfile>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    this->setWindowTitle("Registration");
    this->resize(width, height);
    this->setMaximumHeight(this->size().height());
    this->setMaximumWidth(this->size().width() + 300);

    sign_in_window = new Sign_in;
    sign_up_window = new Sign_up;
    stackedWidget = new QStackedWidget(this);
    QWidget *mainWidget = new QWidget(this);
    QVBoxLayout *main_layout = new QVBoxLayout();

    QLabel *myChatApp_label = new QLabel("MyChat", mainWidget);
    QFont font = myChatApp_label->font();
    font.setBold(true);
    font.setPointSize(26);
    myChatApp_label->setFont(font);
    myChatApp_label->setAlignment(Qt::AlignCenter);

    sign_in_button = new QPushButton("Sign in", mainWidget);
    sign_up_button = new QPushButton("Sign up", mainWidget);
    exit_button = new QPushButton("Exit", mainWidget);

    main_layout->addWidget(myChatApp_label);
    main_layout->addWidget(sign_in_button);
    main_layout->addWidget(sign_up_button);
    main_layout->addWidget(exit_button);
    mainWidget->setLayout(main_layout);

    stackedWidget->insertWidget(0, mainWidget);
    stackedWidget->insertWidget(1, sign_in_window);
    stackedWidget->insertWidget(2, sign_up_window);
    stackedWidget->setCurrentIndex(0);


    setCentralWidget(stackedWidget);

    connect(sign_in_button, &QPushButton::clicked, this, &MainWindow::on_sign_in_clicked);
    connect(sign_up_button, &QPushButton::clicked, this, &MainWindow::on_sign_up_clicked);
    connect(exit_button, &QPushButton::clicked, this, &MainWindow::on_exit_clicked);

    connect(sign_in_window, &Sign_in::signal_back, this, &MainWindow::slot_back);
    connect(sign_in_window, &Sign_in::signal_sign_up, this, &MainWindow::on_sign_up_clicked);
    connect(sign_up_window, &Sign_up::signal_back, this, &MainWindow::slot_back);
}

void MainWindow::slot_back()
{
    stackedWidget->setCurrentIndex(0);
    this->resize(width, height);
}

void MainWindow::on_sign_in_clicked()
{
    stackedWidget->setCurrentIndex(1);
    this->resize(0, 0);
}

void MainWindow::on_sign_up_clicked()
{
    stackedWidget->setCurrentIndex(2);
    this->resize(0, 0);
}

void MainWindow::on_exit_clicked()
{
    QApplication::exit();
}

MainWindow::~MainWindow()
{
}
