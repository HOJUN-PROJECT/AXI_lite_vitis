#ifndef SRC_AP_UPCOUNTER_UPCOUNTER_H_
#define SRC_AP_UPCOUNTER_UPCOUNTER_H_
#include <stdint.h>
#include "../../driver/fnd/fnd.h"
#include "../../driver/led/led.h"
#include "../../driver/common/millis.h"


void initUpCounter();
void runUpCounter();
void clearUpCounter();

#endif /* SRC_AP_UPCOUNTER_UPCOUNTER_H_ */
