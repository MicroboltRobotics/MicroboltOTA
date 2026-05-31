# 🚀 MicroboltOTA

**Simple OTA Updates & Wireless Debugging for ESP32**

MicroboltOTA makes it easy to upload firmware and monitor logs over Wi-Fi without constantly plugging in a USB cable.

Perfect for:

🤖 Robotics Projects
🏠 IoT Devices
🚗 RC Vehicles
🔬 Embedded Development
⚡ Rapid Prototyping

---

## ✨ Features

✅ OTA Firmware Uploads over Wi-Fi

✅ Wireless Serial Monitoring

✅ mDNS Hostname Support (`MyRobot.local`)

✅ Automatic Wi-Fi Reconnection

✅ Telnet Debug Console

✅ PlatformIO Friendly

✅ Lightweight & Easy to Use

---

## 📦 Installation

Add the library to your PlatformIO project:

```ini
lib_deps =
    https://github.com/MicroboltRobotics/MicroboltOTA.git
```

---

## 🌐 Hostnames (No More IP Addresses!)

MicroboltOTA uses mDNS hostnames to identify devices on your network.

Example:

```cpp
MicroboltOTA::begin(
    "YOUR_WIFI_NAME",
    "YOUR_WIFI_PASSWORD",
    "MyRobot"
);
```

The third parameter becomes your device hostname.

```text
MyRobot.local
```

Instead of remembering:

```text
192.168.1.123
```

you can simply use:

```text
MyRobot.local
```

for OTA uploads and wireless monitoring.

### 🚀 OTA Upload

```ini
upload_protocol = espota
upload_port = MyRobot.local
```

### 🖥️ Wireless Monitor

```ini
monitor_port = socket://MyRobot.local:23
monitor_speed = 115200
```

### 💡 Default Hostname

If no hostname is provided:

```cpp
MicroboltOTA::begin(
    "WiFi",
    "Password"
);
```

MicroboltOTA automatically uses:

```text
MicroboltOTA.local
```

---

## ⚡ Quick Start

```cpp
#include <MicroboltOTA.h>

void setup()
{
    MicroboltOTA::begin(
        "YOUR_WIFI_NAME",
        "YOUR_WIFI_PASSWORD",
        "MyRobot"
    );

    MicroboltOTA::println("MicroboltOTA Started");
}

void loop()
{
    MicroboltOTA::run();

    static unsigned long last = 0;

    if (millis() - last > 1000)
    {
        last = millis();

        MicroboltOTA::println("Robot Alive");
    }
}
```

---

## 🚀 OTA Upload Setup

Configure PlatformIO:

```ini
upload_protocol = espota
upload_port = MyRobot.local
```

Upload normally using the PlatformIO Upload button.

No USB cable required after the first upload.

---

## 🖥️ Wireless Monitor Setup

Configure PlatformIO:

```ini
monitor_port = socket://MyRobot.local:23
monitor_speed = 115200
```

Open the PlatformIO Serial Monitor to view logs over Wi-Fi.

---

## 📝 Logging Functions

```cpp
MicroboltOTA::print("Hello");
MicroboltOTA::println("World");
MicroboltOTA::printf("Value: %d\n", value);
```

Output is automatically sent to:

* USB Serial
* Telnet Console

This makes remote debugging easy when your robot or device is across the room.

---

## ⚠️ Important

Always call:

```cpp
MicroboltOTA::run();
```

inside your `loop()` function.

MicroboltOTA uses this function to handle:

* OTA Updates
* Telnet Connections
* Wi-Fi Reconnection

Without it, OTA and wireless monitoring will not work.

---

## 📟 Example Startup Output

```text
WiFi Connected
IP Address: 192.168.1.5
mDNS Started

OTA Ready
Telnet Server Ready
Hostname: MyRobot.local
Monitor: socket://MyRobot.local:23
Version: 1.0.0
```

---

## ⚙️ Example PlatformIO Configuration

```ini
[env:esp32]
platform = espressif32
board = esp32dev
framework = arduino

lib_deps =
    https://github.com/MicroboltRobotics/MicroboltOTA.git

upload_protocol = espota
upload_port = MyRobot.local

monitor_port = socket://MyRobot.local:23
monitor_speed = 115200
```

---

## 🛠️ Requirements

* ESP32
* Arduino Framework
* PlatformIO

---

## 📄 License

MIT License

---

## 👨‍💻 Author

### 🤖 Microbolt Robotics

ESP32 • Robotics • Embedded Systems

GitHub: https://github.com/MicroboltRobotics

YouTube: https://www.youtube.com/@MicroboltRobotics

⭐ If you find this project useful, consider starring the repository.
