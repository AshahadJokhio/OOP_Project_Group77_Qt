#ifndef PERSONALTASK_H
#define PERSONALTASK_H

#include "task.h"
#include <QWidget>

namespace Ui {
class PersonalTask;
}

class PersonalTask : public Task {
    Q_OBJECT

public:
    explicit PersonalTask(QWidget *parent = nullptr);
    ~PersonalTask();

private slots:
    void on_AddPersonalButton_clicked(); // Add a personal task
    void on_BacktoTaskfromPersonal_clicked(); // Navigate back to Task Manager

private:
    Ui::PersonalTask *ui;
};

#endif // PERSONALTASK_H
