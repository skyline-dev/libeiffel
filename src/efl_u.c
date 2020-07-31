#include "eiffel/user.h"
#include "service_guard.h"

static Service g_eiffelSrv;

NX_GENERATE_SERVICE_GUARD(eiffel);

Result _eiffelInitialize() { return smGetService(&g_eiffelSrv, EIFFEL_USER_SERVICE_NAME); }

void _eiffelCleanup(void) { serviceClose(&g_eiffelSrv); }
