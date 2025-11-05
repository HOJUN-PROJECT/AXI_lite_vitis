#include "ap.h"
#include "sleep.h"

hLed downLed;

void ap_main()
{

   initPowerInd();
   initUpCounter();

   while(1)
   {
//      FND_DispNumber(counter++);
//      counter++;
      dispPowerInd();
      runUpCounter();

      ISR();
   }

}
//    while(1)
//      {
//         static int init = 0;
//         if (!init) { counter = 0; init = 1; }
//
//
//         for (int i = 0; i < 1000; i++)
//         {
//            FND_DispNumber(counter);
//
//            if (i < 250) {
//               LED_On(&powerLed);
//               LED_Off(&upLed);
//               LED_Off(&downLed);
//            } else if (i < 500) {
//               LED_Off(&powerLed);
//               LED_On(&upLed);
//               LED_Off(&downLed);
//            } else if (i < 750) {
//               LED_Off(&powerLed);
//               LED_Off(&upLed);
//               LED_On(&downLed);
//            } else {
//               LED_Off(&powerLed);
//               LED_Off(&upLed);
//               LED_Off(&downLed);
//            }
//            usleep(500);
//         }
//         counter = (counter + 1) % 10000;
//      }
//

void ISR() // Interrupt Service Routine
{
   millisCounter();

   FND_DispNumber();
}

void millisCounter()
{
   incMillis();
   usleep(1000);
}







