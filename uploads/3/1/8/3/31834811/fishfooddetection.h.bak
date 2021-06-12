#ifndef FISHFOODDETECTION_H
#define FISHFOODDETECTION_H 

#define NONE           10
#define FISH_PIN_M0    0
#define FISH_PIN_M1    1
#define FISH_PIN_M2    2
#define FISH_PIN_M3    3
#define FISH_PIN_M4    4
#define FISH_PIN_M5    5


void FishFoodDetectionPinInit(void);

/*
  fish detection use M0~M5 pins
  this initialization will initial M0~M5 for use
  Will not touch other pins

*/

int CheckWhichFishIsFeed(void);

/*
  this function will check if there is any fish been fed
  it will only check once
  so for real use, it needs a loop to run this function
  so can check for a longer time , not just once
  
  return: 
  it will return the number for the fish pin (M0~M5) which has been feed
  if no fish is been fed, it will return 10
*/


int CheckIfSpecificFishAreFed(int FishPin1,int FishPin2,int FishPin3,int FishPin4,int FishPin5,int FishPin6);

/*
  this function will check if there is specific fish been fed
  Paremeter: 6 number from 0~5, it's pin number of fish which you wanna check
             if you dont need to check all of them, then put 
             NONE as input
             you should have 6 input  
  Usage: CheckIfSpecifiFishAreFed(0,1,3,5,NONE,NONE);
  Return: It will return the pin number where the fish is fed, return NONE if no fish is Fed
  
   
*/


int GetFishSignal(int FishFoodDetectionPin);

#endif  FISHFOODDETECTION_H
