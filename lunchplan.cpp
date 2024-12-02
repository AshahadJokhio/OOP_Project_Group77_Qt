#include "lunchplan.h"
#include "ui_lunchplan.h"
#include "dietmanagement.h"

LunchPlan::LunchPlan(QWidget *parent)
    : DietPlan(parent), ui(new Ui::LunchPlan)  // Pass 'parent' to the base class and initialize 'ui'
{
    ui->setupUi(this);

    // Connect signals to slots
    connect(ui->AddLunchButton, &QPushButton::clicked, this, &LunchPlan::on_AddLunchButton_clicked);
    connect(ui->BacktoDietfromLunch, &QPushButton::clicked, this, &LunchPlan::on_BacktoDietfromLunch_clicked);
}

LunchPlan::~LunchPlan() {
    delete ui;  // Proper cleanup of dynamically allocated UI pointer
}

void LunchPlan::addMeal(const QString &description, const QDateTime &time, int calories) {
    mealDescription = description;
    mealTime = time;
    mealCalories = calories;

    // Create a single alert message
    QString alertMessage = QString("Meal: %1\nTime: %2\nCalories: %3")
                               .arg(description)
                               .arg(time.toString("hh:mm AP"))
                               .arg(calories);

    // Check if the calorie limit is exceeded
    if (checkCalories(700)) { // Example calorie limit for lunch
        alertMessage += "\nWarning: Calorie limit exceeded!";
    }

    // Show the combined alert
    sendAlert("Lunch Meal Added", time, alertMessage);
}

bool LunchPlan::checkCalories(int calorieLimit) const {
    return mealCalories > calorieLimit;  // Return whether the calorie limit is exceeded
}

void LunchPlan::on_AddLunchButton_clicked() {
    // Retrieve input values from the UI
    QString meal = ui->AddMealLunch->toPlainText();
    QDateTime time = QDateTime(QDate::currentDate(), ui->AddTimeLunch->time());  // Convert QTime to QDateTime
    int calories = ui->AddCalorieLunch->text().toInt();

    // Call addMeal, which handles all alert logic
    addMeal(meal, time, calories);
}

void LunchPlan::on_BacktoDietfromLunch_clicked() {
    // Navigate back to DietManagement screen
    DietManagement *dietScreen = new DietManagement();
    dietScreen->show();
    this->close();  // Close the LunchPlan screen
}

