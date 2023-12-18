#ifndef ARRHYTHMIADETECTION_H
#define ARRHYTHMIADETECTION_H

#include <QObject>
#include <QString>
#include <QVector>
#include <QPair>
#include <cmath>
#include <iostream>

class arrhythmiadetection : public QObject
{
    Q_OBJECT
public:
    arrhythmiadetection();

    void setVfib(bool rythm);
    void setVtach(bool rythm);

    QVector<QPair<double,double>>* ventricularTach();
    QVector<QPair<double,double>>* ventricularFib();
    QVector<QPair<double,double>>* sinusRhythm();
    QVector<QPair<double,double>>* asystole();
    QVector<QPair<double, double>>* flatline();

private:
    bool vTach;
    bool vFib;
};

#endif // ARRHYTHMIADETECTION_H
