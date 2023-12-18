#include "simulatedscenarios.h"

SimulatedScenarios::SimulatedScenarios()
{
    cprFb = new CPRfeedback;
    display = new VisualPrompts;
    detection = new arrhythmiadetection;

    numShocks = 0;
    cprTime = 0;
    adultPads = false;
    pediatricPads = false;
    lowBattery = false;
    electrodeSensor = false;

    ECGdata = new QVector<QPair<double, double>>;

    connect(cprFb, SIGNAL(updateLCD(QString, double)), this, SLOT(handleDepthAnalysis(QString, double)));

}


void SimulatedScenarios::setAdultPads(bool b){adultPads = b;}
void SimulatedScenarios::setPediatricPads(bool b){pediatricPads = b;}
void SimulatedScenarios::setLowBattery(bool b){lowBattery = b;}
void SimulatedScenarios::setElectrodeSensor(bool b){electrodeSensor = b;}
void SimulatedScenarios::setECGdataRhythm(QString str){ECGdataRhythm = str;}


bool SimulatedScenarios::getElectrodeSensor(){return electrodeSensor;}
bool SimulatedScenarios::getBatterySensor(){return lowBattery;}
QString SimulatedScenarios::getECGdataRhythm(){return ECGdataRhythm;}


//After the Fully Automatic AED Plus is powered on and completes its self-test, the unit will issue
//an “Adult Pads” voice prompt or a “Pediatric Pads” voice prompt to indicate the type of electrodes
//connected to the unit.
void SimulatedScenarios::pediatric(){
    if(adultPads == true){return;}
    delay(1);
    updateLCD(display->pediatricPads());
    delay(1);
    startProcedure();
}

void SimulatedScenarios::adult(){
    if(pediatricPads == true){return;}
    delay(1);
    updateLCD(display->adultPads());
    delay(1);
    startProcedure();

}



//When the Fully Automatic AED Plus has completed its self test, the unit automatically initiates the sequence of
//voice prompts and graphic illuminations for a rescue event
//by cycling through the check responsivness, call for help and attach pads to patient sequence
//next function: startAnalysis()
void SimulatedScenarios::startProcedure(){
    delay(1);

    //tells operator to stay calm
    updateLCD(display->stayCalm());
    delay(1);

    //check patient responsivness
    updateLCD(display->checkResponsivness());
    updateLEDs(1);
    delay(1);

    //call for help
    updateLCD(display->callForHelp());
    updateLEDs(2);
    delay(1);

    //attach defib pads to patient
    updateLCD(display->attchDefibPads());

    updateLEDs(3);
    delay(1);

}

//As soon as electrodes are attached to the victim and impedance of the connection is
//verified, the unit stops cycling through the check responsivness, call for help and attach pads to patient sequence
//and automatically begins analysis of the ECG rhythm
void SimulatedScenarios::startAnalysis(int shock){    //shock decides shockable or non-shockable (1 shockable, 0 non-shoc)
    //warns operator to not move patient
    updateLCD(display->dontTouchPatient());
    updateLEDs(4);


    //arrhythmia detection
    int randomECG = QRandomGenerator::global()->bounded(1,3); //50% chance between vTach and vFib (set randomECG = 1 for vTach else for Vfib)
    ECGtimer = new QTimer(this);

    if(shock == 1){   //if user selected shockable then it randomizes between vTach and vFib rhythms

        if(randomECG == 1){   //vTach
            ECGdata = detection->ventricularTach();
            updateECG(*detection->ventricularTach());
            setECGdataRhythm("vTach");

        }else{                //vFib
            ECGdata = detection->ventricularFib();
            updateECG(*detection->ventricularFib());
            setECGdataRhythm("vFib");
        }

    }else{   //if user selected non-shockable

        if(randomECG == 1){   //sinus rhythm (PEA)
            ECGdata = detection->sinusRhythm();
            updateECG(*detection->sinusRhythm());
            setECGdataRhythm("pea");

        }else{                //Asystole
            ECGdata = detection->asystole();
            updateECG(*detection->asystole());
            setECGdataRhythm("asystole");
        }

    }

    connect(ECGtimer, SIGNAL(timeout()), this, SLOT(newValues()));
    ECGtimer->start(5000);

    delay(2); //analysis delay

    //shock advised or not advised depending on scenario selection
    if(shock == 1){
        updateLCD(display->shockAdvised());
        updateLEDs(7); //shock LED
        updateShockSafety(false); //sets safety to off

    }else{
        updateLCD(display->noShockAdvised());
        updateLEDs(5); //cpr LED
        delay(2);
        updateLCD(display->startCPR());
        updateUserInteraction(2,1);
    }

}

