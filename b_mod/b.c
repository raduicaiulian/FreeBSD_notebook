#include <sys/param.h>
#include <sys/kernel.h>
#include <sys/module.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/systm.h>
#include "b.h"
void print(){
	printf("mere");
}

static int
b_modevent(struct module *inModule, int inEvent, void* inArg)
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

static moduledata_t b_mod = {
	"b",
	b_modevent,
	NULL
};

DECLARE_MODULE(b, b_mod, SI_SUB_DRIVERS, SI_ORDER_ANY);
MODULE_VERSION(b, 1);
