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

### Lab 2
TIM2 -> Clock Source: Internal Clock -> NVIC Settings -> TIM2 global interrupt: enabled -> Parameter Settings -> Prescaler: 84-1, Counter Period: 1000-1 (1ms timer interupt)

PB3 (SPI1_SCK)
PB4 (SPI1_MISO)
PB5 (SPI1_MOSI)
PD3 (GPIO_Output) -> BTN_LOAD
PD6 (GPIO_Output) -> LD_LATCH

SPI1 -> Mode: Full-Duplex Master -> Parameter Settings -> Baud Rate: 21.0 MBits/s (led 7 segment)