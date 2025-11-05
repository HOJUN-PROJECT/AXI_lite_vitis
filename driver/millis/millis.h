#ifndef SRC_DRIVER_COMMON_MILLIS_H_
#define SRC_DRIVER_COMMON_MILLIS_H_
#include <stdint.h>

void incMillis();
void clearMillis();
void seteMillis(uint32_t t);
uint32_t millis();

#endif /* SRC_DRIVER_COMMON_MILLIS_H_ */
