IoT-Based Women's Safety Device
An Arduino-powered safety device that sends the live GPS location via SMS when the panic button is pressed.

🔹 Features
-Sends live GPS location to a predefined phone number.
-Uses a GSM module (SIM800L) for SMS alerts.
-Integrates GPS module (NEO-6M) for location tracking.
-Includes a buzzer for an audible alert.
-Works with a simple button press to trigger the alert.

Components Required
Microcontroller-Arduino Uno->Main controller
GPS Module-NEO-6M->Fetches live location
GSM Module-SIM800L->Sends SMS alerts
Panic Button-Push Button->Triggers emergency alert

Wiring Connections
Component	 |  Arduino Pin
GPS TX	   |  Pin 4
GPS RX	   |  Pin 3
GSM TX	   |  Pin 10
GSM RX	   |  Pin 11
Button	   |  Pin 2

Installation & Setup
Connect all components as per the wiring connections as desribed above.
1. Insert a SIM card in the GSM module (ensure it has SMS balance).
2. Upload the Arduino code (provided in this repository).
3. Power the Arduino via USB or an external battery.
4. Press the panic button → Device will send a live location SMS.

Future Enhancements
-Add a voice activation trigger (e.g., "Help me!")
-Integrate IoT cloud services for remote monitoring
-Add an SOS auto-call feature

