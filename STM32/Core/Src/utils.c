/*
 * utils.c
 *
 *  Created on: Nov 23, 2024
 *      Author: ngtrunghieu
 */

#include "utils.h"

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

uint8_t BCD2DEC(uint8_t data)
{
	return (data >> 4) * 10 + (data & 0x0f);
}

uint8_t DEC2BCD(uint8_t data)
{
	return (data / 10) << 4 | (data % 10);
}

#ifdef __cplusplus
}
#endif /* __cplusplus */
