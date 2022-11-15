#include <ME218_C32.h>
#include <ADS12.h>
#include "PennyInsertion.h"

 
void PennyPinInit(void)
{  
    //AD0 is input "I"
    ADS12_Init(ADPinInitString);    
}


//------------------------------------------------

int CheckIfPennyIn(void)
{
    
    //--------------------------------------------
    //return 1 if detect a penny;
    //return 0 if no penny detected
  	//penny pin=AD0
    //if this pin gives a 5V output-->yes penny in, 
    // signal will be positive value  
    //--------------------------------------------
    
    int signal=PTIAD & BIT0HI; 
    
    if (signal > 0)
    {
        return 1;	 //penny in
    } 
    else 
        return 0;    //penny not in
}

