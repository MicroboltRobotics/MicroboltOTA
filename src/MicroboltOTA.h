#pragma once

#include <WiFi.h>
#include <ArduinoOTA.h>

namespace MicroboltOTA
{
    constexpr const char *VERSION = "1.0.0";

    inline WiFiServer telnetServer(23);
    inline WiFiClient telnetClient;

    inline unsigned long lastReconnect = 0;

    void run()
    {
        ArduinoOTA.handle();

        // WiFi reconnect every 5 seconds if disconnected
        if (WiFi.status() != WL_CONNECTED)
        {
            if (millis() - lastReconnect > 5000)
            {
                lastReconnect = millis();
                WiFi.reconnect();
            }
        }

        // Clean up disconnected telnet client
        if (telnetClient && !telnetClient.connected())
        {
            telnetClient.stop();
        }

        // Accept new telnet connection
        if (telnetServer.hasClient())
        {
            WiFiClient newClient = telnetServer.available();

            if (!telnetClient || !telnetClient.connected())
            {
                telnetClient = newClient;

                Serial.println();
                Serial.println("Telnet client connected");
            }
            else
            {
                // Only allow one client
                newClient.stop();
            }
        }
    }

    void begin(
        const char *ssid,
        const char *password,
        const char *hostname = "MicroboltOTA")
    {
        Serial.begin(115200);

        WiFi.mode(WIFI_STA);
        WiFi.setSleep(false);
        WiFi.begin(ssid, password);

        Serial.print("Connecting WiFi");

        while (WiFi.status() != WL_CONNECTED)
        {
            delay(500);
            Serial.print(".");
        }

        Serial.println();
        Serial.println("WiFi Connected");
        Serial.print("IP Address: ");
        Serial.println(WiFi.localIP());

        ArduinoOTA.setHostname(hostname);

        ArduinoOTA.onStart([]()
                           { Serial.println("OTA Start"); });

        ArduinoOTA.onEnd([]()
                         { Serial.println("\nOTA Complete"); });

        ArduinoOTA.onProgress([](unsigned int progress,
                                 unsigned int total)
                              {
            Serial.printf(
                "OTA %u%%\r",
                (progress * 100) / total); });

        ArduinoOTA.onError([](ota_error_t error)
                           { Serial.printf("OTA Error %u\n", error); });

        ArduinoOTA.begin();

        telnetServer.begin();
        telnetServer.setNoDelay(true);

        Serial.println("OTA Ready");
        Serial.println("Telnet Server Ready");
        Serial.print("Hostname: ");
        Serial.println(hostname);
        Serial.print("Version: ");
        Serial.println(VERSION);
    }

    void print(const String &msg)
    {
        Serial.print(msg);

        if (telnetClient && telnetClient.connected())
        {
            telnetClient.print(msg);
        }
    }

    void println(const String &msg)
    {
        Serial.println(msg);

        if (telnetClient && telnetClient.connected())
        {
            telnetClient.println(msg);
        }
    }

    template <typename... Args>
    void printf(const char *format, Args... args)
    {
        char buffer[256];

        snprintf(
            buffer,
            sizeof(buffer),
            format,
            args...);

        Serial.print(buffer);

        if (telnetClient && telnetClient.connected())
        {
            telnetClient.print(buffer);
        }
    }
}