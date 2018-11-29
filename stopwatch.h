#pragma once

#include <cstdint>
#include <ctime>
#include <string>
#include <iostream>
#include <new>

// T must be an enum
template<typename T>
class stop_watch
{
    static_assert( std::is_enum<T>::value , "type T is not an enum" );

    private:
	stop_watch() = delete;
	stop_watch( const stop_watch & ) = delete;
	stop_watch & operator=( const stop_watch & ) = delete;

	struct t_split
	{
	    int64_t m_time;
	    T       m_id;
	    bool    m_mark;
	    uint8_t m_padding[16-( sizeof(m_time) + sizeof(m_id) + sizeof(m_mark) )];

	    t_split()
	    :m_time{ 0 },
	     m_mark( false )
	    {
	    }

	    t_split( const int64_t a_time,
	             const T       a_id,
	             const bool    a_mark)
	    :m_time{ a_time },
	     m_id{ a_id },
	     m_mark( a_mark )
            {
            }
	};

	std::string m_name;
	t_split *   m_splits;
	t_split *   m_split;

	int64_t epoch_nanos()
	{
	    timespec l_ts;
	    ::clock_gettime( CLOCK_REALTIME , &l_ts );
	    return( static_cast<int64_t>( l_ts.tv_sec ) * 1000000000LL +
		    static_cast<int64_t>( l_ts.tv_nsec ) );
	}

    protected:

    public:
	stop_watch( const char * a_name , const uint64_t a_splits )
	:m_name( a_name ),
	 m_splits( new t_split[ a_splits ] )
	{
	    reset();
	}

	virtual ~stop_watch()
	{
	    delete []m_splits;
	}

	void reset()
	{
	    m_split = m_splits;
	}

	[[gnu::noinline]] void split( const T a_id , const bool a_mark = false )
	{
            new ( m_split ) t_split{ epoch_nanos() , a_id , a_mark };
#if 0 
	    m_split->m_time = epoch_nanos();
	    m_split->m_id   = a_id;
	    m_split->m_mark = a_mark;
#endif
	    m_split++;
	}

	void splits()
	{
	   for( auto l_split = m_splits; 
		l_split != m_split;
		++l_split )
	   {
std::cout << l_split->m_time << " " << (long)l_split->m_id << std::endl;
	   }
	}
};
