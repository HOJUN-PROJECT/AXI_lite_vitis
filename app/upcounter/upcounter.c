#include "upCounter.h"

int counter = 0;
hLed upLed;
hLed downLed;

void initUpCounter()
{
   FND_Init();
   LED_Init(&upLed, LED_GPIO, LED_1);
   LED_Init(&downLed, LED_GPIO, LED_2);
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

void clearUpCounter()
{
   counter = 0;
}
