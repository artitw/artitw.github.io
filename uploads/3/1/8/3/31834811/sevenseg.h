//SevenSeg.h
#ifndef _SEVEN_SEG_H_
#define _SEVEN_SEG_H_

//public prototypes
void InitSevenSeg(void);
//Initializes the seven segment display
//User should initialize the display in the beginning of each game
//The display should be empty after initialization
//note: initializes the AD pins with ADS12_Init("OOOOAOOI") 

void PrintToSevenSeg(int NumToDisplay, char WhichDisp);
//Prints a number to one of the two the seven segment display
//ex: PrintToSevenSeg(6,'2') displays 6 on the second seven segment display
//note: 0 <= NumToDisplay <= 9



/*hardware connection
CP,1  - T7
DS1,1 - T6
CP,2  - T5
DS1,2 - T4

MR,1  - AD1
MR,2  - AD2
*/

#endif
