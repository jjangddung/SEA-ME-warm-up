#include <QMainWindow>
//#include <vector>
//#include "contact.h"
#include "contactlist.h"

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_addButton_clicked();
    void on_searchButton_clicked();
    //void on_pushButton_2_clicked();

    void on_hideButton_clicked();

    void on_removeButton_clicked();

    void on_bookmarkButton_clicked();

    void on_exitButton_clicked();

    void on_namesearch_clicked();

    void on_removeButton_2_clicked();

    void on_editButton_clicked();

    void addContactToTable(const Contact &contact, int index);

private:
    Ui::MainWindow *ui;
    ContactList CL;
    //std::vector<Contact> contactList;
};

#endif // MAINWINDOW_H
