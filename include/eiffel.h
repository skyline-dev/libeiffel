#pragma once

#include <switch.h>

#define EIFFEL_SERVICE_NAME "efl"

typedef enum {
    EFL_CMD_LOG = 0,
} EiffelCommandId;

typedef enum {
    EFL_LOG_LEVEL_INFO = 0,
    EFL_LOG_LEVEL_WARNING = 1,
    EFL_LOG_LEVEL_ERROR = 2,
} EiffelLogLevel;

Result eiffelInitialize();
void eiffelExit();

Result eiffelLog(const char* moduleName, EiffelLogLevel level, const char* logContent);
