#include <iostream>
#include "contact.h"


Contact::Contact(const QString &n, const QString &p,const QString &e, bool b)
    : name(n) , phone(p) , bookmark(b) , email(e){}

Contact::~Contact(){
    std::cout << "------Contact_Destructor--------\n";

}

Contact::Contact(const Contact&other)
    : name(other.name), phone(other.phone),  bookmark(other.bookmark), email(other.email){
    //delete year;
    std::cout << "------Contact_Copy Constructor--------\n";
}

Contact& Contact::operator  =(const Contact& other){
    if (this != &other){
        name = other.name;
        phone = other.phone;
        bookmark = other.bookmark;
        email = other.email;
        std::cout << "------Contact_Copy assignment operator override--------\n";
    }
    return *this; //자기 자신 반환
}
QString Contact::getEmail() const{
    return email;
}
QString Contact::getName()  const {
    return name;
}
QString Contact::getPhone() const {
    return phone;
}
bool Contact::getBookmark() const {
    return bookmark;
}

bool Contact::isBookmarked() const {
    return bookmark;
}
