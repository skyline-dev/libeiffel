#pragma once

#include <switch.h>

#ifdef __cplusplus
extern "C" {
#endif

#define EIFFEL_USER_SERVICE_NAME "efl:u"

typedef enum {
    EFL_U_CMD_GET_PLUGIN_READY_EVENT = 0,
    EFL_U_CMD_GET_PLUGIN_INFO = 1,
} EiffelUserCommandId;

Result eiffelInitialize();
void eiffelExit();

#ifdef __cplusplus
}
#endif
