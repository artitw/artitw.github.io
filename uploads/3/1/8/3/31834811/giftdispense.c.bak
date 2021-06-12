//#define GIFTDISPENSE_TEST

#include <ME218_C32.h>
#include <PWMS12.h>
#include <TimerS12.h>
#include "GiftDispense.h"

#define PWMS12_16667US      0x40FA  // 60Hz
#define TWO_SECOND_COUNTER  2000    // 2 seocnds
#define DC_FOR_90_DEGREES   30		// duty cycle	 (20 in the beginning)
#define DC_FOR_0_DEGREE     4		// duty cycle


static void Wait(unsigned int ms);

void GiftPinInit(void)
{  
    PWMS12_Init();
    PWMS12_SetPeriod(PWMS12_16667US,PWMS12_GRP0); //16ms, 60Hz
    PWMS12_SetDuty(DC_FOR_90_DEGREES, PWMS12_CHAN0);
}

//-------------------------------------------------------

void GiftDispense(void)
{
    PWMS12_SetDuty(DC_FOR_0_DEGREE, PWMS12_CHAN0);//motor turn to 4 
    Wait(TWO_SECOND_COUNTER);    
    PWMS12_SetDuty(DC_FOR_90_DEGREES, PWMS12_CHAN0); //motor turn to 1       
    Wait(TWO_SECOND_COUNTER);
}


//-------------------------------------------------------

//Waits for given number of ms
//Assumes TMRS12_Init(TMRS12_RATE_1MS) called beforehand

static void Wait(unsigned int ms)
{
    unsigned int time0 = TMRS12_GetTime();     //Initial count
    while((TMRS12_GetTime()-time0)<ms);
}


//-------------------------------------------------------
#ifdef GIFTDISPENSE_TEST
//Test harness for this module


#include <stdio.h>


void main(void)
{
    TMRS12_Init(TMRS12_RATE_32MS);

    GiftPinInit();
    while(1)
    {
        puts("Dispense...\r\n");
        GiftDispense();	     
     
    }
    
    return;
}


#endif  //GIFTDISPENSE_TEST