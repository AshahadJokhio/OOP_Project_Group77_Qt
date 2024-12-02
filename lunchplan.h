#ifndef LUNCHPLAN_H
#define LUNCHPLAN_H

#include "dietplan.h"      // Base class
#include "ui_lunchplan.h"  // Generated UI header

class LunchPlan : public DietPlan {
    Q_OBJECT

public:
    explicit LunchPlan(QWidget *parent = nullptr);
    ~LunchPlan();

    // Overridden methods for polymorphism
    void addMeal(const QString &description, const QDateTime &time, int calories) override;
    bool checkCalories(int calorieLimit) const override;

private:
    Ui::LunchPlan *ui;  // Declare the UI pointer

private slots:
    void on_AddLunchButton_clicked();         // Slot for adding lunch meal
    void on_BacktoDietfromLunch_clicked();    // Slot for navigating back to DietManagement
};

#endif // LUNCHPLAN_H
