#include <Arduino.h>
#include "WiFi.h"

#define WLAN_SSID "May"
#define WLAN_PASS "20102010"
#define WIFI_TIMEOUT 30000

WiFiClient client;

bool initWiFi()
{
    Serial.begin(115200); // Start the serial communication for debugging

    Serial.println("Connecting to WiFi...");
    WiFi.begin(WLAN_SSID, WLAN_PASS);

    unsigned long currentMillis = millis(); // Get the current time in milliseconds

    // Wait for the connection or timeout
    while (WiFi.status() != WL_CONNECTED)
    {
        if (millis() - currentMillis >= WIFI_TIMEOUT) // Timeout condition
        {
            Serial.println("WiFi connection failed: Timeout");
            return false;
        }

        delay(500);        // Delay between checks for connection status
        Serial.print("."); // Print a dot to show that we're still trying
    }

    // Connection successful
    Serial.println("\nConnected to WiFi!");
    Serial.print("IP address: ");
    Serial.println(WiFi.localIP()); // Print the local IP address assigned by the router
    return true;
}