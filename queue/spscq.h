#pragma once

#include "preproc.h"
#include "memory.h"

#include <iostream>

namespace fof
{
namespace queues
{

    // TODO allow user to specify alignment of data section...
#define ALIGNMENT 24

    struct spscQ
    {
        public:
            struct qslot
            {
                friend spscQ;

                public:
                    uint8_t * data()
                    {
                        return( m_data );
                    }

                    void info( std::string a_indent = "" )
                    {
                        std::cout << a_indent << "slot-->[" << (void *)this << "," << m_next << "," << (uint64_t)m_state << "," << (void *)m_data << "]" << std::endl;
                    }

                private:
                    enum class state : uint64_t
                    {
                        released  = 0,
                        reserved  = 1,
                        populated = 2
                    };

                    volatile state m_state;
                    uintptr_t      m_next;
                    uint8_t        m_data[0];

                    qslot() = delete;
                    qslot( const qslot & ) = delete;
                    qslot & operator=( const qslot & ) = delete;

                    qslot( const decltype(m_next) a_next )
                    :m_next( a_next ),
                     m_state( state::released )
                    {
                    }
            } PACK;

            NEVER_INLINE void info()
            {
                std::cout << "spscQ-->[" << this << "," << sizeof( *this ) << "]" << std::endl;
                std::cout << "    elements------->[" << (void *)&m_elements << "," << offsetof(spscQ,m_elements) << "," << m_elements << "]" << std::endl;
                std::cout << "    slot info------>[" << (void *)&m_slotSize << "," << offsetof(spscQ,m_slotSize) << "," << m_slotSize << "," << sizeof( qslot ) << "]" << std::endl;
                std::cout << "    head slot------>[" << (void *)&m_head << "," << offsetof(spscQ,m_head) << "," << (void *)m_head << "]" << std::endl;
                std::cout << "    tail slot------>[" << (void *)&m_tail << "," << offsetof(spscQ,m_tail) << "," << (void *)m_tail << "]" << std::endl;
                std::cout << "    slots---------->[" << (void *)m_slots << "," << offsetof(spscQ,m_slots) << "]" << std::endl;
#if 0
                for( size_t l_index = 0;
                     l_index < m_elements;
                     ++l_index )
                {
                    reinterpret_cast<qslot *>( m_slots + ( l_index * m_slotSize ) )->info( "        " );
                }
#endif
            }

            // overlay spscQ on a memory location
            ALWAYS_INLINE static spscQ * allocate( void * a_memory )
            {
                return( reinterpret_cast<spscQ *>( a_memory ) );
            }

            // overlay spscQ on a memory location and construct
            NEVER_INLINE static spscQ * allocate( void *       a_memory,
                                                  const size_t a_elements,
                                                  const size_t a_size )
            {
                auto l_slotSize = ( ( sizeof( qslot ) + a_size + ALIGNMENT - 1 ) / ALIGNMENT ) * ALIGNMENT;
                auto l_queue    = allocate( a_memory );
                new ( l_queue ) spscQ( a_elements , l_slotSize );
#if 0
                l_queue->info();
#endif
                return( l_queue );
            }

            // allocate spscQ memory location and construct
            NEVER_INLINE static spscQ * allocate( const size_t a_elements,
                                                  const size_t a_size )
            {
                auto l_slotSize = ( ( sizeof( qslot ) + a_size + ALIGNMENT - 1 ) / ALIGNMENT ) * ALIGNMENT;
                auto l_queue    = reinterpret_cast<spscQ *>( _mm_malloc( sizeof( spscQ ) + ( a_elements * l_slotSize ) , 4096 ) );
                new ( l_queue ) spscQ( a_elements , l_slotSize );
#if 0
                l_queue->info();
#endif
                return( l_queue );
            }

            ALWAYS_INLINE void producerInit()
            {
                m_tail = reinterpret_cast<qslot *>( m_slots );
            }

            ALWAYS_INLINE void consumerInit()
            {
                m_head = reinterpret_cast<qslot *>( m_slots );
            }

