#include "ap.h"
#include "sleep.h"

#include "../driver/btn/btn.h"
#include "powerind/powerind.h"
#include "../driver/fnd/fnd.h"
#include "../driver/btn/btn.h"
#include "upcounter/upcounter.h"

hLed powerLed;
hLed upLed;
hLed downLed;
hLed togLed;

hButton upBtn;

void ap_main(){
   LED_Init(&powerLed, LED_GPIO, LED_0);
   LED_Init(&upLed, LED_GPIO, LED_1);
   LED_Init(&downLed, LED_GPIO, LED_2);
   LED_Init(&togLed, LED_GPIO, LED_3);

   FND_Init();
   Button_Init(&upBtn, GPIOC, GPIO_PIN_0);
   initPowerInd();
   initUpCounter();

   while(1)
   {
      dispPowerInd();
//      runUpCounter();
      //btnLedOn();
//      if(Button_getState(&upBtn)==ACT_RELEASED){
//         LED_Toggle(&powerLed);
//      }
      exeUpCounter();
      ISR();
   }
}


void ISR()
{
   millisCounter();

   FND_DispNumber();
}

void millisCounter()
{
   incMillis();
   usleep(1000);
}
