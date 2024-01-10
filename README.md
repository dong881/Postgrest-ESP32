# IoT Sensor Data Uploader

This Arduino sketch demonstrates how to upload sensor data to a server using the ESP32 WiFi module. In this example, we use the HTTPClient library to make a POST request to a specified server URL with JSON-formatted sensor data.

## Prerequisites
1. Arduino IDE installed.
2. ESP32 board support installed in Arduino IDE.
3. `WiFi.h` and `HTTPClient.h` libraries installed in Arduino IDE.

## Configuration
Before uploading the sketch, make sure to update the following constants in the code:

```cpp
#define WIFI_SSID "Your_WiFi_SSID"
#define WIFI_PASSWORD "Your_WiFi_Password"
const char *serverUrl = "http://your_server_ip:3000/sensor_data";
const char *accessToken = "Your_Auth_Token";
```

Replace placeholders with your WiFi credentials, server IP, and access token.

## Sensor Data
You can customize the sensor data in the `setup()` function:

```cpp
const char *deviceId = "Your_Device_ID";
const char *angle = "12.34";
const char *illumination = "567";
const char *time = "2024-01-9 03:59:59";
```

Replace placeholders with your sensor data.

## Usage
1. Connect your ESP32 to your computer.
2. Open the Arduino IDE and upload the sketch to your ESP32.
3. Open the Serial Monitor to view the connection status and HTTP response.

## Important Note
Make sure your server is configured to handle the incoming sensor data and validate the access token.