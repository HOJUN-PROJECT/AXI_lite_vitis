/*
 * ap.c
 *
 *  Created on: 2025. 11. 4.
 *      Author: kccistc
 */


#include "ap.h"
#include "sleep.h"
#include "../driver/btn/btn.h"
#include "../driver/common/millis.h"
#include "../device/timer/timer.h"
#include "xintc.h"
#include "xil_exception.h"
#include "xparameters.h"

hButton upBtn;
hLed led0;

void intc_init();
void TIMER_IntrInit();
void ISR();

XIntc intc;


void ap_main()
{


	initPowerInd();
	initUpCounter();



	Millis_Init(TMR1);
	intc_init();
	TIMER_IntrInit();

	while(1)
	{

		dispPowerInd();
		exeUpCounter();

	}
}

void intc_init()
{
	int status = XIntc_Initialize(&intc, XPAR_INTC_0_DEVICE_ID);
	if(status == XST_SUCCESS)
	{
		xil_printf("INTC Init Successful!\n");
	} else {
		xil_printf("INTC Init Fail!\n");
	}
	status = XIntc_SelfTest(&intc);
	if(status == XST_SUCCESS)
	{
		xil_printf("INTC SelfTest Successful!\n");
	} else {
		xil_printf("INTC SelfTest Fail!\n");
	}

	///////////////////////////////////////////////////////////////
	// Initailize and Enable Exception handler
	//////////////////////////////////////////////////////////////
	Xil_ExceptionInit();
	Xil_ExceptionRegisterHandler(XIL_EXCEPTION_ID_INT, (Xil_ExceptionHandler)XIntc_InterruptHandler, &intc);
	Xil_ExceptionEnable();

	// function pointer connect
	XIntc_Connect(&intc, XPAR_INTC_0_TIMER_0_VEC_ID, (XInterruptHandler)ISR, 0);
	XIntc_Enable(&intc, XPAR_INTC_0_TIMER_0_VEC_ID);

	// enable global interrupt
	XIntc_Start(&intc, XIN_REAL_MODE);
}

void TIMER_IntrInit()
{
	TMR_SetPSC(TMR0, 100);
	TMR_SetARR(TMR0, 1000);
	TMR_Start(TMR0);
	TMR_IntrStart(TMR0);
}
void ISR()	// Interrupt Service Routine
{
	FND_DispNumber();
}


void millisCounter()
{
	incMillis();
}
