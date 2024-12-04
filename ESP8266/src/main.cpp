#include <Arduino.h>
#include "WiFi.h"
#include "usart.h"
#include "adafruit.h"

#define LED_DEBUG_PIN 2
#define BUSY_PIN 5

void initSystem(void);
void toggleLedDebug(void);
void setBusyPin(uint8_t pin_status);

unsigned long currentMillis = 0;
unsigned long previousMillis = 0;

void setup()
{
  pinMode(LED_DEBUG_PIN, OUTPUT);
  pinMode(BUSY_PIN, OUTPUT);

  setBusyPin(HIGH);
  initSystem();
  setBusyPin(LOW);
}

void loop()
{
  currentMillis = millis();

  if (currentMillis - previousMillis >= 10)
  {
    previousMillis = currentMillis;

    if (Serial.available())
    {
      String rawData = "";

      while (Serial.available())
      {
        char c = Serial.read();
        rawData += c;
        delay(10);
      }

      Serial.print("Received raw data: ");
      Serial.println(rawData);

      rawData.trim(); // remove blankspace
      if (rawData.startsWith("!TEMP:") && rawData.endsWith("#"))
      {
        rawData.remove(0, 7);
        rawData.remove(rawData.length() - 2);

        Serial.print(rawData);

        float temperature = atof(rawData.c_str()); // convert to float

        publishTemp(temperature);
      }
      else
      {
        Serial.println("Invalid data format.");
      }
    }
  }
}

void initSystem()
{
  initUSART();

  if (!initWiFi())
  {
    assert(false && "WiFi connection failed!");
  }

  if (!initConnectAda())
  {
    assert(false && "Adafruit connection failed!");
  }
}

void toggleLedDebug()
{
  static uint8_t led_status = LOW;
  led_status ^= HIGH;
  digitalWrite(2, led_status);
}

/**
 * @param pin_status  HIGH: esp8266 busy LED 4 on board High
 *                    LOW: esp8266 idle LED 4 on board Low
 */
void setBusyPin(uint8_t pin_status)
{
  digitalWrite(BUSY_PIN, pin_status);
}
