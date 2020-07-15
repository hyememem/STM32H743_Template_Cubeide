/*
 * at24cxx.c
 *
 *  Created on: 2020-6-15
 *      Author: wuliZhao_ch
 *       brief: Source file of EEPROM.
 *   attention: Use for AT24C04~AT24C256.
 */

#include "at24cxx.h"


/**
  * @brief  Function Write a Byte to at24cXX
  * @param  Addr: Start Write Address
  * @param  Data: Data Content Write
  * @param  Time_out: Timeout duration
  * @retval HAL status
  */
uint8_t AT24CXX_ByteWrite(uint16_t Addr, uint8_t* data, uint32_t Time_out)
{
    return HAL_I2C_Mem_Write(&IIC_HANDLE, AT24CXX_ADDR_WRITE, Addr, I2C_MEMADD_SIZE_16BIT, data, 1, Time_out);
}

/**
  * @brief  Function Read a Byte to at24cXX
  * @param  Addr: Start Reading the Starting Address
  * @param  Data: Data Content Read
  * @param  Time_out: Timeout duration
  * @retval HAL status
  */
uint8_t AT24CXX_ByteRead(uint16_t Addr, uint8_t* read_buff, uint32_t Time_out)
{
    return HAL_I2C_Mem_Read(&IIC_HANDLE, AT24CXX_ADDR_READ, Addr, I2C_MEMADD_SIZE_16BIT, read_buff, 1, Time_out);
}

/**
  * @brief  Function Write MultiByte to at24cXX
  * @param  Addr: Start Reading the Starting Address
  * @param  Data: Data Content Read
  * @param  Size: Amount of data to be sent
  * @param  Time_out: Timeout duration
  * @retval HAL status
  */
uint8_t AT24CXX_MultiByteWrite(uint16_t Addr, uint8_t* data, uint16_t size, uint32_t Time_out)
{
    uint8_t i = 0;
    uint16_t Byte_cnt = 0;
    if(Addr % AT24CXX_PAGE_SIZE_MAX == 0)
    {
        if(size < AT24CXX_PAGE_SIZE_MAX)
        {
            return HAL_I2C_Mem_Write(&IIC_HANDLE, AT24CXX_ADDR_WRITE, Addr, I2C_MEMADD_SIZE_16BIT, data, size, Time_out);
        }
        else
        {
            for(i = 0; i < size / AT24CXX_PAGE_SIZE_MAX; i++)
            {
                HAL_I2C_Mem_Write(&IIC_HANDLE, AT24CXX_ADDR_WRITE, Addr, I2C_MEMADD_SIZE_16BIT, &data[Byte_cnt], AT24CXX_PAGE_SIZE_MAX, Time_out);
                Addr += AT24CXX_PAGE_SIZE_MAX;
                Byte_cnt += AT24CXX_PAGE_SIZE_MAX;
                HAL_Delay(5);
            }
            return HAL_I2C_Mem_Write(&IIC_HANDLE, AT24CXX_ADDR_WRITE, Addr, I2C_MEMADD_SIZE_16BIT, &data[Byte_cnt], size - Byte_cnt, Time_out);
        }
    }
    else
    {
        if(size < (AT24CXX_PAGE_SIZE_MAX - Addr % AT24CXX_PAGE_SIZE_MAX))
        {
            return HAL_I2C_Mem_Write(&IIC_HANDLE, AT24CXX_ADDR_WRITE, Addr, I2C_MEMADD_SIZE_16BIT, data, size, Time_out);
        }
        else
        {
            Byte_cnt += AT24CXX_PAGE_SIZE_MAX - Addr % AT24CXX_PAGE_SIZE_MAX;
            HAL_I2C_Mem_Write(&IIC_HANDLE, AT24CXX_ADDR_WRITE, Addr, I2C_MEMADD_SIZE_16BIT, data, Byte_cnt, Time_out);
            Addr += Byte_cnt;
            for(i = 0; i < (size -Byte_cnt) / AT24CXX_PAGE_SIZE_MAX; i++)
            {
                HAL_I2C_Mem_Write(&IIC_HANDLE, AT24CXX_ADDR_WRITE, Addr, I2C_MEMADD_SIZE_16BIT, &data[Byte_cnt], AT24CXX_PAGE_SIZE_MAX, Time_out);
                Addr += AT24CXX_PAGE_SIZE_MAX;
                Byte_cnt += AT24CXX_PAGE_SIZE_MAX;
                HAL_Delay(5);
            }
            return HAL_I2C_Mem_Write(&IIC_HANDLE, AT24CXX_ADDR_WRITE, Addr, I2C_MEMADD_SIZE_16BIT, &data[Byte_cnt], size - Byte_cnt, Time_out);
        }
    }
}

/**
  * @brief  Function Read MultiByte to at24cXX
  * @param  Addr: Start Reading the Starting Address
  * @param  Read_Data: Data Content Read
  * @param  Size: Amount of data to be sent
  * @param  Time_out: Timeout duration
  * @retval HAL status
  */
uint8_t AT24CXX_MultiByteRead(uint16_t Addr, uint8_t* read_buff, uint16_t size, uint32_t Time_out)
{
    return HAL_I2C_Mem_Read(&IIC_HANDLE, AT24CXX_ADDR_READ, Addr, I2C_MEMADD_SIZE_16BIT, read_buff, size, Time_out);
}


/**
  * @brief  Function Test to at24cXX
  * @retval NULL
  */
void AT24CXX_Read_Write_Test(void)
{
    uint8_t onebyte = 0x5B;
    uint8_t onebytetemp = 0x00;
    uint8_t data[200] = { 0 };
    uint8_t rev_buffer[200] = { 0 };

    for (uint16_t i = 0; i < 200; i++)
    {
        data[i] = i;
    }

    if (HAL_OK == AT24CXX_ByteWrite(0, &onebyte, TIME_OUT))
    {
        printf("One byte Write OK!\r\n");
    }
    HAL_Delay(50);
    if (HAL_OK == AT24CXX_ByteRead(0, &onebytetemp, TIME_OUT))
    {
        printf("One byte read OK!\r\n");
        printf("One byte value is %x\r\n", onebytetemp);
    }

    if (HAL_OK == AT24CXX_MultiByteWrite(10, data, 20, TIME_OUT))
    {
        printf("MultiByte Write OK!\r\n");
    }
    HAL_Delay(50);
    if (HAL_OK == AT24CXX_MultiByteRead(10, rev_buffer, 20, TIME_OUT))
    {
        printf("MultiByte read OK!\r\n");
        for (uint16_t i = 0; i < 20; i++)
        {
            printf("value is %d\r\n", data[i]);
        }
    }

}
