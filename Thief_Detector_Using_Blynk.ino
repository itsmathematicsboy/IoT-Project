#define BLYNK_TEMPLATE_ID "TMPL6uWZj4xyG"
#define BLYNK_TEMPLATE_NAME "thief detector"
#define BLYNK_AUTH_TOKEN "tNT6ugxRXm67xqMfpYlyF7XZBY66EEHx"
/* Comment this out to disable prints and save space */
#define BLYNK_PRINT Serial

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>


// Pin assignments
#define PIR 34          // Analog pin for PIR sensor
#define Buzzer 13       // Pin for buzzer

BlynkTimer timer;

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "Ardhana";
char pass[] = "1234567890";

void setup() {
  // Debug console
  Serial.begin(115200);
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass, "blynk.cloud", 80);
  pinMode(PIR, INPUT);
  pinMode(Buzzer, OUTPUT);

}

// Function to handle PIR sensor interrupt
void motionDetected() {
  int motion = digitalRead(PIR);

  if (motion == HIGH) {
    // Jika gerakan terdeteksi, aktifkan buzzer
    digitalWrite(Buzzer, HIGH);
    Serial.println("Motion detected! Warning activated."); // Pesan peringatan di Serial Monitor
    delay(1000); // Waktu bunyi buzzer (opsional)
    digitalWrite(Buzzer, LOW);
  }
 Blynk.virtualWrite(V0, motion);
}

void loop() {
  Blynk.run();
  timer.run();
  motionDetected(); // Periksa gerakan
}