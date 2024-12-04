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
      int msg = Serial.read();

      if (msg == 'o')
      {
        Serial.print('O');
      }
      else if (msg == 'a')
      {
        publishLightStatus(0);
      }
      else if (msg == 'A')
      {
        publishLightStatus(1);
      }
    }

    toggleLedDebug();
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
