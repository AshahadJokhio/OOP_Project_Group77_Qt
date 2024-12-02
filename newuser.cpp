#include "newuser.h"
#include "ui_newuser.h"
#include <QMessageBox>

NewUser::NewUser(QWidget *parent) : QWidget(parent), ui(new Ui::NewUser)
{
    ui->setupUi(this);

    // Connect Register button to registration logic
    connect(ui->NewRegisterButton, &QPushButton::clicked, this, &NewUser::registerUser);

    // Connect Cancel button to close the form
    connect(ui->CancelButton, &QPushButton::clicked, this, &NewUser::close);
}

NewUser::~NewUser()
{
    delete ui;
}

void NewUser::registerUser() {
    QString username = ui->AddUsername->text();
    QString email = ui->AddEmail->text();
    QString password = ui->AddPassword->text();
    QString confirmPassword = ui->AddConfirmPassword->text();

    // Validation logic
    if (username.isEmpty() || email.isEmpty() || password.isEmpty() || confirmPassword.isEmpty()) {
        QMessageBox::warning(this, "Registration Failed", "Please fill in all fields.");
        return;
    }

    if (password != confirmPassword) {
        QMessageBox::warning(this, "Registration Failed", "Passwords do not match.");
        return;
    }

    QMessageBox::information(this, "Registration Successful", "You have successfully registered.");
    emit registeredSuccessfully(); // Emit the success signal
    this->close(); // Close the registration form
}

