#ifndef USERTYPE_H
#define USERTYPE_H

#include <string>
#include <QWidget>
#include <QMap>


class userType
{
public:

    // Constructor - Public - The creation of a user.

    userType();

    userType(QString user, QString pass, QString fName, QString lName, QString gender, QString age);

private:

    // Variables - These are set to private thus directly accessing these information must be accessed through getters and setters which are set to public.

    // Basic User Info

    QString username;
    QString password;
    QString firstName;
    QString lastName;
    QString gender;
    QString age;

    // Vaccine Status Info

    bool firstVac;
    bool secondVac;
    bool boosterVac;

    // Vaccine Test List using maps (Key = Time / Value = Positive/Negative)

    QMap<QString,QString> userTestList;

    // Implementation and declaration of some of these function will be here on the header as their instructions are one line of coode thus using 'inline'.
    //

public:

    // Getters

    inline QString getUsername(){return this->username;}
    inline QString getPassword(){return this->password;}
    inline QString getFirstName(){return this->firstName;}
    inline QString getLastName(){return this->lastName;}

    // Vaccine States:

    inline bool getFirstVac(){return this->firstVac;}
    inline bool getSecondVac(){return this->secondVac;}
    inline bool getBoosterVac(){return this->boosterVac;}

    inline void setFirstVac(bool state){firstVac = state;}
    inline void setSecondVac(bool state){secondVac = state;}
    inline void setBoosterVac(bool state){boosterVac = state;}



};


#endif // USERTYPE_H
