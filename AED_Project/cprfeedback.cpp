#include "cprfeedback.h"

//Real-Time CPR Feedback: Some modern AEDs, like the AED Plus, provide real-time
//feedback on the quality and rate of chest compressions during CPR. This feature helps rescuers
//administer effective chest compressions.

CPRfeedback::CPRfeedback()
{
    cprStatus = false;
}

bool CPRfeedback::getCPRstatus(){return cprStatus;}
void CPRfeedback::setCPRstatus(bool b){cprStatus = b;}

//randomized double between 0.0 and 3.0
//if the number under 2.0
//scale:
//0 - 0.75 = 0 - 2
//0.75 - 2 = 2 - 3
//this because QT slider only uses ints (can't use double)
//triggers bad compression prompt
void CPRfeedback::cprDepthAnalysis(){


    while (cprStatus == true){
        double randomDepth = QRandomGenerator::global()->bounded(0,4);

        if(randomDepth < 1.0){
            updateLCD("bad", randomDepth);

        }else{
            updateLCD("good", randomDepth);
        }
    }

}
