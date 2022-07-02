#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
    , adminMode(false)
    , currentAdminUser("Admin")
    , currentAdminPass("Charles")
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->invalidLogin_Label->hide();
    ui->stackedWidget->setCurrentIndex(0);
    ui->QRCodeImage->setPixmap(*imageQR);

}

MainWindow::~MainWindow()
{
    delete ui;
}

// Add users to widget list who requested a QR Code.

void MainWindow::refreshQRList(){

    if(userQRList.isEmpty()){}
    else{

        ui->qrRequestList->clear();
        for(auto &e : userQRList.keys()){

            ui->qrRequestList->addItem(e + " " +userQRList.value(e));

        }

    }


}

// Searches for user and returns address pointer to that user in the vector.

userType& MainWindow::searchUser(){

    for(userType &i : users){
        if(i.getUsername() == currentUser && i.getPassword() == currentPass){
            return i;
        }
    }

}

// Main Menu (LoginRegister Widget) Buttons:
// Widgets 0 : Login / 1 :  Register / 2 : User Menu / 3: covidTestsPage / 4: Admin Menu
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

    ui->userRegLine->clear();
    ui->passRegLine->clear();
    ui->fNameRegLine->clear();
    ui->lNameRegLine->clear();
    ui->genderRegLine->clear();
    ui->ageRegLine->clear();
}

// Login (LoginPage Widget) Buttons:
//-------------------------------------------

void MainWindow::on_mainRegisterBttn_clicked() // Goes to registration page
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_loginBttn_clicked() // Attempts to login NOTE: For realism; can not access admin account without atleast 1 registered user vector will be empty + pointless to use admin as its sole purpose is to modify user accounts.
{
    QString username = ui->user_Login_Line_Edit->text();
    QString password = ui->pass_Password_Line_Edit->text();

    for(userType &i : users){


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

            // Check user's basic info (age/gender) and implement proper info to LINE EDITS

            ui->userAgeLine->setText(i.getAge());
            ui->userGenderLine->setText(i.getGender());

            // Set User info to be unmodifiable (Tickboxes and specific lineEdits)

            ui->firstVacCheck_User->setEnabled(false);
            ui->secondVacCheck_User->setEnabled(false);
            ui->boosterCheck_User->setEnabled(false);
            ui->userAgeLine->setEnabled(false);
            ui->userGenderLine->setEnabled(false);

            // Set Covid Testing to be view mode only.

            ui->covidTestDate->hide();
            ui->covidTestState->hide();
            ui->submitTestBttn_Admin->hide();

            // Vaccination Status

            ui->vaccinationStatusLabel->setText(i.getVaccinationStatus());

            // Change to User Page

            ui->stackedWidget->setCurrentIndex(2);

            // Show QR Request Button

            ui->QRCodeReqBttn_User->show();

            // Hide add QR Button

            ui->QRCodeAddBttn_Admin->hide();

            // Set QR Code

            if(searchUser().getImageQR() == true){
                ui->QRCodeImage->show();
                ui->QRCodeImage->setScaledContents(true);
            }
            else{ui->QRCodeImage->hide();}


        }
        else if(currentAdminUser == username && currentAdminPass == password){

            adminMode = true;
            ui->stackedWidget->setCurrentIndex(4);

            // Set Covid Testing to be view mode only.

            ui->covidTestDate->show();
            ui->covidTestState->show();
            ui->submitTestBttn_Admin->show();

            refreshQRList();

            // Hide QR Request Button

            ui->QRCodeReqBttn_User->hide();

            // Show QR Add Button

            ui->QRCodeAddBttn_Admin->show();


        }
        else{

            ui->invalidLogin_Label->show();
            ui->stackedWidget->setCurrentIndex(0);

        }

    }

}


// User Menu (UserMenuPage Widget) Buttons:
//-------------------------------------------

void MainWindow::on_qrBttn_User_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);

}

void MainWindow::on_logOutBttn_User_clicked() // Logout and return to main page.
{

    ui->invalidLogin_Label->hide();

    if(adminMode == true){ // Apply Changes in admin Mode.

        ui->stackedWidget->setCurrentIndex(4);

        for(userType& i : users){

            if(i.getUsername() == currentUser && i.getPassword() == currentPass){

                i.setFirstVac(ui->firstVacCheck_User->checkState());
                i.setSecondVac(ui->secondVacCheck_User->checkState());
                i.setBoosterVac(ui->boosterCheck_User->checkState());
                i.setAge(ui->userAgeLine->text());
                i.setGender(ui->userGenderLine->text());
            }
        }



    }
    else{ui->stackedWidget->setCurrentIndex(0);}

}


void MainWindow::on_covidTestBttn_User_clicked() // View the users' list of covid testing
{
    ui->stackedWidget->setCurrentIndex(3);

    if(searchUser().getUserTestList().empty()){}
    else{

        for(auto &e : searchUser().getUserTestList().keys()){

            ui->covidTestList->addItem(e + " " + searchUser().getUserTestList().value(e));


        }

    }



}

// Covid Test Page (covidTestsPage Widget) Buttons:
//-------------------------------------------

void MainWindow::on_covidTestbackBttn_User_clicked() // Go back to user menu.
{
    ui->covidTestList->clear();
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_submitTestBttn_Admin_clicked() // Submit a covid test with date and result.
{
    ui->covidTestList->clear();
    searchUser().insertUserTestList( ui->covidTestDate->text(),ui->covidTestState->currentText());
    if(searchUser().getUserTestList().empty()){}
    else{

        ui->covidTestList->clear();

        for(auto &e : searchUser().getUserTestList().keys()){

            ui->covidTestList->addItem(e + " " + searchUser().getUserTestList().value(e));

        }

    }

}

// Admin Menu (AdminMenuPage Widget) Buttons:

void MainWindow::on_logOutBttn_Admin_clicked() // Go back to login
{
    ui->qrRequestList->clear();
    ui->invalidLogin_Label->hide();
    ui->stackedWidget->setCurrentIndex(0);
    adminMode = false;
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

            ui->firstVacCheck_User->setEnabled(true);
            ui->secondVacCheck_User->setEnabled(true);
            ui->boosterCheck_User->setEnabled(true);
            ui->userAgeLine->setEnabled(true);
            ui->userGenderLine->setEnabled(true);

            ui->nameLine_User->setText(i.getUsername());
            ui->userAgeLine->setText(i.getAge());
            ui->userGenderLine->setText(i.getGender());
            ui->vaccinationStatusLabel->setText(i.getVaccinationStatus());

            if(searchUser().getImageQR() == true){
                ui->QRCodeImage->show();
                ui->QRCodeImage->setScaledContents(true);
            }
            else{ui->QRCodeImage->hide();}


        }

    }


}

// QR Code Page (QRCode_UserPage)

void MainWindow::on_qrCodeBackBttn_User_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}


void MainWindow::on_QRCodeReqBttn_User_clicked() // Request QR code from
{
    userQRList.insert(searchUser().getFirstName(),searchUser().getLastName());
}

void MainWindow::on_QRCodeAddBttn_Admin_clicked() // Adds QR Code when admin Mode
{
    userQRList.remove(searchUser().getFirstName());
    refreshQRList();
    searchUser().setImageQR(true);
}

