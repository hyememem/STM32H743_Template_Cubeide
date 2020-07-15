/*
 * at24c256.h
 *
 *  Created on: 2020-6-15
 *      Author: wuliZhao_ch
 */


#ifndef AT24C256_H_
#define AT24C256_H_
#ifdef __cplusplus
 extern "C" {
#endif
#include "main.h"
#include "i2c.h"
#include "usart.h"
#include "stdio.h"

#define AT24C256_WRITE_ADDRESS      0xA0
#define AT24C256_READ_ADDRESS       0xA1
#define AT24C256_PAGE_SIZE_MAX      64
#define IIC_HANDLE                  hi2c2
#define AT24C256_TIME_OUT           0xFFFF

uint8_t AT24C256_ByteWrite(uint16_t Addr, uint8_t* data, uint32_t Time_out);
uint8_t AT24C256_ByteRead(uint16_t Addr, uint8_t* read_buff, uint32_t Time_out);
uint8_t AT24C256_MultiByteWrite(uint16_t Addr, uint8_t* data, uint16_t size, uint32_t Time_out);
uint8_t AT24C256_MultiByteRead(uint16_t Addr, uint8_t* read_buff, uint16_t size, uint32_t Time_out);
void AT24C256_Read_Write_Test(void);




#ifdef __cplusplus
}
#endif
#endif /* AT24C256_H_ */
