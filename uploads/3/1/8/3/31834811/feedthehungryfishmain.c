  //------------------------------
  //     Game Flow Pseudo Code
  //------------------------------
  /* 
        1. Initialize pin direction and states
            -timers
            -penny detection
            -start button
            -fish food detection
            -score display
            -gift dispenser
            -fish lighting
            -sound effect
            
        2. Wait Until Penny is Inserted
        3. Initialize Score to ZERO
        4. Turn on Start Button Light
        5. Wait Until Start Button is Pressed
        6. Turn Off Start Button Light
	    7. First Stage: Fish lights off one-bye-one as fed
	        In a continous loop:
        	    -Initialize state of all fish to be hungry
        	    -Light fish's eyes with state string
        	    -Check for game timeout
        	    -Check if all hungry fish are fed
        	    -Obtain the specific fish fed
        	    -If fish fed is hungry, increment score, display it, and say "I Love You".  Otherwise, ignore
        	    -Turn off fish light when fish is fed and no longer hungry
        	    -Check Evilness knob and update Evil Fisherman
        8. Second Stage: Fish randomly get hungry
                -Initialize Random module with time counter as seed
            In a continous loop:
                -Set fed fish variable to the currently fed fish
                -Obtain random number between 0 and 5, inclusive
        	    -Check for game timeout
                -Make sure the next hungry fish is not the one that has just been fed
                -Turn off all fish
                -Light the next random fish
                -Obtain the specific fish fed 
                -Check Evilness knob and update Evil Fisherman
                -If the hungry fish is fed and there is still game time, increment score, display it, and say "I Love You"
       
        EndGameSequence:
        9. Turn Off All Fish                
        10.Turn off Evil Fisherman Before Dispensing Candy
        11.Dispense Gift
                -Wait a bit for player to be ready to receive gift
                -Dispense gift only if they have enough points 
        12.Go back to STEP 2       	    
  */
  	   

#include <ME218_C32.h>
#include <timers12.h>
#include <ADS12.h>
#include <PWMS12.h>
#include <stdlib.h>
  

#include "FishFoodDetection.h"
#include "EvilFisherman.h"
#include "SevenSeg.h"
#include "GiftDispense.h"
#include "PennyInsertion.h"
#include "ShowScoreOnLED.h"
#include "StartPushButton.h"
#include "StartButtonLEDLight.h"
#include "LightFish.h"
#include "SoundEffect.h"
				  

#define SIXTY_SECONDS_COUNTER       60000 //For 60 seconds
#define ONE_SECOND_COUNTER          1000 //For 1 seconds
#define POINTS_FOR_GIFT             10
#define ON  '1'
#define OFF '0'


