#ifndef USERTYPE_H
#define USERTYPE_H

#include <string>
#include <QWidget>


class userType
{
public:

    // Variables

    QString username;
    QString password;
    QString firstName;
    QString lastName;
    QString gender;
    QString age;

    // Constructor

    userType(QString user, QString pass, QString fName, QString lName, QString gender, QString age);

};


#endif // USERTYPE_H
