
#include <bur/plctypes.h>

#ifdef _DEFAULT_INCLUDES
	#include <AsDefault.h>
#endif

void _INIT ProgramInit(void)
{
     fb_motor.Tm = 0.06;
     fb_motor.ke = 27.0/145.0;
     fb_motor.dt = 0.01;
    
    fb_motor2.Tm = 0.06;
    fb_motor2.ke = 27.0/145.0;
    fb_motor2.dt = 0.01;

    
    fb_regulator.k_i = fb_motor.ke / 0.03;
    fb_regulator.k_p = (fb_motor.ke * fb_motor.Tm) / 0.03;
    fb_regulator.max_abs_value = 27; 
    fb_regulator.dt = 0.01;
    fb_regulator.iyOld = 0;
    
    speed = 0;
    enable = 1;
    counter = 0;
}
