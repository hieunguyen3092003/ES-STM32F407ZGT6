# ES-STM32F407ZGT6
Lab 2 Embedded System, experimented on Kit Arm. Exercises are stored in git branches

## Configuration
### Lab 1 Config GPIO, clock source
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

### Lab 2: Config software timer, SPI1, Button, Led7Seg 
TIM2 -> Clock Source: Internal Clock -> NVIC Settings -> TIM2 global interrupt: enabled -> Parameter Settings -> Prescaler: 84-1, Counter Period: 1000-1 (1ms timer interupt)

PB3 (SPI1_SCK)
PB4 (SPI1_MISO)
PB5 (SPI1_MOSI)
PD3 (GPIO_Output) -> BTN_LOAD
PD6 (GPIO_Output) -> LD_LATCH

SPI1 -> Mode: Full-Duplex Master -> Parameter Settings -> Baud Rate: 21.0 MBits/s (led 7 segment)

### Lab 3: Config LCD
FSMC -> LCD 1 -> Chip Select: NE1, Memory type: LCD Interface, LCD Register Select: A19, Data: 16 bits -> NOR/PSRAM 1 -> Extended mode: Enabled, Address setup time in HCLK clock cycles: 15, Data setup time in HCLK clock cycles: 60, Bus turn around time in HCLK clock cycles: 0, Access mode: A, Extended address setup time: 8, Extended data setup time: 9, Extended bus turn around time: 0, Extended access mode: A

PC13-ANTI_TAMP (GPIO_Output) -> FSMC_RES
PA8 (GPIO_Output) -> FSMC_BLK

### Lab 6: Config ADC, Buzzer
ADC1 -> IN8, IN9, IN10, IN11, IN12: checked -> Parameter Settings -> Scan Conversion Mode: enabled, Number Of Conversion: 5, Rank 1: Channel 8, Rank 2: Channel 9, Rank 3: Channel 10, Rank 4: Channel 11, Rank 5: Channel 12 -> DMA Settings -> Add -> DMA Request: ADC1 -> Mode: Cicular

TIM13 -> Activated: checked, Channel1: PWM Generation CH1

### Lab 8: Config esp8266
PF10 (GPIO_Output) -> ESP12_PWR
PF9 (GPIO_Input) -> ESP12_BUSY
PA3 (USART2_RX)
PA2 (USART2_TX)

USART2 -> Mode: Asyncronous -> USART2 global interupt: enabled

## Program
### Lab 8 
./esp8266 is a directory used to program the ESP8266. This program uses the PlatformIO plugin.