// include/backends/backend.h
#pragma once
#include <string>

struct Model;
struct Tensor;

struct Backend {
    const char* name;

    bool (*load_model)(Model*, const std::string&);
    bool (*run)(Model*, const Tensor*, Tensor*);
    void (*free_model)(Model*);
};