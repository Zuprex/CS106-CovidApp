#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "usertype.h"
#include <QWidget>
#include <vector>
#include <QMap>
#include <QFile>
#include <QTextStream>
#include <QPixmap>
#include <QMessageBox>

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

    bool adminMode;

    QVector<userType> users;

    // Map container for QR Code request from users.

    QMap<QString,QString> userQRList;

    QString currentUser;
    QString currentPass;

    // The only login for Admin (Integrated Login - No registration required)

    QString currentAdminUser;
    QString currentAdminPass;

    // Methods

    void refreshQRList();
    userType& searchUser();

    // QR Image

    QPixmap *imageQR = new QPixmap("C:/Users/Charles/Documents/QTCreator Projects/CS106Assesment/codeQRImage.png");

private slots:

    void on_mainRegisterBttn_clicked();

    void on_registerBttn_Cancel_clicked();

    void on_loginBttn_clicked();

    void on_registerBttn_clicked();

    void on_logOutBttn_User_clicked();

    void on_covidTestBttn_User_clicked();

    void on_covidTestbackBttn_User_clicked();

    void on_logOutBttn_Admin_clicked();

    void on_searchUserBttn_Admin_clicked();

    void on_submitTestBttn_Admin_clicked();

    void on_qrCodeBackBttn_User_clicked();

    void on_QRCodeReqBttn_User_clicked();

    void on_qrBttn_User_clicked();

    void on_QRCodeAddBttn_Admin_clicked();

    void on_reportBugBttn_User_clicked();

    void on_bugReturnBttn_clicked();

    void on_submitBugBttn_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
