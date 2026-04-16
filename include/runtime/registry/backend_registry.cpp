#include <map>
#include <string>

#include "backends/backend.h"

static std::map<std::string, Backend*> g_backends;
static std::string g_default_backend = "llama.cpp";

void register_backend(const std::string& name, Backend* backend) {
    g_backends[name] = backend;
}

Backend* get_backend(const std::string& name) {
    return g_backends[name];
}
