#include <string.h>

#include "eiffel/sl.h"
#include "service_guard.h"

static Service g_eiffelSlSrv;

NX_GENERATE_SERVICE_GUARD(eiffelSl);

Result _eiffelSlInitialize() { return smGetService(&g_eiffelSlSrv, EIFFEL_SKYLINE_SERVICE_NAME); }

void _eiffelSlCleanup(void) { serviceClose(&g_eiffelSlSrv); }

Result eiffelSlLog(const char* moduleName, EiffelLogLevel level, const char* logContent) {
    return serviceDispatchIn(&g_eiffelSlSrv, EFL_SL_CMD_LOG, level,
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
