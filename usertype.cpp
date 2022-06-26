#include "usertype.h"

userType::userType(QString user, QString pass, QString fName, QString lName, QString gender, QString age){

    this->setUsername(user);
    this->setPassword(pass);
    this->firstName = fName;
    this->lastName = lName;
    this->gender = gender;
    this-> age = age;

    // New users by default have 0 vaccination and no booster shots. 1st & 2nd will dictate state - Unvacinnated / Partial / Vaccinated

    this->firstVac = false;
    this->secondVac = false;
    this->boosterVac = false;

    // No QR Code by default

    imageQR = false;

}

QString userType::getVaccinationStatus()
{

    if(firstVac == true && secondVac == false){return QString("Partial");}
    else if(firstVac == true && secondVac == true){return QString("Completed");}
    else{return QString("Unvaccinated");}

}



