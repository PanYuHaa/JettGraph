#pragma once

#include <cstddef>

#include "base_memory_pool.h"

class MallocMemoryPoolV1 : public BaseMemoryPool {
 public:
  explicit MallocMemoryPoolV1();
  ~MallocMemoryPoolV1() override;

  void* allocate(size_t size) override;
  void deallocate(void** ptr) override;
};