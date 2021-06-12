//#define LIGHTFISH_TEST
#include "LightFish.h"
#include <ME218_C32.h>
#include <ADS12.h>
#include <string.h>


#define PULSE_TIME 500
#define AD12_INIT_STRING "OOOOAOOI"


//private prototypes
static void ResetAllLEDs(void);
static void ShiftIn(char NewElement);
static void PulseCP(void);

void InitLightFish(void) 
{
	//set AD5,6,7 as output pins
    if(ADS12_Init(AD12_INIT_STRING) == ADS12_OK)
    ResetAllLEDs();
    return;
}

void LightFish(char LightConfig[]) 
{
    int k;
    ResetAllLEDs();
    //always shift in two zeroes first
    //the last two output pins on the shift registered are un-used
    ShiftIn('0');
    ShiftIn('0');
    
    //Shift in HI or LO according to the string
    for(k=0;k<6;k++)
    {
        if(LightConfig[k]=='1')
        {
            ShiftIn('1');
        }
        else
        {
            ShiftIn('0');
        }
    }
   
    return;
}

static void ShiftIn(char NewElement) 
{
    //set MR to high
    PTAD = PTAD | BIT7HI;
    if(NewElement == '1')
    {
          //SET DS1 high
     	  PTAD = PTAD | BIT6HI; 
     	  //pulse CP
     	  PulseCP();
    }
     		
    if(NewElement == '0')
    {
          //set DS1 low
          PTAD = PTAD & BIT6LO;
          //pulse CP
          PulseCP();
    }  
}

static void PulseCP(void) 
{
  
		 //set CP pin high
     int k;
     PTAD = PTAD | BIT5HI;
     for (k=1 ; k< PULSE_TIME ; k++)
     {
         //waste time
     }
     	  
     //set CP pin low
     PTAD = PTAD & BIT5LO;
     for (k=1 ; k< PULSE_TIME ; k++)
     {
         //waste time
     }
}

static void ResetAllLEDs(void) 
{
    int k;
		PTAD = PTAD & BIT7LO;    //resetting all fish LED to low
		for (k=1 ; k< PULSE_TIME ; k++)
		{
		    //waste time
		}

}

#ifdef LIGHTFISH_TEST
//TEST MODULE
//This test module does that following:
//1. Lights up all fish
//2. Lights up fish #1
//3. Lights up fish #2
//4. Lights up fish #3
//5. Lights up fish #4
//6. Lights up fish #5
//7. Lights up fish #6

#include <timers12.h>
void main(void){
    
    int time0;
    
    TMRS12_Init(TMRS12_RATE_1MS);
    
    InitLightFish();

    beginning:
        
    LightFish("111111");
    time0 = TMRS12_GetTime();
    while( TMRS12_GetTime()-time0 < 2000);
    
    LightFish("100000");
    time0 = TMRS12_GetTime();
    while( TMRS12_GetTime()-time0 < 2000);
   
    LightFish("010000");
    time0 = TMRS12_GetTime();
    while( TMRS12_GetTime()-time0 < 2000);
    
    LightFish("001000");
    time0 = TMRS12_GetTime();
    while( TMRS12_GetTime()-time0 < 2000);
    
    LightFish("000100");
    time0 = TMRS12_GetTime();
    while( TMRS12_GetTime()-time0 < 2000);
    
    LightFish("000010");
    time0 = TMRS12_GetTime();
    while( TMRS12_GetTime()-time0 < 2000);
    
    LightFish("000001");
    time0 = TMRS12_GetTime();
    while( TMRS12_GetTime()-time0 < 2000);
    
    goto beginning;
    
    return;

}

#endif