int TranslateFishPinToFishLight(int FishPin);
int score; 

  				   
void main()
{
    unsigned int time0 = 0;  //Time counter variable
    int DetectWhichFishIsFeed=0; 
    int thisfish=0;
    int dummyfish=0;
    int seed;   
    char FishEyeString[6]="000000";	 //string storing state of each fish
    
   
         
    //----------------------------------------
    //  1. Initialize pin direction and states 
    //----------------------------------------
     
    TMRS12_Init(TMRS12_RATE_1MS);
    PennyPinInit();
    StartPushButtonInit();
    FishFoodDetectionPinInit();
    InitSevenSeg();
    EvilFishermanInit();
    GiftPinInit();
    InitLightFish();
    SoundEffectInit();

    
    StepTwo:

    
    //----------------------------------------
    //  2. Wait Until Penny is Inserted
    //----------------------------------------
   															 
    while(CheckIfPennyIn() == 0);

  
    //----------------------------------------
    //  3. Initialize Score to ZERO
    //----------------------------------------
    
    score = 0;
    ShowScoreOnLED(0);

     
    //----------------------------------------
    //  4. Turn on Start Button Light
    //----------------------------------------
  
    StartButtonLightOn();
    
    
    //----------------------------------------
    //  5. Wait Until Start Button is Pressed 
    //----------------------------------------
    
    while(CheckIfStartPushButtonIsPushed() == 0); 
        
    
    //----------------------------------------
    //  6. Turn Off Start Button Light
    //----------------------------------------
    
    StartButtonLightOff(); 
    
  
    //----------------------------------------
    //  7. First Stage: Fish lights off one-bye-one as fed
    //----------------------------------------
    
    time0 = TMRS12_GetTime();  //Set initial time
    
    //Initialize state of all fish to be hungry
    FishEyeString[0]='1';
    FishEyeString[1]='1';
    FishEyeString[2]='1';
    FishEyeString[3]='1';
    FishEyeString[4]='1';
    FishEyeString[5]='1';
    
    //Light fish's eyes with state string   
    LightFish(FishEyeString);
    
  
    while(1)
    { 
    
        //game timout
        if(TMRS12_GetTime()-time0 > SIXTY_SECONDS_COUNTER)
        {
            break;
        }
    
        //all hungry fish are fed
        if(FishEyeString[0]==OFF &&	FishEyeString[1]==OFF && FishEyeString[2]==OFF && FishEyeString[3]==OFF && FishEyeString[4]==OFF && FishEyeString[5]==OFF)
        {
            break;
        }
          
        //obtain the specific fish fed
        DetectWhichFishIsFeed=CheckIfSpecificFishAreFed(FISH_PIN_M0, FISH_PIN_M1, FISH_PIN_M2, FISH_PIN_M3, FISH_PIN_M4, FISH_PIN_M5);
        
        if(DetectWhichFishIsFeed != NONE)
        {
        
    		//if fish fed is hungry, increment score, display it, and say "I Love You".  otherwise, ignore
   	        if(FishEyeString[TranslateFishPinToFishLight(DetectWhichFishIsFeed)]==ON)
   	        {
   	            score++;
   	            ShowScoreOnLED(score);
   	            SayILoveYou();
   	            
   	            //turn off fish light because fish is no longer hungry
   	            FishEyeString[TranslateFishPinToFishLight(DetectWhichFishIsFeed)]=OFF;  
                LightFish(FishEyeString); 
   	        }
     
        }
        
        //Check Evilness knob and update Evil Fisherman 
       	UpdateFishermanEvilness();
           
    }
    
  
   
    //----------------------------------------
    //  8. Second Stage: Fish randomly get hungry
    //----------------------------------------
      
    //initialize Random module with time counter as seed
    seed = TMRS12_GetTime();
    srand(seed);

    Part2Start:    
    
    //set fed fish variable (dummyfish) to the currently fed fish (thisfish)
    dummyfish=thisfish;
    
    //obtain random number between 0 and 5, inclusive
    thisfish=rand()%6;
    
    //game timout
    if(TMRS12_GetTime()-time0 > SIXTY_SECONDS_COUNTER)
    {
        goto EndGameSequence;
    }
    
    //make sure the next hungry fish (thisfish) is not the one that has just been fed (dummyfish)
    while(dummyfish==thisfish)
    {  
        thisfish=rand()%6;
    }
    
    //turn off all fish
    FishEyeString[0]=OFF;
    FishEyeString[1]=OFF;
    FishEyeString[2]=OFF;
    FishEyeString[3]=OFF;
    FishEyeString[4]=OFF;
    FishEyeString[5]=OFF;
    
    //light the next random fish
    FishEyeString[TranslateFishPinToFishLight(thisfish)]=ON;
    LightFish(FishEyeString);
    
    
    WaitForInput:
    
    //obtain the specific fish fed    
    DetectWhichFishIsFeed=CheckIfSpecificFishAreFed(FISH_PIN_M0, FISH_PIN_M1, FISH_PIN_M2, FISH_PIN_M3, FISH_PIN_M4, FISH_PIN_M5);
    
    //Check Evilness knob and update Evil Fisherman 
    UpdateFishermanEvilness();
    
    //if the hungry fish is fed and there is still game time, increment score, display it, and say "I Love You"
    if(DetectWhichFishIsFeed==thisfish && (TMRS12_GetTime()-time0 < SIXTY_SECONDS_COUNTER))
    {
        score++;
        ShowScoreOnLED(score);
        SayILoveYou();
        goto Part2Start;
    }
    
    else if(TMRS12_GetTime()-time0 > SIXTY_SECONDS_COUNTER)
    {      
        goto EndGameSequence;
    
    }
    
    else    
    {   
        UpdateFishermanEvilness();
        goto WaitForInput;	   
    }
           
    
    EndGameSequence:
    
    //---------------------------------
    //  9. Turn Off All Fish
    //--------------------------------- 
  
    LightFish("000000");
    
    
    //---------------------------------
    //  10. Turn off Evil Fisherman Before Dispensing Candy
    //---------------------------------   
   
    TurnOffEvilFisherman();
    
    
    //---------------------------------
    //  11. Dispense Gift
    //--------------------------------- 
  
    time0 = TMRS12_GetTime();
   
    //Wait a bit for player to be ready to receive gift
    while(TMRS12_GetTime()-time0 > ONE_SECOND_COUNTER);
    
    //dispense gift only if they have enough points
    if(score >= POINTS_FOR_GIFT) 
    {
        GiftDispense();
    }
    

  
    //---------------------------------
    //   12. Go Back To Step 2
    //--------------------------------- 
    
    goto StepTwo;
         
    
    return;    
}
 
        
int TranslateFishPinToFishLight(int FishPin)
{
  int FishLight;
    
  switch(FishPin)
  {
      case FISH_PIN_M0:
           FishLight=0;
           break;
           
      case FISH_PIN_M1:
           FishLight=1;
           break;   
      
      case FISH_PIN_M2:
           FishLight=3;
           break; 
           
      case FISH_PIN_M3:
           FishLight=5;
           break; 
           
      case FISH_PIN_M4:
           FishLight=4;
           break;
           
      case FISH_PIN_M5:
           FishLight=2;
           break;                 
 
  }
 
    return FishLight;  
    
}
 