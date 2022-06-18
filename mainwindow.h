#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "usertype.h"
#include <QWidget>
#include <vector>

using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QWidget
{
    Q_OBJECT

public:

    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    QVector<userType> users;

    QString currentUser;
    QString currentPass;

private slots:

    void on_mainRegisterBttn_clicked();

    void on_registerBttn_Cancel_clicked();

    void on_loginBttn_clicked();

    void on_mainLoginBttn_clicked();

    void on_registerBttn_clicked();

    void on_logOutBttn_User_clicked();

    void on_infoBttn_User_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
