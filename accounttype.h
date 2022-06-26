#ifndef ACCOUNTTYPE_H
#define ACCOUNTTYPE_H

#include <string>
#include <QWidget>
#include <QMap>

class accountType
{
public:

    accountType();

private:

    QString username;
    QString password;

public:

    // Getters

    inline QString getUsername(){return this->username;}
    inline QString getPassword(){return this->password;}

    // Setters

    inline void setUsername(QString username){this->username = username;}
    inline void setPassword(QString password){this->password = password;}

};

#endif // ACCOUNTTYPE_H
