# AED Plus Simulator (C++ / Qt)

A desktop app that simulates the **AED Plus**, the portable defibrillator used to help someone whose heart has stopped. It was a team project for COMP 3004 (Object-Oriented Software Engineering) at Carleton University.

**Team:** Abdul Raheem, Giovanni Kassis, Aidan Mackenzie, Usman Iftikhar

## What it does

The app walks the user through a rescue, the same way the real device would:

1. **Power on and self-test.** Checks the battery and the unit before starting.
2. **Voice and text prompts.** "Stay calm", "Call for help", "Attach pads"…
3. **Pads.** The user chooses **adult** or **child** pads and places them.
4. **Heart rhythm check.** The app shows a live **ECG graph** and decides whether a shock is needed. It can simulate normal rhythm, ventricular fibrillation (VF), ventricular tachycardia (VT) and flatline.
5. **Shock.** If one is advised, it warns "Don't touch the patient" and delivers it.
6. **CPR feedback.** It measures how deep the compressions are and says "Push harder" or "Good compressions".

It also handles problem cases, like a **low battery** or **pads not attached properly**.

## How it's built

The code is split into classes that each do one job, and they talk to each other through Qt **signals and slots** (one part sends a message, another part reacts to it):

| Class | Job |
|---|---|
| `MainWindow` | The user interface: buttons, lights, screen and ECG graph |
| `SimulatedScenarios` | The main logic: runs each step of the rescue |
| `ArrhythmiaDetection` | Creates the heart-rhythm data for each condition |
| `CPRfeedback` | Checks compression depth and gives feedback |
| `VisualPrompts` | All the text and voice prompts |

The ECG graph uses the open-source [QCustomPlot](https://www.qcustomplot.com/) library.

## Run it

You need **Qt 5** (or Qt 6) and Qt Creator.

1. Open `AED_Project/AED_Project.pro` in Qt Creator.
2. Pick a kit and click **Run**.

Or from the command line:

```bash
cd AED_Project
qmake
make
./AED_Project
```

## What I learned

- Planning a system with **UML class and sequence diagrams** before writing code
- Splitting a large program into small classes with clear jobs
- Event-driven design with signals and slots
- Testing **failure cases** (low battery, bad pad contact), not just the happy path. That matters a lot for a safety device.
