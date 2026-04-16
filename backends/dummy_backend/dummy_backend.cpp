// backends/dummy_backend/dummy_backend.cpp

#include <iostream>
#include "backends/backend.h"
#include "runtime/model.h"
#include "runtime/tensor.h"

static bool load_model(Model* model, const std::string& path) {
    std::cout << "[dummy] load model: " << path << std::endl;
    model->impl = nullptr;
    return true;
}

static bool run(Model* model, const Tensor* input, Tensor* output) {
    std::cout << "[dummy] run\n";

    output->data = input->data;
    for (auto& v : output->data) {
        v *= 2.0f; // 简单逻辑
    }

    return true;
}

static void free_model(Model* model) {
    std::cout << "[dummy] free model\n";
}

Backend dummy_backend = {
    "dummy",
    load_model,
    run,
    free_model
};