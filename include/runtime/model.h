#pragma once

#include <string>
#include "backends/backend.h"

struct Model {
    std::string type;
    Backend* backend = nullptr;

    void* impl = nullptr; // backend specific implementation (imported!)
};