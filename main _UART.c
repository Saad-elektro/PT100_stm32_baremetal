#include "stm32f10x.h"                  // Device header
#include "ADS1220.h"
#include "printf.h"
#include <math.h>


int main (void){
	
	unsigned char reg0 ,reg1, reg2,reg3  ;
	int32_t Raw_Code;
	volatile float Rtd_Value;
  volatile float temp;
	
	GPIO_Init();
	USART_Init();
	USART2_Init();
	GPIOA->BSRR |= GPIO_BSRR_BR4; // Set CS Low
	
	

  ADS_Init();
	
	// Write registers
	GPIOA->BSRR |= GPIO_BSRR_BR4; // Set CS Low 	

	DelayTimerUs(2);

	Write_Register(config_REG0_ADDR, 0x08); 
  DelayTimerUs(2);
  Write_Register(config_REG1_ADDR, 0x04);
  DelayTimerUs(2);
  Write_Register(config_REG2_ADDR, 0x54);
  DelayTimerUs(2);
	Write_Register(config_REG3_ADDR, 0x70); 
	DelayTimerUs(2);

	
  
	// Read back all configurations registers
  DelayTimerUs(2);
  GPIOA->BSRR |= GPIO_BSRR_BR4; // Set CS Low 	
	 DelayTimerUs(2);
	 
/*	 
	// Solution 1---------------- 
  SPI_Send(RREG|0x00<<2);
	//DelayTimerUs(2);
	reg0 = SPI_Receive();
	reg0 = SPI_Receive();
//-------------------------------	
*/

  reg0 = Read_register(config_REG0_ADDR);
	DelayTimerUs(5);
	
  reg1 = Read_register(config_REG1_ADDR);
  DelayTimerUs(5);
	
  reg2 = Read_register(config_REG2_ADDR);
  DelayTimerUs(5);
	
  reg3 = Read_register(config_REG3_ADDR);
  DelayTimerUs(5);

	
	// Pseudo_Code part 2
	
	GPIOA->BSRR |= GPIO_BSRR_BR4; // Set CS Low 	

  SPI_Send(START_SYNC); // Start conversion
  DelayTimerUs(0.1); // wait 30ns
  GPIOA->BSRR |= GPIO_BSRR_BS4; // clear SPI interface --> Set CS high
	
	printf_( "%s \n" ,"----SPI TEST----");
	GPIOA->BSRR |= GPIO_BSRR_BR4; // Set CS Low
	
	while(1){
	/*
		// Read back Register values
		
	  printf_( "0x%02x \n" ,reg0);
    DelayTimerUs(1000000);
    printf_( "0x%02x \n" ,reg1);
   DelayTimerUs(1000000);
   printf_( "0x%02x \n" ,reg2);
   DelayTimerUs(1000000);
	 
   printf_( "0x%02x\n" ,reg3);
   DelayTimerUs(1000000);

*/
		
		GPIOA->BSRR |= GPIO_BSRR_BR4; // Set CS Low 
		DelayTimerUs(100);
		Raw_Code = Read_ADC();
		DelayTimerUs(100);
		Rtd_Value = CodeToRtd(Raw_Code);
		DelayTimerUs(100);
		temp = RtdToTemperature(Rtd_Value);
		DelayTimerUs(100);
		
		printf_(" Raw_Code %d \n\r", Raw_Code);
		DelayTimerUs(2000000);
		DelayTimerUs(2000000);
		DelayTimerUs(2000000);
		
		printf_(" RTD_Value %.4f Ohms \n\r", Rtd_Value);
		DelayTimerUs(2000000);
		DelayTimerUs(2000000);
		
		printf_(" Temperature %.4f °C \n\r",  temp ) ;
		DelayTimerUs(2000000);
		DelayTimerUs(2000000);
		DelayTimerUs(2000000);
		
//--------------------	
	
	
	}
	
}