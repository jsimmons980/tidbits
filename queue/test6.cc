#include "spscq.h"

#include "timeutils.h"

#include <sys/sysinfo.h>

#if 0
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <pthread.h>
#include <sched.h>
#include <string.h>
#include <stdlib.h>
#endif

fof::queues::spscQ * g_queue;

void setAffinity( const int a_cpu )
{
    if ( a_cpu != -1 )
    {
        cpu_set_t l_cpuSet;
        CPU_ZERO( &l_cpuSet );
        CPU_SET( a_cpu , &l_cpuSet );
        ::sched_setaffinity( 0 , sizeof(cpu_set_t) , &l_cpuSet );
    }
}

int           g_producerCPU;
int           g_consumerCPU;
uint64_t      g_start;
uint64_t      g_end;
volatile bool g_go;

#define ITERATIONS       100000000
#define NANOS_PER_SECOND 1000000000

void * producerThread( void * a_ptr )
{
    setAffinity( g_producerCPU );

    g_queue->producerInit();

    register auto l_queue = g_queue;
    for( register uint64_t l_counter = 0;
         l_counter <= ITERATIONS;
         ++l_counter )
    {
        *reinterpret_cast<uint64_t *>( l_queue->tailSpin()->data() ) = l_counter;
        l_queue->tailPushUnsafe();
    }

    pthread_exit( nullptr );
}

void * consumerThread( void * a_ptr )
{
    setAffinity( g_consumerCPU );

    g_queue->consumerInit();

    register uint64_t l_counter;
    register auto     l_queue = g_queue;
    register auto     l_begin = jas::time::epoch::nanos();
    do
    {
        l_counter = *reinterpret_cast<uint64_t *>( l_queue->headSpin()->data() );
        l_queue->headPopUnsafe();
    } while( l_counter not_eq ITERATIONS );
    register auto l_end = jas::time::epoch::nanos();
    auto l_elapsed = l_end - l_begin;
    printf( "%llu %llu (%d-%d) %f %llu %llu\n",
            l_elapsed,
            l_counter,
            g_producerCPU,
            g_consumerCPU,
            (double)NANOS_PER_SECOND / (double)l_elapsed * (double)l_counter,
            g_queue->headSpinIterations(),
            g_queue->tailSpinIterations() );

    pthread_exit( nullptr );
}

int main( int a_argc , char * a_argv[] )
{
    int l_numberOfCpus = get_nprocs();
    for( g_producerCPU = 0;
         g_producerCPU < l_numberOfCpus;
         g_producerCPU++ )
    {
        for( g_consumerCPU = 0;
             g_consumerCPU < l_numberOfCpus;
             g_consumerCPU++ )
        {
            if ( g_producerCPU != g_consumerCPU )
            {
                g_go = false;
                g_queue = fof::queues::spscQ::allocate( atoi( a_argv[1] ) , sizeof( uint64_t ) );

                pthread_t l_tid1;
                pthread_t l_tid2;
                pthread_create( &l_tid1 , nullptr , &consumerThread , nullptr );
                pthread_create( &l_tid2 , nullptr , &producerThread , nullptr );
                pthread_join( l_tid2 , nullptr );
                pthread_join( l_tid1 , nullptr );
            }
        }
    }
}

