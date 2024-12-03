/*
 * dma.c
 *
 *  Created on: Dec 6, 2023
 *      Author: ADMIN
 */

#include "dma.h"

void MX_DMA_Init(void){

  /* DMA controller clock enable */
  __HAL_RCC_DMA2_CLK_ENABLE();

  /* DMA interrupt init */
  /* DMA2_Stream0_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(DMA2_Stream0_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(DMA2_Stream0_IRQn);

}
