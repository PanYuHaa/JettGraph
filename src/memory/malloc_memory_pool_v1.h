#pragma once

#include <cstddef>

#include "base_memory_pool.h"

class MallocMemoryPoolV1 : public BaseMemoryPool {
 public:
  static MallocMemoryPoolV1& Instance() {
    static MallocMemoryPoolV1 instance;
    return instance;
  }
  ~MallocMemoryPoolV1() override;

  void* Allocate(size_t size) override;
  void Deallocate(void** ptr) override;

 private:
  MallocMemoryPoolV1();
};