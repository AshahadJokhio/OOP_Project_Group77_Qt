#ifndef NEWUSER_H
#define NEWUSER_H

#include <QWidget>

namespace Ui {
class NewUser;
}

class NewUser : public QWidget
{
    Q_OBJECT

public:
    explicit NewUser(QWidget *parent = nullptr);
    ~NewUser();

signals:
    void registeredSuccessfully(); // Signal for successful registration

private slots:
    void registerUser();

private:
    Ui::NewUser *ui;
};

#endif // NEWUSER_H
