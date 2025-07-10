#include "adddialog.h"
#include "ui_adddialog.h"

AddDialog::AddDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddDialog)
{
    ui->setupUi(this);
    connect(ui->buttonBox, &QDialogButtonBox::accepted, this, &AddDialog::accept);
    connect(ui->buttonBox, &QDialogButtonBox::rejected, this, &AddDialog::reject);
}

AddDialog::~AddDialog()
{
    delete ui;
}

QString AddDialog::getName() const {
    return ui->lineEdit_name->text();
}

QString AddDialog::getPhone() const {
    return ui->lineEdit_phone->text();
}

QString AddDialog::getEmail() const {
    return ui->lineEdit_email->text();
}

bool AddDialog::isBookmarked() const {
    return ui->checkBox_bookmark->isChecked();
}
void AddDialog::setName(const QString& name) {
    ui->lineEdit_name->setText(name);
}

void AddDialog::setPhone(const QString& phone) {
    ui->lineEdit_phone->setText(phone);
}

void AddDialog::setEmail(const QString& email) {
    ui->lineEdit_email->setText(email);
}

void AddDialog::setBookmarked(bool bookmarked) {
    ui->checkBox_bookmark->setChecked(bookmarked);
}
