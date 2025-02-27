#include <SoftwareSerial.h>
#include <TinyGPS++.h>

#define BUTTON_PIN 2   // Push Button Pin
#define BUZZER_PIN 8   // Buzzer Pin

SoftwareSerial gsm(9, 10);  // GSM Module (TX, RX)

SoftwareSerial gps(4, 5);   // GPS Module (TX, RX)
TinyGPSPlus gpsData;

String phoneNumber = "+919625301534";  // Replace with Parent's Number

void setup() {
    Serial.begin(9600);
    gsm.begin(9600);
    gps.begin(9600);

    pinMode(BUTTON_PIN, INPUT_PULLUP);
    pinMode(BUZZER_PIN, OUTPUT);

    Serial.println("Women's Safety Device Ready...");
    sendSMS("Device Activated! Press Button for Help.");
}

void loop() {
    while (gps.available()) {
        gpsData.encode(gps.read());
        if (gpsData.location.isUpdated()) {
            String latitude = String(gpsData.location.lat(), 6);
            String longitude = String(gpsData.location.lng(), 6);
            return "https://maps.google.com/?q=" + latitude + "," + longitude;
        }
    }
    return "GPS Signal Not Found!";
}

void sendSMS(String message) {
    gsm.println("AT+CMGF=1");
    delay(500);
    gsm.println("AT+CMGS=\"" + phoneNumber + "\"");
    delay(500);
    gsm.println(message);
    delay(500);
    gsm.write(26);  // End message with Ctrl+Z
    delay(5000);
}