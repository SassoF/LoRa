// oled_display.ino
#include "oled_display.h"

#ifdef OLED

void setMessage(const char* text, int posX, int posY, bool clearDisplay) {
    if (clearDisplay) {
        display.clearDisplay();
    }
    display.setTextSize(1.5);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(posX, posY);
    display.print(text);
    display.display();
}

void updateMessageReceived(const char* text) {
    setMessage("LORA RECEIVER", 0, 0, true);
    setMessage("Packet received: ", 0, 20, false);
    setMessage(text, 0, 40, false);
}

void displayLogo() {
    display.clearDisplay();
    display.drawBitmap(0, 0, logoBitMap, SCREEN_WIDTH, SCREEN_HEIGHT, SSD1306_WHITE);
    display.display();
    delay(1500);
}

#endif