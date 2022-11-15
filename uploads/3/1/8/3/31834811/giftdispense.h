#ifndef GIFTDISPENSE_H
#define GIFTDISPENSE_H

void GiftPinInit(void);

/*
   Gift dispension pin use pin T0
   It will initPWM
   It will set a timer number 1 for 0.5 second and be ready to use
   to use this function
   
   *****NEED TO INIT TIMER for 1ms rate BEFORE USE!!*****   

*/


void GiftDispense(void);

/*
  this function will open the gate for 2 seconds and close it
*/


#endif  //GIFTDISPENSE_H