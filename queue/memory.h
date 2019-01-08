#pragma once

#include "preproc.h"

#include <x86intrin.h>

#include <cstdint>

namespace fof
{
namespace memory
{

    static constexpr uint64_t CL_SIZE = 64;
    static constexpr uint64_t PAGE_4K = CL_SIZE * 64;
    static constexpr uint64_t PAGE_2M = CL_SIZE * 32768;
    static constexpr uint64_t PAGE_1G = CL_SIZE * 262144;

} // memory
} // fof
