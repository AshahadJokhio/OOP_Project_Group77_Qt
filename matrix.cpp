#include "matrix.h"
#include "ui_matrix.h"
#include "tabs.h"
#include "newuser.h"
#include <QMessageBox> // Required for QMessageBox

Matrix::Matrix(QWidget *parent)
    : QWidget(parent), ui(new Ui::Matrix)
{
    ui->setupUi(this);
    connect(ui->LoginButton, &QPushButton::clicked, this, &Matrix::onLoginButtonClicked);
    connect(ui->RegisterButton, &QPushButton::clicked, this, &Matrix::onRegisterButtonClicked);
}

Matrix::~Matrix()
{
    delete ui;
}

void Matrix::onLoginButtonClicked() {
    QString username = ui->UsernameLine->text();
    QString password = ui->PasswordLine->text();
    if (username == "admin" && password == "admin") {
        QMessageBox::information(this, "Login Successful", "You have successfully logged in.");

        // Open the Tabs screen
        Tabs *tabsScreen = new Tabs();
        tabsScreen->show();
        this->close(); // Close the login screen
    } else {
        QMessageBox::warning(this, "Login Failed", "Incorrect username or password.");
    }
}


void Matrix::onRegisterButtonClicked() {
    NewUser *registrationForm = new NewUser();

    connect(registrationForm, &QWidget::destroyed, this, [this]() {
        this->show(); // Show login screen when registration form is closed
    });

    connect(registrationForm, &NewUser::registeredSuccessfully, this, [this]() {
        // Open the Tabs screen after successful registration
        Tabs *tabsScreen = new Tabs();
        tabsScreen->show();
        this->close(); // Close the login screen
    });

    this->hide();               // Hide the login screen
    registrationForm->show();   // Show the registration form
}


