#ifndef DIETMANAGEMENT_H
#define DIETMANAGEMENT_H

#include <QWidget>

namespace Ui {
class DietManagement;
}

class DietManagement : public QWidget {
    Q_OBJECT

public:
    explicit DietManagement(QWidget *parent = nullptr);
    ~DietManagement();

private slots:
    void on_BreakfastPlan_clicked();  // Navigate to Breakfast Plan
    void on_LunchPlan_clicked();      // Navigate to Lunch Plan
    void on_DinnerPlan_clicked();     // Navigate to Dinner Plan
    void on_BacktoTabsfromDiet_clicked(); // Navigate back to Tabs

private:
    Ui::DietManagement *ui;
};

#endif // DIETMANAGEMENT_H
