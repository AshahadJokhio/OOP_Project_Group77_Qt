#ifndef FITNESSROUTINE_H
#define FITNESSROUTINE_H

#include <QWidget>
#include <QString>
#include <QDateTime>
#include "notification.h"

namespace Ui {
class FitnessRoutine;
}

class FitnessRoutine : public QWidget, public Notification {
    Q_OBJECT

public:
    explicit FitnessRoutine(QWidget *parent = nullptr);
    ~FitnessRoutine();

    // Override the sendAlert method from Notification
    void sendAlert(const QString &title, const QDateTime &alertTime, const QString &details) const override;

private slots:
    void on_SuggestPlanButton_clicked();
    void on_BacktoTabsfromFitness_clicked();

private:
    Ui::FitnessRoutine *ui;
};

#endif // FITNESSROUTINE_H
