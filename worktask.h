#ifndef WORKTASK_H
#define WORKTASK_H

#include "task.h"
#include <QWidget>

namespace Ui {
class WorkTask;
}

class WorkTask : public Task {
    Q_OBJECT

public:
    explicit WorkTask(QWidget *parent = nullptr);
    ~WorkTask();

private slots:
    void on_AddWorkButton_clicked(); // Add a work task
    void on_BacktoTaskfromWork_clicked(); // Navigate back to Task Manager

private:
    Ui::WorkTask *ui;
};

#endif // WORKTASK_H
