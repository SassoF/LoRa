// oled_display.ino
#include "oled_display.h"

#ifdef OLED

void displayMessage(const char* text) {
    setMessage(text, 0 , 30, true);
    display.display();
}

void setMessage(const char* text, int posX, int posY, bool clearDisplay) {
    if (clearDisplay) {
        display.clearDisplay();
    }
    display.setTextSize(1.5);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(posX, posY);
    display.print(text);
}

void updatePacketStatus(const char* text, bool packetStatus) {
    setMessage("LORA SENDER", 0, 0, true);
    setMessage(packetStatus ? "[LoRa] Packet sent." : "[LoRa] Send failed!", 0, 20, false);
    setMessage("Voltage:", 0, 30, false);
    setMessage(text, 60, 30, false);
    setMessage("Power outage detected!", 0, 40, false);
    display.display();
}

void displayLogo() {
    display.clearDisplay();
    display.drawBitmap(0, 0, logoBitMap, SCREEN_WIDTH, SCREEN_HEIGHT, SSD1306_WHITE);
    display.display();
    delay(1500);
}

#endif