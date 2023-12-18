#include "arrhythmiadetection.h"


//Cardiac Arrhythmia Detection: AEDs can analyze the heart's electrical activity to determine if
//a shockable rhythm, such as ventricular fibrillation or ventricular tachycardia, is present. If such
//a rhythm is detected, the AED advises the user to deliver a shock.


arrhythmiadetection::arrhythmiadetection()
{
    vTach = false;
    vFib = false;
}

void arrhythmiadetection::setVtach(bool rythm){vTach = rythm;}
void arrhythmiadetection::setVfib(bool rythm){vFib = rythm;}


//detects Ventricular Tachycardia
QVector<QPair<double, double>>* arrhythmiadetection::ventricularTach() {
    QVector<QPair<double, double>>* data = new QVector<QPair<double, double>>();
    //data->append(qMakePair(0,0));
    data->append(qMakePair(0.25,-2.5));
    data->append(qMakePair(0.335,2.25));
    data->append(qMakePair(0.5,2.5));
    data->append(qMakePair(0.75,2));
    data->append(qMakePair(0.8125,1.5));
    data->append(qMakePair(0.9375,-2.25));

    return data;
}


//detects Ventricular Fibrillation
QVector<QPair<double, double>>* arrhythmiadetection::ventricularFib() {
    QVector<QPair<double, double>>* data = new QVector<QPair<double, double>>();
    data->append(qMakePair(0,1));
    data->append(qMakePair(0.0675,0.1));
    data->append(qMakePair(0.12,0.8));
    data->append(qMakePair(0.1875,-2));
    data->append(qMakePair(0.24,0.8));
    data->append(qMakePair(0.3075,-2));
    data->append(qMakePair(0.3675,0.8));
    data->append(qMakePair(0.4275,0.1));
    data->append(qMakePair(0.4875,0.8));
    data->append(qMakePair(0.60,2.25));
    data->append(qMakePair(0.725,-1));
    data->append(qMakePair(0.7875,-0.1));
    data->append(qMakePair(0.8675,-1));
    data->append(qMakePair(0.9375,1));


    return data;
}


//detects non shockable rythms
QVector<QPair<double, double>>* arrhythmiadetection::sinusRhythm() {
    QVector<QPair<double, double>>* data = new QVector<QPair<double, double>>();
    data->append(qMakePair(0,0.125));
    data->append(qMakePair(0.125,0));
    data->append(qMakePair(0.375,0));
    data->append(qMakePair(0.4375,-0.125));
    data->append(qMakePair(0.5625,2.5));
    data->append(qMakePair(0.6875,-1));
    data->append(qMakePair(0.8125,0));
    data->append(qMakePair(0.9375,0));
    data->append(qMakePair(1,0.05));
    data->append(qMakePair(1.1,0.1));
    data->append(qMakePair(1.15,0.12));
    data->append(qMakePair(1.2,0.14));
    data->append(qMakePair(1.25,0.15));
    data->append(qMakePair(1.30,0.14));
    data->append(qMakePair(1.35,0.12));
    data->append(qMakePair(1.40,0.1));
    data->append(qMakePair(1.45,0.05));
    data->append(qMakePair(1.5,0));
    data->append(qMakePair(1.875,0));
    data->append(qMakePair(2,0.125));

    return data;
}

QVector<QPair<double, double>>* arrhythmiadetection::asystole() {
    QVector<QPair<double, double>>* data = new QVector<QPair<double, double>>();
    data->append(qMakePair(0,0));
    data->append(qMakePair(0.05,0.025));
    data->append(qMakePair(0.10,0.05));
    data->append(qMakePair(0.15,0.075));
    data->append(qMakePair(0.20,0.1));
    data->append(qMakePair(0.25,0.0125));
    data->append(qMakePair(0.30,0.15));
    data->append(qMakePair(0.35,0.175));
    data->append(qMakePair(0.40,0.2));
    data->append(qMakePair(0.45,0.22));
    data->append(qMakePair(0.50,0.227));
    data->append(qMakePair(0.55,0.235));
    data->append(qMakePair(0.60,0.24));
    data->append(qMakePair(0.65,0.245));
    data->append(qMakePair(0.70,0.25));
    data->append(qMakePair(0.75,0.25));
    data->append(qMakePair(0.80,0.24));
    data->append(qMakePair(0.85,0.235));
    data->append(qMakePair(0.90,0.227));
    data->append(qMakePair(0.95,0.22));
    data->append(qMakePair(1.00,0.2));
    data->append(qMakePair(1.05,0.175));
    data->append(qMakePair(1.10,0.15));
    data->append(qMakePair(1.15,0.125));
    data->append(qMakePair(1.20,0.1));
    data->append(qMakePair(1.25,0.075));
    data->append(qMakePair(1.30,0.05));
    data->append(qMakePair(1.35,0.025));
    data->append(qMakePair(1.40,0));
    data->append(qMakePair(1.45,-0.05));
    data->append(qMakePair(1.50,-0.1));
    data->append(qMakePair(1.55,-0.125));
    data->append(qMakePair(1.60,-0.15));
    data->append(qMakePair(1.65,-0.175));
    data->append(qMakePair(1.70,-0.18));
    data->append(qMakePair(1.75,-0.175));
    data->append(qMakePair(1.80,-0.15));
    data->append(qMakePair(1.85,-0.125));
    data->append(qMakePair(1.90,-0.1));
    data->append(qMakePair(1.95,-0.05));
    data->append(qMakePair(2.00,0));


    return data;
}


//detects flatline (no rhythm/ECG)
QVector<QPair<double, double>>* arrhythmiadetection::flatline() {
    QVector<QPair<double, double>>* data = new QVector<QPair<double, double>>();
    data->append(qMakePair(0,0));

    return data;
}
