/*
 * Used_functions.c
 *
 * Created: 9/26/2021 1:56:20 PM
 *  Author: mohamed magdy - nouran saad
 */ 

#include "Used_functions.h"

uint8_t Compare_String(uint8_t arr1[10], uint8_t arr2[10])
{
	uint8_t i=0;
	uint8_t flag=0;
	while((arr1[i]!='\0'))
	{
		if(arr1[i]!=arr2[i])
		{
			flag=0;
			break;
		}
		else
		{
			flag=1;
		}
		i++;
	}
	return flag;
}

void Clear_array(uint8_t arr[],uint8_t size)
{
	for(int i=0;i<size;i++)
	{
		arr[i] = 0;
	}
}