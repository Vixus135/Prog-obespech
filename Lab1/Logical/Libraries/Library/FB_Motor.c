
#include <bur/plctypes.h>
#ifdef __cplusplus
	extern "C"
	{
#endif
	#include "Library.h"
#ifdef __cplusplus
	};
#endif
/* TODO: Add your comment here */
void FB_Motor(struct FB_Motor* inst)
{
    REAL U = inst->u / inst->ke; 
    REAL wich = (U-inst->w) /inst->Tm;
    inst->integrator.in = wich;
    FB_Integrator(&inst->integrator);
    inst->w = inst->integrator.out;
    inst->integrator2.in = inst->w;
    FB_Integrator(&inst->integrator2);
    inst->phi = inst->integrator2.out;
}
