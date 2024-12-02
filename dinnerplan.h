#ifndef DINNERPLAN_H
#define DINNERPLAN_H

#include "dietplan.h"      // Base class
#include "ui_dinnerplan.h" // Generated UI header

class DinnerPlan : public DietPlan {
    Q_OBJECT

public:
    explicit DinnerPlan(QWidget *parent = nullptr);
    ~DinnerPlan();

    // Overridden methods for polymorphism
    void addMeal(const QString &description, const QDateTime &time, int calories) override;
    bool checkCalories(int calorieLimit) const override;

private:
    Ui::DinnerPlan *ui;  // Declare the UI pointer

private slots:
    void on_AddDinnerButton_clicked();         // Slot for adding dinner meal
    void on_BacktoDietfromDinner_clicked();    // Slot for navigating back to DietManagement
};

#endif // DINNERPLAN_H
