#ifndef LIB_ADAFRUIT_H
#define LIB_ADAFRUIT_H

#include <stdint.h>

bool initConnectAda();
void publishLightStatus(uint8_t status);
void publishTemp(float temperature);

#endif /* LIB_ADAFRUIT_H */