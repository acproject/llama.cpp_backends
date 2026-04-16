#pragma once
#include <string>
#include "backends/backend.h"

void register_backend(const std::string& name, Backend* backend);
Backend* get_backend(const std::string& name);