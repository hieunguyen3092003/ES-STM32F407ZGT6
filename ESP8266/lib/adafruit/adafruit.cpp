#include "adafruit.h"
#include "config.h"
#include "WiFi.h"
#include <Adafruit_MQTT.h>
#include <Adafruit_MQTT_Client.h>

#define AIO_SERVER "io.adafruit.com"
#define AIO_SERVERPORT 1883

Adafruit_MQTT_Client mqtt(&client, AIO_SERVER,
                          AIO_SERVERPORT, AIO_USERNAME, AIO_KEY);

Adafruit_MQTT_Publish light_pub = Adafruit_MQTT_Publish(&mqtt, AIO_USERNAME "/feeds/led");
Adafruit_MQTT_Publish temp_pub = Adafruit_MQTT_Publish(&mqtt, AIO_USERNAME "/feeds/temperature");

bool initConnectAda()
{
    int retry_count = 0;        // Counter to track the number of connection retries
    const int max_retries = 10; // Maximum number of retries before giving up (adjustable)

    Serial.println("Connecting to MQTT...");

    // Try connecting to the MQTT broker. Keep retrying if connection fails.
    while (mqtt.connect() != 0 && retry_count < max_retries)
    {
        // Print the error code if connection fails
        Serial.print("MQTT connect failed, retrying in 500ms... Error code: ");
        Serial.println(mqtt.connect()); // Print error code for debugging purposes

        retry_count++; // Increment the retry counter
        delay(500);    // Wait for 500ms before trying again
    }

    // If the connection fails after max_retries, print a failure message
    if (retry_count >= max_retries)
    {
        Serial.println("Failed to connect to MQTT after multiple attempts. Exiting...");
        // Perform other actions like resetting or stopping the program
        return false; // Return false to indicate failure
    }
    else
    {
        // If connection is successful, print a success message
        Serial.println("MQTT connected successfully!");
        return true; // Return true to indicate success
    }
}

void publishLightStatus(uint8_t status)
{
    light_pub.publish(status);
}

void publishTemp(float temperature)
{
    if (temp_pub.publish(temperature))
    {
        Serial.print("Published temperature: ");
        Serial.println(temperature);
    }
    else
    {
        Serial.println("Failed to publish temperature.");
    }
}