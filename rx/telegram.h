// telegram.h
#ifndef TELEGRAM_H
#define TELEGRAM_H

#include <WiFi.h>
#include <HTTPClient.h>
#include "config.h"

#ifdef TELEGRAM
void sendTelegramNotification(const char* text);
#endif

#endif