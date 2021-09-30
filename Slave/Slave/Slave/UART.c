/*
* UART.c
*
* Created: 2/13/2021 9:11:14 PM
*  Author: mohamed magdy - nouran saad
*/


#include "UART.h"


void UART_Init(void)
{
	/*Baud rate value variable*/
	uint16_t UBRR_Val = 0;
	/*Enable Transmitter and Receiver bits*/
	UCSRB = (1 << RXEN) | (1 << TXEN);
	/*Full configuration for UART*/ //sending 8 bits data in frame (UCSZ1 & UCSZ0 must be =1) UCSEL =1 means we will write data in UCSRC and not UBRRH as the share same addess
	UCSRC = (1 << URSEL) | (1 << UCSZ1) | (1 << UCSZ0);
	/*Baud Rate Calculations*/
	UBRR_Val = (((FRQ) / (16 * BAUDRATE)) - 1);//11110101 00111001
	UBRRL = UBRR_Val;     //00000000 00111001
	UBRRH = UBRR_Val >> 8;//00000000 11110101
}
void UART_Transmit(uint8_t data)
{
	UDR = data;
	while (GET_BIT(UCSRA, TXC) != 1);
}
uint8_t UART_Receive(void)
{
	while (GET_BIT(UCSRA, RXC) != 1);
	return UDR;
}

void UART_Receive_String(uint8_t* ptr)  //no returb, it takes an array that gets populated inside the fn
{
	uint8_t i;
	ptr[i] = UART_Receive();
	while(ptr[i] != '#')
	{
		i++;
		ptr[i] = UART_Receive();
	}
	ptr[i] = '\0';
}