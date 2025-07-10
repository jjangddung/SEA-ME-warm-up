#ifndef ADDDIALOG_H
#define ADDDIALOG_H

#include <QDialog>

namespace Ui {
class AddDialog;
}

class AddDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddDialog(QWidget *parent = nullptr);
    ~AddDialog();

    QString getName() const;
    QString getPhone() const;
    QString getEmail() const;
    bool isBookmarked() const;

    void setName(const QString& name);
    void setPhone(const QString& phone);
    void setEmail(const QString& email);
    void setBookmarked(bool bookmarked);


private:
    Ui::AddDialog *ui;
};

#endif // ADDDIALOG_H
