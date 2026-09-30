
#include <bur/plctypes.h>

#ifdef _DEFAULT_INCLUDES
	#include <AsDefault.h>
#endif

void _CYCLIC ProgramCyclic(void)
{
    
    counter++;
    if ((counter >= 300) && (counter <= 800))
        speed = 100;
    else
        speed = 0;
   
    // без рег
    fb_motor2.u = speed * fb_motor2.ke;
    FB_Motor(&fb_motor2);
    // с рег
    fb_regulator.e = speed  - fb_motor.w;
    FB_Regulator(&fb_regulator);
    fb_motor.u = fb_regulator.u;
    FB_Motor(&fb_motor);
    
}
