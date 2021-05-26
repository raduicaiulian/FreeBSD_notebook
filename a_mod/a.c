#include <sys/param.h>
#include <sys/kernel.h>
#include <sys/module.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/systm.h>
#include "b.h"
static int
a_modevent(struct module *inModule, int inEvent, void* inArg)
{
	int ret=0;

	switch(inEvent) {
	case MOD_LOAD:
		print();
		break;

	case MOD_UNLOAD:
		break;

	default:
		ret = EOPNOTSUPP;
		break;
	}

	return ret;
}

static moduledata_t a_mod = {
	"a",
	a_modevent,
	NULL
};
MODULE_DEPEND(a, b, 1, 1, 1);
DECLARE_MODULE(a, a_mod, SI_SUB_DRIVERS, SI_ORDER_ANY);
MODULE_VERSION(a, 1);
