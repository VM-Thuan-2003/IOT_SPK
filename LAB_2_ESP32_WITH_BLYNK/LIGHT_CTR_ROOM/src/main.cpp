#define BLYNK_TEMPLATE_ID "TMPL6a3GFXNsI"
#define BLYNK_TEMPLATE_NAME "lightcontrol"
#define BLYNK_AUTH_TOKEN "lvNLl23CQTd6NMTuNQgf2CH0_-oDvvcc"

#define BLYNK_PRINT Serial

#define ss_light 35
#define light 16

const float GAMMA = 0.7;
const float RL10 = 85;

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

char ssid[] = "Benjamin Albert";
char pass[] = "11111111";

BlynkTimer timer;

int limit = 0;

BLYNK_WRITE(V3)
{
  int value = param.asInt();
  limit = value;
}

void myTimerEvent()
{
  int analogValue = analogRead(ss_light);
  float voltage = analogValue / 1024. * 3.3;
  float resistance = 5000 * voltage / (1 - voltage / 3.3);
  float lux = pow(RL10 * 1e3 * pow(10, GAMMA) / resistance, (1 / GAMMA));

  if (int(lux) <= limit)
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
  Blynk.virtualWrite(V0, lux);
}

void setup()
{
  limit = 0;
  analogReadResolution(10);
  pinMode(light, OUTPUT);

  Serial.begin(115200);

  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  timer.setInterval(1000L, myTimerEvent);
}

void loop()
{
  Blynk.run();
  timer.run();
}
