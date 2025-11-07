/*
 * upCounter.c
 *
 *  Created on: 2025. 11. 5.
 *      Author: kccistc
 */

#include "upCounter.h"

enum {STOP, UP, DOWN, CLEAR};

int upCounterState = STOP;

int counter = 0;

hLed upLed;
hLed downLed;
hLed stopLed;

hButton btnUp;
hButton btnClear;
hButton btnDown;
hButton btnStop;

void initUpCounter()
{
	//	int upCounterState = STOP;
	//	int counter = 0;
	FND_Init();
	LED_Init(&upLed,	LED_GPIO, LED_1);
	LED_Init(&downLed,  LED_GPIO, LED_2);
	LED_Init(&stopLed,  LED_GPIO, LED_3);

	Button_Init(&btnUp, BUTTON_GPIO, BUTTON_0);			// UP Button
	Button_Init(&btnClear, BUTTON_GPIO, BUTTON_1);		// Left Button
	Button_Init(&btnStop, BUTTON_GPIO, BUTTON_2);		// Right Button
	Button_Init(&btnDown, BUTTON_GPIO, BUTTON_3);		// Down Button
}

void exeUpCounter()
{
	switch(upCounterState)
	{
	case STOP:
		StopCounter();
		if(Button_getState(&btnUp) == ACT_PUSHED){
			upCounterState = UP;
		}
		else if(Button_getState(&btnDown) == ACT_PUSHED){
			upCounterState = DOWN;
		}
		else if(Button_getState(&btnClear) == ACT_PUSHED){
			upCounterState = CLEAR;
		}
		break;

	case UP:
		runUpCounter();
		if(Button_getState(&btnStop) == ACT_PUSHED){
			upCounterState = STOP;
		}
		else if(Button_getState(&btnDown) == ACT_PUSHED){
			upCounterState = DOWN;
		}
		break;
	case DOWN:
		runDownCounter();
		if(Button_getState(&btnStop) == ACT_PUSHED){
			upCounterState = STOP;
		}
		else if(Button_getState(&btnUp) == ACT_PUSHED){
			upCounterState = UP;
		}
		break;

	case CLEAR:
		clearUpCounter();
		upCounterState = STOP;
		break;
	}
}

void runUpCounter()
{
	static uint32_t prevTime = 0;
	uint32_t curTime = millis();
	if(curTime - prevTime < 100) return;
	prevTime = curTime;

	FND_SetNumber(counter);
	if(counter == 9999){
		counter = 0;
	} else{
		counter++;
	}
	LED_Toggle(&upLed);
	LED_Off(&downLed);
	LED_Off(&stopLed);
}

void runDownCounter()
{
	static uint32_t prevTime = 0;
	uint32_t curTime = millis();
	if(curTime - prevTime < 100) return;
	prevTime = curTime;

	FND_SetNumber(counter);

	if(counter == 0){
		counter = 9999;
	} else{
		counter--;
	}
	counter = counter;
	LED_Toggle(&downLed);
	LED_Off(&upLed);
	LED_Off(&stopLed);
}

void StopCounter()
{
	static uint32_t prevTime = 0;
	uint32_t curTime = millis();
	if(curTime - prevTime < 100) return;
	prevTime = curTime;

	FND_SetNumber(counter);

	LED_Toggle(&stopLed);
	LED_Off(&upLed);
	LED_Off(&downLed);
}

void clearUpCounter()
{
	counter = 0;
	FND_SetNumber(counter);
}
