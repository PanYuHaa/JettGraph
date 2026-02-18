#pragma once

#include <cstddef>

/**
 * BaseMemoryPool
 */
class BaseMemoryPool {
 public:
  virtual ~BaseMemoryPool() = default;

  virtual void* allocate(size_t size) = 0;

  virtual void deallocate(void** ptr) = 0;
};