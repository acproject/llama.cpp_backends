#pragma once

#include <string>

struct Model;
struct Tensor;

struct Backend {
    const char* name;
    bool (*load_model)(Model* model, const std::string& model_path);
    bool (*run)(Model* model, Tensor* input, Tensor* output);
    void (*free_model)(Model* model);
};