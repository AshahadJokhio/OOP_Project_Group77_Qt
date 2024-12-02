#ifndef TASKMANAGER_H
#define TASKMANAGER_H

#include <QWidget>

namespace Ui {
class TaskManager;
}

class TaskManager : public QWidget
{
    Q_OBJECT

public:
    explicit TaskManager(QWidget *parent = nullptr);
    ~TaskManager();

private slots:
    void on_WorkTaskButton_clicked();    // Navigate to WorkTask screen
    void on_PersonalTaskButton_clicked(); // Navigate to PersonalTask screen
    void on_Backtab_clicked();           // Navigate back to Tabs screen

private:
    Ui::TaskManager *ui;
};

#endif // TASKMANAGER_H
