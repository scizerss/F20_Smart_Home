/*
 * Slave.c
 *
 * Created: 9/26/2021 2:25:23 PM
 * Author : mohamed magdy - nouran saad
 */ 

#include "LCD.h"
#include "UART.h"
#include "OUTPUT_Module.h"
#include "SPI.h"

int main(void)
{
	uint8_t dataReceived;    //data received from spi
	LCD_Init();
	LCD_CLEAR();
	LED0_Initialize();
	LED1_Initialize();
	LED2_Initialize();
	SPI_Slave_Init();     //initialized as slave
	LCD_CLEAR();
	LCD_WRITE_STR("Slave");
	_delay_ms(1000);
	LCD_CLEAR();
	
    while (1) 
    {
		dataReceived=SPI_Rx();
		_delay_ms(10);
		switch (dataReceived)              //we receive data that takes value from 1-7 and we check on the
		{
			case 1:                       //if value is 1, we call fn led1_on and write it on the LCD
			LCD_CLEAR();
			LCD_WRITE_STR("led0 on");
			LED0_ON();
			dataReceived=0;               //clear data receive to prepare for the next instruction
			break;              
			
			case 2:
			LCD_CLEAR();
			LCD_WRITE_STR("led0 off");
			LED0_OFF();
			dataReceived=0;
			break;
			
			case 3:
			LCD_CLEAR();
			LCD_WRITE_STR("led1 on");
			LED1_ON();
			dataReceived=0;
			break;
			
			case 4:
			LCD_CLEAR();
			LCD_WRITE_STR("led1 off");
			LED1_OFF();
			dataReceived=0;
			break;
			
			case 5:
			LCD_CLEAR();
			LCD_WRITE_STR("led2 on");
			LED2_ON();
			dataReceived=0;
			break;
			
			case 6:
			LCD_CLEAR();
			LCD_WRITE_STR("led2 off");
			LED2_OFF();
			dataReceived=0;
			break;
			
			case 7:                    //if data received is '7', means user entered invalid string
			LCD_CLEAR();
			LCD_WRITE_STR("invalid entry");
			dataReceived=0;
			break;
			
	
		
		}
    }
	return 0;
}

