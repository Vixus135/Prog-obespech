
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
void FB_Regulator(struct FB_Regulator* inst)
{
    REAL p1 = inst->e * inst->k_p;
    
    REAL p2 = inst->e * inst->k_i;
    
    inst->integrator.in = p2 + inst->iyOld;
    FB_Integrator(&inst->integrator);
    REAL r = inst->integrator.out;
    REAL p3 = p1 + r;
    REAL pered = p3;
    REAL lim;
    if (pered > inst->max_abs_value)   lim=inst->max_abs_value;
    else if (pered < -inst->max_abs_value)   lim=-inst->max_abs_value;
    else lim = pered;
    REAL correction = lim - pered;
    inst->iyOld = r+ correction;
    inst->u = lim;
}
