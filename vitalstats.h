#ifndef VITALSTATS_H
#define VITALSTATS_H

#include <QWidget>
#include "notification.h"
#include <QDate>

// Base Vitals Class
class Vitals : public Notification {
public:
    Vitals(const QDate &lastCheckedDate, bool checkedAtHome)
        : lastCheckedDate(lastCheckedDate), checkedAtHome(checkedAtHome) {}
    virtual ~Vitals() {}

    // Days since last check
    int lastChecked() const;
    // Checked at home status
    QString checkedAtHomeStatus() const;

    // Pure virtual method for calculations (must be overridden by derived classes)
    virtual void calculate() = 0;

    // Override notification function from Notification
    void sendAlert(const QString &title, const QDateTime &dueDate, const QString &details) const override;

protected:
    QDate lastCheckedDate;
    bool checkedAtHome;
};

// Derived BMI Class
class BMI : public Vitals {
public:
    BMI(const QDate &lastCheckedDate, bool checkedAtHome, double weight, double height);
    void calculate() override;

private:
    double weight;
    double height;
};

// Derived GlucoseLevel Class
class GlucoseLevel : public Vitals {
public:
    GlucoseLevel(const QDate &lastCheckedDate, bool checkedAtHome, double glucoseReading);
    void calculate() override;

private:
    double glucoseReading;
};

// Derived BloodPressure Class
class BloodPressure : public Vitals {
public:
    BloodPressure(const QDate &lastCheckedDate, bool checkedAtHome, int systolic, int diastolic);
    void calculate() override;

private:
    int systolic;
    int diastolic;
};

// UI Class for VitalStats
namespace Ui {
class VitalStats;
}

class VitalStats : public QWidget {
    Q_OBJECT

public:
    explicit VitalStats(QWidget *parent = nullptr);
    ~VitalStats();

private slots:
    void on_CheckVitalButton_clicked();
    void on_BacktoTabsfromVitals_clicked();

private:
    Ui::VitalStats *ui;
};

#endif // VITALSTATS_H


