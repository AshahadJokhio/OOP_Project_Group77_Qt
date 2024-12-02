#ifndef MATRIX_H
#define MATRIX_H

#include <QWidget>
#include "newuser.h" // Include the header for NewUser

QT_BEGIN_NAMESPACE
namespace Ui { class Matrix; }
QT_END_NAMESPACE

class Matrix : public QWidget
{
    Q_OBJECT

public:
    explicit Matrix(QWidget *parent = nullptr);
    ~Matrix();

private slots:
    void onLoginButtonClicked();   // Slot for handling login button click
    void onRegisterButtonClicked(); // Slot for handling register button click

private:
    Ui::Matrix *ui;
    NewUser *registrationForm = nullptr; // Member variable to hold the registration form
};

#endif // MATRIX_H
