#pragma once

#include <switch.h>

#ifdef __cplusplus
extern "C" {
#endif

#define EIFFEL_SKYLINE_SERVICE_NAME "efl:sl"

typedef enum {
    EFL_SL_CMD_LOG = 0,
} EiffelSlCommandId;

typedef enum {
    EFL_LOG_LEVEL_INFO = 0,
    EFL_LOG_LEVEL_WARNING = 1,
    EFL_LOG_LEVEL_ERROR = 2,
} EiffelLogLevel;

Result eiffelSlInitialize();
void eiffelSlExit();

Result eiffelSlLog(const char* moduleName, EiffelLogLevel level, const char* logContent);

#ifdef __cplusplus
}
#endif
