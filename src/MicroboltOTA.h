#pragma once

#include <WiFi.h>
#include <ArduinoOTA.h>

namespace MicroboltOTA
{
    extern WiFiServer telnetServer;
    extern WiFiClient telnetClient;
    extern unsigned long lastReconnect;

    constexpr const char *VERSION = "1.0.0";

    void begin(
        const char *ssid,
        const char *password,
        const char *hostname = "MicroboltOTA");

    void run();

    void print(const String &msg);
    void println(const String &msg);

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