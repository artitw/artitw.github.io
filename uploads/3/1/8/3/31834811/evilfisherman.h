/*
 * File: EvilFisherman.h
 * --------------
 * Defines the interface for the EvilFisherman module. 
 * 
 * Artit Wangperawong wrote this for ME218A
 *
 */

#ifndef EVILFISHERMAN_H
#define EVILFISHERMAN_H

#define A2DINITSTRING       "OOOOAOOI"  //Set pin 3 for A/D input
#define EVILNESSPIN         3           //For AD3


	/**
	 *
	 * Member function: EvilFishermanInit
	 * Usage: EvilFishermanInit();
	 * ---------------------------------
	 * Initializes A/D converter and PWM module.
	 *
	 */

void EvilFishermanInit(void);


	/**
	 *
	 * Member function: UpdateFishermanEvilness
	 * Usage: UpdateFishermanEvilness();
	 * ---------------------------------
	 * Obtains ADC value from Evilness knob position and updates the PWM duty cycle accordingly.
	 *
	 */
	 
void UpdateFishermanEvilness(void);


	/**
	 *
	 * Member function: TurnOffEvilFisherman
	 * Usage: TurnOffEvilFisherman();
	 * ---------------------------------
	 * Turn off Evil Fisherman
	 *
	 */
	 
void TurnOffEvilFisherman(void);



#endif /* EVILFISHERMAN_H */