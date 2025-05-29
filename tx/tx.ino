// tx.ino
#include "config.h"
#include "oled_display.h"
#include "lora_functions.h"

#ifdef OLED
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);
#endif

void setup() {
    #ifdef DEBUG
    Serial.begin(115200);
    #endif

    #ifdef OLED
    if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
        DEBUG_PRINTLN("[OLED] Init failed!");
        while (1);
    }
    displayLogo();
    #endif

    setupLoRa();
}

void loop() {
    loopLoRa();
    delay(10000);
}


