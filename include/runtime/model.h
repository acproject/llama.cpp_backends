#pragma once

#include <string>
#include "backends/backend.h"

struct Model {
    std::string type;
    Backend* handle;

    void* impl; // backend specific implementation (imported!)
};