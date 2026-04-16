// apps/cli/main.cpp

#include <iostream>
#include "runtime/model.h"
#include "runtime/tensor.h"
#include "runtime/backend_registry.h"

// extern backend
extern Backend dummy_backend;

int main() {
    // 注册 backend
    register_backend("dummy", &dummy_backend);

    // 创建 model
    Model model;
    model.backend = get_backend("dummy");

    model.backend->load_model(&model, "test.model");

    // 输入
    Tensor in;
    in.data = {1, 2, 3};

    Tensor out;

    // 运行
    model.backend->run(&model, &in, &out);

    // 输出
    std::cout << "Output: ";
    for (auto v : out.data) {
        std::cout << v << " ";
    }
    std::cout << std::endl;

    model.backend->free_model(&model);

    return 0;
}