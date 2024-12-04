/*
 * lightControl.c
 *
 *  Created on: Dec 3, 2024
 *      Author: hieun
 */

#include "lightControl.h"

uint8_t light_status = 0;

void lightProcess(){
	if(button_count[13] == 1){
		light_status = 1 - light_status;
		if(light_status == 1){
			uart_EspSendBytes((uint8_t*)"A", 1);
		} else {

			uart_EspSendBytes((uint8_t*)"a", 1);
		}
	}
	if(light_status == 1){
		HAL_GPIO_WritePin(OUTPUT_Y0_GPIO_Port, OUTPUT_Y0_Pin, 1);
	} else {
		HAL_GPIO_WritePin(OUTPUT_Y0_GPIO_Port, OUTPUT_Y0_Pin, 0);
	}
}

void test_Esp(){
	if(!uart_EspCheck())
		uart_EspSendBytes(( uint8_t*)"o", 1);
	else lcdShowString(10, 50, "ESP Connect", GREEN, BLACK, 24, 0);
}
