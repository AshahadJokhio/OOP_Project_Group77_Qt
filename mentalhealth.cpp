#include "mentalhealth.h"
#include "ui_mentalhealth.h"
#include <QMessageBox>
#include <QDateTime>

// Constructor
MentalHealth::MentalHealth(QWidget *parent)
    : QWidget(parent), Notification(), ui(new Ui::MentalHealth) {
    ui->setupUi(this);

    // Connect signals to slots
    connect(ui->LogMoodButton, &QPushButton::clicked, this, &MentalHealth::on_LogMoodButton_clicked);
    connect(ui->BacktoTabsfromMental, &QPushButton::clicked, this, &MentalHealth::on_BacktoTabsfromMental_clicked);
}

// Destructor
MentalHealth::~MentalHealth() {
    delete ui;
}

// Override sendAlert to show mood-specific notifications
void MentalHealth::sendAlert(const QString &title, const QDateTime &alertTime, const QString &details) const {
    QString alertMessage = QString("%1\nTime: %2\nDetails: %3")
    .arg(title)
        .arg(alertTime.toString("hh:mm AP"))
        .arg(details);
    QMessageBox::information(nullptr, "Mental Health Notification", alertMessage);
}

// Slot: Log Mood Button
void MentalHealth::on_LogMoodButton_clicked() {
    QString mood;
    if (ui->HappyButton->isChecked()) {
        mood = "Happy";
    } else if (ui->SadButton->isChecked()) {
        mood = "Sad";
    } else if (ui->TiredButton->isChecked()) {
        mood = "Tired";
    } else if (ui->WorriedButton->isChecked()) {
        mood = "Worried";
    } else if (ui->ProductiveButton->isChecked()) {
        mood = "Productive";
    } else {
        QMessageBox::warning(this, "Mood Selection", "Please select a mood before logging!");
        return;
    }

    // Create a mood-specific notification
    QDateTime currentTime = QDateTime::currentDateTime();
    QString details;

    if (mood == "Happy") {
        details = "Keep up the good vibes! Enjoy your day!";
    } else if (mood == "Sad") {
        details = "Take some time to relax and talk to someone who cares.";
    } else if (mood == "Tired") {
        details = "Make sure to get some rest and stay hydrated.";
    } else if (mood == "Worried") {
        details = "Try mindfulness or meditation to calm your nerves.";
    } else if (mood == "Productive") {
        details = "Great job! Keep the momentum going.";
    }

    // Call overridden sendAlert function
    sendAlert(QString("Mood Logged: %1").arg(mood), currentTime, details);
}

// Slot: Back to Tabs Button
void MentalHealth::on_BacktoTabsfromMental_clicked() {
    Tabs *tabsScreen = new Tabs();
    tabsScreen->show();
    this->close();
}
