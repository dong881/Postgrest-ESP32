#include <WiFi.h>
#include <HTTPClient.h>

#define WIFI_SSID "Eprotocol"
#define WIFI_PASSWORD "53734312"
String serverUrl = "http://192.168.50.174:3000/";
const char *accessToken = "eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJyb2xlIjoidG9kb191c2VyIn0.0Pem5uTOSUFAMKrsY49c1MJ4_WM1-5shQqVDp6CPxJg";

void postSensorData(const char *deviceId, const char *angle, const char *illumination, const char *time) {
  // Connect to Wi-Fi
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");
  
  // add correct table path
  serverUrl += deviceId;
  
  // Make POST request
  HTTPClient http;
  http.begin(serverUrl);
  http.addHeader("Authorization", "Bearer " + String(accessToken));
  http.addHeader("Content-Type", "application/json");

  // Prepare JSON payload
  String jsonPayload = "{\"angle\":\"" + String(angle) + "\",\"illumination\":\"" + String(illumination) + "\",\"time\":\"" + String(time) + "\"}";

  // Send POST request
  int httpResponseCode = http.POST(jsonPayload);
  if (httpResponseCode > 0) {
    Serial.print("HTTP Response code: ");
    Serial.println(httpResponseCode);
    String response = http.getString();
    Serial.println(response);
  } else {
    Serial.print("HTTP Request failed. Error code: ");
    Serial.println(httpResponseCode);
  }

  // Close connection
  http.end();
}

void setup() {
  Serial.begin(115200);

  // Example usage
  const char *deviceId = "TEST";
  const char *angle = "12.34";
  const char *illumination = "567";
  const char *time = "2024-01-9 03:59:59";

  // Call the function with the sensor data
  postSensorData(deviceId, angle, illumination, time);
}

void loop() {
  // Your code here
}
