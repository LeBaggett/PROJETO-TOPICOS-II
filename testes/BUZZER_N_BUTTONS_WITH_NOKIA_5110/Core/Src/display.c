#include "display.h"
#include "screen_logo.h"
#include "string.h"

/* Display físico real */
extern SPI_HandleTypeDef hspi1;

void Display_Init(void)
{
    // Aqui você define PINOS, SPI
	gLcdScreen.mPinout.mSpiHandle = &hspi1;

	gLcdScreen.mPinout.mLcdSpiRstPort = LCD_RST_GPIO_Port;
	gLcdScreen.mPinout.mLcdSpiRstPin  = LCD_RST_Pin;

	gLcdScreen.mPinout.mLcdSpiCePort  = LCD_CS_GPIO_Port;
	gLcdScreen.mPinout.mLcdSpiCePin   = LCD_CS_Pin;

	gLcdScreen.mPinout.mLcdSpiDcPort  = LCD_DC_GPIO_Port;
	gLcdScreen.mPinout.mLcdSpiDcPin   = LCD_DC_Pin;

	gLcdScreen.mPinout.mLcdSpiDinPort = MOSI_GPIO_Port;
	gLcdScreen.mPinout.mLcdSpiDinPin  = MOSI_Pin;

	gLcdScreen.mPinout.mLcdSpiClkPort = SCK_GPIO_Port;
	gLcdScreen.mPinout.mLcdSpiClkPin  = SCK_Pin;

    LCD_PCD8544_init(&gLcdScreen);
    HAL_GPIO_WritePin(LCD_BL_GPIO_Port, LCD_BL_Pin, GPIO_PIN_SET);
    LogoScreen_Show();
//    uint8_t test[84];
//    memset(test, 0xAA, 84);  // padrão 10101010
//
//    for (uint8_t p = 0; p < 6; p++)
//    {
//        LCD_PCD8544_write_bytes(&gLcdScreen, p, 0, test, 84);
//    }

}

void Display_Clear(void)
{
    LCD_PCD8544_clear_ram(&gLcdScreen);
}

void Display_WriteLine(uint8_t line, const char *text)
{
    LCD_PCD8544_write_line(&gLcdScreen, line, text);
}
