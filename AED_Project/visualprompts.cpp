#include "visualprompts.h"

//Voice and Visual Prompts: AEDs provide step-by-step voice and visual prompts to instruct
//users on the proper actions to take, including when to initiate CPR and when to stand clear
//during defibrillation.

VisualPrompts::VisualPrompts()
{

}


// UNIT OK. Fully Automatic AED Plus has successfully passed its power up self tests.
QString VisualPrompts::unitOk() { QString str = "UNIT OK."; return str; }

// UNIT FAILED. Fully Automatic AED Plus has failed its power up self tests and is not usable for victim care.
QString VisualPrompts::unitFailed() { QString str = "UNIT FAILED."; return str; }

// CHANGE BATTERIES. Fully Automatic AED Plus self-test has detected a low battery condition that is insufficient for the device’s use for victim care. Replace batteries immediately.
QString VisualPrompts::changeBatteries() { QString str = "CHANGE BATTERIES."; return str; }

// STAY CALM. Relax as much as possible and focus on the rescue effort.
QString VisualPrompts::stayCalm() { QString str = "STAY CALM."; return str; }

// CHECK RESPONSIVENESS. Check victim for responsiveness/consciousness by gently shaking the victim and shouting “Are you all right?”.
QString VisualPrompts::checkResponsivness() { QString str = "CHECK RESPONSIVENESS."; return str; }

// CALL FOR HELP. Activate the EMS system or ask a bystander to do it for you.
QString VisualPrompts::callForHelp() { QString str = "CALL FOR HELP."; return str; }

// OPEN AIRWAY. Place victim in the supine position and perform Head Tilt – Chin Lift or Jaw – Thrust maneuver to open the victim’s airway. (This prompt is off by default.)
QString VisualPrompts::openAirway() { QString str = "OPEN AIRWAY."; return str; }

// CHECK BREATHING. Look, listen or feel for the presence of breathing and/or airflow from the victim’s lungs. (This prompt is off by default.)
QString VisualPrompts::checkBreathing() { QString str = "CHECK BREATHING."; return str; }

// GIVE TWO BREATHS. If the victim is not breathing, give two rescue breaths. (This prompt is off by default.)
QString VisualPrompts::giveTwoBreaths() { QString str = "GIVE TWO BREATHS."; return str; }

// PLUG IN CABLE. Ensure that the electrode cable is properly connected to the Fully Automatic AED Plus electrode connector.
QString VisualPrompts::plugInCable() { QString str = "PLUG IN CABLE."; return str; }

// ATTACH DEFIB PADS TO PATIENT’S BARE CHEST. Attach defibrillation pads to the victim’s bare chest.
QString VisualPrompts::attchDefibPads() { QString str = "ATTACH DEFIB PADS \nTO PATIENT’S BARE CHEST."; return str; }

// CHECK ELECTRODE PADS. Previously attached electrodes are not making good contact with the victim’s skin or the electrodes are defective.
QString VisualPrompts::checkElectrodePads() { QString str = "CHECK ELECTRODE PADS."; return str; }

// ADULT PADS. Fully Automatic AED Plus has detected adult electrode pads connected to it and adjusted defibrillation energy settings to adult levels.
QString VisualPrompts::adultPads() { QString str = "ADULT PADS."; return str; }

// PEDIATRIC PADS. Fully Automatic AED Plus has detected pediatric electrode pads connected to it and adjusted defibrillation energy settings to pediatric levels.
QString VisualPrompts::pediatricPads() { QString str = "PEDIATRIC PADS."; return str; }

// DON’T TOUCH PATIENT, ANALYZING. Do not touch the victim; an ECG rhythm analysis is in progress or about to begin.
QString VisualPrompts::dontTouchPatient() { QString str = "DON’T TOUCH PATIENT\n, ANALYZING."; return str; }

// SHOCK ADVISED. ECG rhythm analysis has detected the presence of ventricular fibrillation or shockable ventricular tachycardia.
QString VisualPrompts::shockAdvised() { QString str = "SHOCK ADVISED."; return str; }

// NO SHOCK ADVISED. ECG rhythm analysis has detected a rhythm that is not treatable by defibrillation.
QString VisualPrompts::noShockAdvised() { QString str = "NO SHOCK ADVISED."; return str; }

// ANALYSIS HALTED. KEEP PATIENT STILL. ECG rhythm analysis has been halted due to excessive ECG signal artifact. Stop any ongoing CPR and keep the victim as motionless as possible.
QString VisualPrompts::analysisHalted() { QString str = "ANALYSIS HALTED."; return str; }

// SHOCK WILL BE DELIVERED IN THREE (TWO), (ONE). A shock is about to be delivered to the victim. Warn all persons attending the victim to stand clear and stop touching the victim. If the unit must be discharged before a shock is delivered, press the On/Off button.
QString VisualPrompts::shockWillBeDelivered() { QString str = "SHOCK WILL BE DELIVERED\n IN THREE (TWO),(ONE)."; return str; }

// SHOCK DELIVERED. A defibrillation shock has just been delivered to the victim.
QString VisualPrompts::shochDelivered() { QString str = "SHOCK DELIVERED."; return str; }

// NO SHOCK DELIVERED. No shock was delivered to the victim because an error condition was detected.
QString VisualPrompts::noShockDelivered() { QString str = "NO SHOCK DELIVERED."; return str; }

// n SHOCKS DELIVERED. A total of n shocks have been delivered since the Fully Automatic AED Plus was turned on.
QString VisualPrompts::NshocksDelivered() { QString str = " SHOCKS DELIVERED."; return str; }

// START CPR. Begin CPR.
QString VisualPrompts::startCPR() { QString str = "START CPR."; return str; }

// CONTINUE CPR. Continue providing CPR. This prompt may also be issued if Real CPR Help fails to detect chest compressions at least ¾ of an inch deep.
QString VisualPrompts::continueCPR() { QString str = "CONTINUE CPR."; return str; }

// PUSH HARDER. CPR compressions are consistently less than 2 inches deep.
QString VisualPrompts::pushHarder() { QString str = "PUSH HARDER."; return str; }

// GOOD COMPRESSIONS. After prompting to Push Harder, the rescuer has succeeded in delivering chest compressions at least 2 inches deep.
QString VisualPrompts::goodCompressions() { QString str = "GOOD COMPRESSIONS."; return str; }

// STOP CPR. Stop CPR; the Fully Automatic AED Plus is about to begin an ECG rhythm analysis.
QString VisualPrompts::stopCPR() { QString str = "STOP CPR."; return str; }

// Non-Clinical Voice Prompts

// IF NEW BATTERIES, PRESS BUTTON. Press the Battery Reset Button located in the battery compartment after replacing ALL batteries in the device with new batteries.
QString VisualPrompts::ifNewBattiesPressButton() { QString str = "IF NEW BATTERIES,\n PRESS BUTTON."; return str; }

// NON-RESCUE MODE. Fully Automatic AED Plus device has entered the diagnostics/data communications mode.
QString VisualPrompts::nonRescueMode() { QString str = "NON-RESCUE MODE."; return str; }

// COMMUNICATIONS ESTABLISHED. IrDA Communications between the Fully Automatic AED Plus and a personal computer or modem have been established.
QString VisualPrompts::communicationsEstablished() { QString str = "COMMUNICATIONS ESTABLISHED."; return str; }
