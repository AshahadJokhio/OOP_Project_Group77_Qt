#include "personaltask.h"
#include "ui_personaltask.h"
#include "taskmanager.h"
#include "QMessageBox"

PersonalTask::PersonalTask(QWidget *parent) :
    Task(parent),
    ui(new Ui::PersonalTask)
{
    ui->setupUi(this);

    // Connect buttons to slots
    connect(ui->AddPersonalButton, &QPushButton::clicked, this, &PersonalTask::on_AddPersonalButton_clicked);
    connect(ui->BacktoTaskfromPersonal, &QPushButton::clicked, this, &PersonalTask::on_BacktoTaskfromPersonal_clicked);
}

PersonalTask::~PersonalTask() {
    delete ui;
}

void PersonalTask::on_AddPersonalButton_clicked() {
    QString taskTitle = ui->AddTitlePersonal->text();
    QDateTime dueDate = ui->AddDatePersonal->dateTime();
    QString priority = ui->AddPriorityPersonal->currentText();

    // Validate inputs
    if (taskTitle.isEmpty()) {
        QMessageBox::warning(this, "Error", "Task title cannot be empty.");
        return;
    }

    // Add task logic
    addTask(taskTitle, dueDate, priority);

    QMessageBox::information(this, "Task Added", "Personal Task added successfully.");
}

void PersonalTask::on_BacktoTaskfromPersonal_clicked() {
    TaskManager *taskManagerScreen = new TaskManager();
    taskManagerScreen->show();
    this->close();
}
