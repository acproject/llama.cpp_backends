#include "runtime/model.h"

bool run_model(Model* model, Tensor* input, Tensor* output) {
    return model->handle->run(model, input, output);
}