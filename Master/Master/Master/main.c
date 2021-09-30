/*
 * Master.c
 *
 * Created: 9/26/2021 1:52:10 PM
 * Author : mohamed magdy - nouran saad
 */ 

#include "LCD.h"
#include "SPI.h"
#include "UART.h"
#include "Used_functions.h"



int main(void)
{
	//initialization
	
	LCD_Init();
	LCD_CLEAR();	
	SPI_Master_Init();   //initialized as master
	SPI_Slave();          //choose which slave
	UART_Init();
	
	uint8_t data0_on=1;         //each data corresponds to a specific LED
	uint8_t data0_off=2;        //ex: data0 >> led0
	uint8_t data1_on=3;          //ex: data1 >> led1
	uint8_t data1_off=4;         //ex: data2>> led2
	uint8_t data2_on=5;
	uint8_t data2_off=6;
	uint8_t data_invalid=7;       //in case user sent invalid data to bluetooth module, we send number '7' to the slave and it handles it
	uint8_t dataReceived;       //data received from UART
	
	uint8_t arr[10];           //array holds the string that user sends from mobile phone to bluetooth module
	LCD_CLEAR();
	LCD_WRITE_STR("Master");
	_delay_ms(1000);
	LCD_CLEAR();
	
	
    while (1) 
    {		
		
		UART_Receive_String(arr);     //fn that receives an array of characters from the UART receive
		_delay_ms(10);
		if (Compare_String(arr, "led0on"))      //fn that compares received array with "led0on" to turn led0 on
		{
			SPI_Tx(data0_on);                    //send dataon_on (previously defined) to slave via SPI
			LCD_CLEAR();
			LCD_WRITE_STR("Data transmitted"); 
			Clear_array(arr,10);                  //fn that empties the array to prepare for another instruction
		}
		else if (Compare_String(arr, "led0off"))
		{
			SPI_Tx(data0_off);
			LCD_CLEAR();
			LCD_WRITE_STR("Data transmitted");
			Clear_array(arr,10);
		}
		else if (Compare_String(arr, "led1on"))
		{
			SPI_Tx(data1_on);
			LCD_CLEAR();
			LCD_WRITE_STR("Data transmitted");
			Clear_array(arr,10);
		}
		else if (Compare_String(arr, "led1off"))
		{
			SPI_Tx(data1_off);
			LCD_CLEAR();
			LCD_WRITE_STR("Data transmitted");
			Clear_array(arr,10);
		}
		else if (Compare_String(arr, "led2on"))
		{
			SPI_Tx(data2_on);
			LCD_CLEAR();
			LCD_WRITE_STR("Data transmitted");
			Clear_array(arr,10);
		}
		else if (Compare_String(arr, "led2off"))
		{
			SPI_Tx(data2_off);
			LCD_CLEAR();
			LCD_WRITE_STR("Data transmitted");
			Clear_array(arr,10);
		}
		
		else
		
		{   
			SPI_Tx(data_invalid);         //if user send an invalid string, we send data_invalid (previously defined)to slave via SPI
			LCD_CLEAR();
			LCD_WRITE_STR("invalid entry: ");
			LCD_WRITE_CMD(0xC0);           //moves the curser to 2nd row of lcd
			LCD_WRITE_STR(arr);           //prints the invalid string the user enters on the LCD 
			Clear_array(arr,10);
			LCD_WRITE_CMD(0x80);           //moves the curser back to 1st row of lcd
		}
    }
	
	return 0;
	
}
