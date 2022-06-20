#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->invalidLogin_Label->hide();
}

MainWindow::~MainWindow()
{
    delete ui;
}


// Main Menu (LoginRegister Widget) Buttons:
// Widgets 0 : Login / 1 :  Register / 2 : User Menu / 3: covidTestsPage
//-------------------------------------------

// Registration (RegisterPage Widget) Buttons:
//-------------------------------------------

void MainWindow::on_registerBttn_Cancel_clicked() // Cancels Registration.
{
    ui->invalidLogin_Label->hide();
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

    ui->invalidLogin_Label->hide();
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

        if(i.getUsername() == username && i.getPassword() == password){

            // Set who is currently logged in.

            currentUser = i.getUsername();
            currentPass = i.getPassword();

            ui->nameLine_User->setText(i.getUsername());
            ui->nameLine_User->setEnabled(false);

            // Check user's vaccination status and implement proper state to TICK BOXES.

            if(i.getFirstVac() == true){ui->firstVacCheck_User->setChecked(true);}
            else {ui->firstVacCheck_User->setChecked(false);}

            if(i.getSecondVac() == true){ui->secondVacCheck_User->setChecked(true);}
            else {ui->secondVacCheck_User->setChecked(false);}

            if(i.getBoosterVac() == true){ui->boosterCheck_User->setChecked(true);}
            else {ui->boosterCheck_User->setChecked(false);}

            // Set tick boxes to be unmodifiable.

            ui->firstVacCheck_User->setEnabled(false);
            ui->secondVacCheck_User->setEnabled(false);
            ui->boosterCheck_User->setEnabled(false);

            // Change to User Page

            ui->stackedWidget->setCurrentIndex(2);

        }
        else{

            ui->invalidLogin_Label->show();
            ui->stackedWidget->setCurrentIndex(0);

        }

    }

}


// User Menu (UserMenuPage Widget) Buttons:
//-------------------------------------------

void MainWindow::on_logOutBttn_User_clicked() // Logout and return to main page.
{


    if(adminMode == true){



    }
    else{

        ui->invalidLogin_Label->hide();
        ui->stackedWidget->setCurrentIndex(0);

    }

}


void MainWindow::on_covidTestBttn_User_clicked() // View the users' list of covid testing
{
    ui->stackedWidget->setCurrentIndex(3);
}

// Covid Test Page (covidTestsPage Widget) Buttons:
//-------------------------------------------

void MainWindow::on_covidTestbackBttn_User_clicked() // Go back to user menu.
{
    ui->stackedWidget->setCurrentIndex(2);
}

// Admin Menu (AdminMenuPage Widget) Buttons:

void MainWindow::on_logOutBttn_Admin_clicked() // Go back to login
{
    ui->invalidLogin_Label->hide();
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_searchUserBttn_Admin_clicked() // Search for a specific user.
{

    QString currentUserFName = ui->searchFNameUserLine_Admin->text();
    QString currentUserLName = ui->searchLNameUserLine_Admin->text();

    for(userType& i : users){

        if(i.getFirstName() == currentUserFName && i.getLastName() == currentUserLName){

            this->currentUser = i.getUsername();
            this->currentPass = i.getPassword();

            ui->stackedWidget->setCurrentIndex(2);

            on_logOutBttn_User_clicked();



        }

    }


}

