#ifndef TABS_H
#define TABS_H

#include <QWidget>

namespace Ui {
class Tabs;
}

class Tabs : public QWidget {
    Q_OBJECT

public:
    explicit Tabs(QWidget *parent = nullptr);
    ~Tabs();

private slots:
    void on_BacktoSign_clicked();     // Slot for Back to Sign-In button
    void on_Close_clicked();          // Slot for Close button
    void on_TaskManager_clicked();    // Slot for Task Manager button
    void on_DietPlan_clicked();       // Slot for Diet Plan button
    void on_MentalHealth_clicked();  // Add slot for Mental Health tab
    void on_FitnessRoutine_clicked(); // Slot for Fitness Routine button
    void on_HealthVitalStats_clicked(); // Slot for navigating to VitalStats



private:
    Ui::Tabs *ui;
};

#endif // TABS_H
