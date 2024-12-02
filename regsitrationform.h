#ifndef REGISTRATIONFORM_H
#define REGISTRATIONFORM_H

#include <QWidget>

namespace Ui {
class RegistrationForm;
}

class RegistrationForm : public QWidget
{
    Q_OBJECT

public:
    explicit RegistrationForm(QWidget *parent = nullptr);
    ~RegistrationForm();

private slots:
    void on_NewRegisterButton_clicked();
    void on_CancelButton_clicked();

private:
    Ui::RegistrationForm *ui;
};

#endif // REGISTRATIONFORM_H
