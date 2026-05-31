

\# MicroboltOTA



🚀 ESP32 OTA Firmware Updates + Wireless Serial Debugging (Telnet)



MicroboltOTA is a lightweight, header-only ESP32 library that provides over-the-air (OTA) firmware updates and wireless serial monitoring via Telnet with a simple API.



Designed for robotics, IoT, and embedded systems projects.



\---



\## ✨ Features



\- 📡 OTA firmware updates using ArduinoOTA

\- 🌐 Wireless Serial Monitor via Telnet (port 23)

\- 🔁 Automatic WiFi reconnect handling

\- ⚡ Non-blocking background execution

\- 🧠 Simple API (begin + run)

\- 🪶 Header-only (no installation complexity)

\- 🤖 Built for ESP32 robotics \& embedded systems



\---



\## 📦 Installation



\### PlatformIO



Add to `lib\_deps`



```ini

lib\_deps =

&#x20;   httpsgithub.comMicroboltRoboticsMicroboltOTA

````



\---



\### Manual Installation



1\. Download this repository

2\. Copy `MicroboltOTA.h` into your `lib` folder

3\. Include it in your project



\---



\## 🚀 Quick Start



```cpp

\#include MicroboltOTA.h



void setup()

{

&#x20;   MicroboltOTAbegin(

&#x20;       YOUR\_WIFI\_NAME,

&#x20;       YOUR\_WIFI\_PASSWORD

&#x20;   );

}



void loop()

{

&#x20;   MicroboltOTArun();



&#x20;   static unsigned long t = 0;



&#x20;   if (millis() - t  1000)

&#x20;   {

&#x20;       t = millis();

&#x20;       MicroboltOTAprintln(Robot Alive);

&#x20;   }

}

```



\---



\## 🌐 OTA Upload (PlatformIO)



After first USB upload



```ini

upload\_protocol = espota

upload\_port = 192.168.1.100

```



Or using hostname



```ini

upload\_protocol = espota

upload\_port = MicroboltOTA.local

```



\---



\## 💻 Wireless Serial Monitor (Telnet)



Connect using



```bash

telnet device-ip 23

```



Example



```bash

telnet 192.168.1.100 23

```



\---



\## 🧠 API Reference



\### begin(ssid, password, hostname)



Initializes WiFi, OTA, and Telnet server.



```cpp

MicroboltOTAbegin(WiFi, Password, Robot01);

```



\---



\### run()



Must be called inside `loop()`.



Handles



&#x20;OTA updates

&#x20;WiFi reconnect

&#x20;Telnet connections



\---



\### print()  println()



Send logs to Serial + Telnet.



```cpp

MicroboltOTAprintln(Hello Robot);

```



\---



\### printf()



Formatted output.



```cpp

MicroboltOTAprintf(Battery %d%%n, 85);

```



\---



\## ⚠️ Important Notes



&#x20;Always call `MicroboltOTArun()` in `loop()`

&#x20;First upload must be via USB

&#x20;OTA requires stable WiFi connection

&#x20;Telnet runs on port 23



\---



\## 🧪 Example Use Cases



&#x20;ESP32 Robot Cars

&#x20;IoT Sensor Nodes

&#x20;Wireless telemetry systems

&#x20;Robotics debugging tools



\---



\## 📌 Version



v1.0.0



\---



\## 👨‍💻 Author



Microbolt Robotics  

ESP32 • Robotics • Embedded Systems  



🌐 GitHub httpsgithub.comMicroboltRobotics  

📺 YouTube httpsyoutube.com@MicroboltRobotics  



\---



\## 📄 License



MIT License



\---



\## ⭐ Why MicroboltOTA



Instead of writing long OTA + logging setup code, use



```cpp

MicroboltOTAbegin(...);

MicroboltOTArun();

```



That’s it.