            ALWAYS_INLINE void free()
            {
                _mm_free( this );
            }

            ~spscQ()
            {
            }

            //
            // head methods
            //
            ALWAYS_INLINE qslot * headSpin()
            {
                decltype(headNoSpin()) l_slot;
                while( ( l_slot = headNoSpin() ) == nullptr )
                {
                    ++m_headSpinIterations;
                }
                return( l_slot );
            }

            ALWAYS_INLINE qslot * headNoSpin()
            {
                return( ( qslot::state::populated == m_head->m_state ) ? m_head : nullptr );
            }

            ALWAYS_INLINE bool headPopSafe()
            {
                return( ( qslot::state::populated == m_head->m_state ) ? headPopUnsafe() : false );
            }

            ALWAYS_INLINE bool headPopUnsafe()
            {
                auto l_slot = m_head;
                l_slot->m_state = qslot::state::released;
                m_head = reinterpret_cast<qslot *>( m_slots + l_slot->m_next );
                return( true );
            }

            //
            // tail methods
            //
            ALWAYS_INLINE qslot * tailSpin()
            {
                decltype(tailNoSpin()) l_slot;
                while( ( l_slot = tailNoSpin() ) == nullptr )
                {
                    ++m_tailSpinIterations;
                }
                return( l_slot );
            }

            ALWAYS_INLINE qslot * tailNoSpin()
            {
                auto l_slot = m_tail;
                if ( qslot::state::released == l_slot->m_state )
                {
                    l_slot->m_state = qslot::state::reserved;
                    return( l_slot );
                }
                return( nullptr );
            }

            ALWAYS_INLINE bool tailPushSafe()
            {
                return( ( qslot::state::reserved == m_tail->m_state ) ? tailPushUnsafe() : false );
            }

            ALWAYS_INLINE bool tailPushUnsafe()
            {
                auto l_slot = m_tail;
                l_slot->m_state = qslot::state::populated;
                m_tail = reinterpret_cast<qslot *>( m_slots + l_slot->m_next );
                return( true );
            }

            ALWAYS_INLINE size_t size()
            {
                auto l_tail = m_tail;
                auto l_head = m_head;

                if ( l_tail < l_head )
                {
                    return( m_elements + ( l_tail - l_head ) );
                }
                else
                {
                    return( l_tail - l_head );
                }
                return( 0 );
            }

            uint64_t headSpinIterations()
            {
                return( m_headSpinIterations );
            }

            uint64_t tailSpinIterations()
            {
                return( m_tailSpinIterations );
            }

        private:
            size_t   m_elements;
            size_t   m_slotSize;
            qslot *  m_head     ALIGN( fof::memory::CL_SIZE );
            uint64_t m_headSpinIterations;
            qslot *  m_tail     ALIGN( fof::memory::CL_SIZE );
            uint64_t m_tailSpinIterations;
            uint8_t  m_slots[0] ALIGN( fof::memory::CL_SIZE );

            spscQ() = delete;
            spscQ( const spscQ & ) = delete;
            spscQ & operator=( const spscQ & ) = delete;

            spscQ( const decltype(m_elements) a_elements,
                   const decltype(m_slotSize) a_slotSize )
            :m_elements( a_elements ),
             m_slotSize( a_slotSize ),
             m_head( nullptr ),
             m_headSpinIterations( 0 ),
             m_tail( nullptr ),
             m_tailSpinIterations( 0 )
            {
                for( std::remove_const<decltype(a_elements)>::type l_element = 0;
                     l_element < a_elements;
                     l_element++ )
                {
                    auto l_slot = m_slots + ( l_element * a_slotSize );
                    if ( l_element != ( a_elements - 1 ) )
                    {
                        new ( l_slot ) qslot( ( l_element + 1 ) * a_slotSize );
                    }
                    else
                    {
                        new ( l_slot ) qslot( 0 );
                    }
                }
            }
    } PACK;

} // queues
} // fof
