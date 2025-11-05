#ifndef SRC_AP_AP_H_
#define SRC_AP_AP_H_

#include "../driver/led/led.h"
#include "../driver/fnd/fnd.h"
#include "../driver/common/millis.h"
#include "powerind/powerind.h"
#include "upCounter/upCounter.h"
#include "../driver/btn/btn.h"

void ap_main();
void millisCounter();
void ISR();

#endif /* SRC_AP_AP_H_ */
