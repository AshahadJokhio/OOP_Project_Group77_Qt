#ifndef TASK_H
#define TASK_H

#include <QWidget>
#include <QDateTime>
#include <QString>

class Task : public QWidget {
    Q_OBJECT

public:
    explicit Task(QWidget *parent = nullptr);
    virtual ~Task();

    virtual void addTask(const QString &title, const QDateTime &dueDate, const QString &priority);

protected:
    QString taskTitle;
    QDateTime dueDate;
    QString priority;
};

#endif // TASK_H
