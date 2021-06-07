
/************************************************************************************
* File Name     : ADS1220.h                                                                                                                                                                                                                                                                                                                                  *
* Author        : SAAD IDRISSI                                                                                                                                                                                                                                                                                                                 *
* Designation   : Electronic Engineer                                                                                                                                                                                                                                                                                                                      *
* Version       : 1.0                                                                                                                                                                            *
* Description   : Bare metal driver to implement for ADS1220 Using SPI Communication.                                                                                                                                        *
* Target        : stm32f103 microcontroller
* Processor     : ARM-Cortex M3
* IDE           : Keil Uvision
*/




#ifndef ADS1220_H_
#define ADS1220_H_

/* Definition of GPIO stm32 Port Bits Used for Communication */

/* PA4 */
#define ADS1220_CS    0x10   	//(1<<4)   localisation of pin 4  Port A    0x10
/* PA7  */
#define ADS1220_DIN   0x80  	//(1<<7)    localisation of pin 7  port A    
/* PA6 */
#define ADS1220_DOUT   0x40  	//(1<<6)   localisation of pin 6  port A    0x40 
/* PC7 */
#define ADS1220_DRDY   0x80 	//(1<<7)    localisation of pin 7  port C    0x80
/* PA5 */
#define ADS1220_SCLK   0x20 	//(1<<5)    localisation of pin 5  port A    0x20

/* Error Return Values */
#define ADS1220_NO_ERROR     0
#define ADS1220_ERROR				-1
	

// Regsiters ADDRESSES
#define config_REG0_ADDR  0x00
#define config_REG1_ADDR  0x01
#define config_REG2_ADDR  0x02
#define config_REG3_ADDR  0x03
#define config_REG4_ADDR  0x03

// COMMANDES ADDRESSES
#define RDATA    	 0x10
#define WREG       0x40
#define RREG       0x20
#define RESET      0x06
#define START_SYNC 0x08
#define SPI_MASTER_DUMMY 0xFF

/* ADS1220 Register 0 Definition */
/*   Bit 7   |   Bit 6   |   Bit 5   |   Bit 4   |   Bit 3   |   Bit 2   |   Bit 1   |   Bit 0 
//--------------------------------------------------------------------------------------------
//                     MUX [3:0]                 |             GAIN[2:0]             | PGA_BYPASS
*/
/* Define MUX */
#define ADS1220_MUX_0_1   	0x00
#define ADS1220_MUX_0_2   	0x10
#define ADS1220_MUX_0_3   	0x20
#define ADS1220_MUX_1_2   	0x30
#define ADS1220_MUX_1_3   	0x40
#define ADS1220_MUX_2_3   	0x50
#define ADS1220_MUX_1_0   	0x60
#define ADS1220_MUX_3_2   	0x70
#define ADS1220_MUX_0_G		  0x80
#define ADS1220_MUX_1_G   	0x90
#define ADS1220_MUX_2_G   	0xa0
#define ADS1220_MUX_3_G   	0xb0
#define ADS1220_MUX_EX_VREF 0xc0
#define ADS1220_MUX_AVDD   	0xd0
#define ADS1220_MUX_DIV2   	0xe0
/* Define GAIN */
#define ADS1220_GAIN_1      0x00
#define ADS1220_GAIN_2      0x02
#define ADS1220_GAIN_4      0x04
#define ADS1220_GAIN_8      0x06
#define ADS1220_GAIN_16     0x08
#define ADS1220_GAIN_32     0x0a
#define ADS1220_GAIN_64     0x0c
#define ADS1220_GAIN_128    0x0e
/* Define PGA_BYPASS */
#define ADS1220_PGA_BYPASS 	0x01

/* ADS1220 Register 1 Definition */
/*   Bit 7   |   Bit 6   |   Bit 5   |   Bit 4   |   Bit 3   |   Bit 2   |   Bit 1   |   Bit 0 
//--------------------------------------------------------------------------------------------
//                DR[2:0]            |      MODE[1:0]        |     CM    |     TS    |    BCS
*/
/* Define DR (data rate) */
#define ADS1220_DR_20		0x00
#define ADS1220_DR_45		0x20
#define ADS1220_DR_90		0x40
#define ADS1220_DR_175		0x60
#define ADS1220_DR_330		0x80
#define ADS1220_DR_600		0xa0
#define ADS1220_DR_1000		0xc0

