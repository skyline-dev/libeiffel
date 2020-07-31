#include "eiffel.h"

#include <string.h>

#include "service_guard.h"

static Service g_eiffelSrv;

NX_GENERATE_SERVICE_GUARD(eiffel);

Result _eiffelInitialize() { return smGetService(&g_eiffelSrv, EIFFEL_SERVICE_NAME); }

void _eiffelCleanup(void) { serviceClose(&g_eiffelSrv); }

Result eiffelLog(const char* moduleName, EiffelLogLevel level, const char* logContent) {
    return serviceDispatchIn(&g_eiffelSrv, EFL_CMD_LOG, level,
                             .buffer_attrs =
                                 {
                                     SfBufferAttr_HipcMapAlias | SfBufferAttr_In,
                                     SfBufferAttr_HipcMapAlias | SfBufferAttr_In,
                                 },
                             .buffers = {
                                 {moduleName, strlen(moduleName) + 1},
                                 {logContent, strlen(logContent) + 1},
                             });
}
