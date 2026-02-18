#include "malloc_memory_pool_v1.h"

#include <glog/logging.h>

#include <cstdlib>
#include <new>

MallocMemoryPoolV1::MallocMemoryPoolV1() {
}

MallocMemoryPoolV1::~MallocMemoryPoolV1() {
}

void* MallocMemoryPoolV1::Allocate(size_t size) {
#ifdef JETT_DEBUG_MODE
  LOG(INFO) << "Allocate " << size << " bytes.";
#endif
  if (size == 0) {
    return nullptr;
  }
  return malloc(size);
}

void MallocMemoryPoolV1::Deallocate(void** ptr) {
  if (ptr == nullptr)
    return;
  free(*ptr);
  *ptr = nullptr;
}