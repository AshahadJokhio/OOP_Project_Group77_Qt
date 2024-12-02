#ifndef NOTIFICATION_H
#define NOTIFICATION_H

#include <QString>
#include <QDateTime>

class Notification {
public:
    virtual ~Notification() = default;
    void virtual sendAlert(const QString &title, const QDateTime &dueDate, const QString &details) const;
};

#endif // NOTIFICATION_H
