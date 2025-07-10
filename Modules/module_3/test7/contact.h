
#pragma once
#include <QString>
class Contact
{
private:
    QString name ;
    QString phone;
    QString email;
    bool bookmark;

public:
    Contact(const QString &n, const QString &p, const QString &e, bool b);
    ~Contact();
    Contact(const Contact & other);
    Contact& operator = (const Contact& other);
    bool isBookmarked() const;
    QString getName() const;
    QString getPhone() const ;
    QString getEmail() const ;
    bool getBookmark() const ;
};