//once cpr initiation button is pressed
void SimulatedScenarios::CPRprocedure(){
    updateLCD(display->continueCPR());
    updateUserInteraction(2,0);
    delay(5); //sec delay for cpr

    //cprfeedback tracker
    cprFb->setCPRstatus(true);
    cprFb->cprDepthAnalysis();
    //qInfo("reached");
    updateLCD(display->stopCPR());
    updateUserInteraction(3,1);
}

//once user stops cpr (clicks stop cpr button)
//decision on what happens next
// 1. non shockable
// 2. shockable
// 3. patient flatlined
// 4. patient cured
void SimulatedScenarios::stopCPR(){
    updateUserInteraction(3,0);

    //50% chance of patient being cured or requires more help
    int randomChance = QRandomGenerator::global()->bounded(0,3);

    if(randomChance == 0){ //non-shockable
        clearECG();
        startAnalysis(randomChance);

    }else if(randomChance == 1){  //shockable
        clearECG();
        startAnalysis(randomChance);

    }else{ //flatline (end of sim?)

        ECGdata = (detection->flatline());
        setECGdataRhythm("flatline");
        updateLCD(QString::number(numShocks)+display->NshocksDelivered());
    }

}

//contols of cpr depth and slider and instruction updates
//sends signals to the mainwindow
void SimulatedScenarios::handleDepthAnalysis(QString status, double depth){
    if(status == "bad"){
        updateLCD(display->pushHarder());
        updateDepth(depth);

    }else if(status == "good"){
        updateLCD(display->goodCompressions());
        updateDepth(depth);
    }

    //cpr length (delays 5 times for 2seconds)
    delay(2);
    cprTime+=2;

    if(cprTime == 20){  //increase or decrease for cpr time

        updateDepth(0);
        cprFb->setCPRstatus(false);
        cprTime = 0;

    }

}

//shock delivery
void SimulatedScenarios::deliverShock(){
    //warns user of shock in 3sec
    updateLCD(display->shockWillBeDelivered());
    delay(2);

    //shock delivered
    updateLCD(display->shochDelivered());
    delay(1);
    numShocks++;
    updateNumShocks(numShocks);
    delay(1);

    //start cpr and cpr LED on
    updateLEDs(5);
    updateLCD(display->startCPR());
    updateUserInteraction(2,1);

}

void SimulatedScenarios::batteryTest(){
    updateLCD(display->changeBatteries());
    delay(1);
    updateLCD(display->ifNewBattiesPressButton());
}



//The Fully Automatic AED Plus performs a self test whenever the unit is turned on and verifies the
//following functions:
//1. Battery Capacity: Verifies that the battery usage indicator shows adequate battery capacity
//remaining.
//2. Defibrillation Electrodes Connection: Verifies that the defibrillation electrodes are properly pre-
//connected to the device
//next function: startProcedure();
void SimulatedScenarios::selfTest(){

    updateLEDs(0);
    if(lowBattery == true){
        batteryTest();
        updateUserInteraction(4,1);
    }else{

        if(adultPads == true){
            updateLCD(display->unitOk());
            updateIndicator(1);
            delay(1);
            adult();

        }else if(pediatricPads == true){
            updateLCD(display->unitOk());
            updateIndicator(1);
            delay(1);
            pediatric();

        }else{
            //If the electrode cable is not properly
            //attached to the unit, the unit issues the PLUG IN CABLE prompt
            updateLCD(display->plugInCable());

        }
    }

}

//sends updated ECG rhythm values
void SimulatedScenarios::newValues(){
    continueRhythm(ECGdata, ECGdataRhythm);
}



void SimulatedScenarios::turnOffAED(){
    cprFb->setCPRstatus(false);
    detection->setVfib(false);
    detection->setVtach(false);

    ECGtimer->stop();
    clearECG();
    //need to reset ecg data


    numShocks = 0;
    cprTime = 0;

    adultPads = false;
    pediatricPads = false;
    lowBattery = false;
    electrodeSensor = false;

}
