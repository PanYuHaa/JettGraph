#pragma once

#include <cstddef>

/**
 * BaseMemoryPool
 */
class BaseMemoryPool {
 public:
  virtual ~BaseMemoryPool() = default;

  virtual void* Allocate(size_t size) = 0;

  virtual void Deallocate(void** ptr) = 0;
};