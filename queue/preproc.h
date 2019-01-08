#pragma once

#define ALIGN(X)      alignas(X)
#define USED          __attribute__((used))
#define PACK          __attribute__((packed))
#define NEVER_INLINE  __attribute__((noinline))
#define ALWAYS_INLINE inline __attribute__((always_inline))
#define LIKELY(X)     __builtin_expect(!!(X),1)
#define UNLIKELY(X)   __builtin_expect(!!(X),0)
