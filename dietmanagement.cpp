#include "dietmanagement.h"
#include "ui_dietmanagement.h"
#include "breakfastplan.h"
#include "lunchplan.h"
#include "dinnerplan.h"
#include "tabs.h"

DietManagement::DietManagement(QWidget *parent)
    : QWidget(parent), ui(new Ui::DietManagement)
{
    ui->setupUi(this);

    // Connect buttons to their respective slots
    connect(ui->BreakfastPlan, &QPushButton::clicked, this, &DietManagement::on_BreakfastPlan_clicked);
    connect(ui->LunchPlan, &QPushButton::clicked, this, &DietManagement::on_LunchPlan_clicked);
    connect(ui->DinnerPlan, &QPushButton::clicked, this, &DietManagement::on_DinnerPlan_clicked);
    connect(ui->BacktoTabsfromDiet, &QPushButton::clicked, this, &DietManagement::on_BacktoTabsfromDiet_clicked);
}

DietManagement::~DietManagement() {
    delete ui;
}

// Slot: Navigate to Breakfast Plan
void DietManagement::on_BreakfastPlan_clicked() {
    auto *breakfastScreen = new BreakfastPlan(); // Create a new screen
    breakfastScreen->setAttribute(Qt::WA_DeleteOnClose); // Automatically delete on close
    breakfastScreen->show();
    this->hide();  // Hide the current screen instead of closing it
    connect(breakfastScreen, &QWidget::destroyed, this, [this]() {
        this->show();  // Show the DietManagement screen again if the BreakfastPlan is closed
    });
}

// Slot: Navigate to Lunch Plan
void DietManagement::on_LunchPlan_clicked() {
    auto *lunchScreen = new LunchPlan(); // Create a new screen
    lunchScreen->setAttribute(Qt::WA_DeleteOnClose); // Automatically delete on close
    lunchScreen->show();
    this->hide();  // Hide the current screen instead of closing it
    connect(lunchScreen, &QWidget::destroyed, this, [this]() {
        this->show();  // Show the DietManagement screen again if the LunchPlan is closed
    });
}

// Slot: Navigate to Dinner Plan
void DietManagement::on_DinnerPlan_clicked() {
    auto *dinnerScreen = new DinnerPlan(); // Create a new screen
    dinnerScreen->setAttribute(Qt::WA_DeleteOnClose); // Automatically delete on close
    dinnerScreen->show();
    this->hide();  // Hide the current screen instead of closing it
    connect(dinnerScreen, &QWidget::destroyed, this, [this]() {
        this->show();  // Show the DietManagement screen again if the DinnerPlan is closed
    });
}

// Slot: Navigate back to Tabs
void DietManagement::on_BacktoTabsfromDiet_clicked() {
    Tabs *tabsScreen = new Tabs();
    tabsScreen->show();
    this->close();  // Close the current DietManagement screen
}
