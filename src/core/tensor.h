#pragma once

#include "core/utils.h"
#include "glog/logging.h"
#include "memory/malloc_memory_pool_v1.h"

/**
 * data_type: fp32, fp16, int32, int16
 * 
 */
template <typename T>
class Tensor {
 public:
  explicit Tensor(const Shape& shape) : shape_(shape) {
    size_t total_size = sizeof(T);
    for (const auto& s : shape) {
      total_size *= s;
    }

    data_ =
        static_cast<T*>(MallocMemoryPoolV1::Instance().Allocate(total_size));
    memset(data_, 0, total_size);
  }

  ~Tensor() {
    if (data_) {
      void* ptr = static_cast<void*>(data_);
      MallocMemoryPoolV1::Instance().Deallocate(&ptr);
    }
  }

  void Print() const {
    CHECK_EQ(shape_.size(), 2)
        << "Tensor::Print only supports 2D tensor, but got " << shape_.size()
        << "D";

    size_t rows = shape_[0];
    size_t cols = shape_[1];

    LOG(INFO) << "Tensor Print (shape=[" << rows << ", " << cols << "])";

    for (size_t i = 0; i < rows; ++i) {
      std::ostringstream oss;
      for (size_t j = 0; j < cols; ++j) {
        oss << data_[i * cols + j];
        if (j + 1 < cols) {
          oss << " ";
        }
      }
      LOG(INFO) << oss.str();
    }
  }

 private:
  T* data_;
  Shape shape_;
  DeviceType device_type_;
};