/*
 * system.h
 *
 *  Created on: 2020-6-12
 *      Author: wuliZhao_ch
 *
 */

#ifndef SYSTEM_H_
#define SYSTEM_H_

#include "common.h"


// HSE_VALUE definition in stm32f7xx_hal_conf.h must be CORRECTED!!!
//#define HSE_VALUE    ((uint32_t)25000000U)

//#define SYSTICK_Frequency 1000	//in Hz

//void Cache_Enable(void);

//void RCC_CLK_Enable(void);

void SystemClock_Config(void);

void Error_Handler(void);

//void SYS_Delay_US(uint32_t delay_us);

//void MPU_Config(void);


#endif /* SYSTEM_H_ */
