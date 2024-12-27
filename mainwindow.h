#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "sign_in.h"
#include "sign_up.h"
#include <QMainWindow>
#include <QStackedWidget>
#include <QPushButton>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void slot_back();
    void on_sign_in_clicked();
    void on_exit_clicked();
    void on_sign_up_clicked();

private:
    Sign_in *sign_in_window;
    Sign_up *sign_up_window;
    const int width = 210;
    const int height = 260;

private: //gui
    QStackedWidget *stackedWidget;
    QPushButton *sign_in_button;
    QPushButton *sign_up_button;
    QPushButton *exit_button;
};

#endif // MAINWINDOW_H
