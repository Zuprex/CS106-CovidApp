#include "mainwindow.h"
#include "./ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

// Main Menu (LoginRegister Widget) Buttons:
// Widgets 0 : Login / 1 :  Register / 2 : User Menu / 3:
//-------------------------------------------

void MainWindow::on_mainLoginBttn_clicked() // Goes to login page
{
    ui->stackedWidget->setCurrentIndex(2);
}

// Registration (RegisterPage Widget) Buttons:
//-------------------------------------------

void MainWindow::on_registerBttn_Cancel_clicked() // Cancels Registration.
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_registerBttn_clicked() // Attempts to create user account.
{

    QString username = ui->userRegLine->text();
    QString password = ui->passRegLine->text();
    QString firstName = ui->fNameRegLine->text();
    QString lastName = ui->lNameRegLine->text();
    QString gender = ui->genderRegLine->text();
    QString age = ui->ageRegLine->text();

    userType i = userType(username,password,firstName,lastName,gender,age);

    users.push_back(i);

    ui->stackedWidget->setCurrentIndex(0);
}

// Login (LoginPage Widget) Buttons:
//-------------------------------------------

void MainWindow::on_mainRegisterBttn_clicked() // Goes to registration page
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_loginBttn_clicked() // Attempts to login
{
    QString username = ui->user_Login_Line_Edit->text();
    QString password = ui->pass_Password_Line_Edit->text();

    for(userType& i : users){

        if(i.username == username && i.password == password){

            currentUser = i.username;
            currentPass = i.password;

            ui->stackedWidget->setCurrentIndex(2);

        }

    }

}


// User Menu (UserMenuPage Widget) Buttons:
//-------------------------------------------

void MainWindow::on_logOutBttn_User_clicked() // Logout and return to main page.
{
    ui->stackedWidget->setCurrentIndex(0);
}


void MainWindow::on_infoBttn_User_clicked() // View user info.
{

}

