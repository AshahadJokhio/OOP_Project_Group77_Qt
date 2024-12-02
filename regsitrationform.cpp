#include "registrationform.h"
#include "ui_registrationform.h"
#include <QMessageBox>

RegistrationForm::RegistrationForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RegistrationForm)
{
    ui->setupUi(this);
    connect(ui->NewRegisterButton, &QPushButton::clicked, this, &RegistrationForm::on_NewRegisterButton_clicked);
    connect(ui->CancelButton, &QPushButton::clicked, this, &RegistrationForm::on_CancelButton_clicked);
}

RegistrationForm::~RegistrationForm()
{
    delete ui;
}

void RegistrationForm::on_NewRegisterButton_clicked()
{
    // Validation and registration logic goes here
    QMessageBox::information(this, "Registration", "You are successfully registered!");
    this->close(); // Close registration form after successful registration
}

void RegistrationForm::on_CancelButton_clicked()
{
    this->close(); // Close the registration form
}
