#include "fitnessroutine.h"
#include "ui_fitnessroutine.h"
#include "tabs.h"
#include <QMessageBox>

// Constructor
FitnessRoutine::FitnessRoutine(QWidget *parent)
    : QWidget(parent), ui(new Ui::FitnessRoutine) {
    ui->setupUi(this);

    // Connect buttons to their slots
    connect(ui->SuggestPlanButton, &QPushButton::clicked, this, &FitnessRoutine::on_SuggestPlanButton_clicked);
    connect(ui->BacktoTabsfromFitness, &QPushButton::clicked, this, &FitnessRoutine::on_BacktoTabsfromFitness_clicked);
}

// Destructor
FitnessRoutine::~FitnessRoutine() {
    delete ui;
}

// Overridden sendAlert method
void FitnessRoutine::sendAlert(const QString &title, const QDateTime &alertTime, const QString &details) const {
    QString alertMessage = QString("[Fitness Routine]\nTitle: %1\nTime: %2\nDetails: %3")
    .arg(title)
        .arg(alertTime.toString("hh:mm AP"))
        .arg(details);
    QMessageBox::information(nullptr, "Fitness Routine Notification", alertMessage);
}

// Slot: Suggest Plan Button Clicked
void FitnessRoutine::on_SuggestPlanButton_clicked() {
    QString mood = ui->MoodList->currentText();
    QString workout;
    QString workoutPlan;

    // Determine workout type
    if (ui->UpperBodyButton->isChecked()) {
        workout = "Upper Body";
        if (mood == "Happy" || mood == "Productive") {
            workoutPlan = "1. Push-ups (3 sets of 12 reps)\n"
                          "2. Pull-ups (3 sets of 10 reps)\n"
                          "3. Dumbbell Bench Press (3 sets of 15 reps)";
        } else {
            workoutPlan = "1. Light push-ups (3 sets of 8 reps)\n"
                          "2. Seated Row (3 sets of 10 reps)\n"
                          "3. Shoulder Stretch (Hold for 30 seconds)";
        }
    } else if (ui->LowerBodyButton->isChecked()) {
        workout = "Lower Body";
        if (mood == "Happy" || mood == "Productive") {
            workoutPlan = "1. Squats (3 sets of 15 reps)\n"
                          "2. Lunges (3 sets of 12 reps per leg)\n"
                          "3. Deadlifts (3 sets of 10 reps)";
        } else {
            workoutPlan = "1. Bodyweight Squats (3 sets of 10 reps)\n"
                          "2. Step-ups (3 sets of 12 reps per leg)\n"
                          "3. Calf Raises (3 sets of 15 reps)";
        }
    } else if (ui->CardioButton->isChecked()) {
        workout = "Cardio/HIIT";
        if (mood == "Happy" || mood == "Productive") {
            workoutPlan = "1. Jumping Jacks (3 sets of 30 seconds)\n"
                          "2. Burpees (3 sets of 15 reps)\n"
                          "3. Mountain Climbers (3 sets of 20 seconds)";
        } else {
            workoutPlan = "1. Brisk Walking (10 minutes)\n"
                          "2. Light Jogging (10 minutes)\n"
                          "3. Stretching (Hold each stretch for 30 seconds)";
        }
    } else {
        QMessageBox::warning(this, "Workout Selection", "Please select a workout routine!");
        return;
    }

    // Combine mood and workout-specific plan details
    QString planDetails = QString("Mood: %1\nWorkout: %2\nPlan:\n%3")
                              .arg(mood)
                              .arg(workout)
                              .arg(workoutPlan);

    // Use the overridden sendAlert function
    QDateTime currentTime = QDateTime::currentDateTime();
    sendAlert("Workout Plan Suggested", currentTime, planDetails);
}

// Slot: Back to Tabs Button Clicked
void FitnessRoutine::on_BacktoTabsfromFitness_clicked() {
    Tabs *tabsScreen = new Tabs();
    tabsScreen->show();
    this->close();
}

