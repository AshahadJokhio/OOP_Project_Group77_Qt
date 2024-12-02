#include "worktask.h"
#include "ui_worktask.h"
#include "taskmanager.h"
#include "QMessageBox"

WorkTask::WorkTask(QWidget *parent) :
    Task(parent),
    ui(new Ui::WorkTask)
{
    ui->setupUi(this);

    // Connect buttons to slots
    connect(ui->AddWorkButton, &QPushButton::clicked, this, &WorkTask::on_AddWorkButton_clicked);
    connect(ui->BacktoTaskfromWork, &QPushButton::clicked, this, &WorkTask::on_BacktoTaskfromWork_clicked);
}

WorkTask::~WorkTask() {
    delete ui;
}

void WorkTask::on_AddWorkButton_clicked() {
    QString taskTitle = ui->AddTtitlWork->text();
    QDateTime dueDate = ui->AddDateWork->dateTime();
    QString priority = ui->AddPrioritWork->currentText();

    // Validate inputs
    if (taskTitle.isEmpty()) {
        QMessageBox::warning(this, "Error", "Task title cannot be empty.");
        return;
    }

    // Add task logic
    addTask(taskTitle, dueDate, priority);

    QMessageBox::information(this, "Task Added", "Work Task added successfully.");
}

void WorkTask::on_BacktoTaskfromWork_clicked() {
    TaskManager *taskManagerScreen = new TaskManager();
    taskManagerScreen->show();
    this->close();
}
