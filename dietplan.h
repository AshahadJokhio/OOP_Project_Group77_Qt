#ifndef DIETPLAN_H
#define DIETPLAN_H

#include <QWidget>  // Include QWidget
#include <QString>
#include <QDateTime>
#include "notification.h"  // Notification class for alerts

class DietPlan : public QWidget, public Notification {  // Inherit from QWidget and Notification
    Q_OBJECT

public:
    explicit DietPlan(QWidget *parent = nullptr);  // Constructor accepting QWidget parent
    virtual ~DietPlan() = default;                 // Virtual destructor for polymorphism

    // Virtual methods for derived classes
    virtual void addMeal(const QString &description, const QDateTime &time, int calories) = 0;
    virtual bool checkCalories(int calorieLimit) const = 0;

protected:
    QString mealDescription;
    QDateTime mealTime;
    int mealCalories;
};

#endif // DIETPLAN_H

