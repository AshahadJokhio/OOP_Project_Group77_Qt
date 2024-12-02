#include "task.h"
#include "QMessageBox"

Task::Task(QWidget *parent) : QWidget(parent) {}

Task::~Task() {}

void Task::addTask(const QString &title, const QDateTime &dueDate, const QString &priority) {
    taskTitle = title;
    this->dueDate = dueDate;
    this->priority = priority;

    // For now, just print a message. You can extend this logic.
    QMessageBox::information(this, "Task Added",
                             QString("Task: %1\nDue: %2\nPriority: %3")
                                 .arg(taskTitle)
                                 .arg(dueDate.toString())
                                 .arg(priority));
}
