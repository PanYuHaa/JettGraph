#pragma once
#include <vector>
#include <cstdint>

enum DeviceType { CPU = 0, GPU = 1, XPU = 2 };
using Shape = std::vector<int32_t>;