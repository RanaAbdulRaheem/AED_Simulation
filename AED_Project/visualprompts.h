#ifndef VISUALPROMPTS_H
#define VISUALPROMPTS_H

#include <QObject>
#include <QString>

class VisualPrompts : public QObject
{
    Q_OBJECT
public:
    VisualPrompts();

public slots:
    QString unitOk();
    QString unitFailed();
    QString changeBatteries();
    QString stayCalm();
    QString checkResponsivness();
    QString callForHelp();
    QString openAirway();
    QString checkBreathing();
    QString giveTwoBreaths();
    QString plugInCable();
    QString attchDefibPads();
    QString checkElectrodePads();
    QString adultPads();
    QString pediatricPads();
    QString dontTouchPatient();
    QString shockAdvised();
    QString noShockAdvised();
    QString analysisHalted();
    QString shockWillBeDelivered();
    QString shochDelivered();
    QString noShockDelivered();
    QString NshocksDelivered();
    QString startCPR();
    QString continueCPR();
    QString pushHarder();
    QString goodCompressions();
    QString stopCPR();

    //non-clinical
    QString communicationsEstablished();
    QString nonRescueMode();
    QString ifNewBattiesPressButton();
};

#endif // VISUALPROMPTS_H

