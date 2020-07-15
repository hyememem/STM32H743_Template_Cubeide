/* Includes ------------------------------------------------------------------*/
#include "includes.h"

/* Define ------------------------------------------------------------------*/
#define RNG_LEN 10
/* variables ------------------------------------------------------------------*/
uint32_t ranDom[RNG_LEN] = {0};
uint32 Main_loop = 0;

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
    HAL_Init();
    SystemClock_Config();

    DEBUG_PRINT("\nSystem Go...\r\n");
    MX_GPIO_Init();
    MX_DMA_Init();
    MX_ADC1_Init();
    MX_I2C2_Init();
    MX_USART1_UART_Init();
    MX_RNG_Init();
    AT24CXX_Read_Write_Test();
//    AT24C256_Read_Write_Test();
    for(uint8_t i = 0; i < RNG_LEN; i++)
    {
        if((HAL_RNG_GenerateRandomNumber(&hrng, (uint32_t *)&ranDom[i])) != HAL_OK)
        {
            Error_Handler();
        }
    }
    for(uint8_t j = 0; j < RNG_LEN; j++)
    {
        DEBUG_PRINT("0x%lx\r\n", ranDom[j]);
    }
    while (1)
    {
        DEBUG_PRINT("\nMain_loop is: %lu\r\n", Main_loop);
        Main_loop++;
        HAL_GPIO_TogglePin(GPIOG, LED1_Pin | LED2_Pin | LED3_Pin);
        HAL_Delay(1000);

    }

}


