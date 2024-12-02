#include "vitalstats.h"
#include "ui_vitalstats.h"
#include "tabs.h"             // Include Tabs class header
#include <QMessageBox>
#include <QDateTime>
#include <QInputDialog>

// Implementation of Vitals base class
int Vitals::lastChecked() const {
    return lastCheckedDate.daysTo(QDate::currentDate());
}

QString Vitals::checkedAtHomeStatus() const {
    return checkedAtHome ? "Yes" : "No";
}

void Vitals::sendAlert(const QString &title, const QDateTime &dueDate, const QString &details) const {
    QString alertMessage = QString("[Vital Stats Alert]\nTitle: %1\nDue Date: %2\nDetails: %3")
    .arg(title)
        .arg(dueDate.toString("dd-MM-yyyy hh:mm"))
        .arg(details);
    QMessageBox::information(nullptr, title, alertMessage);
}

// BMI class
BMI::BMI(const QDate &lastCheckedDate, bool checkedAtHome, double weight, double height)
    : Vitals(lastCheckedDate, checkedAtHome), weight(weight), height(height) {}

void BMI::calculate() {
    double bmi = weight / (height * height);
    QString result = bmi < 18.5 ? "Underweight" : (bmi < 24.9 ? "Normal" : "Overweight");
    QString details = QString("BMI: %1 (%2)\nLast Checked: %3 days ago\nChecked at Home: %4")
                          .arg(bmi, 0, 'f', 2).arg(result).arg(lastChecked()).arg(checkedAtHomeStatus());
    QDateTime now = QDateTime::currentDateTime();
    sendAlert("BMI Status", now, details);
}

// GlucoseLevel class
GlucoseLevel::GlucoseLevel(const QDate &lastCheckedDate, bool checkedAtHome, double glucoseReading)
    : Vitals(lastCheckedDate, checkedAtHome), glucoseReading(glucoseReading) {}

void GlucoseLevel::calculate() {
    QString result = glucoseReading < 70 ? "Low" : (glucoseReading <= 140 ? "Normal" : "High");
    QString details = QString("Glucose Level: %1 mg/dL (%2)\nLast Checked: %3 days ago\nChecked at Home: %4")
                          .arg(glucoseReading).arg(result).arg(lastChecked()).arg(checkedAtHomeStatus());
    QDateTime now = QDateTime::currentDateTime();
    sendAlert("Glucose Level Status", now, details);
}

// BloodPressure class
BloodPressure::BloodPressure(const QDate &lastCheckedDate, bool checkedAtHome, int systolic, int diastolic)
    : Vitals(lastCheckedDate, checkedAtHome), systolic(systolic), diastolic(diastolic) {}

void BloodPressure::calculate() {
    QString result = (systolic < 120 && diastolic < 80) ? "Normal" :
                         ((systolic < 140 && diastolic < 90) ? "Elevated" : "High");
    QString details = QString("Blood Pressure: %1/%2 mmHg (%3)\nLast Checked: %4 days ago\nChecked at Home: %5")
                          .arg(systolic).arg(diastolic).arg(result).arg(lastChecked()).arg(checkedAtHomeStatus());
    QDateTime now = QDateTime::currentDateTime();
    sendAlert("Blood Pressure Status", now, details);
}

// VitalStats UI Class
VitalStats::VitalStats(QWidget *parent) : QWidget(parent), ui(new Ui::VitalStats) {
    ui->setupUi(this);
    connect(ui->CheckVitalButton, &QPushButton::clicked, this, &VitalStats::on_CheckVitalButton_clicked);
    connect(ui->BacktoTabsfromVitals, &QPushButton::clicked, this, &VitalStats::on_BacktoTabsfromVitals_clicked);
}

VitalStats::~VitalStats() {
    delete ui;
}

void VitalStats::on_CheckVitalButton_clicked() {
    QString vitalType = ui->VitalTypeAdd->currentText();
    QDate lastChecked = ui->DateCheckedAdd->date();
    bool checkedAtHome = (ui->CheckAdd->currentText() == "Yes");

    if (vitalType == "BMI") {
        bool ok;
        double weight = QInputDialog::getDouble(this, "Enter Weight", "Weight (kg):", 0, 0, 500, 1, &ok);
        if (!ok) return;
        double height = QInputDialog::getDouble(this, "Enter Height", "Height (m):", 0, 0, 3, 2, &ok);
        if (!ok) return;
        BMI bmi(lastChecked, checkedAtHome, weight, height);
        bmi.calculate();
    } else if (vitalType == "Glucose level") {
        bool ok;
        double glucose = QInputDialog::getDouble(this, "Enter Glucose", "Glucose Level (mg/dL):", 0, 0, 500, 1, &ok);
        if (!ok) return;
        GlucoseLevel glucoseLevel(lastChecked, checkedAtHome, glucose);
        glucoseLevel.calculate();
    } else if (vitalType == "Blood Pressure") {
        bool ok;
        int systolic = QInputDialog::getInt(this, "Enter Systolic", "Systolic (mmHg):", 0, 0, 300, 1, &ok);
        if (!ok) return;
        int diastolic = QInputDialog::getInt(this, "Enter Diastolic", "Diastolic (mmHg):", 0, 0, 300, 1, &ok);
        if (!ok) return;
        BloodPressure bp(lastChecked, checkedAtHome, systolic, diastolic);
        bp.calculate();
    }
}

void VitalStats::on_BacktoTabsfromVitals_clicked() {
    Tabs *tabsScreen = new Tabs();
    tabsScreen->show();
    this->close();
}
