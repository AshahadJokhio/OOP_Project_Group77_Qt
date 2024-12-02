#include "tabs.h"
#include "ui_tabs.h"
#include "matrix.h"       // Include the login screen header for navigation
#include "taskmanager.h"  // Include the Task Manager header for navigation
#include "dietmanagement.h" // Include the Diet Management header for navigation
#include "mentalhealth.h"
#include "fitnessroutine.h"
#include "vitalstats.h"

Tabs::Tabs(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Tabs)
{
    ui->setupUi(this);

    // Connect signals for Back to Sign-In, Close, Task Manager, and Diet Plan Management buttons
    connect(ui->BacktoSign, &QPushButton::clicked, this, &Tabs::on_BacktoSign_clicked);
    connect(ui->Close, &QPushButton::clicked, this, &Tabs::on_Close_clicked);
    connect(ui->TaskManager, &QPushButton::clicked, this, &Tabs::on_TaskManager_clicked);
    connect(ui->DietPlan, &QPushButton::clicked, this, &Tabs::on_DietPlan_clicked);
    connect(ui->FitnessRoutine, &QPushButton::clicked, this, &Tabs::on_FitnessRoutine_clicked);
    connect(ui->HealthVitalStats, &QPushButton::clicked, this, &Tabs::on_HealthVitalStats_clicked); // Added this line
}

Tabs::~Tabs() {
    delete ui;
}

void Tabs::on_BacktoSign_clicked() {
    // Go back to the login screen
    Matrix *loginScreen = new Matrix();
    loginScreen->show();
    this->close(); // Close the current Tabs screen
}

void Tabs::on_Close_clicked() {
    // Close the application
    QApplication::quit();
}

void Tabs::on_TaskManager_clicked() {
    // Open the Task Manager screen
    TaskManager *taskManagerScreen = new TaskManager();
    taskManagerScreen->show();
    this->close(); // Close the current Tabs screen
}

void Tabs::on_DietPlan_clicked() {
    // Open the Diet Management screen
    DietManagement *dietScreen = new DietManagement();
    dietScreen->show();
    this->close(); // Close the current Tabs screen
}

void Tabs::on_MentalHealth_clicked() {
    MentalHealth *mentalHealthScreen = new MentalHealth();
    mentalHealthScreen->show();
    this->close();
}

void Tabs::on_FitnessRoutine_clicked() {
    // Navigate to FitnessRoutine screen
    FitnessRoutine *fitnessScreen = new FitnessRoutine();
    fitnessScreen->show();
    this->close(); // Close the current Tabs screen
}

void Tabs::on_HealthVitalStats_clicked() {
    // Navigate to VitalStats screen
    VitalStats *vitalStatsScreen = new VitalStats();
    vitalStatsScreen->show();
    this->close();
}
