cmake_minimum_required(VERSION 3.17)

project(
  JGraph
  VERSION 1.0
  LANGUAGES CXX)

include_directories(src)

# add_compile_options(-DJETT_DEBUG_MODE)
add_compile_options(-Wall -Wextra)
add_compile_options(-Wno-unused-parameter -Wno-sign-compare
                    -Wno-unused-function -Wno-implicit-exception-spec-mismatch 
                    -Wno-maybe-uninitialized)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})
include(FetchContent)
# third_party
FetchContent_Declare(
  glog
  GIT_REPOSITORY https://github.com/google/glog.git
  GIT_TAG v0.4.0
  GIT_SHALLOW ON)

FetchContent_Declare(
  gflags
  GIT_REPOSITORY https://github.com/gflags/gflags.git
  GIT_TAG v2.2.2
  GIT_SHALLOW ON)
  
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG release-1.10.0
  GIT_SHALLOW ON)

FetchContent_MakeAvailable(gflags glog googletest)

# src
add_subdirectory(src)
add_subdirectory(test)