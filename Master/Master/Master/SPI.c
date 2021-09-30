/*
* SPI.c
*
* Created: 9/10/2021 6:56:09 PM
*  Author: mohamed magdy - nouran saad
*/


#include "SPI.h"

/*void SPI_Init(void)
{
#if SPI_Mode == SPI_Master

//set pin direction

SET_BIT(DDRB,MOSI);
CLR_BIT(DDRB,MISO);
SET_BIT(DDRB,SCK);
SET_BIT(DDRB,SS);

//enable SPI

SET_BIT(SPCR,SPE);

//data order LSB 1st

SET_BIT(SPCR,DORD);

//enable master mode

SET_BIT(SPCR,MSTR);

//master sets clk at freq/128

CLR_BIT(SPSR,SPI2X); SET_BIT(SPCR,SPR1); SET_BIT(SPCR,SPR0);



#elif SPI_Mode == SPI_Slave


//set pin direction

CLR_BIT(DDRB,MOSI);
SET_BIT(DDRB,MISO);
CLR_BIT(DDRB,SCK);
CLR_BIT(DDRB,SS);

//enable SPI

SET_BIT(SPCR,SPE);

//data order LSB 1st

SET_BIT(SPCR,DORD);

//disable master mode

CLR_BIT(SPCR,MSTR);


#endif



} */



void SPI_Master_Init(void){
	
	//set pin direction
	
	SET_BIT(DDRB,MOSI);
	CLR_BIT(DDRB,MISO);
	SET_BIT(DDRB,SCK);
	SET_BIT(DDRB,SS);
	
	//enable SPI
	
	/*SET_BIT(SPCR,SPE);
	
	//data order LSB 1st
	
	SET_BIT(SPCR,DORD);
	
	//enable master mode
	
	SET_BIT(SPCR,MSTR);
	
	//master sets clk at freq/128
	
	CLR_BIT(SPSR,SPI2X); SET_BIT(SPCR,SPR1); SET_BIT(SPCR,SPR0);
	
	*/
	
	SPCR=0x53; //ob 01010011
}
void SPI_Slave_Init(void){
	
	//set pin direction
	
	CLR_BIT(DDRB,MOSI);
	SET_BIT(DDRB,MISO);
	CLR_BIT(DDRB,SCK);
	CLR_BIT(DDRB,SS);
	
	/* //enable SPI
	
	SET_BIT(SPCR,SPE);
	
	//data order LSB 1st
	
	SET_BIT(SPCR,DORD);
	
	//disable master mode
	
	CLR_BIT(SPCR,MSTR);
	*/
	SPCR=0x43; //01000011
}


void SPI_Tx(uint8_t data){
	
	SPDR=data; //insert data in data register to be transmitted
	while(GET_BIT(SPSR,SPIF) !=1 ); //wait till data is transmitted, SPIF flag =1 when transfer is complete
}
uint8_t  SPI_Rx(void){
	
	uint8_t data;
	while(GET_BIT(SPSR,SPIF) !=1 ); //wait till all data in transferred
	data=SPDR;                      //data is received in SPDR (data register)
	return data;                    //return the data
	
}
void SPI_Slave(){
	
	CLR_BIT(PORTB,SS);
	
}
