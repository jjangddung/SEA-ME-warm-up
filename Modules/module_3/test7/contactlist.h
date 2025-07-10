#pragma once
#include "contact.h"
//#include <vector>
#include <QVector>
#include <optional>

class ContactList
{
private:
    QVector<Contact> contacts;


public:
    ContactList();
    ~ContactList();
    ContactList(const ContactList& other);
    ContactList& operator = (const ContactList& other);

    int addContact(const Contact& contact);
    void removeAt(int index);
    std::optional<Contact> get(int index) const;
    int size() const;
    const QVector<Contact>& getAll() const;
    QVector<Contact> getBookmarkedContacts() const;
    QVector<Contact> getContacts() const;
    QVector<Contact> searchByName(const QString& name) const;
    void updateAt(int index, const Contact& contact);







};