/* Define MODE of Operation */
#define ADS1220_MODE_NORMAL 0x00
#define ADS1220_MODE_DUTY	0x08
#define ADS1220_MODE_TURBO 	0x10
#define ADS1220_MODE_DCT	0x18
/* Define CM (conversion mode) */
#define ADS1220_CC			0x04
/* Define TS (temperature sensor) */
#define ADS1220_TEMP_SENSOR	0x02
/* Define BCS (burnout current source) */
#define ADS1220_BCS			0x01
/* ADS1220 Register 2 Definition */
/*   Bit 7   |   Bit 6   |   Bit 5   |   Bit 4   |   Bit 3   |   Bit 2   |   Bit 1   |   Bit 0 
//--------------------------------------------------------------------------------------------
//         VREF[1:0]     |        50/60[1:0]     |    PSW    |             IDAC[2:0]
*/
/* Define VREF */
#define ADS1220_VREF_INT	0x00
#define ADS1220_VREF_EX_DED	0x40
#define ADS1220_VREF_EX_AIN	0x80
#define ADS1220_VREF_SUPPLY	0xc0
/* Define 50/60 (filter response) */
#define ADS1220_REJECT_OFF	0x00
#define ADS1220_REJECT_BOTH	0x10
#define ADS1220_REJECT_50	0x20
#define ADS1220_REJECT_60	0x30
/* Define PSW (low side power switch) */
#define ADS1220_PSW_SW		0x08
/* Define IDAC (IDAC current) */
#define ADS1220_IDAC_OFF	0x00
#define ADS1220_IDAC_10		0x01
#define ADS1220_IDAC_50		0x02
#define ADS1220_IDAC_100	0x03
#define ADS1220_IDAC_250	0x04
#define ADS1220_IDAC_500	0x05
#define ADS1220_IDAC_1000	0x06
#define ADS1220_IDAC_2000	0x07
/* ADS1220 Register 3 Definition */
/*   Bit 7   |   Bit 6   |   Bit 5   |   Bit 4   |   Bit 3   |   Bit 2   |   Bit 1   |   Bit 0 
//--------------------------------------------------------------------------------------------
//               I1MUX[2:0]          |               I2MUX[2:0]          |   DRDYM   | RESERVED
*/
/* Define I1MUX (current routing) */
#define ADS1220_IDAC1_OFF	0x00
#define ADS1220_IDAC1_AIN0	0x20
#define ADS1220_IDAC1_AIN1	0x40
#define ADS1220_IDAC1_AIN2	0x60
#define ADS1220_IDAC1_AIN3	0x80
#define ADS1220_IDAC1_REFP0	0xa0
#define ADS1220_IDAC1_REFN0	0xc0
/* Define I2MUX (current routing) */
#define ADS1220_IDAC2_OFF	0x00
#define ADS1220_IDAC2_AIN0	0x04
#define ADS1220_IDAC2_AIN1	0x08
#define ADS1220_IDAC2_AIN2	0x0c
#define ADS1220_IDAC2_AIN3	0x10
#define ADS1220_IDAC2_REFP0	0x14
#define ADS1220_IDAC2_REFN0	0x18
/* define DRDYM (DOUT/DRDY behaviour) */
#define ADS1220_DRDY_MODE	0x02


// RTD Coefficients

#define A 0.00391
#define B -0.000000578
#define R100 100 

// Function declaration

void GPIO_Init(void);
void SPI1_init(void);
void USART2_Init(void);
void USART_write(int ch);
void DelayTimerUs(int n);
unsigned char SPI_Write(unsigned char data);
void SPI_Send(unsigned char byte);
unsigned char SPI_Receive(void);
unsigned char SPI_Send_Receive(unsigned char byte);
void Write_Register(unsigned char addr, unsigned char data);
unsigned char Read_register(unsigned char addr);
int32_t Read_ADC (void);
void ADS_Init(void);
float CodeToRtd(int32_t code);
float RtdToTemperature(float rtd);


#endif /*ADS1220_H_*/
