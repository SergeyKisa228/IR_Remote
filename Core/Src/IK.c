#include "IK.h"
#include "st7735.h"
#include <stdio.h>
#include <string.h>

volatile uint8_t ir_recv_state = 0;
volatile uint32_t ir_code = 0;
volatile uint8_t ir_bit_count = 0;

void test_ik()
{
	if ((HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_0)) ==  GPIO_PIN_RESET)
	{
        HAL_GPIO_WritePin(GPIOC, GPIO_PIN_13, GPIO_PIN_RESET);
        HAL_Delay(100);
        HAL_GPIO_WritePin(GPIOC, GPIO_PIN_13, GPIO_PIN_SET);
        HAL_Delay(500);
	}
}

void DisplayButton(uint32_t code)
{
    ST7735_FillRectangle(11, 41, ST7735_WIDTH-22, 48, ST7735_BLACK);

    char buf[32];
    const char *text;
    switch (code)
    {
        case 0xFFA25D: text = "1"; break;
        case 0xFF629D: text = "2"; break;
        case 0xFFE21D: text = "3"; break;
        case 0xFF22DD: text = "4"; break;
        case 0xFF02FD: text = "5"; break;
        case 0xFFC23D: text = "6"; break;
        case 0xFFE01F: text = "7"; break;
        case 0xFFA857: text = "8"; break;
        case 0xFF906F: text = "9"; break;
        case 0xFF9867: text = "0"; break;
        case 0xFF38C7: text = "OK"; break;
        case 0xFF6897: text = "*"; break;
        case 0xFFB04F: text = "#"; break;
        case 0xFF10EF: text = "LEFT"; break;
        case 0xFF5AA5: text = "RIGHT"; break;
        case 0xFF18E7: text = "UP"; break;
        case 0xFF4AB5: text = "DOWN"; break;
        default: sprintf(buf, "0x%08lX", code); text = buf; break;
    }

    uint8_t len = strlen(text);
    uint16_t text_width = len * 11;
    uint16_t x_center = (ST7735_WIDTH - text_width) / 2;
    if (x_center < 10) x_center = 10;

    ST7735_WriteString(x_center, 55, text, Font_11x18, ST7735_YELLOW, ST7735_BLACK);
}
