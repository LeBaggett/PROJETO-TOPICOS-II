#include "display.h"
#include "lcd_pcd8544.h"

/* Display físico real */
static LCD_PCD8544_screen_t lcd;

static void Display_Init_Impl(void)
{
    // Aqui você define PINOS, SPI, etc (1 vez só)
    lcd.mPinout.mSpiHandle = &hspi1;

    lcd.mPinout.mLcdSpiRstPort = LCD_RST_GPIO_Port;
    lcd.mPinout.mLcdSpiRstPin  = LCD_RST_Pin;

    lcd.mPinout.mLcdSpiCePort  = LCD_CS_GPIO_Port;
    lcd.mPinout.mLcdSpiCePin   = LCD_CS_Pin;

    lcd.mPinout.mLcdSpiDcPort  = LCD_DC_GPIO_Port;
    lcd.mPinout.mLcdSpiDcPin   = LCD_DC_Pin;

    lcd.mPinout.mLcdSpiDinPort = MOSI_GPIO_Port;
    lcd.mPinout.mLcdSpiDinPin  = MOSI_Pin;

    lcd.mPinout.mLcdSpiClkPort = SCK_GPIO_Port;
    lcd.mPinout.mLcdSpiClkPin  = SCK_Pin;

    LCD_PCD8544_init(&lcd);
}

static void Display_Clear_Impl(void)
{
    LCD_PCD8544_clear_ram(&lcd);
}

static void Display_WriteLine_Impl(uint8_t line, const char *text)
{
    LCD_PCD8544_write_line(&lcd, line, text);
}

/* Interface pública */
Display_t Display = {
    .init       = Display_Init_Impl,
    .clear      = Display_Clear_Impl,
    .write_line = Display_WriteLine_Impl
};
