
# MicroboltOTA

🚀 ESP32 OTA Firmware Updates + Wireless Serial Debugging (Telnet)

MicroboltOTA is a lightweight, header-only ESP32 library that provides **over-the-air (OTA) firmware updates** and **wireless serial monitoring via Telnet** with a simple API.

Designed for robotics, IoT, and embedded systems projects.

---

## ✨ Features

- 📡 OTA firmware updates using ArduinoOTA
- 🌐 Wireless Serial Monitor via Telnet (port 23)
- 🔁 Automatic WiFi reconnect handling
- ⚡ Non-blocking background execution
- 🧠 Simple API (begin + run)
- 🪶 Header-only (no installation complexity)
- 🤖 Built for ESP32 robotics & embedded systems

---

## 📦 Installation

### PlatformIO

Add to `lib_deps`:

```ini
lib_deps =
    https://github.com/MicroboltRobotics/MicroboltOTA
````

---

### Manual Installation

1. Download this repository
2. Copy `MicroboltOTA.h` into your `lib/` folder
3. Include it in your project

---

## 🚀 Quick Start

```cpp
#include <MicroboltOTA.h>

void setup()
{
    MicroboltOTA::begin(
        "YOUR_WIFI_NAME",
        "YOUR_WIFI_PASSWORD"
    );
}

void loop()
{
    MicroboltOTA::run();

    static unsigned long t = 0;

    if (millis() - t > 1000)
    {
        t = millis();
        MicroboltOTA::println("Robot Alive");
    }
}
```

---

## 🌐 OTA Upload (PlatformIO)

After first USB upload:

```ini
upload_protocol = espota
upload_port = 192.168.1.100
```

Or using hostname:

```ini
upload_protocol = espota
upload_port = MicroboltOTA.local
```

---

## 💻 Wireless Serial Monitor (Telnet)

Connect using:

```bash
telnet <device-ip> 23
```

Example:

```bash
telnet 192.168.1.100 23
```

---

## 🧠 API Reference

### begin(ssid, password, hostname)

Initializes WiFi, OTA, and Telnet server.

```cpp
MicroboltOTA::begin("WiFi", "Password", "Robot01");
```

---

### run()

Must be called inside `loop()`.

Handles:

* OTA updates
* WiFi reconnect
* Telnet connections

---

### print() / println()

Send logs to Serial + Telnet.

```cpp
MicroboltOTA::println("Hello Robot");
```

---

### printf()

Formatted output.

```cpp
MicroboltOTA::printf("Battery: %d%%\n", 85);
```

---

## ⚠️ Important Notes

* Always call `MicroboltOTA::run()` in `loop()`
* First upload must be via USB
* OTA requires stable WiFi connection
* Telnet runs on port **23**

---

## 🧪 Example Use Cases

* ESP32 Robot Cars
* IoT Sensor Nodes
* Wireless telemetry systems
* Robotics debugging tools

---

## 📌 Version

v1.0.0

---

## 👨‍💻 Author

Microbolt Robotics
ESP32 • Robotics • Embedded Systems

GitHub: [https://github.com/MicroboltRobotics](https://github.com/MicroboltRobotics)

---

## 📄 License

MIT License

---

## ⭐ Why MicroboltOTA?

Instead of writing long OTA + logging setup code, use:

```cpp
MicroboltOTA::begin(...);
MicroboltOTA::run();
```

That’s it.

```

---

If you want next step, I can help you:
- :contentReference[oaicite:0]{index=0}
- :contentReference[oaicite:1]{index=1}
- or :contentReference[oaicite:2]{index=2}
```
