/*
 * SPI_CONFIG.h
 *
 * Created: 9/10/2021 6:42:50 PM
 *  Author: mohamed magdy - nouran saad
 */ 


#ifndef SPI_CONFIG_H_
#define SPI_CONFIG_H_

//macros

#include "CPU_Configurations.h"

//registers needed
/*
#define SPCR (*(volatile Uint8t*)(0x2D))
#define SPSR (*(volatile Uint8t*)(0x2E))
#define SPDR (*(volatile Uint8t*)(0x2F))
*/
//rename port

#define SPI_PORT DIO_PORTB

//rename pins

#define MOSI 5
#define MISO 6
#define SCK 7
#define SS 4



//states

#define SPI_Master 1
#define SPI_Slavee 0
#define SPI_Mode SPI_Master






#endif /* SPI_CONFIG_H_ */