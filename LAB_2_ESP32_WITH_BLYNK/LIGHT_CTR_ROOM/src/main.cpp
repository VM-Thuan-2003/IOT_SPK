/*************************************************************

  This is a simple demo of sending and receiving some data.
  Be sure to check out other examples!
 *************************************************************/

/* Fill-in information from Blynk Device Info here */
#define BLYNK_TEMPLATE_ID "TMPL6a3GFXNsI"
#define BLYNK_TEMPLATE_NAME "lightcontrol"
#define BLYNK_AUTH_TOKEN "lvNLl23CQTd6NMTuNQgf2CH0_-oDvvcc"

/* Comment this out to disable prints and save space */
#define BLYNK_PRINT Serial

#define ss_light 35
#define light 16

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "H04_L1_2.4G";
char pass[] = "happymk01";

BlynkTimer timer;

int limit = 0;
int valuess;

BLYNK_WRITE(V3)
{
  // Set incoming value from pin V0 to a variable
  int value = param.asInt();
  limit = value;
}

// This function sends Arduino's uptime every second to Virtual Pin 2.
void myTimerEvent()
{
  // You can send any value at any time.
  // Please don't send more that 10 values per second.

  valuess = map(analogRead(ss_light), 0, 4095, 100, 0);

  if (int(valuess) <= limit)
  {
    digitalWrite(light, 1);
    Blynk.virtualWrite(V2, 1);
  }
  else
  {
    digitalWrite(light, 0);
    Blynk.virtualWrite(V2, 0);
  }

  Blynk.virtualWrite(V1, millis() / 1000);
  Blynk.virtualWrite(V0, valuess);
}

void setup()
{
  limit = 0;

  pinMode(light, OUTPUT);

  // Debug console
  Serial.begin(115200);

  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  // You can also specify server:
  // Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass, "blynk.cloud", 80);
  // Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass, IPAddress(192,168,1,100), 8080);

  // Setup a function to be called every second
  timer.setInterval(1000L, myTimerEvent);
}

void loop()
{
  Blynk.run();
  timer.run();
  // You can inject your own code or combine it with other sketches.
  // Check other examples on how to communicate with Blynk. Remember
  // to avoid delay() function!
}
