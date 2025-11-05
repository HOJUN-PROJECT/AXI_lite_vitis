#include "upCounter.h"

enum {STOP, UP, CLEAR, DOWN};

int upCounterState = STOP;
int counter = 0;

hLed upLed;
hLed downLed;
hButton btnStop;
hButton btnUP;
hButton btnClear;
hButton btnDown;

void initUpCounter()
{
	upCounterState = STOP;
	counter = 0;
	FND_Init();
	LED_Init(&upLed, LED_GPIO, LED_1);
	LED_Init(&downLed, LED_GPIO, LED_2);

	Button_Init(&btnStop, BTN_GPIO, BTN_0);
	Button_Init(&btnClear, BTN_GPIO, BTN_1);
	Button_Init(&btnUP, BTN_GPIO, BTN_2);
	Button_Init(&btnDown, BTN_GPIO, BTN_3);
}

void exeUpCounter()
{
	switch (upCounterState)
	{
	case STOP:
		if (Button_getState(&btnUP) == ACT_PUSHED) {
			upCounterState = UP;
		} else if (Button_getState(&btnClear) == ACT_PUSHED) {
			upCounterState = CLEAR;
		} else if (Button_getState(&btnDown) == ACT_PUSHED) {
			upCounterState = DOWN;
		}
		break;
	case UP:
		runUpCounter();
		if (Button_getState(&btnStop) == ACT_PUSHED) {
					upCounterState = STOP;
		} else if (Button_getState(&btnDown) == ACT_PUSHED) {
			upCounterState = DOWN;
		}
		break;
	case DOWN:
		runDownCounter();
		if (Button_getState(&btnStop) == ACT_PUSHED) {
			upCounterState = STOP;
		} else if (Button_getState(&btnUP) == ACT_PUSHED) {
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
	if (curTime - prevTime < 100) return;
	prevTime = curTime;

	FND_SetNumber(counter++);

	LED_Off(&downLed);
	LED_Toggle(&upLed);
}

void runDownCounter()
{
	static uint32_t prevTime = 0;
	uint32_t curTime = millis();
	if (curTime - prevTime < 100) return;
	prevTime = curTime;

	FND_SetNumber(counter);
	if (counter == 0)
	    {
	        counter = 9999;
	    }
	    else
	    {
	        counter--;
	    }
	LED_Off(&upLed);
	LED_Toggle(&downLed);
}

void clearUpCounter()
{
	counter = 0;
	FND_SetNumber(counter);
}
