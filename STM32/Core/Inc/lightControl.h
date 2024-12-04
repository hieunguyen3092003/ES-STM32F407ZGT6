/*
 * lightControl.h
 *
 *  Created on: Dec 3, 2024
 *      Author: hieun
 */

#ifndef INC_LIGHTCONTROL_H_
#define INC_LIGHTCONTROL_H_

#include <stdint.h>
#include "gpio.h"
#include "uart.h"
#include "button.h"
#include "lcd.h"

extern uint8_t light_status;

void lightProcess();

void test_Esp();

#endif /* INC_LIGHTCONTROL_H_ */
