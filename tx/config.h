// config.h
#ifndef CONFIG_H
#define CONFIG_H

#define SCK   5      // Serial Clock pin (SCK) for SPI communication
#define MISO  19     // Master In Slave Out pin (MISO) for receiving data from the slave
#define MOSI  27     // Master Out Slave In pin (MOSI) for sending data to the slave
#define SS    18     // Slave Select pin (SS) to select the specific slave device
#define RST   14     // Reset pin (RST) to reset the LoRa module
#define DIO0  26     // Digital Input/Output pin 0 (DIO0) for signaling events or states
#define BAND  868E6  // Europe Frequency Band
#define SF    12     // SpreadingFactor
#define TX_PWR 17    // TX Power db
#define VOLTAGE 34   // Pin for reading the voltage

// Uncomment to enable, comment to disable
#define DEBUG

// Uncomment to enable, comment to disable
#define OLED

#ifdef DEBUG
#define DEBUG_PRINTLN(x) Serial.println(x)
#define DEBUG_PRINT(x) Serial.print(x)
#else
#define DEBUG_PRINTLN(x)
#define DEBUG_PRINT(x)
#endif

#ifdef OLED
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#endif
#endif