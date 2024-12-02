#include "notification.h"
#include <QMessageBox>

void Notification::sendAlert(const QString &title, const QDateTime &time, const QString &details) const {
    QString alertMessage = QString("Reminder: %1 is scheduled for %2. Details: %3")
    .arg(title)
        .arg(time.toString("hh:mm AP"))
        .arg(details);
    QMessageBox::information(nullptr, "Notification", alertMessage);
}
