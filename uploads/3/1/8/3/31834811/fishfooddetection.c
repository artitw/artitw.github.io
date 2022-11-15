#include <ME218_C32.h>
#include "FishFoodDetection.h" 

  
//-----------------------------------------------   
void FishFoodDetectionPinInit(void)
{    
    //do the pin initialization
    //fish pin==M0~M5
    //be input  
    //fish number0~5
    
    DDRM=0;
      
}

//-----------------------------------------------
int GetFishSignal(int FishFoodDetectionPin)
{
  
    //static int FishSignal[6]={0,0,0,0,0,0};  
    //initially, all fish's signal(pin) is 0V
    //fish is 0,1,2,3,4,5  means port M0~M5
    //this are the pin number
 
    int signal=0;
  
    switch (FishFoodDetectionPin)
    {
        case FISH_PIN_M0: 
            signal=PTM & BIT0HI;
            break;
 
        case FISH_PIN_M1: 
            signal=PTM & BIT1HI;
            break;
    
        case FISH_PIN_M2: 
            signal=PTM & BIT2HI;
            break;
    
        case FISH_PIN_M3: 
            signal=PTM & BIT3HI;
            break;
    
        case FISH_PIN_M4: 
            signal=PTM & BIT4HI;
            break;
    
        case FISH_PIN_M5: 
            signal=PTM & BIT5HI;
            break;
  
    }//end switch
  
  
    if (signal>0)
    {
        return 1;  // 1 means this fish is feed!(5V)
    }
    else 
        return 0;  // 0 means this fish is not feed!(0V)
  
}



//-----------------------------------------------

int CheckWhichFishIsFeed(void)
{
  
    int thefishisfeed=  NONE;
    int FishPinNumber=  0;  
    
    static int OldFishSignal[6]= {0,0,0,0,0,0}; //this array contain the voltage level fopr each fish detecter
    static int NewFishSignal[6]= {0,0,0,0,0,0};
    
  
    for(FishPinNumber=0 ; FishPinNumber<6 ; FishPinNumber++)
    {
        NewFishSignal[FishPinNumber]=GetFishSignal(FishPinNumber); //now the array is new fish signal from the 6 pins   
    }		
   
  
    for(FishPinNumber=0 ; FishPinNumber<6 ; FishPinNumber++)
    {
        if(OldFishSignal[FishPinNumber]==1 && NewFishSignal[FishPinNumber]==0) 
        {      
            thefishisfeed=FishPinNumber;   //means a pulse from this pin   	
 		}		
    }
    
    for(FishPinNumber=0 ; FishPinNumber<6 ; FishPinNumber++)
    {
        OldFishSignal[FishPinNumber]=NewFishSignal[FishPinNumber]; // new signal is now become old signal   
    }		
    
 
    return thefishisfeed;
  
} 

//--------------------------------------------------

int CheckIfSpecificFishAreFed(int FishPin1,int FishPin2,int FishPin3,int FishPin4,int FishPin5,int FishPin6)
{
    
    int thefishisfeed=  NONE;
    int FishPinNumber=  0;    
  
    static int OldFishSignal[6]= {0,0,0,0,0,0}; //this array contain the voltage level fopr each fish detecter
    static int NewFishSignal[6]= {0,0,0,0,0,0};
    
    for(FishPinNumber=0 ; FishPinNumber<6 ; FishPinNumber++)
    {
        NewFishSignal[FishPinNumber]=GetFishSignal(FishPinNumber); //now the array is new fish signal from the 6 pins   
    }		
   
  
    for(FishPinNumber=0 ; FishPinNumber<6 ; FishPinNumber++)
    {
        if(OldFishSignal[FishPinNumber]==1 && NewFishSignal[FishPinNumber]==0 && ( (FishPinNumber==FishPin1) || (FishPinNumber==FishPin2) || (FishPinNumber==FishPin3) || (FishPinNumber==FishPin4) || (FishPinNumber==FishPin5) || (FishPinNumber==FishPin6) )) 
        {      
            thefishisfeed=FishPinNumber;   //means a pulse from this pin   	
 		}		
    }
    
    for(FishPinNumber=0 ; FishPinNumber<6 ; FishPinNumber++)
    {
        OldFishSignal[FishPinNumber]=NewFishSignal[FishPinNumber]; // new signal is now become old signal   
    }		
    
 
    return thefishisfeed;    
 
    

}
