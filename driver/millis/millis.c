/*
 * millis.c
 *
 *  Created on: 2025. 11. 5.
 *      Author: kccistc
 */

#include "millis.h"

uint32_t m_counter = 0;
Timer_TypeDef *millis_timer;

void Millis_Init(Timer_TypeDef *tmr)
{
	millis_timer = tmr;
	TMR_SetPSC(millis_timer, 100000);
	TMR_SetARR(millis_timer, 0xffffffff);
	TMR_Start(millis_timer);
}

void incMillis()
{
	m_counter++;
}

void clearMillis()
{
	m_counter = 0;
}

void setMillis(uint32_t t)
{
	m_counter = t;
}

uint32_t millis()
{
	//return m_counter;
	return TMR_ReadCNT(millis_timer);
}
