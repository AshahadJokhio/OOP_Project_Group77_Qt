#include "dinnerplan.h"
#include "ui_dinnerplan.h"
#include "dietmanagement.h"

// Constructor
DinnerPlan::DinnerPlan(QWidget *parent)
    : DietPlan(parent), ui(new Ui::DinnerPlan)  // Pass 'parent' to the base class and initialize 'ui'
{
    ui->setupUi(this);

    // Connect signals to slots
    connect(ui->AddDinnerButton, &QPushButton::clicked, this, &DinnerPlan::on_AddDinnerButton_clicked);
    connect(ui->BacktoDietfromDinner, &QPushButton::clicked, this, &DinnerPlan::on_BacktoDietfromDinner_clicked);
}

// Destructor
DinnerPlan::~DinnerPlan() {
    delete ui;  // Proper cleanup of dynamically allocated UI pointer
}

// Add Meal
void DinnerPlan::addMeal(const QString &description, const QDateTime &time, int calories) {
    mealDescription = description;
    mealTime = time;
    mealCalories = calories;

    // Create a single alert message
    QString alertMessage = QString("Meal: %1\nTime: %2\nCalories: %3")
                               .arg(description)
                               .arg(time.toString("hh:mm AP"))
                               .arg(calories);

    // Check if the calorie limit is exceeded
    if (checkCalories(600)) { // Example calorie limit for dinner
        alertMessage += "\nWarning: Calorie limit exceeded!";
    }

    // Show the combined alert
    sendAlert("Dinner Meal Added", time, alertMessage);
}

// Check Calories
bool DinnerPlan::checkCalories(int calorieLimit) const {
    return mealCalories > calorieLimit;  // Return whether the calorie limit is exceeded
}

// Slot: Add Dinner Button Clicked
void DinnerPlan::on_AddDinnerButton_clicked() {
    // Retrieve input values from the UI
    QString meal = ui->AddMealDinner->toPlainText();
    QDateTime time = QDateTime(QDate::currentDate(), ui->AddTimeDinner->time());  // Convert QTime to QDateTime
    int calories = ui->AddCalorieDinner->text().toInt();

    // Call addMeal, which handles all alert logic
    addMeal(meal, time, calories);
}

// Slot: Back to Diet Plan Clicked
void DinnerPlan::on_BacktoDietfromDinner_clicked() {
    // Navigate back to DietManagement screen
    DietManagement *dietScreen = new DietManagement();
    dietScreen->show();
    this->close();  // Close the DinnerPlan screen
}
