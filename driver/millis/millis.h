/*
 * miillis.h
 *
 *  Created on: 2025. 11. 5.
 *      Author: kccistc
 */

#ifndef SRC_DRIVER_COMMON_MILLIS_H_
#define SRC_DRIVER_COMMON_MILLIS_H_

#include <stdint.h>
#include "../../device/timer/timer.h"

void Millis_Init(Timer_TypeDef *tmr);
void incMillis();
void clearMillis();
void setMillis(uint32_t t);
uint32_t millis();


#endif /* SRC_DRIVER_COMMON_MILLIS_H_ */
