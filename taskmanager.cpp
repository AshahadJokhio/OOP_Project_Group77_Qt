#include "taskmanager.h"
#include "ui_taskmanager.h"
#include "worktask.h"
#include "personaltask.h"
#include "tabs.h"

TaskManager::TaskManager(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TaskManager)
{
    ui->setupUi(this);

    // Connect buttons to their respective slots
    connect(ui->WorkTaskButton, &QPushButton::clicked, this, &TaskManager::on_WorkTaskButton_clicked);
    connect(ui->PersonalTaskButton, &QPushButton::clicked, this, &TaskManager::on_PersonalTaskButton_clicked);
    connect(ui->Backtab, &QPushButton::clicked, this, &TaskManager::on_Backtab_clicked);
}

TaskManager::~TaskManager() {
    delete ui;
}

void TaskManager::on_WorkTaskButton_clicked() {
    // Navigate to WorkTask screen
    WorkTask *workTaskScreen = new WorkTask(); // Create WorkTask screen
    workTaskScreen->setAttribute(Qt::WA_DeleteOnClose); // Ensure memory cleanup when the window is closed
    workTaskScreen->show();
    this->close(); // Close the current TaskManager screen
}

void TaskManager::on_PersonalTaskButton_clicked() {
    // Navigate to PersonalTask screen
    PersonalTask *personalTaskScreen = new PersonalTask(); // Create PersonalTask screen
    personalTaskScreen->setAttribute(Qt::WA_DeleteOnClose); // Ensure memory cleanup when the window is closed
    personalTaskScreen->show();
    this->close(); // Close the current TaskManager screen
}

void TaskManager::on_Backtab_clicked() {
    // Navigate back to Tabs screen
    Tabs *tabsScreen = new Tabs(); // Create Tabs screen
    tabsScreen->setAttribute(Qt::WA_DeleteOnClose); // Ensure memory cleanup when the window is closed
    tabsScreen->show();
    this->close(); // Close the current TaskManager screen
}
