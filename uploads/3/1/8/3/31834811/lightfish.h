//LightFish.h
#ifndef _LIGHT_FISH_H_
#define _LIGHT_FISH_H_

void LightFish(char LightConfig[]);
//LightConfig is a string of six characters
//The fish that are lit up correspond to the LighConfig string
//Ex: LightFish("111010");  - Fish#1,2,3,5 are ON, Fish#4,6 are OFF 

void InitLightFish(void);
//Initialiazes the port AD as follows: "OOOOAOOI"
//Also resets all the fish LEDs to low

/*
Required Hardware connection:
AD5 - CP
AD6 - DS1
AD7 - MR
*/

#endif