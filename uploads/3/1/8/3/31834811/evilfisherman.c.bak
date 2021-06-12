//#define TEST_EVILFISHERMAN
/* For test function */

#include <stdio.h>
#include <ME218_C32.h>
#include <ADS12.h>
#include <PWMS12.h>
#include "EvilFisherman.h"

//#define A2DINITSTRING       "OOOOAOOI"  //Set pin 3 for A/D input
//#define EVILNESSPIN         3           //For AD2
#define PWMTOADCCONVERSION    10          //2^10/100 for 10-bit A/D
#define PWMS12_PER            0x3032         //600Hz PWM frequency

//void EvilFishermanInit(void);
//void UpdateFishermanEvilness(void);



//Initializes A/D converter and PWM module.
void EvilFishermanInit(void)
{
    //Initialize A/D converter
    if(ADS12_Init(A2DINITSTRING) == ADS12_Err)
    {
       //puts("ERROR: ADS12_INIT not successful!\r\n");
        return;
    }
    
    
    PWMS12_Init();  //Initiliaze PWM 500Hz, 1% res, 0% DC
    					    
    //Set period to 1000us
    if(PWMS12_SetPeriod(PWMS12_PER, PWMS12_GRP1) == PWMS12_ERR)
    {
       // puts("ERROR: PWMS12_SetPeriod not successful!\r\n");
        return;
    }
    
    		   
   // puts("Evil Fisherman initiliazed.\r\n");
}


//Obtains ADC value from Evilness knob position and updates the PWM duty cycle accordingly.
void UpdateFishermanEvilness(void)
{
    unsigned char DC;
    short evilnessValue = ADS12_ReadADPin(EVILNESSPIN);//Obtain evilness value from potentiometer knob
 
    //printf("evilnessvalue: %d\r\n", evilnessValue);
 
    if( evilnessValue != -1)//Make sure value is valid
    {
        //Set PWM signal proportional to pot's knob turn
        DC = (unsigned char)(evilnessValue/PWMTOADCCONVERSION); 
        //printf("Calculated duty cycle: %d\r\n", DC);
        if(PWMS12_SetDuty(DC, PWMS12_CHAN2) == PWMS12_OK)
            return;
        //else
         //puts("ERROR: PWMS12_SetDuty not successful!\r\n");
    }
    //else
        //puts("ERROR: ADS12_ReadPin not successful!\r\n");    
        
}


//Turn off Evil Fisherman
void TurnOffEvilFisherman(void)
{

     PWMS12_SetDuty(PWMS12_MIN_DC, PWMS12_CHAN2);
  
}




#ifdef TEST_EVILFISHERMAN
// Test harness for this module

void main(void)
{   
    puts("Testing...\r\n");

    EvilFishermanInit();
    
    while(1)
    { 
	    UpdateFishermanEvilness(); 
	    
    }
    
    return;
}



#endif	
