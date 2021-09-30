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
	uint8_t x=strlen(arr1);      //get length of 1st array passedto fn (this is the  string the user entered)
	uint8_t y=strlen(arr2);     //get length of 2nd array passedto fn (this is the predefined string, ex: "led1on", "led1off",....etc)
	if (x == y)                 //we only compare strings if they have same length, so if the user entereda shorter or a longer string, it's automatically invalid and we don't enter the compare fn
	{
		while((arr2[i]!='\0'))
		{
			if(arr1[i]!=arr2[i])   //if any letter doesn't match, flag is zero and we break the fn and returns flag
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
        else                 //if the 2 stings have diff lengths, flag is zero as they don't match
		{
		flag = 0;
		return flag;
		}

	}

void Clear_array(uint8_t arr[],uint8_t size)  //fn that takes an array and its size and it clears the array
{
	for(int i=0;i<size;i++)
	{
		arr[i] = 0;
	}
}