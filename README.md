# IR_Remote-STM32📟
![IR_Remote](https://github.com/user-attachments/assets/7d5bc353-c8c0-4230-adcb-b4e70cbc0844)

STM32F401 reads NEC IR signals, decodes them, and shows the button name on a 1.8" TFT display. Perfect for learning timers, SPI, and interrupts.

## Description
A universal IR remote receiver and decoder. Using a KY-022 module, the STM32 captures NEC protocol signals, measures pulse durations with TIM2 Input Capture, and displays the pressed button (e.g., "1", "OK", "LEFT") on an ST7735 SPI display. Great for home automation or as a visual remote feedback.

## Hardware
STM32F401RCT6
KY‑022 IR receiver module
1.8" TFT display (ST7735, SPI)
LED on PC13 for blink indication

## Schematic
<img width="782" height="605" alt="IR_Schematic" src="https://github.com/user-attachments/assets/7b228d83-c36c-46f6-a086-06ee219e3b13" />

## How it works
1. TIM2 in Input Capture mode detects rising/falling edges on PA0.
2. Interrupt handler measures the duration of high‑level pulses (gaps).
3. Gap ~4.5 ms → leader; ~0.56 ms → bit 0; ~1.69 ms → bit 1.
4. After 32 bits, a “data ready” flag is set.
5. Main loop calls DisplayButton() and shows the button name on the TFT.

https://github.com/user-attachments/assets/c8a0cded-8d6a-4405-ba46-1629f918ec19
                                                                            🔇
## Author
👾**SergeyKisa228**👾
