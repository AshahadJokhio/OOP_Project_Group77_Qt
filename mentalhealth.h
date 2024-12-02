#ifndef MENTALHEALTH_H
#define MENTALHEALTH_H

#include <QWidget>
#include "notification.h"
#include "ui_mentalhealth.h"
#include "tabs.h"

class MentalHealth : public QWidget, public Notification {
    Q_OBJECT

public:
    explicit MentalHealth(QWidget *parent = nullptr);
    ~MentalHealth();

    // Overridden notification function to show mood-based alerts
    void sendAlert(const QString &title, const QDateTime &alertTime, const QString &details) const override;

private slots:
    void on_LogMoodButton_clicked();         // Slot for logging mood
    void on_BacktoTabsfromMental_clicked();  // Slot for going back to tabs

private:
    Ui::MentalHealth *ui;
};

#endif // MENTALHEALTH_H

