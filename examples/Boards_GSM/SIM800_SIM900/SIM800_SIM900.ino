/**************************************************************
 * Blynk is a platform with iOS and Android apps to control
 * Arduino, Raspberry Pi and the likes over the Internet.
 * You can easily build graphic interfaces for all your
 * projects by simply dragging and dropping widgets.
 *
 *   Downloads, docs, tutorials: http://www.blynk.cc
 *   Blynk community:            http://community.blynk.cc
 *   Social networks:            http://www.fb.com/blynkapp
 *                               http://twitter.com/blynk_app
 *
 * Blynk library is licensed under MIT license
 * This example code is in public domain.
 *
 **************************************************************
 *
 * This example shows how to use SIM800 or SIM900 modem series
 * to connect your project to Blynk.
 *
 * Attention! Please check out TinyGSM guide:
 *   http://tiny.cc/tiny-gsm-readme
 *
 * WARNING: SIM module support is for BETA testing.
 *
 * Change GPRS apm, user, pass, and Blynk auth token to run :)
 * Feel free to apply it to any other example. It's simple!
 *
 **************************************************************/

#define BLYNK_PRINT Serial    // Comment this out to disable prints and save space

// Default heartbeat interval for GSM is 60
// If you want override this value, uncomment and set this option:
//#define BLYNK_HEARTBEAT 30

// Select your modem:
#define TINY_GSM_MODEM_SIM800
//#define TINY_GSM_MODEM_SIM900
//#define TINY_GSM_MODEM_M590

#include <TinyGsmClient.h>
#include <BlynkSimpleSIM800.h>

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
const char auth[] = "YourAuthToken";

// Your GPRS credentials
// Leave empty, if missing user or pass
const char apn[]  = "YourAPN";
const char user[] = "";
const char pass[] = "";

// Hardware Serial on Mega, Leonardo, Micro
#define SerialAT Serial1

// or Software Serial on Uno, Nano
//#include <SoftwareSerial.h>
//SoftwareSerial SerialAT(2, 3); // RX, TX

TinyGsm modem(SerialAT);

void setup()
{
  // Set console baud rate
  Serial.begin(115200);
  delay(10);

  // Set GSM module baud rate
  SerialAT.begin(115200);
  delay(3000);

  // Restart takes quite some time
  // To skip it, call init() instead of restart()
  Serial.println("Initializing modem...");
  modem.restart();

  // Unlock your SIM card with a PIN
  //modem.simUnlock("1234");

  Blynk.begin(auth, modem, apn, user, pass);
}

void loop()
{
  Blynk.run();
}

