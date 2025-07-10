#include "contactlist.h"

ContactList::ContactList() {}

ContactList::~ContactList() {}

ContactList::ContactList(const ContactList& other)
    : contacts(other.contacts) {}  // vector는 깊은 복사됨

ContactList& ContactList::operator=(const ContactList& other) {
    if (this != &other) {
        contacts = other.contacts;
    }
    return *this;
}

int ContactList::addContact(const Contact& contact) {
    contacts.push_back(contact);
    return contacts.size();
}

void ContactList::removeAt(int index) {
    if (index >= 0 && index < static_cast<int>(contacts.size()))
        contacts.erase(contacts.begin() + index);
}

std::optional<Contact> ContactList::get(int index) const {
    if (index >= 0 && index < static_cast<int>(contacts.size()))
        return contacts[index];
    return std::nullopt;
}

int ContactList::size() const {
    return contacts.size();
}

const QVector<Contact>& ContactList::getAll() const {
    return contacts;
}
QVector<Contact> ContactList::getBookmarkedContacts() const {
    QVector<Contact> result;
    for (const auto& contact : contacts) {
        if (contact.isBookmarked()) {
            result.push_back(contact);
        }
    }
    return result;
}


QVector<Contact> ContactList::getContacts() const {
    QVector<Contact> result;
    for (const auto& contact : contacts) {
        result.push_back(contact);
    }
    return result;
}

QVector<Contact> ContactList::searchByName(const QString& name) const {
    QVector<Contact> result;
    for (const auto& contact : contacts) {
        if (contact.getName() == name) {
            result.push_back(contact);
        }
    }
    return result;
}

void ContactList::updateAt(int index, const Contact& contact) {
    if (index >= 0 && index < contacts.size()) {
        contacts[index] = contact;
    }
}


