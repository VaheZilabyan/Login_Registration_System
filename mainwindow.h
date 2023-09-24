#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "sign_in.h"
#include "sign_up.h"
#include <QMainWindow>

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
    void back();
    void on_sign_in_clicked();
    void on_exit_clicked();
    void on_sing_up_clicked();

private:
    Ui::MainWindow *ui;
    Sign_in *sign_in;
    Sign_up *sign_up;
    const int width = 210;
    const int height = 260;
};

#endif // MAINWINDOW_H
