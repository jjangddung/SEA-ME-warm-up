#include <QMessageBox>
#include <QDebug>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "adddialog.h"
#include "contactlist.h"
#include <QTableWidgetItem>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->tableWidget->setColumnCount(4);
    ui->tableWidget->setHorizontalHeaderLabels({"이름", "전화번호", "이메일", "북마크"});
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Fixed);
    ui->tableWidget->setColumnWidth(0, 120);
    ui->tableWidget->setColumnWidth(1, 120);
    ui->tableWidget->setColumnWidth(2, 180);
    ui->tableWidget->setColumnWidth(3, 60);

    ui->tableWidget->hide();
    ui->hideButton->hide();
    ui->booklist->hide();
    ui->searchName->hide();
    ui->namesearch->hide();
    ui->namelabel->hide();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::addContactToTable(const Contact &contact, int index) {
    int row = ui->tableWidget->rowCount();
    ui->tableWidget->insertRow(row);

    auto *itemName = new QTableWidgetItem(contact.getName());
    auto *itemPhone = new QTableWidgetItem(contact.getPhone());
    auto *itemEmail = new QTableWidgetItem(contact.getEmail());
    auto *itemBookmark = new QTableWidgetItem(contact.getBookmark() ? "o" : "");

    itemName->setData(Qt::UserRole, index);

    ui->tableWidget->setItem(row, 0, itemName);
    ui->tableWidget->setItem(row, 1, itemPhone);
    ui->tableWidget->setItem(row, 2, itemEmail);
    ui->tableWidget->setItem(row, 3, itemBookmark);
}

void MainWindow::on_addButton_clicked()
{
    AddDialog dlg(this);
    if (dlg.exec() == QDialog::Accepted) {
        Contact newContact(dlg.getName(), dlg.getPhone(), dlg.getEmail(), dlg.isBookmarked());
        int index = CL.addContact(newContact);
        addContactToTable(newContact, index);
    }
}
void MainWindow::on_removeButton_2_clicked(){

}

void MainWindow::on_searchButton_clicked()
{
    ui->tableWidget->clearContents();
    ui->tableWidget->setRowCount(0);
    const QVector<Contact> &contacts = CL.getContacts();
    for (int i = 0; i < contacts.size(); ++i) {
        addContactToTable(contacts[i], i);
    }
    ui->tableWidget->show();
    ui->hideButton->show();
    ui->booklist->show();
    ui->namesearch->show();
    ui->namelabel->show();
    ui->searchName->show();
}

void MainWindow::on_hideButton_clicked()
{
    ui->tableWidget->hide();
    ui->hideButton->hide();
    ui->booklist->hide();
}

void MainWindow::on_removeButton_clicked()
{
    int row = ui->tableWidget->currentRow();
    if (row < 0) {
        QMessageBox::warning(this, "경고", "삭제할 항목을 선택하세요!");
        return;
    }

    int index = ui->tableWidget->item(row, 0)->data(Qt::UserRole).toInt();
    CL.removeAt(index);
    ui->tableWidget->removeRow(row);
}

void MainWindow::on_bookmarkButton_clicked()
{
    ui->tableWidget->clearContents();
    ui->tableWidget->setRowCount(0);

    const QVector<Contact> &contacts = CL.getContacts();
    for (int i = 0; i < contacts.size(); ++i) {
        if (contacts[i].getBookmark()) {
            addContactToTable(contacts[i], i);
        }
    }
    ui->tableWidget->show();
    ui->hideButton->show();
}

void MainWindow::on_exitButton_clicked()
{
    close();
}

void MainWindow::on_namesearch_clicked()
{
    QString keyword = ui->searchName->text().trimmed();
    ui->tableWidget->clearContents();
    ui->tableWidget->setRowCount(0);

    QVector<Contact> result = keyword.isEmpty() ? CL.getContacts() : CL.searchByName(keyword);

    if (result.isEmpty() && !keyword.isEmpty()) {
        QMessageBox::information(this, "검색 결과 없음", "해당 이름의 연락처가 없습니다.");
    }

    const QVector<Contact> &allContacts = CL.getContacts();
    for (int i = 0; i < allContacts.size(); ++i) {
        if (keyword.isEmpty() || allContacts[i].getName().contains(keyword)) {
            addContactToTable(allContacts[i], i);
        }
    }

    ui->namesearch->hide();
    ui->namelabel->hide();
    ui->searchName->hide();
}

void MainWindow::on_editButton_clicked()
{
    ui->tableWidget->show();
    ui->booklist->show();
    ui->hideButton->show();

    int row = ui->tableWidget->currentRow();  // 선택된 행 인덱스

    if (row < 0 || row >= CL.size()) {
        QMessageBox::warning(this, "경고", "수정할 연락처를 선택하세요!");
        return;
    }


    std::optional<Contact> opt = CL.get(row);
    if (!opt.has_value()) return;

    Contact contact = opt.value();


    AddDialog dlg(this);
    dlg.setName(contact.getName());
    dlg.setPhone(contact.getPhone());
    dlg.setEmail(contact.getEmail());
    dlg.setBookmarked(contact.isBookmarked());


    if (dlg.exec() == QDialog::Accepted) {

        QString name = dlg.getName();
        QString phone = dlg.getPhone();
        QString email = dlg.getEmail();
        bool bookmarked = dlg.isBookmarked();


        Contact updated(name, phone, email, bookmarked);
        CL.updateAt(row, updated);

        on_searchButton_clicked();
    }
}

