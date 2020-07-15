/*
 * common.h
 *
 *  Created on: 2020-6-12
 *      Author: wuliZhao_ch
 */


#ifndef COMMON_H_
#define COMMON_H_

#define TRUE        1
#define FALSE       0

#define HIGH        1
#define LOW         0

#include "stm32h7xx_hal.h"

#include "mytype.h"

#include "system.h"

#define PRINTF_LOG_ENABLED

#ifdef PRINTF_LOG_ENABLED
#define DEBUG_PRINT(ftm, ...)	printf(ftm, ##__VA_ARGS__)

/* LOG level control， 取值为LOG_LEVEL中枚举类型
 * 该定义设置打印级别，设置级别越高， 打印的信息越多；
 * 当产品发布后，应当把打印级别修改为LOG_OFF或者LOG_ERROR；
 * 调试阶段，打印级别设置为LOG_DEBUG */
#define PRINTF_LOG_LEVEL    LOG_DEBUG

//LOG LEVELS
typedef enum
{
    LOG_OFF = 0,
    LOG_ERROR,
    LOG_WARNING,
    LOG_INFO,
    LOG_DEBUG
}LOG_LEVEL;

#define DEBUG_PRINT_LEVEL(level, ftm, ...)      if (level <=  PRINTF_LOG_LEVEL)             \
                                                {                                           \
                                                    printf(ftm, ##__VA_ARGS__);             \
                                                }

#else
#define DEBUG_PRINT(ftm, ...)
#endif


#endif /* COMMON_H_ */
