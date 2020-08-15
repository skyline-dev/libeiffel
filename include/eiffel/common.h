#pragma once

#include <stdint.h>

typedef char SlPluginName[16];

// subject to change
typedef struct {
    SlPluginName name;
    uint32_t version;
    uint32_t apiVersion;
} SlPluginMeta;
