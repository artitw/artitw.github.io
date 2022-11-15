#include <ME218_C32.h>
#include <ADS12.h>
#include "StartButtonLEDLight.h"


void StartButtonLightOn(void)
{
    PTAD = PTAD | BIT4HI;    
}


void StartButtonLightOff(void)
{
    PTAD = PTAD & BIT4LO;     
}
