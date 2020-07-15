# STM32H743_Template_Cubeide

#### 介绍
基于STM32CubeIDE创建工程模板（STM32H743）

#### 开发环境
- 硬件开发环境
  - PC : Windows 10 Enterprise Edition x64
  - MCU : STM32H743IIT6
- 软件开发环境
  - STM32CubeIDE：Version: 1.3.1
  - STM32CubeMX：Version: 5.6.1
  - Firmware Package Name and Version：STM32Cube FW_H7 V1.7.0

#### 硬件配置

- **串口USART配置**
  - PIN
    - USART_TX：**PA9**
    - USART_RX：**PA10**
  - Basic Parameter
    - Baud Rate：**115200Bits/s**
    - Word Length：**8Bits(including Parity)**
    - Parity：**None**
    - Stop Bits：**1**
- **LED指示灯配置**
  - PIN
    - LED1：**PG2**
    - LED2：**PG3**
    - LED3：**PG4**
- **ADC_DMA配置**
  - PIN
    - ADC1_INP9：**PB0**
  - ADCs_Common_Settings：
    - Mode：**Independent mode**
  - ADCs_Settings：
    - Clock Prescaler：**Asynchronous clock mode divided by 10**
    - Resolution：**ADC 12-bit resolution**
    - Scan Conversion Mode：**Disabled**
    - Continuous Conversion Mode：**Enabled**
    - Discontinuous Conversion Mode：**Disabled**
    - End Of Conversion Selection：**End of single conversion**
    - Overrun behaviour ：**Overrun data preserved**
    - Conversion Data Management Mode ：**DMA Circular Mode**
    - Low Power Auto Wait ：**Disabled**
- **IIC配置**
  - PIN
    - I2C2_SDA：**PF0**
    - I2C2_SCL：**PF1**