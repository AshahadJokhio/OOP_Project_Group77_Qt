#include "breakfastplan.h"
#include "ui_breakfastplan.h"
#include "dietmanagement.h"

BreakfastPlan::BreakfastPlan(QWidget *parent)
    : DietPlan(parent), ui(new Ui::BreakfastPlan)  // Ensure 'parent' is passed to DietPlan
{
    ui->setupUi(this);

    // Connect signals to slots using member functions
    connect(ui->AddBreakfastButton, &QPushButton::clicked, this, &BreakfastPlan::on_AddBreakfastButton_clicked);
    connect(ui->BacktoDietfromBreakfast, &QPushButton::clicked, this, &BreakfastPlan::on_BacktoDietfromBreakfast_clicked);
}

BreakfastPlan::~BreakfastPlan() {
    delete ui;  // Proper cleanup of dynamically allocated UI pointer
}

void BreakfastPlan::addMeal(const QString &description, const QDateTime &time, int calories) {
    mealDescription = description;
    mealTime = time;
    mealCalories = calories;

    // Create a single alert message
    QString alertMessage = QString("Meal: %1\nTime: %2\nCalories: %3")
                               .arg(description)
                               .arg(time.toString("hh:mm AP"))
                               .arg(calories);

    // Check if the calorie limit is exceeded
    if (checkCalories(500)) { // Example calorie limit for breakfast
        alertMessage += "\nWarning: Calorie limit exceeded!";
    }

    // Show the combined alert
    sendAlert("Breakfast Meal Added", time, alertMessage);
}

bool BreakfastPlan::checkCalories(int calorieLimit) const {
    return mealCalories > calorieLimit;  // Return whether the calorie limit is exceeded
}

void BreakfastPlan::on_AddBreakfastButton_clicked() {
    // Retrieve input values from the UI
    QString meal = ui->AddMealBreakfast->toPlainText();
    QDateTime time = QDateTime(QDate::currentDate(), ui->AddTimeBreakfast->time());
    int calories = ui->AddCalorieBreakfast->text().toInt();

    // Call addMeal, which handles all alert logic
    addMeal(meal, time, calories);
}

void BreakfastPlan::on_BacktoDietfromBreakfast_clicked() {
    // Navigate back to DietManagement screen
    DietManagement *dietScreen = new DietManagement();
    dietScreen->show();
    this->close();  // Close the BreakfastPlan screen
}
