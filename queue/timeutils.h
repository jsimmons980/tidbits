#pragma once

#include "preproc.h"

#include <ctime>

namespace jas
{
namespace time
{

    NEVER_INLINE int64_t rdtsc()
    {
        return( _rdtsc() );
    };

    ALWAYS_INLINE int64_t rdtscp()
    {
        unsigned int l_dummy;
        return( _rdtscp( &l_dummy ) );
    };

    namespace epoch
    {
        NEVER_INLINE int64_t nanos()
        {
            timespec l_ts;
            ::clock_gettime( CLOCK_REALTIME , &l_ts );
            return( static_cast<uint64_t>( l_ts.tv_sec ) * 1000000000ULL +
                    static_cast<uint64_t>( l_ts.tv_nsec ) );
        }

        ALWAYS_INLINE int64_t micros()
        {
            return( nanos() / 1000 );
        }

        ALWAYS_INLINE int64_t millis()
        {
            return( nanos() / 1000000 );
        }
    } // epoch

} // time
} // jas
