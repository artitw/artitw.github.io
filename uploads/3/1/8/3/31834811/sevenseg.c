#include "SevenSeg.h"
#include <stdio.h>
#include <ME218_C32.h>
#include <ADS12.h>


#define PULSE_TIME 100

//Priviate Prototypes
static void PulseCP(char WhichDisp);		    
static void ShiftIn(char NewElement, char WhichDisp);
static void ResetBothLEDs(void);


//Public Prototypes
void InitSevenSeg(void)
{
		
    //set T4,5,6,7 as output pins
    DDRT = DDRT | 0xF0; //0xF0 = 11110000
		
    //set AD1, 2 as output pins
    if(ADS12_Init("OOOOAOOI") == ADS12_OK)
    ResetBothLEDs();
      
   
    return;
}

void PrintToSevenSeg(int NumToDisplay, char WhichDisp)
{
    ResetBothLEDs();
    switch(NumToDisplay)
    {
     case 0:
          ShiftIn('1', WhichDisp);
          ShiftIn('1', WhichDisp);
          ShiftIn('1', WhichDisp);
          ShiftIn('0', WhichDisp);
          ShiftIn('0', WhichDisp);
          ShiftIn('1', WhichDisp);
          ShiftIn('1', WhichDisp);
          ShiftIn('1', WhichDisp);
          break;
    
     case 1:
          ShiftIn('1', WhichDisp);
          ShiftIn('0', WhichDisp);
          ShiftIn('0', WhichDisp);
          ShiftIn('0', WhichDisp);
          ShiftIn('0', WhichDisp);
          ShiftIn('1', WhichDisp);
          ShiftIn('0', WhichDisp);
          ShiftIn('0', WhichDisp);
          break;
     
     case 2:
          ShiftIn('1', WhichDisp);
          ShiftIn('1', WhichDisp);
          ShiftIn('0', WhichDisp);
          ShiftIn('1', WhichDisp);
          ShiftIn('0', WhichDisp);
          ShiftIn('0', WhichDisp);
          ShiftIn('1', WhichDisp);
          ShiftIn('1', WhichDisp);
          break;
     
     case 3:
          ShiftIn('1', WhichDisp);
          ShiftIn('1', WhichDisp);
          ShiftIn('0', WhichDisp);
          ShiftIn('1', WhichDisp);
          ShiftIn('0', WhichDisp);
          ShiftIn('1', WhichDisp);
          ShiftIn('1', WhichDisp);
          ShiftIn('0', WhichDisp);
          break;
     
     case 4:
          ShiftIn('1', WhichDisp);
          ShiftIn('0', WhichDisp);
          ShiftIn('1', WhichDisp);
          ShiftIn('1', WhichDisp);
          ShiftIn('0', WhichDisp);
          ShiftIn('1', WhichDisp);
          ShiftIn('0', WhichDisp);
          ShiftIn('0', WhichDisp);
          break;
     
     case 5:
          ShiftIn('0', WhichDisp);
          ShiftIn('1', WhichDisp);
          ShiftIn('1', WhichDisp);
          ShiftIn('1', WhichDisp);
          ShiftIn('0', WhichDisp);
          ShiftIn('1', WhichDisp);
          ShiftIn('1', WhichDisp);
          ShiftIn('0', WhichDisp);
          break;
     
     case 6:
          ShiftIn('0', WhichDisp);
          ShiftIn('1', WhichDisp);
          ShiftIn('1', WhichDisp);
          ShiftIn('1', WhichDisp);
          ShiftIn('0', WhichDisp);
          ShiftIn('1', WhichDisp);
          ShiftIn('1', WhichDisp);
          ShiftIn('1', WhichDisp);
          break;
     
     case 7:
          ShiftIn('1', WhichDisp);
          ShiftIn('1', WhichDisp);
          ShiftIn('0', WhichDisp);
          ShiftIn('0', WhichDisp);
          ShiftIn('0', WhichDisp);
          ShiftIn('1', WhichDisp);
          ShiftIn('0', WhichDisp);
          ShiftIn('0', WhichDisp);
          break;
     
     case 8:
          ShiftIn('1', WhichDisp);
          ShiftIn('1', WhichDisp);
          ShiftIn('1', WhichDisp);
          ShiftIn('1', WhichDisp);
          ShiftIn('0', WhichDisp);
          ShiftIn('1', WhichDisp);
          ShiftIn('1', WhichDisp);
          ShiftIn('1', WhichDisp);
          break;
     
     case 9:
          ShiftIn('1', WhichDisp);
          ShiftIn('1', WhichDisp);
          ShiftIn('1', WhichDisp);
          ShiftIn('1', WhichDisp);
          ShiftIn('0', WhichDisp);
          ShiftIn('1', WhichDisp);
          ShiftIn('1', WhichDisp);
          ShiftIn('0', WhichDisp);
          break;
          
    }

    return;
}


//Private Prototypes


//at the moment pulse CP will only pulse
//LED1, CP  - T7
//      DS1 - T6
//LED2, CP  - T5
//      DS1 - T4
static void PulseCP(char WhichDisp)
{
     	if (WhichDisp == '1')
     	{
     	     
     		//set CP pin high
     		int k;
     		PTT = PTT | BIT7HI;
     		for (k=1 ; k< PULSE_TIME ; k++)
     		{
     		    //waste time
     		}
     	  
     		//set CP pin low
     		PTT = PTT & BIT7LO;
     		for (k=1 ; k< PULSE_TIME ; k++)
     		{
     		    //waste time
     		}
     	}
     	
     	if (WhichDisp == '2')
     	{
     	      
     		//set CP pin high
     		int k;
     		PTT = PTT | BIT5HI;
     		for (k=1 ; k< PULSE_TIME ; k++)
     		{
     		    //waste time
     		}
     	  
     		//set CP pin low
     		PTT = PTT & BIT5LO;
     		for (k=1 ; k< PULSE_TIME ; k++)
     		{
     		    //waste time
     		}
     	
     	}
		return;
}

static void ShiftIn(char NewElement, char WhichDisp)
{
		if (WhichDisp == '1')
		{
     		
     		//set MR to high
     		PTAD = PTAD | BIT1HI;
     		if(NewElement == '1')
     		{
     		     //SET DS1 high
     			PTT = PTT | BIT6HI; 
     			//pulse CP
     			PulseCP(WhichDisp);
     		}
     		
     		if(NewElement == '0')
     		{
     		    //set DS1 low
     		    PTT = PTT & BIT6LO;
     		    //pulse CP
     		    PulseCP(WhichDisp);
     		}
		}
		
		if (WhichDisp == '2')
		{
     		//set MR to high 
     		PTAD = PTAD | BIT2HI;
     		if(NewElement == '1')
     		{
     		     //SET DS1 high
     			PTT = PTT | BIT4HI; 
     			//pulse CP
     			PulseCP(WhichDisp);
     		}
     		
     		if(NewElement == '0')
     		{
     		    //set DS1 low
     		    PTT = PTT & BIT4LO;
     		    //pulse CP
     		    PulseCP(WhichDisp);
     		}		
				
		}
		
          return;
}


//LED 1: MR - AD1
//LED 2: MR - AD2
static void ResetBothLEDs(void)
{
    //resets all the pins to LOW for BOTH seven seg LEDs, essentially turns off everything
    //set CP pin low
		int k;
		PTAD = PTAD & BIT1LO;    //resetting SevenSeg #1
		PTAD = PTAD & BIT2LO;    //resetting SevenSeg #2   
		for (k=1 ; k< PULSE_TIME ; k++)
		{
		    //waste time
		}

}
