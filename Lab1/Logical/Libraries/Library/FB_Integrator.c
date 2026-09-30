
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
void FB_Integrator(struct FB_Integrator* inst)
{
    inst->dt = 0.01;
    inst->out = inst->out + inst->in * inst->dt;
    inst->star = inst->out;
}
