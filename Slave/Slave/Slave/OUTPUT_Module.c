/*
 * OUTPUT_Module.c
 *
 * Created: 8/7/2021 10:20:07 PM
 *  Author: mohamed magdy - nouran saad
 */ 


#include "OUTPUT_Module.h"

LED0_Initialize(void)
{
	DIO_SetPin_Direction(LED0_DDR, LED0, LED_OUTPUT);
}

LED0_ON(void)
{
	DIO_SetPin_State(LED0_PRT, LED0, LED_HIGH);
}
LED0_OFF(void)
{
	DIO_SetPin_State(LED0_PRT, LED0, LED_LOW);
}
LED0_Toggle(void)
{
	DIO_TglPin_State(LED0_PRT, LED0);
}

LED1_Initialize(void)
{
	DIO_SetPin_Direction(LED1_DDR, LED1, LED_OUTPUT);
}

LED1_ON(void)
{
	DIO_SetPin_State(LED1_PRT, LED1, LED_HIGH);
}
LED1_OFF(void)
{
	DIO_SetPin_State(LED1_PRT, LED1, LED_LOW);
}
LED1_Toggle(void)
{
	DIO_TglPin_State(LED1_PRT, LED1);
}

LED2_Initialize(void)
{
	DIO_SetPin_Direction(LED2_DDR, LED2, LED_OUTPUT);
}

LED2_ON(void)
{
	DIO_SetPin_State(LED2_PRT, LED2, LED_HIGH);
}
LED2_OFF(void)
{
	DIO_SetPin_State(LED2_PRT, LED2, LED_LOW);
}
LED2_Toggle(void)
{
	DIO_TglPin_State(LED2_PRT, LED2);
}

BUZZER_Initialize(void)
{
	DIO_SetPin_Direction(BUZZER_DDR, BUZZER, BUZZER_OUTPUT);
}

BUZZER_ON(void)
{
	DIO_SetPin_State(BUZZER_PRT, BUZZER, BUZZER_HIGH);
}
BUZZER_OFF(void)
{
	DIO_SetPin_State(BUZZER_PRT, BUZZER, BUZZER_LOW);
}
BUZZER_Toggle(void)
{
	DIO_TglPin_State(BUZZER_PRT, BUZZER);
}

RELAY_Initialize(void)
{
	DIO_SetPin_Direction(RELAY_DDR, RELAY, RELAY_OUTPUT);
}

RELAY_ON(void)
{
	DIO_SetPin_State(RELAY_PRT, RELAY, RELAY_HIGH);
}
RELAY_OFF(void)
{
	DIO_SetPin_State(RELAY_PRT, RELAY, RELAY_LOW);
}
RELAY_Toggle(void)
{
	DIO_TglPin_State(RELAY_PRT, RELAY);
}
