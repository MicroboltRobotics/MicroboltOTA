#include <MicroboltOTA.h>

void setup()
{
    // Start WiFi + OTA + Telnet
    MicroboltOTA::begin(
        "YOUR_WIFI_NAME",
        "YOUR_WIFI_PASSWORD"
    );

    MicroboltOTA::println("MicroboltOTA Example Started 🚀");
}

void loop()
{
    // Must be called constantly
    MicroboltOTA::run();

    // Simple demo task
    static unsigned long last = 0;

    if (millis() - last > 1000)
    {
        last = millis();

        MicroboltOTA::println("Robot Alive ✔");

        MicroboltOTA::printf(
            "Free Heap: %u bytes\n",
            ESP.getFreeHeap()
        );
    }
}