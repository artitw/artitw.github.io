#include <stdio.h>
#include <ME218_C32.h>
#include "StartPushButton.h"

//int CheckIfStartPushButtonIsPushed(void);
//void StartPushButtonInit(void);

void StartPushButtonInit(void)
{
 
 //----------------------------------------------
 //  init the T3 pin to input for start push btn 
 //----------------------------------------------  
    
 DDRT=DDRT & BIT3LO;
   
}

int CheckIfStartPushButtonIsPushed(void)
{
 
 
 
 //----------------------------------------------
 //  if yes return 1 if not return 0
 //----------------------------------------------   
  int signal=0;
  
  signal=PTT & BIT3HI;
  
  if(signal>0)
     return 1;
  
  else if ( signal ==0)
     return 0;
 
  
}
  
  
    
