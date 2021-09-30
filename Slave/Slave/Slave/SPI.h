/*
 * SPI.h
 *
 * Created: 9/10/2021 6:49:18 PM
 *  Author: mohamed magdy - nouran saad
 */ 


#ifndef SPI_H_
#define SPI_H_

//macros

#include "SPI_CONFIG.h"

void SPI_Master_Init(void);
void SPI_Slave_Init(void);
void SPI_Tx(uint8_t data);
uint8_t  SPI_Rx(void);
void SPI_Slave();





#endif /* SPI_H_ */