#ifndef SIMULATEDSCENARIOS_H
#define SIMULATEDSCENARIOS_H

#include <QObject>
#include <QString>
#include <QVector>
#include <QTime>
#include <QTimer>
#include <QPair>
#include <QRandomGenerator>
#include "cprfeedback.h"
#include "visualprompts.h"
#include "arrhythmiadetection.h"


class SimulatedScenarios : public QObject
{
    Q_OBJECT
public:
    SimulatedScenarios();

    void pediatric();
    void adult();
    void startAnalysis(int);
    void startProcedure();
    void deliverShock();
    void CPRprocedure();
    void turnOffAED();
    void stopCPR();
    void batteryTest();
    void selfTest();


    //setter
    void setAdultPads(bool b);
    void setPediatricPads(bool);
    void setLowBattery(bool);
    void setElectrodeSensor(bool);
    void setECGdataRhythm(QString);

    bool getElectrodeSensor();
    bool getBatterySensor();
    QString getECGdataRhythm();


signals:
    void updateIndicator(int);
    void clearECG();
    void updateLCD(QString);
    void updateLEDs(int);
    void updateDepth(double);
    void updateShockSafety(bool);
    void updateNumShocks(int);
    void updateECG(QVector<QPair<double,double>>);
    void continueRhythm(QVector<QPair<double,double>>*, QString);
    void updateUserInteraction(int, int);
    void delay(int);

public slots:
    void newValues();
    void handleDepthAnalysis(QString, double);


private:
    CPRfeedback *cprFb;
    VisualPrompts *display;
    arrhythmiadetection *detection;
    QTimer *ECGtimer;
    QVector<QPair<double,double>> *ECGdata;
    QString ECGdataRhythm;
    int numShocks;
    int cprTime;

    bool adultPads;
    bool pediatricPads;
    bool lowBattery;
    bool electrodeSensor;

};

#endif // SIMULATEDSCENARIOS_H
