//#define SOUNDEFFECT_TEST

#include <ME218_C32.h>
#include <stdio.h> 
#include <pwms12.h>
#include "SoundEffect.h"
 
#define PULSE_TIME  65000 


void SayILoveYou(void)
{
    unsigned int i=0;
    PWMS12_SetDuty(PWMS12_MIN_DC, PWMS12_CHAN1);  //give T1 a pulse
    for (i=0 ; i < PULSE_TIME ; i++); //pulse time
    PWMS12_SetDuty(PWMS12_MAX_DC, PWMS12_CHAN1);  //set T1 to 5v

}


void SoundEffectInit(void)
{

    PWMS12_SetDuty(PWMS12_MAX_DC, PWMS12_CHAN1);
}



#ifdef SOUNDEFFECT_TEST

#include <timers12.h>

#define PWMS12_PER            0x3032         //600Hz PWM frequency

void main()
{ 

    int time0;
    
    TMRS12_Init(TMRS12_RATE_1MS);
       
    PWMS12_Init();  //Initiliaze PWM 500Hz, 1% res, 0% DC
    					    
    //Set period to 1000us
    if(PWMS12_SetPeriod(PWMS12_PER, PWMS12_GRP1) == PWMS12_ERR)
    {
        puts("ERROR: PWMS12_SetPeriod not successful!\r\n");
    }
    
    SoundEffectInit();
    
    while(1)
    {
        time0 = TMRS12_GetTime();
        while( TMRS12_GetTime()-time0 < 2000);
        SayILoveYou();
    }
    
    return; 
}

#endif  //SOUNDEFFECT_H