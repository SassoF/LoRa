// lora_functions.ino
#include "lora_functions.h"
#include "oled_display.h"
#include "config.h"
#include "voltage.h"

void setupLoRa() {
    SPI.begin(SCK, MISO, MOSI, SS);
    LoRa.setPins(SS, RST, DIO0);

    LoRa.setSpreadingFactor(SF);
    LoRa.setTxPower(TX_PWR);

    #ifdef OLED
    displayMessage("[LoRa] Init");
    delay(250);
    #endif
    DEBUG_PRINTLN("[LoRa] Init");

    if (!LoRa.begin(BAND)) {
        #ifdef OLED
        displayMessage("[LoRa] Init failed!");
        #endif
        DEBUG_PRINTLN("[LoRa] Starting failed!");
        while (1);
    }

    #ifdef OLED
    displayMessage("[LoRa] Ready!");
    delay(250);
    #endif
    DEBUG_PRINTLN("[LoRa] Ready!");
}

void loopLoRa() {
    float voltageLevel = readVoltage();

    if (voltageLevel != 0) {
      bool packetStatus = createPacket(voltageLevel);
      #ifdef OLED
      updatePacketStatus(String(voltageLevel).c_str(), packetStatus);
      #endif
    } else {
      #ifdef OLED
      displayMessage("Power is ON");
      #endif
    }
}

bool createPacket(float voltageLevel) {
    LoRa.beginPacket();
    LoRa.print(voltageLevel);

    if (LoRa.endPacket()) {
        DEBUG_PRINTLN("[LoRa] Packet sent successfully!");
        return true;
    } else {
        DEBUG_PRINTLN("[LoRa] Packet send failed!");
        return false;
    }
}