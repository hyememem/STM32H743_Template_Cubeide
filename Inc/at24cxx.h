/*
 * at24cxx.h
 *
 *  Created on: 2020-6-15
 *      Author: wuliZhao_ch
 */

#ifndef AT24Cxx_H_
#define AT24Cxx_H_

#include "main.h"
#include "i2c.h"
#include "stdio.h"


/* Choose according to your EEPROM type */

//#define     AT24C01_ENABLED
//#define     AT24C02_ENABLED
//#define     AT24C04_ENABLED
//#define     AT24C08_ENABLED
//#define     AT24C16_ENABLED
//#define     AT24C32_ENABLED
//#define     AT24C64_ENABLED
//#define     AT24C128_ENABLED
#define     AT24C256_ENABLED
//#define     AT24C512_ENABLED



#if     defined(AT24C01_ENABLED)
    #define AT24CXX_PAGE_SIZE_MAX          8
#elif   defined(AT24C02_ENABLED)
    #define AT24CXX_PAGE_SIZE_MAX          8
#elif   defined(AT24C04_ENABLED)
    #define AT24CXX_PAGE_SIZE_MAX          16
#elif   defined(AT24C08_ENABLED)
    #define AT24CXX_PAGE_SIZE_MAX          16
#elif   defined(AT24C16_ENABLED)
    #define AT24CXX_PAGE_SIZE_MAX          16
#elif   defined(AT24C32_ENABLED)
    #define AT24CXX_PAGE_SIZE_MAX          32
#elif   defined(AT24C64_ENABLED)
    #define AT24CXX_PAGE_SIZE_MAX          32
#elif   defined(AT24C128_ENABLED)
    #define AT24CXX_PAGE_SIZE_MAX          64
#elif   defined(AT24C256_ENABLED)
    #define     AT24CXX_PAGE_SIZE_MAX           64
#else
    #define AT24CXX_PAGE_SIZE_MAX          128
#endif


/*   Device Address
 *   | 1 0 1 0 | A2 A1 A0 | R/W |
 *   |    A    | 0  0  0  | 1/0 |
 *   A2,A1,A0 are 3-bit device addresses
 * */
#define AT24CXX_ADDR_WRITE              0xA0
#define AT24CXX_ADDR_READ               0xA1


#define IIC_HANDLE                      hi2c2
#define TIME_OUT                        0xFFFF


uint8_t AT24CXX_ByteWrite(uint16_t Addr, uint8_t* data, uint32_t Time_out);
uint8_t AT24CXX_ByteRead(uint16_t Addr, uint8_t* read_buff, uint32_t Time_out);
uint8_t AT24CXX_MultiByteWrite(uint16_t addr, uint8_t* data, uint16_t size, uint32_t Time_out);
uint8_t AT24CXX_MultiByteRead(uint16_t addr, uint8_t* read_buff, uint16_t size, uint32_t Time_out);

void AT24CXX_Read_Write_Test(void);

#endif /* _AT24Cxx_H_ */


