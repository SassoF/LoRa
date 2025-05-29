// voltage.ino
#include "voltage.h"
#include "config.h"

float readVoltage() {
    return 3300.0 * 2 * float(analogRead(VOLTAGE))/1023.0;
}