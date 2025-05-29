// telegram.ino
#include "telegram.h"

#ifdef TELEGRAM

void sendTelegramNotification(const char* messageReceived){
    
    if (strcmp(messageReceived, "26419.36") != 0) {
        return;
    }

    while (WiFi.status() != WL_CONNECTED) {
        DEBUG_PRINTLN("[WiFi] Attempting to connect to WiFi...");
        delay(500);
    }
    
    HTTPClient http;
    String url = "https://api.telegram.org/bot"
                    + String(BOT_TOKEN)
                    + "/sendMessage?chat_id="
                    + String(USER_ID)
                    + "&text="
                    + MESSAGE + "%0A";

    http.begin(url);

    int httpResponseCode = http.GET();

    if (httpResponseCode > 0) {
        DEBUG_PRINT("[Telegram] Response received: ");
        DEBUG_PRINTLN(http.getString());
    } else {
        DEBUG_PRINT("[Telegram] Failed to send message. Error code: ");
        DEBUG_PRINTLN(httpResponseCode);
        DEBUG_PRINTLN(http.getString());
    }

    http.end();
    delay(300000);
}

#endif
