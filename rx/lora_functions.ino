// lora_functions.ino
#include "lora_functions.h"
#include "oled_display.h"
#include "config.h"
#include "telegram.h"

void setupLoRa() {
    SPI.begin(SCK, MISO, MOSI, SS);
    LoRa.setPins(SS, RST, DIO0);

    #ifdef OLED
    setMessage("[LoRa] Init");
    delay(250);
    #endif
    DEBUG_PRINTLN("[LoRa] Init");

    if (!LoRa.begin(BAND)) {
        #ifdef OLED
        setMessage("[LoRa] Init failed!");
        #endif
        DEBUG_PRINTLN("[LoRa] Starting LoRa failed!");
        while (1);
    }

    #ifdef TELEGRAM
    WiFi.begin(WIFI_SSID, WIFI_PSWD);
    #ifdef OLED
    setMessage("[WiFi] Connecting...");
    #endif
    DEBUG_PRINTLN("[WiFi] Attempting connection to: " + String(WIFI_SSID));

    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
    }
    
    #ifdef OLED
    setMessage("[WiFi] Connected!");
    delay(250);
    #endif
    DEBUG_PRINTLN("[WiFi] Connected!");
    #endif

    #ifdef OLED
    setMessage("[LoRa] Ready!");
    delay(250);
    #endif
    DEBUG_PRINTLN("[LoRa] Ready!");
};


void loopLoRa() {
    int packetSize = LoRa.parsePacket();

    if (packetSize) {
        String receivedMessage = "";
        
        while (LoRa.available()) {
            receivedMessage += (char)LoRa.read();
        }

        DEBUG_PRINT("[LoRa] Received packet: ");
        DEBUG_PRINTLN(receivedMessage); 

        #ifdef OLED
        updateMessageReceived(receivedMessage.c_str());
        #endif

        #ifdef TELEGRAM
        sendTelegramNotification(receivedMessage.c_str());        
        #endif
    }
};
