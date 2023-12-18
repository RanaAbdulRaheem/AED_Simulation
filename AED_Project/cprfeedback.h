#ifndef CPRFEEDBACK_H
#define CPRFEEDBACK_H

#include <QObject>
#include <QString>
#include <QRandomGenerator>

class CPRfeedback : public QObject
{
    Q_OBJECT
public:
    CPRfeedback();

    bool getCPRstatus();
    void setCPRstatus(bool b);

    void cprDepthAnalysis();

signals:
    void updateLCD(QString, double);

private:
    bool cprStatus;
};

#endif // CPRFEEDBACK_H
