#include "utils.hpp"

void setupSerial() {
    Serial.begin(115200);
    Serial.print("Connecting to ");
    Serial.println(WIFI_SSID);
}

void setupWifi() {
    WiFi.mode(WIFI_STA);
    WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
    if (WiFi.waitForConnectResult() != WL_CONNECTED) {
        Serial.printf("WiFi Failed!\n");
        throw std::runtime_error("Wifi init connection failed");
    }   

    Serial.print("IP Address: ");
    Serial.println(WiFi.localIP());
}