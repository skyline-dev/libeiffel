#pragma once

#include <stddef.h>
#include <stdint.h>

typedef char SlPluginName[16];

// subject to change
typedef struct {
    SlPluginName name;
    uint32_t version;
    uint32_t apiVersion;
} SlPluginMeta;

typedef struct {
    uint32_t handle;
    size_t size;
    uint32_t perm;
} SlPluginSharedMemInfo;
