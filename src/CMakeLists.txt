# src
add_library(memory STATIC memory/malloc_memory_pool_v1.cc)
target_link_libraries(memory PUBLIC glog::glog)