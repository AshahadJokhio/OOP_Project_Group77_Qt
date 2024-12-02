#ifndef BREAKFASTPLAN_H
#define BREAKFASTPLAN_H

#include "dietplan.h"  // Base class
#include "ui_breakfastplan.h"  // Generated UI header

class BreakfastPlan : public DietPlan {
    Q_OBJECT

public:
    explicit BreakfastPlan(QWidget *parent = nullptr);
    ~BreakfastPlan();

    // Overridden methods for polymorphism
    void addMeal(const QString &description, const QDateTime &time, int calories) override;
    bool checkCalories(int calorieLimit) const override;

private:
    Ui::BreakfastPlan *ui;  // Declare the UI pointer

private slots:
    void on_AddBreakfastButton_clicked();        // Slot for adding breakfast meal
    void on_BacktoDietfromBreakfast_clicked();   // Slot for navigating back to DietManagement
};

#endif // BREAKFASTPLAN_H
