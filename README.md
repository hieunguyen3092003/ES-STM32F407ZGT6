# ES-STM32F407ZGT6
Lab 2 Embedded System, experimented on Kit Arm. Exercises are stored in git branches

## Configuration
### Lab 1
SYS -> Debug: Serial Wire
RCC -> HSE: Crystal/Ceramic Resonator

PE4 (GPIO_Output) -> LED_DEBUG
PE5 (GPIO_Output) -> OUTPUT_Y0
PE6 (GPIO_Output) -> OUTPUT_Y1

PA6 (GPIO_Input PULL-UP) -> INPUT_X0
PA7 (GPIO_Input PULL-UP) -> INPUT_X1
PC5 (GPIO_Input PULL-UP) -> INPUT_X2
PC5 (GPIO_Input PULL-UP) -> INPUT_X3

Clock Configuration -> HCLK: 168 MHz, APB1 & APB2 Prescaler: /4

