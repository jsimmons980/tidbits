#pragma once

#include <iostream>
#include <cstdint>
#include <string>
#include <iomanip>

#define ALWAYS_INLINE inline __attribute__((always_inline))
#define NEVER_INLINE  __attribute__((noinline))
#define PACK          __attribute__((packed))

namespace mktdata
{

    static NEVER_INLINE void copy( char * a_dst , const char * a_src , size_t a_size )
    {
        while( ( *a_src != '\0' ) && ( a_size ) )
        {
            *a_dst++ = *a_src++;
            --a_size;
        }
        *a_dst = '\0';
    }

    static NEVER_INLINE std::string asString( const char * a_data , size_t a_size )
    {
        std::string l_string;
        while( ( *a_data != '\0' ) && ( a_size ) )
        {
            l_string += *a_data;
            ++a_data;
            --a_size;
        }
        return( l_string );
    }

    struct Asset
    {
        char m_datum[6];
        ALWAYS_INLINE const std::string value() const { return( asString( m_datum , size() ) ); }
        ALWAYS_INLINE const size_t size() const { return( sizeof( *this ) ); }
        friend std::ostream & operator<<( std::ostream & a_stream , const Asset & a_instance )
        {
            a_stream << "Asset(" << a_instance.value() << ")";
            return( a_stream );
        }
    } PACK;

    struct CFICode
    {
        char m_datum[6];
        ALWAYS_INLINE const std::string value() const { return( asString( m_datum , size() ) ); }
        ALWAYS_INLINE const size_t size() const { return( sizeof( *this ) ); }
        friend std::ostream & operator<<( std::ostream & a_stream , const CFICode & a_instance )
        {
            a_stream << "CFICode(" << a_instance.value() << ")";
            return( a_stream );
        }
    } PACK;

    struct CHAR
    {
        char m_datum;
        ALWAYS_INLINE const char value() const { return( m_datum ); }
        friend std::ostream & operator<<( std::ostream & a_stream , const CHAR & a_instance )
        {
            a_stream << "CHAR(" << a_instance.value() << ")";
            return( a_stream );
        }
    } PACK;

    struct Currency
    {
        char m_datum[3];
        ALWAYS_INLINE const std::string value() const { return( asString( m_datum , size() ) ); }
        ALWAYS_INLINE const size_t size() const { return( sizeof( *this ) ); }
        friend std::ostream & operator<<( std::ostream & a_stream , const Currency & a_instance )
        {
            a_stream << "Currency(" << a_instance.value() << ")";
            return( a_stream );
        }
    } PACK;

    struct InstAttribType
    {
        uint8_t m_datum[0];  // forces sizeof( *this ) to return 0
        ALWAYS_INLINE const int8_t value() const { return( 24 ); }
        friend std::ostream & operator<<( std::ostream & a_stream , const InstAttribType & a_instance )
        {
            a_stream << "InstAttribType(" << +a_instance.value() << ")";
            return( a_stream );
        }
    } PACK;

    struct Int16
    {
        int16_t m_datum;
        ALWAYS_INLINE const int16_t value() const { return( m_datum ); }
        friend std::ostream & operator<<( std::ostream & a_stream , const Int16 & a_instance )
        {
            a_stream << "Int16(" << a_instance.value() << ")";
            return( a_stream );
        }
    } PACK;

    struct Int32
    {
        int32_t m_datum;
        ALWAYS_INLINE const int32_t value() const { return( m_datum ); }
        friend std::ostream & operator<<( std::ostream & a_stream , const Int32 & a_instance )
        {
            a_stream << "Int32(" << a_instance.value() << ")";
            return( a_stream );
        }
    } PACK;

    struct Int32NULL
    {
        int32_t m_datum;
        ALWAYS_INLINE const int32_t value() const { return( m_datum ); }
        ALWAYS_INLINE const bool isNull() const { return( m_datum == 2147483647 ); }
        friend std::ostream & operator<<( std::ostream & a_stream , const Int32NULL & a_instance )
        {
            if ( a_instance.isNull() )
            {
                a_stream << "Int32NULL(NULL)";
            }
            else
            {
                a_stream << "Int32NULL(" << a_instance.value() << ")";
            }
            return( a_stream );
        }
    } PACK;

    struct Int8
    {
        int8_t m_datum;
        ALWAYS_INLINE const int8_t value() const { return( m_datum ); }
        friend std::ostream & operator<<( std::ostream & a_stream , const Int8 & a_instance )
        {
            a_stream << "Int8(" << +a_instance.value() << ")";
            return( a_stream );
        }
    } PACK;

    struct Int8NULL
    {
        int8_t m_datum;
        ALWAYS_INLINE const int8_t value() const { return( m_datum ); }
        ALWAYS_INLINE const bool isNull() const { return( m_datum == 127 ); }
        friend std::ostream & operator<<( std::ostream & a_stream , const Int8NULL & a_instance )
        {
            if ( a_instance.isNull() )
            {
                a_stream << "Int8NULL(NULL)";
            }
            else
            {
                a_stream << "Int8NULL(" << +a_instance.value() << ")";
            }
            return( a_stream );
        }
    } PACK;

    struct LocalMktDate
    {
        uint16_t m_datum;
        ALWAYS_INLINE const uint16_t value() const { return( m_datum ); }
        ALWAYS_INLINE const bool isNull() const { return( m_datum == 65535 ); }
        friend std::ostream & operator<<( std::ostream & a_stream , const LocalMktDate & a_instance )
        {
            if ( a_instance.isNull() )
            {
                a_stream << "LocalMktDate(NULL)";
            }
            else
            {
                a_stream << "LocalMktDate(" << a_instance.value() << ")";
            }
            return( a_stream );
        }
    } PACK;

    struct MDEntryTypeChannelReset
    {
        uint8_t m_datum[0];  // forces sizeof( *this ) to return 0
        ALWAYS_INLINE const char value() const { return( 'J' ); }
        friend std::ostream & operator<<( std::ostream & a_stream , const MDEntryTypeChannelReset & a_instance )
        {
            a_stream << "MDEntryTypeChannelReset(" << a_instance.value() << ")";
            return( a_stream );
        }
    } PACK;

    struct MDEntryTypeLimits
    {
        uint8_t m_datum[0];  // forces sizeof( *this ) to return 0
        ALWAYS_INLINE const char value() const { return( 'g' ); }
        friend std::ostream & operator<<( std::ostream & a_stream , const MDEntryTypeLimits & a_instance )
        {
            a_stream << "MDEntryTypeLimits(" << a_instance.value() << ")";
            return( a_stream );
        }
    } PACK;

    struct MDEntryTypeTrade
    {
        uint8_t m_datum[0];  // forces sizeof( *this ) to return 0
        ALWAYS_INLINE const char value() const { return( '2' ); }
        friend std::ostream & operator<<( std::ostream & a_stream , const MDEntryTypeTrade & a_instance )
        {
            a_stream << "MDEntryTypeTrade(" << a_instance.value() << ")";
            return( a_stream );
        }
    } PACK;

    struct MDEntryTypeVol
    {
        uint8_t m_datum[0];  // forces sizeof( *this ) to return 0
        ALWAYS_INLINE const char value() const { return( 'e' ); }
        friend std::ostream & operator<<( std::ostream & a_stream , const MDEntryTypeVol & a_instance )
        {
            a_stream << "MDEntryTypeVol(" << a_instance.value() << ")";
            return( a_stream );
        }
    } PACK;

    struct MDFeedType
    {
        char m_datum[3];
        ALWAYS_INLINE const std::string value() const { return( asString( m_datum , size() ) ); }
        ALWAYS_INLINE const size_t size() const { return( sizeof( *this ) ); }
        friend std::ostream & operator<<( std::ostream & a_stream , const MDFeedType & a_instance )
        {
            a_stream << "MDFeedType(" << a_instance.value() << ")";
            return( a_stream );
        }
    } PACK;

    struct MDUpdateActionNew
    {
        uint8_t m_datum[0];  // forces sizeof( *this ) to return 0
        ALWAYS_INLINE const int8_t value() const { return( 0 ); }
        friend std::ostream & operator<<( std::ostream & a_stream , const MDUpdateActionNew & a_instance )
        {
            a_stream << "MDUpdateActionNew(" << +a_instance.value() << ")";
            return( a_stream );
        }
    } PACK;

    struct MDUpdateTypeNew
    {
        uint8_t m_datum[0];  // forces sizeof( *this ) to return 0
        ALWAYS_INLINE const int8_t value() const { return( 0 ); }
        friend std::ostream & operator<<( std::ostream & a_stream , const MDUpdateTypeNew & a_instance )
        {
            a_stream << "MDUpdateTypeNew(" << +a_instance.value() << ")";
            return( a_stream );
        }
    } PACK;

    struct QuoteReqId
    {
        char m_datum[23];
        ALWAYS_INLINE const std::string value() const { return( asString( m_datum , size() ) ); }
        ALWAYS_INLINE const size_t size() const { return( sizeof( *this ) ); }
        friend std::ostream & operator<<( std::ostream & a_stream , const QuoteReqId & a_instance )
        {
            a_stream << "QuoteReqId(" << a_instance.value() << ")";
            return( a_stream );
        }
    } PACK;

    struct SecurityExchange
    {
        char m_datum[4];
        ALWAYS_INLINE const std::string value() const { return( asString( m_datum , size() ) ); }
        ALWAYS_INLINE const size_t size() const { return( sizeof( *this ) ); }
        friend std::ostream & operator<<( std::ostream & a_stream , const SecurityExchange & a_instance )
        {
            a_stream << "SecurityExchange(" << a_instance.value() << ")";
            return( a_stream );
        }
    } PACK;

    struct SecurityGroup
    {
        char m_datum[6];
        ALWAYS_INLINE const std::string value() const { return( asString( m_datum , size() ) ); }
        ALWAYS_INLINE const size_t size() const { return( sizeof( *this ) ); }
        friend std::ostream & operator<<( std::ostream & a_stream , const SecurityGroup & a_instance )
        {
            a_stream << "SecurityGroup(" << a_instance.value() << ")";
            return( a_stream );
        }
    } PACK;

    struct SecurityIDSource
    {
        uint8_t m_datum[0];  // forces sizeof( *this ) to return 0
        ALWAYS_INLINE const char value() const { return( '8' ); }
        friend std::ostream & operator<<( std::ostream & a_stream , const SecurityIDSource & a_instance )
        {
            a_stream << "SecurityIDSource(" << a_instance.value() << ")";
            return( a_stream );
        }
    } PACK;

    struct SecuritySubType
    {
        char m_datum[5];
        ALWAYS_INLINE const std::string value() const { return( asString( m_datum , size() ) ); }
        ALWAYS_INLINE const size_t size() const { return( sizeof( *this ) ); }
        friend std::ostream & operator<<( std::ostream & a_stream , const SecuritySubType & a_instance )
        {
            a_stream << "SecuritySubType(" << a_instance.value() << ")";
            return( a_stream );
        }
    } PACK;

    struct SecurityType
    {
        char m_datum[6];
        ALWAYS_INLINE const std::string value() const { return( asString( m_datum , size() ) ); }
        ALWAYS_INLINE const size_t size() const { return( sizeof( *this ) ); }
        friend std::ostream & operator<<( std::ostream & a_stream , const SecurityType & a_instance )
        {
            a_stream << "SecurityType(" << a_instance.value() << ")";
            return( a_stream );
        }
    } PACK;

    struct Symbol
    {
        char m_datum[20];
        ALWAYS_INLINE const std::string value() const { return( asString( m_datum , size() ) ); }
        ALWAYS_INLINE const size_t size() const { return( sizeof( *this ) ); }
        friend std::ostream & operator<<( std::ostream & a_stream , const Symbol & a_instance )
        {
            a_stream << "Symbol(" << a_instance.value() << ")";
            return( a_stream );
        }
    } PACK;

    struct Text
    {
        char m_datum[180];
        ALWAYS_INLINE const std::string value() const { return( asString( m_datum , size() ) ); }
        ALWAYS_INLINE const size_t size() const { return( sizeof( *this ) ); }
        friend std::ostream & operator<<( std::ostream & a_stream , const Text & a_instance )
        {
            a_stream << "Text(" << a_instance.value() << ")";
            return( a_stream );
        }
    } PACK;

    struct UnderlyingSymbol
    {
        char m_datum[20];
        ALWAYS_INLINE const std::string value() const { return( asString( m_datum , size() ) ); }
        ALWAYS_INLINE const size_t size() const { return( sizeof( *this ) ); }
        friend std::ostream & operator<<( std::ostream & a_stream , const UnderlyingSymbol & a_instance )
        {
            a_stream << "UnderlyingSymbol(" << a_instance.value() << ")";
            return( a_stream );
        }
    } PACK;

    struct UnitOfMeasure
    {
        char m_datum[30];
        ALWAYS_INLINE const std::string value() const { return( asString( m_datum , size() ) ); }
        ALWAYS_INLINE const size_t size() const { return( sizeof( *this ) ); }
        friend std::ostream & operator<<( std::ostream & a_stream , const UnitOfMeasure & a_instance )
        {
            a_stream << "UnitOfMeasure(" << a_instance.value() << ")";
            return( a_stream );
        }
    } PACK;

    struct UserDefinedInstrument
    {
        char m_datum[1];
        ALWAYS_INLINE const std::string value() const { return( asString( m_datum , size() ) ); }
        ALWAYS_INLINE const size_t size() const { return( sizeof( *this ) ); }
        friend std::ostream & operator<<( std::ostream & a_stream , const UserDefinedInstrument & a_instance )
        {
            a_stream << "UserDefinedInstrument(" << a_instance.value() << ")";
            return( a_stream );
        }
    } PACK;

    struct uInt32
    {
        uint32_t m_datum;
        ALWAYS_INLINE const uint32_t value() const { return( m_datum ); }
        friend std::ostream & operator<<( std::ostream & a_stream , const uInt32 & a_instance )
        {
            a_stream << "uInt32(" << a_instance.value() << ")";
            return( a_stream );
        }
    } PACK;

    struct uInt32NULL
    {
        uint32_t m_datum;
        ALWAYS_INLINE const uint32_t value() const { return( m_datum ); }
        ALWAYS_INLINE const bool isNull() const { return( m_datum == 4294967295 ); }
        friend std::ostream & operator<<( std::ostream & a_stream , const uInt32NULL & a_instance )
        {
            if ( a_instance.isNull() )
            {
                a_stream << "uInt32NULL(NULL)";
            }
            else
            {
                a_stream << "uInt32NULL(" << a_instance.value() << ")";
            }
            return( a_stream );
        }
    } PACK;

    struct uInt64
    {
        uint64_t m_datum;
        ALWAYS_INLINE const uint64_t value() const { return( m_datum ); }
        friend std::ostream & operator<<( std::ostream & a_stream , const uInt64 & a_instance )
        {
            a_stream << "uInt64(" << a_instance.value() << ")";
            return( a_stream );
        }
    } PACK;

    struct uInt64NULL
    {
        uint64_t m_datum;
        ALWAYS_INLINE const uint64_t value() const { return( m_datum ); }
        ALWAYS_INLINE const bool isNull() const { return( m_datum == 18446744073709551615ULL ); }
        friend std::ostream & operator<<( std::ostream & a_stream , const uInt64NULL & a_instance )
        {
            if ( a_instance.isNull() )
            {
                a_stream << "uInt64NULL(NULL)";
            }
            else
            {
                a_stream << "uInt64NULL(" << a_instance.value() << ")";
            }
            return( a_stream );
        }
    } PACK;

    struct uInt8
    {
        uint8_t m_datum;
        ALWAYS_INLINE const uint8_t value() const { return( m_datum ); }
        friend std::ostream & operator<<( std::ostream & a_stream , const uInt8 & a_instance )
        {
            a_stream << "uInt8(" << +a_instance.value() << ")";
            return( a_stream );
        }
    } PACK;

    struct uInt8NULL
    {
        uint8_t m_datum;
        ALWAYS_INLINE const uint8_t value() const { return( m_datum ); }
        ALWAYS_INLINE const bool isNull() const { return( m_datum == 255 ); }
        friend std::ostream & operator<<( std::ostream & a_stream , const uInt8NULL & a_instance )
        {
            if ( a_instance.isNull() )
            {
                a_stream << "uInt8NULL(NULL)";
            }
            else
            {
                a_stream << "uInt8NULL(" << +a_instance.value() << ")";
            }
            return( a_stream );
        }
    } PACK;

    struct Decimal9
    {

        struct mantissa
        {
            int64_t m_datum;
            ALWAYS_INLINE const int64_t value() const { return( m_datum ); }
            friend std::ostream & operator<<( std::ostream & a_stream , const mantissa & a_instance )
            {
                a_stream << "mantissa(" << a_instance.value() << ")";
                return( a_stream );
            }
        } PACK;

        struct exponent
        {
            uint8_t m_datum[0];  // forces sizeof( *this ) to return 0
            ALWAYS_INLINE const int8_t value() const { return( -9 ); }
            friend std::ostream & operator<<( std::ostream & a_stream , const exponent & a_instance )
            {
                a_stream << "exponent(" << +a_instance.value() << ")";
                return( a_stream );
            }
        } PACK;

        mantissa m_mantissa;
        exponent m_exponent;

        friend std::ostream & operator<<( std::ostream & a_stream , const Decimal9 & a_instance )
        {
            a_stream << "Decimal9(";
            a_stream << "[" << a_instance.m_mantissa << "]";
            a_stream << "[" << a_instance.m_exponent << "]";
            a_stream << ")";
            return( a_stream );
        }
    } PACK;

    struct Decimal9NULL
    {

        struct mantissa
        {
            int64_t m_datum;
            ALWAYS_INLINE const int64_t value() const { return( m_datum ); }
            ALWAYS_INLINE const bool isNull() const { return( m_datum == 9223372036854775807 ); }
            friend std::ostream & operator<<( std::ostream & a_stream , const mantissa & a_instance )
            {
                if ( a_instance.isNull() )
                {
                    a_stream << "mantissa(NULL)";
                }
                else
                {
                    a_stream << "mantissa(" << a_instance.value() << ")";
                }
                return( a_stream );
            }
        } PACK;

        struct exponent
        {
            uint8_t m_datum[0];  // forces sizeof( *this ) to return 0
            ALWAYS_INLINE const int8_t value() const { return( -9 ); }
            friend std::ostream & operator<<( std::ostream & a_stream , const exponent & a_instance )
            {
                a_stream << "exponent(" << +a_instance.value() << ")";
                return( a_stream );
            }
        } PACK;

        mantissa m_mantissa;
        exponent m_exponent;

        friend std::ostream & operator<<( std::ostream & a_stream , const Decimal9NULL & a_instance )
        {
            a_stream << "Decimal9NULL(";
            a_stream << "[" << a_instance.m_mantissa << "]";
            a_stream << "[" << a_instance.m_exponent << "]";
            a_stream << ")";
            return( a_stream );
        }
    } PACK;

    struct DecimalQty
    {

        struct mantissa
        {
            int32_t m_datum;
            ALWAYS_INLINE const int32_t value() const { return( m_datum ); }
            ALWAYS_INLINE const bool isNull() const { return( m_datum == 2147483647 ); }
            friend std::ostream & operator<<( std::ostream & a_stream , const mantissa & a_instance )
            {
                if ( a_instance.isNull() )
                {
                    a_stream << "mantissa(NULL)";
                }
                else
                {
                    a_stream << "mantissa(" << a_instance.value() << ")";
                }
                return( a_stream );
            }
        } PACK;

        struct exponent
        {
            uint8_t m_datum[0];  // forces sizeof( *this ) to return 0
            ALWAYS_INLINE const int8_t value() const { return( -4 ); }
            friend std::ostream & operator<<( std::ostream & a_stream , const exponent & a_instance )
            {
                a_stream << "exponent(" << +a_instance.value() << ")";
                return( a_stream );
            }
        } PACK;

        mantissa m_mantissa;
        exponent m_exponent;

        friend std::ostream & operator<<( std::ostream & a_stream , const DecimalQty & a_instance )
        {
            a_stream << "DecimalQty(";
            a_stream << "[" << a_instance.m_mantissa << "]";
            a_stream << "[" << a_instance.m_exponent << "]";
            a_stream << ")";
            return( a_stream );
        }
    } PACK;

    struct FLOAT
    {

        struct mantissa
        {
            int64_t m_datum;
            ALWAYS_INLINE const int64_t value() const { return( m_datum ); }
            friend std::ostream & operator<<( std::ostream & a_stream , const mantissa & a_instance )
            {
                a_stream << "mantissa(" << a_instance.value() << ")";
                return( a_stream );
            }
        } PACK;

        struct exponent
        {
            uint8_t m_datum[0];  // forces sizeof( *this ) to return 0
            ALWAYS_INLINE const int8_t value() const { return( -7 ); }
            friend std::ostream & operator<<( std::ostream & a_stream , const exponent & a_instance )
            {
                a_stream << "exponent(" << +a_instance.value() << ")";
                return( a_stream );
            }
        } PACK;

        mantissa m_mantissa;
        exponent m_exponent;

        friend std::ostream & operator<<( std::ostream & a_stream , const FLOAT & a_instance )
        {
            a_stream << "FLOAT(";
            a_stream << "[" << a_instance.m_mantissa << "]";
            a_stream << "[" << a_instance.m_exponent << "]";
            a_stream << ")";
            return( a_stream );
        }
    } PACK;

    struct MaturityMonthYear
    {

        struct year
        {
            uint16_t m_datum;
            ALWAYS_INLINE const uint16_t value() const { return( m_datum ); }
            ALWAYS_INLINE const bool isNull() const { return( m_datum == 65535 ); }
            friend std::ostream & operator<<( std::ostream & a_stream , const year & a_instance )
            {
                if ( a_instance.isNull() )
                {
                    a_stream << "year(NULL)";
                }
                else
                {
                    a_stream << "year(" << a_instance.value() << ")";
                }
                return( a_stream );
            }
        } PACK;

        struct month
        {
            uint8_t m_datum;
            ALWAYS_INLINE const uint8_t value() const { return( m_datum ); }
            ALWAYS_INLINE const bool isNull() const { return( m_datum == 255 ); }
            friend std::ostream & operator<<( std::ostream & a_stream , const month & a_instance )
            {
                if ( a_instance.isNull() )
                {
                    a_stream << "month(NULL)";
                }
                else
                {
                    a_stream << "month(" << +a_instance.value() << ")";
                }
                return( a_stream );
            }
        } PACK;

        struct day
        {
            uint8_t m_datum;
            ALWAYS_INLINE const uint8_t value() const { return( m_datum ); }
            ALWAYS_INLINE const bool isNull() const { return( m_datum == 255 ); }
            friend std::ostream & operator<<( std::ostream & a_stream , const day & a_instance )
            {
                if ( a_instance.isNull() )
                {
                    a_stream << "day(NULL)";
                }
                else
                {
                    a_stream << "day(" << +a_instance.value() << ")";
                }
                return( a_stream );
            }
        } PACK;

        struct week
        {
            uint8_t m_datum;
            ALWAYS_INLINE const uint8_t value() const { return( m_datum ); }
            ALWAYS_INLINE const bool isNull() const { return( m_datum == 255 ); }
            friend std::ostream & operator<<( std::ostream & a_stream , const week & a_instance )
            {
                if ( a_instance.isNull() )
                {
                    a_stream << "week(NULL)";
                }
                else
                {
                    a_stream << "week(" << +a_instance.value() << ")";
                }
                return( a_stream );
            }
        } PACK;

        year m_year;
        month m_month;
        day m_day;
        week m_week;

        friend std::ostream & operator<<( std::ostream & a_stream , const MaturityMonthYear & a_instance )
        {
            a_stream << "MaturityMonthYear(";
            a_stream << "[" << a_instance.m_year << "]";
            a_stream << "[" << a_instance.m_month << "]";
            a_stream << "[" << a_instance.m_day << "]";
            a_stream << "[" << a_instance.m_week << "]";
            a_stream << ")";
            return( a_stream );
        }
    } PACK;

    struct PRICE
    {

        struct mantissa
        {
            int64_t m_datum;
            ALWAYS_INLINE const int64_t value() const { return( m_datum ); }
            friend std::ostream & operator<<( std::ostream & a_stream , const mantissa & a_instance )
            {
                a_stream << "mantissa(" << a_instance.value() << ")";
                return( a_stream );
            }
        } PACK;

        struct exponent
        {
            uint8_t m_datum[0];  // forces sizeof( *this ) to return 0
            ALWAYS_INLINE const int8_t value() const { return( -7 ); }
            friend std::ostream & operator<<( std::ostream & a_stream , const exponent & a_instance )
            {
                a_stream << "exponent(" << +a_instance.value() << ")";
                return( a_stream );
            }
        } PACK;

        mantissa m_mantissa;
        exponent m_exponent;

        friend std::ostream & operator<<( std::ostream & a_stream , const PRICE & a_instance )
        {
            a_stream << "PRICE(";
            a_stream << "[" << a_instance.m_mantissa << "]";
            a_stream << "[" << a_instance.m_exponent << "]";
            a_stream << ")";
            return( a_stream );
        }
    } PACK;

    struct PRICE9
    {

        struct mantissa
        {
            int64_t m_datum;
            ALWAYS_INLINE const int64_t value() const { return( m_datum ); }
            friend std::ostream & operator<<( std::ostream & a_stream , const mantissa & a_instance )
            {
                a_stream << "mantissa(" << a_instance.value() << ")";
                return( a_stream );
            }
        } PACK;

        struct exponent
        {
            uint8_t m_datum[0];  // forces sizeof( *this ) to return 0
            ALWAYS_INLINE const int8_t value() const { return( -9 ); }
            friend std::ostream & operator<<( std::ostream & a_stream , const exponent & a_instance )
            {
                a_stream << "exponent(" << +a_instance.value() << ")";
                return( a_stream );
            }
        } PACK;

        mantissa m_mantissa;
        exponent m_exponent;

        friend std::ostream & operator<<( std::ostream & a_stream , const PRICE9 & a_instance )
        {
            a_stream << "PRICE9(";
            a_stream << "[" << a_instance.m_mantissa << "]";
            a_stream << "[" << a_instance.m_exponent << "]";
            a_stream << ")";
            return( a_stream );
        }
    } PACK;

    struct PRICENULL
    {

        struct mantissa
        {
            int64_t m_datum;
            ALWAYS_INLINE const int64_t value() const { return( m_datum ); }
            ALWAYS_INLINE const bool isNull() const { return( m_datum == 9223372036854775807 ); }
            friend std::ostream & operator<<( std::ostream & a_stream , const mantissa & a_instance )
            {
                if ( a_instance.isNull() )
                {
                    a_stream << "mantissa(NULL)";
                }
                else
                {
                    a_stream << "mantissa(" << a_instance.value() << ")";
                }
                return( a_stream );
            }
        } PACK;

        struct exponent
        {
            uint8_t m_datum[0];  // forces sizeof( *this ) to return 0
            ALWAYS_INLINE const int8_t value() const { return( -7 ); }
            friend std::ostream & operator<<( std::ostream & a_stream , const exponent & a_instance )
            {
                a_stream << "exponent(" << +a_instance.value() << ")";
                return( a_stream );
            }
        } PACK;

        mantissa m_mantissa;
        exponent m_exponent;

        friend std::ostream & operator<<( std::ostream & a_stream , const PRICENULL & a_instance )
        {
            a_stream << "PRICENULL(";
            a_stream << "[" << a_instance.m_mantissa << "]";
            a_stream << "[" << a_instance.m_exponent << "]";
            a_stream << ")";
            return( a_stream );
        }
    } PACK;

    struct PRICENULL9
    {

        struct mantissa
        {
            int64_t m_datum;
            ALWAYS_INLINE const int64_t value() const { return( m_datum ); }
            ALWAYS_INLINE const bool isNull() const { return( m_datum == 9223372036854775807 ); }
            friend std::ostream & operator<<( std::ostream & a_stream , const mantissa & a_instance )
            {
                if ( a_instance.isNull() )
                {
                    a_stream << "mantissa(NULL)";
                }
                else
                {
                    a_stream << "mantissa(" << a_instance.value() << ")";
                }
                return( a_stream );
            }
        } PACK;

        struct exponent
        {
            uint8_t m_datum[0];  // forces sizeof( *this ) to return 0
            ALWAYS_INLINE const int8_t value() const { return( -9 ); }
            friend std::ostream & operator<<( std::ostream & a_stream , const exponent & a_instance )
            {
                a_stream << "exponent(" << +a_instance.value() << ")";
                return( a_stream );
            }
        } PACK;

        mantissa m_mantissa;
        exponent m_exponent;

        friend std::ostream & operator<<( std::ostream & a_stream , const PRICENULL9 & a_instance )
        {
            a_stream << "PRICENULL9(";
            a_stream << "[" << a_instance.m_mantissa << "]";
            a_stream << "[" << a_instance.m_exponent << "]";
            a_stream << ")";
            return( a_stream );
        }
    } PACK;

    struct groupSize
    {

        struct blockLength
        {
            uint16_t m_datum;
            ALWAYS_INLINE const uint16_t value() const { return( m_datum ); }
            friend std::ostream & operator<<( std::ostream & a_stream , const blockLength & a_instance )
            {
                a_stream << "blockLength(" << a_instance.value() << ")";
                return( a_stream );
            }
        } PACK;

        struct numInGroup
        {
            uint8_t m_datum;
            ALWAYS_INLINE const uint8_t value() const { return( m_datum ); }
            friend std::ostream & operator<<( std::ostream & a_stream , const numInGroup & a_instance )
            {
                a_stream << "numInGroup(" << +a_instance.value() << ")";
                return( a_stream );
            }
        } PACK;

        blockLength m_blockLength;
        numInGroup m_numInGroup;

        friend std::ostream & operator<<( std::ostream & a_stream , const groupSize & a_instance )
        {
            a_stream << "groupSize(";
            a_stream << "[" << a_instance.m_blockLength << "]";
            a_stream << "[" << a_instance.m_numInGroup << "]";
            a_stream << ")";
            return( a_stream );
        }
    } PACK;

    struct groupSize8Byte
    {

        struct blockLength
        {
            uint16_t m_datum;
            ALWAYS_INLINE const uint16_t value() const { return( m_datum ); }
            friend std::ostream & operator<<( std::ostream & a_stream , const blockLength & a_instance )
            {
                a_stream << "blockLength(" << a_instance.value() << ")";
                return( a_stream );
            }
        } PACK;

        struct numInGroup
        {
            uint8_t m_datum;
            ALWAYS_INLINE const uint8_t value() const { return( m_datum ); }
            friend std::ostream & operator<<( std::ostream & a_stream , const numInGroup & a_instance )
            {
                a_stream << "numInGroup(" << +a_instance.value() << ")";
                return( a_stream );
            }
        } PACK;

        blockLength m_blockLength;
        uint8_t m_padding[5];
        numInGroup m_numInGroup;

        friend std::ostream & operator<<( std::ostream & a_stream , const groupSize8Byte & a_instance )
        {
            a_stream << "groupSize8Byte(";
            a_stream << "[" << a_instance.m_blockLength << "]";
            a_stream << "[" << a_instance.m_numInGroup << "]";
            a_stream << ")";
            return( a_stream );
        }
    } PACK;

    struct groupSizeEncoding
    {

        struct blockLength
        {
            uint16_t m_datum;
            ALWAYS_INLINE const uint16_t value() const { return( m_datum ); }
            friend std::ostream & operator<<( std::ostream & a_stream , const blockLength & a_instance )
            {
                a_stream << "blockLength(" << a_instance.value() << ")";
                return( a_stream );
            }
        } PACK;

        struct numInGroup
        {
            uint16_t m_datum;
            ALWAYS_INLINE const uint16_t value() const { return( m_datum ); }
            friend std::ostream & operator<<( std::ostream & a_stream , const numInGroup & a_instance )
            {
                a_stream << "numInGroup(" << a_instance.value() << ")";
                return( a_stream );
            }
        } PACK;

        blockLength m_blockLength;
        numInGroup m_numInGroup;

        friend std::ostream & operator<<( std::ostream & a_stream , const groupSizeEncoding & a_instance )
        {
            a_stream << "groupSizeEncoding(";
            a_stream << "[" << a_instance.m_blockLength << "]";
            a_stream << "[" << a_instance.m_numInGroup << "]";
            a_stream << ")";
            return( a_stream );
        }
    } PACK;

    struct messageHeader
    {

        struct blockLength
        {
            uint16_t m_datum;
            ALWAYS_INLINE const uint16_t value() const { return( m_datum ); }
            friend std::ostream & operator<<( std::ostream & a_stream , const blockLength & a_instance )
            {
                a_stream << "blockLength(" << a_instance.value() << ")";
                return( a_stream );
            }
        } PACK;

        struct templateId
        {
            uint16_t m_datum;
            ALWAYS_INLINE const uint16_t value() const { return( m_datum ); }
            friend std::ostream & operator<<( std::ostream & a_stream , const templateId & a_instance )
            {
                a_stream << "templateId(" << a_instance.value() << ")";
                return( a_stream );
            }
        } PACK;

        struct schemaId
        {
            uint16_t m_datum;
            ALWAYS_INLINE const uint16_t value() const { return( m_datum ); }
            friend std::ostream & operator<<( std::ostream & a_stream , const schemaId & a_instance )
            {
                a_stream << "schemaId(" << a_instance.value() << ")";
                return( a_stream );
            }
        } PACK;

        struct version
        {
            uint16_t m_datum;
            ALWAYS_INLINE const uint16_t value() const { return( m_datum ); }
            friend std::ostream & operator<<( std::ostream & a_stream , const version & a_instance )
            {
                a_stream << "version(" << a_instance.value() << ")";
                return( a_stream );
            }
        } PACK;

        blockLength m_blockLength;
        templateId m_templateId;
        schemaId m_schemaId;
        version m_version;

        friend std::ostream & operator<<( std::ostream & a_stream , const messageHeader & a_instance )
        {
            a_stream << "messageHeader(";
            a_stream << "[" << a_instance.m_blockLength << "]";
            a_stream << "[" << a_instance.m_templateId << "]";
            a_stream << "[" << a_instance.m_schemaId << "]";
            a_stream << "[" << a_instance.m_version << "]";
            a_stream << ")";
            return( a_stream );
        }
    } PACK;

    struct Message
    {
        uint16_t      m_size;
        messageHeader m_mh;
        uint8_t       m_sbeData[0];

        ALWAYS_INLINE Message * next()
        {
            return( reinterpret_cast<Message *>( (uintptr_t)this + m_size ) );
        }
    } PACK;

    struct AggressorSide
    {
        static constexpr uint8_t NoAggressor = 0;
        static constexpr uint8_t Buy = 1;
        static constexpr uint8_t Sell = 2;
        uint8_t m_datum;
        ALWAYS_INLINE const uint8_t value() const { return( m_datum ); }
        NEVER_INLINE static const char * text( const uint8_t a_value )
        {
            switch( a_value )
            {
                case NoAggressor: return( "NoAggressor" );
                case Buy: return( "Buy" );
                case Sell: return( "Sell" );
                default: return( "wtf" );
            }
        }
        ALWAYS_INLINE const char * text() const { return( text( m_datum ) ); }
        friend std::ostream & operator<<( std::ostream & a_stream , const AggressorSide & a_instance )
        {
            a_stream << "AggressorSide(" << a_instance.text() << ")";
            return( a_stream );
        }
    } PACK;

    struct EventType
    {
        static constexpr uint8_t Activation = 5;
        static constexpr uint8_t LastEligibleTradeDate = 7;
        uint8_t m_datum;
        ALWAYS_INLINE const uint8_t value() const { return( m_datum ); }
        NEVER_INLINE static const char * text( const uint8_t a_value )
        {
            switch( a_value )
            {
                case Activation: return( "Activation" );
                case LastEligibleTradeDate: return( "LastEligibleTradeDate" );
                default: return( "wtf" );
            }
        }
        ALWAYS_INLINE const char * text() const { return( text( m_datum ) ); }
        friend std::ostream & operator<<( std::ostream & a_stream , const EventType & a_instance )
        {
            a_stream << "EventType(" << a_instance.text() << ")";
            return( a_stream );
        }
    } PACK;

    struct HaltReason
    {
        static constexpr uint8_t GroupSchedule = 0;
        static constexpr uint8_t SurveillanceIntervention = 1;
        static constexpr uint8_t MarketEvent = 2;
        static constexpr uint8_t InstrumentActivation = 3;
        static constexpr uint8_t InstrumentExpiration = 4;
        static constexpr uint8_t Unknown = 5;
        static constexpr uint8_t RecoveryInProcess = 6;
        uint8_t m_datum;
        ALWAYS_INLINE const uint8_t value() const { return( m_datum ); }
        NEVER_INLINE static const char * text( const uint8_t a_value )
        {
            switch( a_value )
            {
                case GroupSchedule: return( "GroupSchedule" );
                case SurveillanceIntervention: return( "SurveillanceIntervention" );
                case MarketEvent: return( "MarketEvent" );
                case InstrumentActivation: return( "InstrumentActivation" );
                case InstrumentExpiration: return( "InstrumentExpiration" );
                case Unknown: return( "Unknown" );
                case RecoveryInProcess: return( "RecoveryInProcess" );
                default: return( "wtf" );
            }
        }
        ALWAYS_INLINE const char * text() const { return( text( m_datum ) ); }
        friend std::ostream & operator<<( std::ostream & a_stream , const HaltReason & a_instance )
        {
            a_stream << "HaltReason(" << a_instance.text() << ")";
            return( a_stream );
        }
    } PACK;

    struct LegSide
    {
        static constexpr uint8_t BuySide = 1;
        static constexpr uint8_t SellSide = 2;
        uint8_t m_datum;
        ALWAYS_INLINE const uint8_t value() const { return( m_datum ); }
        NEVER_INLINE static const char * text( const uint8_t a_value )
        {
            switch( a_value )
            {
                case BuySide: return( "BuySide" );
                case SellSide: return( "SellSide" );
                default: return( "wtf" );
            }
        }
        ALWAYS_INLINE const char * text() const { return( text( m_datum ) ); }
        friend std::ostream & operator<<( std::ostream & a_stream , const LegSide & a_instance )
        {
            a_stream << "LegSide(" << a_instance.text() << ")";
            return( a_stream );
        }
    } PACK;

    struct MDEntryType
    {
        static constexpr char Bid = '0';
        static constexpr char Offer = '1';
        static constexpr char Trade = '2';
        static constexpr char OpenPrice = '4';
        static constexpr char SettlementPrice = '6';
        static constexpr char TradingSessionHighPrice = '7';
        static constexpr char TradingSessionLowPrice = '8';
        static constexpr char ClearedVolume = 'B';
        static constexpr char OpenInterest = 'C';
        static constexpr char ImpliedBid = 'E';
        static constexpr char ImpliedOffer = 'F';
        static constexpr char BookReset = 'J';
        static constexpr char SessionHighBid = 'N';
        static constexpr char SessionLowOffer = 'O';
        static constexpr char FixingPrice = 'W';
        static constexpr char ElectronicVolume = 'e';
        static constexpr char ThresholdLimitsandPriceBandVariation = 'g';
        char m_datum;
        ALWAYS_INLINE const char value() const { return( m_datum ); }
        NEVER_INLINE static const char * text( const char a_value )
        {
            switch( a_value )
            {
                case Bid: return( "Bid" );
                case Offer: return( "Offer" );
                case Trade: return( "Trade" );
                case OpenPrice: return( "OpenPrice" );
                case SettlementPrice: return( "SettlementPrice" );
                case TradingSessionHighPrice: return( "TradingSessionHighPrice" );
                case TradingSessionLowPrice: return( "TradingSessionLowPrice" );
                case ClearedVolume: return( "ClearedVolume" );
                case OpenInterest: return( "OpenInterest" );
                case ImpliedBid: return( "ImpliedBid" );
                case ImpliedOffer: return( "ImpliedOffer" );
                case BookReset: return( "BookReset" );
                case SessionHighBid: return( "SessionHighBid" );
                case SessionLowOffer: return( "SessionLowOffer" );
                case FixingPrice: return( "FixingPrice" );
                case ElectronicVolume: return( "ElectronicVolume" );
                case ThresholdLimitsandPriceBandVariation: return( "ThresholdLimitsandPriceBandVariation" );
                default: return( "wtf" );
            }
        }
        ALWAYS_INLINE const char * text() const { return( text( m_datum ) ); }
        friend std::ostream & operator<<( std::ostream & a_stream , const MDEntryType & a_instance )
        {
            a_stream << "MDEntryType(" << a_instance.text() << ")";
            return( a_stream );
        }
    } PACK;

    struct MDEntryTypeBook
    {
        static constexpr char Bid = '0';
        static constexpr char Offer = '1';
        static constexpr char ImpliedBid = 'E';
        static constexpr char ImpliedOffer = 'F';
        static constexpr char BookReset = 'J';
        char m_datum;
        ALWAYS_INLINE const char value() const { return( m_datum ); }
        NEVER_INLINE static const char * text( const char a_value )
        {
            switch( a_value )
            {
                case Bid: return( "Bid" );
                case Offer: return( "Offer" );
                case ImpliedBid: return( "ImpliedBid" );
                case ImpliedOffer: return( "ImpliedOffer" );
                case BookReset: return( "BookReset" );
                default: return( "wtf" );
            }
        }
        ALWAYS_INLINE const char * text() const { return( text( m_datum ) ); }
        friend std::ostream & operator<<( std::ostream & a_stream , const MDEntryTypeBook & a_instance )
        {
            a_stream << "MDEntryTypeBook(" << a_instance.text() << ")";
            return( a_stream );
        }
    } PACK;

    struct MDEntryTypeDailyStatistics
    {
        static constexpr char SettlementPrice = '6';
        static constexpr char ClearedVolume = 'B';
        static constexpr char OpenInterest = 'C';
        static constexpr char FixingPrice = 'W';
        char m_datum;
        ALWAYS_INLINE const char value() const { return( m_datum ); }
        NEVER_INLINE static const char * text( const char a_value )
        {
            switch( a_value )
            {
                case SettlementPrice: return( "SettlementPrice" );
                case ClearedVolume: return( "ClearedVolume" );
                case OpenInterest: return( "OpenInterest" );
                case FixingPrice: return( "FixingPrice" );
                default: return( "wtf" );
            }
        }
        ALWAYS_INLINE const char * text() const { return( text( m_datum ) ); }
        friend std::ostream & operator<<( std::ostream & a_stream , const MDEntryTypeDailyStatistics & a_instance )
        {
            a_stream << "MDEntryTypeDailyStatistics(" << a_instance.text() << ")";
            return( a_stream );
        }
    } PACK;

    struct MDEntryTypeStatistics
    {
        static constexpr char OpenPrice = '4';
        static constexpr char HighTrade = '7';
        static constexpr char LowTrade = '8';
        static constexpr char HighestBid = 'N';
        static constexpr char LowestOffer = 'O';
        char m_datum;
        ALWAYS_INLINE const char value() const { return( m_datum ); }
        NEVER_INLINE static const char * text( const char a_value )
        {
            switch( a_value )
            {
                case OpenPrice: return( "OpenPrice" );
                case HighTrade: return( "HighTrade" );
                case LowTrade: return( "LowTrade" );
                case HighestBid: return( "HighestBid" );
                case LowestOffer: return( "LowestOffer" );
                default: return( "wtf" );
            }
        }
        ALWAYS_INLINE const char * text() const { return( text( m_datum ) ); }
        friend std::ostream & operator<<( std::ostream & a_stream , const MDEntryTypeStatistics & a_instance )
        {
            a_stream << "MDEntryTypeStatistics(" << a_instance.text() << ")";
            return( a_stream );
        }
    } PACK;

    struct MDUpdateAction
    {
        static constexpr uint8_t New = 0;
        static constexpr uint8_t Change = 1;
        static constexpr uint8_t Delete = 2;
        static constexpr uint8_t DeleteThru = 3;
        static constexpr uint8_t DeleteFrom = 4;
        static constexpr uint8_t Overlay = 5;
        uint8_t m_datum;
        ALWAYS_INLINE const uint8_t value() const { return( m_datum ); }
        NEVER_INLINE static const char * text( const uint8_t a_value )
        {
            switch( a_value )
            {
                case New: return( "New" );
                case Change: return( "Change" );
                case Delete: return( "Delete" );
                case DeleteThru: return( "DeleteThru" );
                case DeleteFrom: return( "DeleteFrom" );
                case Overlay: return( "Overlay" );
                default: return( "wtf" );
            }
        }
        ALWAYS_INLINE const char * text() const { return( text( m_datum ) ); }
        friend std::ostream & operator<<( std::ostream & a_stream , const MDUpdateAction & a_instance )
        {
            a_stream << "MDUpdateAction(" << a_instance.text() << ")";
            return( a_stream );
        }
    } PACK;

    struct OpenCloseSettlFlag
    {
        static constexpr uint8_t DailyOpenPrice = 0;
        static constexpr uint8_t IndicativeOpeningPrice = 5;
        uint8_t m_datum;
        ALWAYS_INLINE const uint8_t value() const { return( m_datum ); }
        NEVER_INLINE static const char * text( const uint8_t a_value )
        {
            switch( a_value )
            {
                case DailyOpenPrice: return( "DailyOpenPrice" );
                case IndicativeOpeningPrice: return( "IndicativeOpeningPrice" );
                default: return( "wtf" );
            }
        }
        ALWAYS_INLINE const char * text() const { return( text( m_datum ) ); }
        friend std::ostream & operator<<( std::ostream & a_stream , const OpenCloseSettlFlag & a_instance )
        {
            a_stream << "OpenCloseSettlFlag(" << a_instance.text() << ")";
            return( a_stream );
        }
    } PACK;

    struct OrderUpdateAction
    {
        static constexpr uint8_t New = 0;
        static constexpr uint8_t Update = 1;
        static constexpr uint8_t Delete = 2;
        uint8_t m_datum;
        ALWAYS_INLINE const uint8_t value() const { return( m_datum ); }
        NEVER_INLINE static const char * text( const uint8_t a_value )
        {
            switch( a_value )
            {
                case New: return( "New" );
                case Update: return( "Update" );
                case Delete: return( "Delete" );
                default: return( "wtf" );
            }
        }
        ALWAYS_INLINE const char * text() const { return( text( m_datum ) ); }
        friend std::ostream & operator<<( std::ostream & a_stream , const OrderUpdateAction & a_instance )
        {
            a_stream << "OrderUpdateAction(" << a_instance.text() << ")";
            return( a_stream );
        }
    } PACK;

    struct PutOrCall
    {
        static constexpr uint8_t Put = 0;
        static constexpr uint8_t Call = 1;
        uint8_t m_datum;
        ALWAYS_INLINE const uint8_t value() const { return( m_datum ); }
        NEVER_INLINE static const char * text( const uint8_t a_value )
        {
            switch( a_value )
            {
                case Put: return( "Put" );
                case Call: return( "Call" );
                default: return( "wtf" );
            }
        }
        ALWAYS_INLINE const char * text() const { return( text( m_datum ) ); }
        friend std::ostream & operator<<( std::ostream & a_stream , const PutOrCall & a_instance )
        {
            a_stream << "PutOrCall(" << a_instance.text() << ")";
            return( a_stream );
        }
    } PACK;

    struct SecurityTradingEvent
    {
        static constexpr uint8_t NoEvent = 0;
        static constexpr uint8_t NoCancel = 1;
        static constexpr uint8_t ResetStatistics = 4;
        static constexpr uint8_t ImpliedMatchingON = 5;
        static constexpr uint8_t ImpliedMatchingOFF = 6;
        uint8_t m_datum;
        ALWAYS_INLINE const uint8_t value() const { return( m_datum ); }
        NEVER_INLINE static const char * text( const uint8_t a_value )
        {
            switch( a_value )
            {
                case NoEvent: return( "NoEvent" );
                case NoCancel: return( "NoCancel" );
                case ResetStatistics: return( "ResetStatistics" );
                case ImpliedMatchingON: return( "ImpliedMatchingON" );
                case ImpliedMatchingOFF: return( "ImpliedMatchingOFF" );
                default: return( "wtf" );
            }
        }
        ALWAYS_INLINE const char * text() const { return( text( m_datum ) ); }
        friend std::ostream & operator<<( std::ostream & a_stream , const SecurityTradingEvent & a_instance )
        {
            a_stream << "SecurityTradingEvent(" << a_instance.text() << ")";
            return( a_stream );
        }
    } PACK;

    struct SecurityTradingStatus
    {
        static constexpr uint8_t TradingHalt = 2;
        static constexpr uint8_t Close = 4;
        static constexpr uint8_t NewPriceIndication = 15;
        static constexpr uint8_t ReadyToTrade = 17;
        static constexpr uint8_t NotAvailableForTrading = 18;
        static constexpr uint8_t UnknownorInvalid = 20;
        static constexpr uint8_t PreOpen = 21;
        static constexpr uint8_t PreCross = 24;
        static constexpr uint8_t Cross = 25;
        static constexpr uint8_t PostClose = 26;
        static constexpr uint8_t NoChange = 103;
        uint8_t m_datum;
        ALWAYS_INLINE const uint8_t value() const { return( m_datum ); }
        NEVER_INLINE static const char * text( const uint8_t a_value )
        {
            switch( a_value )
            {
                case TradingHalt: return( "TradingHalt" );
                case Close: return( "Close" );
                case NewPriceIndication: return( "NewPriceIndication" );
                case ReadyToTrade: return( "ReadyToTrade" );
                case NotAvailableForTrading: return( "NotAvailableForTrading" );
                case UnknownorInvalid: return( "UnknownorInvalid" );
                case PreOpen: return( "PreOpen" );
                case PreCross: return( "PreCross" );
                case Cross: return( "Cross" );
                case PostClose: return( "PostClose" );
                case NoChange: return( "NoChange" );
                default: return( "wtf" );
            }
        }
        ALWAYS_INLINE const char * text() const { return( text( m_datum ) ); }
        friend std::ostream & operator<<( std::ostream & a_stream , const SecurityTradingStatus & a_instance )
        {
            a_stream << "SecurityTradingStatus(" << a_instance.text() << ")";
            return( a_stream );
        }
    } PACK;

    struct SecurityUpdateAction
    {
        static constexpr char Add = 'A';
        static constexpr char Delete = 'D';
        static constexpr char Modify = 'M';
        char m_datum;
        ALWAYS_INLINE const char value() const { return( m_datum ); }
        NEVER_INLINE static const char * text( const char a_value )
        {
            switch( a_value )
            {
                case Add: return( "Add" );
                case Delete: return( "Delete" );
                case Modify: return( "Modify" );
                default: return( "wtf" );
            }
        }
        ALWAYS_INLINE const char * text() const { return( text( m_datum ) ); }
        friend std::ostream & operator<<( std::ostream & a_stream , const SecurityUpdateAction & a_instance )
        {
            a_stream << "SecurityUpdateAction(" << a_instance.text() << ")";
            return( a_stream );
        }
    } PACK;

    struct InstAttribValue
    {
        uint32_t m_datum;
        uint32_t value() const { return( m_datum ); }
        ALWAYS_INLINE const bool isElectronicMatchEligible() const { return( m_datum & ( 1 << 0 ) ); }
        ALWAYS_INLINE const bool isOrderCrossEligible() const { return( m_datum & ( 1 << 1 ) ); }
        ALWAYS_INLINE const bool isBlockTradeEligible() const { return( m_datum & ( 1 << 2 ) ); }
        ALWAYS_INLINE const bool isEFPEligible() const { return( m_datum & ( 1 << 3 ) ); }
        ALWAYS_INLINE const bool isEBFEligible() const { return( m_datum & ( 1 << 4 ) ); }
        ALWAYS_INLINE const bool isEFSEligible() const { return( m_datum & ( 1 << 5 ) ); }
        ALWAYS_INLINE const bool isEFREligible() const { return( m_datum & ( 1 << 6 ) ); }
        ALWAYS_INLINE const bool isOTCEligible() const { return( m_datum & ( 1 << 7 ) ); }
        ALWAYS_INLINE const bool isiLinkIndicativeMassQuotingEligible() const { return( m_datum & ( 1 << 8 ) ); }
        ALWAYS_INLINE const bool isNegativeStrikeEligible() const { return( m_datum & ( 1 << 9 ) ); }
        ALWAYS_INLINE const bool isNegativePriceOutrightEligible() const { return( m_datum & ( 1 << 10 ) ); }
        ALWAYS_INLINE const bool isIsFractional() const { return( m_datum & ( 1 << 11 ) ); }
        ALWAYS_INLINE const bool isVolatilityQuotedOption() const { return( m_datum & ( 1 << 12 ) ); }
        ALWAYS_INLINE const bool isRFQCrossEligible() const { return( m_datum & ( 1 << 13 ) ); }
        ALWAYS_INLINE const bool isZeroPriceOutrightEligible() const { return( m_datum & ( 1 << 14 ) ); }
        ALWAYS_INLINE const bool isDecayingProductEligibility() const { return( m_datum & ( 1 << 15 ) ); }
        ALWAYS_INLINE const bool isVariableProductEligibility() const { return( m_datum & ( 1 << 16 ) ); }
        ALWAYS_INLINE const bool isDailyProductEligibility() const { return( m_datum & ( 1 << 17 ) ); }
        ALWAYS_INLINE const bool isGTOrdersEligibility() const { return( m_datum & ( 1 << 18 ) ); }
        ALWAYS_INLINE const bool isImpliedMatchingEligibility() const { return( m_datum & ( 1 << 19 ) ); }
        ALWAYS_INLINE const bool isTriangulationEligible() const { return( m_datum & ( 1 << 20 ) ); }
        ALWAYS_INLINE const bool isVariableCabEligible() const { return( m_datum & ( 1 << 21 ) ); }
        friend std::ostream & operator<<( std::ostream & a_stream , const InstAttribValue & a_instance )
        {
            a_stream << "InstAttribValue(0x" << std::hex << std::setw(2*sizeof(a_instance.m_datum)) << std::setfill('0') << +a_instance.m_datum << ',' << std::dec;
            if ( a_instance.isElectronicMatchEligible() )
            {
                a_stream << "ElectronicMatchEligible,";
            }
            if ( a_instance.isOrderCrossEligible() )
            {
                a_stream << "OrderCrossEligible,";
            }
            if ( a_instance.isBlockTradeEligible() )
            {
                a_stream << "BlockTradeEligible,";
            }
            if ( a_instance.isEFPEligible() )
            {
                a_stream << "EFPEligible,";
            }
            if ( a_instance.isEBFEligible() )
            {
                a_stream << "EBFEligible,";
            }
            if ( a_instance.isEFSEligible() )
            {
                a_stream << "EFSEligible,";
            }
            if ( a_instance.isEFREligible() )
            {
                a_stream << "EFREligible,";
            }
            if ( a_instance.isOTCEligible() )
            {
                a_stream << "OTCEligible,";
            }
            if ( a_instance.isiLinkIndicativeMassQuotingEligible() )
            {
                a_stream << "iLinkIndicativeMassQuotingEligible,";
            }
            if ( a_instance.isNegativeStrikeEligible() )
            {
                a_stream << "NegativeStrikeEligible,";
            }
            if ( a_instance.isNegativePriceOutrightEligible() )
            {
                a_stream << "NegativePriceOutrightEligible,";
            }
            if ( a_instance.isIsFractional() )
            {
                a_stream << "IsFractional,";
            }
            if ( a_instance.isVolatilityQuotedOption() )
            {
                a_stream << "VolatilityQuotedOption,";
            }
            if ( a_instance.isRFQCrossEligible() )
            {
                a_stream << "RFQCrossEligible,";
            }
            if ( a_instance.isZeroPriceOutrightEligible() )
            {
                a_stream << "ZeroPriceOutrightEligible,";
            }
            if ( a_instance.isDecayingProductEligibility() )
            {
                a_stream << "DecayingProductEligibility,";
            }
            if ( a_instance.isVariableProductEligibility() )
            {
                a_stream << "VariableProductEligibility,";
            }
            if ( a_instance.isDailyProductEligibility() )
            {
                a_stream << "DailyProductEligibility,";
            }
            if ( a_instance.isGTOrdersEligibility() )
            {
                a_stream << "GTOrdersEligibility,";
            }
            if ( a_instance.isImpliedMatchingEligibility() )
            {
                a_stream << "ImpliedMatchingEligibility,";
            }
            if ( a_instance.isTriangulationEligible() )
            {
                a_stream << "TriangulationEligible,";
            }
            if ( a_instance.isVariableCabEligible() )
            {
                a_stream << "VariableCabEligible,";
            }
            a_stream << ")";
            return( a_stream );
        }
    } PACK;

    struct MatchEventIndicator
    {
        uint8_t m_datum;
        uint8_t value() const { return( m_datum ); }
        ALWAYS_INLINE const bool isLastTradeMsg() const { return( m_datum & ( 1 << 0 ) ); }
        ALWAYS_INLINE const bool isLastVolumeMsg() const { return( m_datum & ( 1 << 1 ) ); }
        ALWAYS_INLINE const bool isLastQuoteMsg() const { return( m_datum & ( 1 << 2 ) ); }
        ALWAYS_INLINE const bool isLastStatsMsg() const { return( m_datum & ( 1 << 3 ) ); }
        ALWAYS_INLINE const bool isLastImpliedMsg() const { return( m_datum & ( 1 << 4 ) ); }
        ALWAYS_INLINE const bool isRecoveryMsg() const { return( m_datum & ( 1 << 5 ) ); }
        ALWAYS_INLINE const bool isReserved() const { return( m_datum & ( 1 << 6 ) ); }
        ALWAYS_INLINE const bool isEndOfEvent() const { return( m_datum & ( 1 << 7 ) ); }
        friend std::ostream & operator<<( std::ostream & a_stream , const MatchEventIndicator & a_instance )
        {
            a_stream << "MatchEventIndicator(0x" << std::hex << std::setw(2*sizeof(a_instance.m_datum)) << std::setfill('0') << +a_instance.m_datum << ',' << std::dec;
            if ( a_instance.isLastTradeMsg() )
            {
                a_stream << "LastTradeMsg,";
            }
            if ( a_instance.isLastVolumeMsg() )
            {
                a_stream << "LastVolumeMsg,";
            }
            if ( a_instance.isLastQuoteMsg() )
            {
                a_stream << "LastQuoteMsg,";
            }
            if ( a_instance.isLastStatsMsg() )
            {
                a_stream << "LastStatsMsg,";
            }
            if ( a_instance.isLastImpliedMsg() )
            {
                a_stream << "LastImpliedMsg,";
            }
            if ( a_instance.isRecoveryMsg() )
            {
                a_stream << "RecoveryMsg,";
            }
            if ( a_instance.isReserved() )
            {
                a_stream << "Reserved,";
            }
            if ( a_instance.isEndOfEvent() )
            {
                a_stream << "EndOfEvent,";
            }
            a_stream << ")";
            return( a_stream );
        }
    } PACK;

    struct SettlPriceType
    {
        uint8_t m_datum;
        uint8_t value() const { return( m_datum ); }
        ALWAYS_INLINE const bool isFinalDaily() const { return( m_datum & ( 1 << 0 ) ); }
        ALWAYS_INLINE const bool isActual() const { return( m_datum & ( 1 << 1 ) ); }
        ALWAYS_INLINE const bool isRounded() const { return( m_datum & ( 1 << 2 ) ); }
        ALWAYS_INLINE const bool isIntraday() const { return( m_datum & ( 1 << 3 ) ); }
        ALWAYS_INLINE const bool isReservedBits() const { return( m_datum & ( 1 << 4 ) ); }
        ALWAYS_INLINE const bool isNullValue() const { return( m_datum & ( 1 << 7 ) ); }
        friend std::ostream & operator<<( std::ostream & a_stream , const SettlPriceType & a_instance )
        {
            a_stream << "SettlPriceType(0x" << std::hex << std::setw(2*sizeof(a_instance.m_datum)) << std::setfill('0') << +a_instance.m_datum << ',' << std::dec;
            if ( a_instance.isFinalDaily() )
            {
                a_stream << "FinalDaily,";
            }
            if ( a_instance.isActual() )
            {
                a_stream << "Actual,";
            }
            if ( a_instance.isRounded() )
            {
                a_stream << "Rounded,";
            }
            if ( a_instance.isIntraday() )
            {
                a_stream << "Intraday,";
            }
            if ( a_instance.isReservedBits() )
            {
                a_stream << "ReservedBits,";
            }
            if ( a_instance.isNullValue() )
            {
                a_stream << "NullValue,";
            }
            a_stream << ")";
            return( a_stream );
        }
    } PACK;

    struct ChannelReset4
    {
        static constexpr int32_t id() { return( 4 ); }
        static constexpr const char * name() { return( "ChannelReset4" ); }

        uInt64 m_TransactTime;
        MatchEventIndicator m_MatchEventIndicator;
        uint8_t m_padding[ 9 - ( sizeof( m_TransactTime ) + sizeof( m_MatchEventIndicator ) ) ];

        uint8_t m_groupBegin[ 0 ];
        struct NoMDEntries
        {
            groupSize m_dimension;
            struct Entry
            {
                MDUpdateTypeNew m_MDUpdateAction;
                MDEntryTypeChannelReset m_MDEntryType;
                Int16 m_ApplID;
                uint8_t m_padding[ 2 - ( sizeof( m_MDUpdateAction ) + sizeof( m_MDEntryType ) + sizeof( m_ApplID ) ) ];

                friend std::ostream & operator<<( std::ostream & a_stream , const Entry & a_instance )
                {
                    a_stream << "           m_MDUpdateAction-->[" << a_instance.m_MDUpdateAction << "]\n";
                    a_stream << "           m_MDEntryType-->[" << a_instance.m_MDEntryType << "]\n";
                    a_stream << "           m_ApplID-->[" << a_instance.m_ApplID << "]\n";
                    return( a_stream );
                }
            } PACK m_entries[0];
            ALWAYS_INLINE const size_t elements() const { return( (size_t)m_dimension.m_numInGroup.value() ); }
            ALWAYS_INLINE const auto entriesBegin() const { return( &m_entries[0] ); }
            ALWAYS_INLINE const auto entriesEnd() const { return( &m_entries[ elements() ] ); }
            ALWAYS_INLINE const void * const next(){ return( (void *)entriesEnd() ); }
        } PACK m_NoMDEntries;

        friend std::ostream & operator<<( std::ostream & a_stream , const ChannelReset4 & a_instance )
        {
            a_stream << "ChannelReset4-->[" << (void *)&a_instance << "]\n";
            a_stream << "    m_TransactTime-->[" << a_instance.m_TransactTime << "]\n";
            a_stream << "    m_MatchEventIndicator-->[" << a_instance.m_MatchEventIndicator << "]\n";
            auto l_block = reinterpret_cast<const void *>( &a_instance.m_groupBegin[ 0 ] );
            {
                auto l_NoMDEntries = reinterpret_cast<const ChannelReset4::NoMDEntries *>( l_block );
                auto l_begin = l_NoMDEntries->entriesBegin();
                auto l_end   = l_NoMDEntries->entriesEnd();
                auto l_size  = l_NoMDEntries->elements();
                a_stream << "    " << "NoMDEntries-->[" << l_size << "]\n";
                for( auto l_entry = l_begin;
                     l_entry != l_end;
                     ++l_entry )
                {
                    a_stream << "        Entry-->[" << ( (l_entry-l_begin) + 1 ) << "/" << l_size << "," << (void *)l_entry << "]\n";
                    a_stream << *l_entry;
                }
                l_block = l_NoMDEntries->next();
            }

            return( a_stream );
        }
    } PACK;

    struct AdminHeartbeat12
    {
        static constexpr int32_t id() { return( 12 ); }
        static constexpr const char * name() { return( "AdminHeartbeat12" ); }

        friend std::ostream & operator<<( std::ostream & a_stream , const AdminHeartbeat12 & a_instance )
        {
            a_stream << "AdminHeartbeat12-->[" << (void *)&a_instance << "]\n";
            return( a_stream );
        }
    } PACK;

    struct AdminLogin15
    {
        static constexpr int32_t id() { return( 15 ); }
        static constexpr const char * name() { return( "AdminLogin15" ); }

        Int8 m_HeartBtInt;
        friend std::ostream & operator<<( std::ostream & a_stream , const AdminLogin15 & a_instance )
        {
            a_stream << "AdminLogin15-->[" << (void *)&a_instance << "]\n";
            a_stream << "    m_HeartBtInt-->[" << a_instance.m_HeartBtInt << "]\n";
            return( a_stream );
        }
    } PACK;

    struct AdminLogout16
    {
        static constexpr int32_t id() { return( 16 ); }
        static constexpr const char * name() { return( "AdminLogout16" ); }

        Text m_Text;
        friend std::ostream & operator<<( std::ostream & a_stream , const AdminLogout16 & a_instance )
        {
            a_stream << "AdminLogout16-->[" << (void *)&a_instance << "]\n";
            a_stream << "    m_Text-->[" << a_instance.m_Text << "]\n";
            return( a_stream );
        }
    } PACK;

    struct MDInstrumentDefinitionFuture27
    {
        static constexpr int32_t id() { return( 27 ); }
        static constexpr const char * name() { return( "MDInstrumentDefinitionFuture27" ); }

        MatchEventIndicator m_MatchEventIndicator;
        uInt32NULL m_TotNumReports;
        SecurityUpdateAction m_SecurityUpdateAction;
        uInt64 m_LastUpdateTime;
        SecurityTradingStatus m_MDSecurityTradingStatus;
        Int16 m_ApplID;
        uInt8 m_MarketSegmentID;
        uInt8 m_UnderlyingProduct;
        SecurityExchange m_SecurityExchange;
        SecurityGroup m_SecurityGroup;
        Asset m_Asset;
        Symbol m_Symbol;
        Int32 m_SecurityID;
        SecurityIDSource m_SecurityIDSource;
        SecurityType m_SecurityType;
        CFICode m_CFICode;
        MaturityMonthYear m_MaturityMonthYear;
        Currency m_Currency;
        Currency m_SettlCurrency;
        CHAR m_MatchAlgorithm;
        uInt32 m_MinTradeVol;
        uInt32 m_MaxTradeVol;
        PRICE m_MinPriceIncrement;
        FLOAT m_DisplayFactor;
        uInt8NULL m_MainFraction;
        uInt8NULL m_SubFraction;
        uInt8NULL m_PriceDisplayFormat;
        UnitOfMeasure m_UnitOfMeasure;
        PRICENULL m_UnitOfMeasureQty;
        PRICENULL m_TradingReferencePrice;
        SettlPriceType m_SettlPriceType;
        Int32NULL m_OpenInterestQty;
        Int32NULL m_ClearedVolume;
        PRICENULL m_HighLimitPrice;
        PRICENULL m_LowLimitPrice;
        PRICENULL m_MaxPriceVariation;
        Int32NULL m_DecayQuantity;
        LocalMktDate m_DecayStartDate;
        Int32NULL m_OriginalContractSize;
        Int32NULL m_ContractMultiplier;
        Int8NULL m_ContractMultiplierUnit;
        Int8NULL m_FlowScheduleType;
        PRICENULL m_MinPriceIncrementAmount;
        UserDefinedInstrument m_UserDefinedInstrument;
        LocalMktDate m_TradingReferenceDate;
        uint8_t m_padding[ 216 - ( sizeof( m_MatchEventIndicator ) + sizeof( m_TotNumReports ) + sizeof( m_SecurityUpdateAction ) + sizeof( m_LastUpdateTime ) + sizeof( m_MDSecurityTradingStatus ) + sizeof( m_ApplID ) + sizeof( m_MarketSegmentID ) + sizeof( m_UnderlyingProduct ) + sizeof( m_SecurityExchange ) + sizeof( m_SecurityGroup ) + sizeof( m_Asset ) + sizeof( m_Symbol ) + sizeof( m_SecurityID ) + sizeof( m_SecurityIDSource ) + sizeof( m_SecurityType ) + sizeof( m_CFICode ) + sizeof( m_MaturityMonthYear ) + sizeof( m_Currency ) + sizeof( m_SettlCurrency ) + sizeof( m_MatchAlgorithm ) + sizeof( m_MinTradeVol ) + sizeof( m_MaxTradeVol ) + sizeof( m_MinPriceIncrement ) + sizeof( m_DisplayFactor ) + sizeof( m_MainFraction ) + sizeof( m_SubFraction ) + sizeof( m_PriceDisplayFormat ) + sizeof( m_UnitOfMeasure ) + sizeof( m_UnitOfMeasureQty ) + sizeof( m_TradingReferencePrice ) + sizeof( m_SettlPriceType ) + sizeof( m_OpenInterestQty ) + sizeof( m_ClearedVolume ) + sizeof( m_HighLimitPrice ) + sizeof( m_LowLimitPrice ) + sizeof( m_MaxPriceVariation ) + sizeof( m_DecayQuantity ) + sizeof( m_DecayStartDate ) + sizeof( m_OriginalContractSize ) + sizeof( m_ContractMultiplier ) + sizeof( m_ContractMultiplierUnit ) + sizeof( m_FlowScheduleType ) + sizeof( m_MinPriceIncrementAmount ) + sizeof( m_UserDefinedInstrument ) + sizeof( m_TradingReferenceDate ) ) ];

        uint8_t m_groupBegin[ 0 ];
        struct NoEvents
        {
            groupSize m_dimension;
            struct Entry
            {
                EventType m_EventType;
                uInt64 m_EventTime;
                uint8_t m_padding[ 9 - ( sizeof( m_EventType ) + sizeof( m_EventTime ) ) ];

                friend std::ostream & operator<<( std::ostream & a_stream , const Entry & a_instance )
                {
                    a_stream << "           m_EventType-->[" << a_instance.m_EventType << "]\n";
                    a_stream << "           m_EventTime-->[" << a_instance.m_EventTime << "]\n";
                    return( a_stream );
                }
            } PACK m_entries[0];
            ALWAYS_INLINE const size_t elements() const { return( (size_t)m_dimension.m_numInGroup.value() ); }
            ALWAYS_INLINE const auto entriesBegin() const { return( &m_entries[0] ); }
            ALWAYS_INLINE const auto entriesEnd() const { return( &m_entries[ elements() ] ); }
            ALWAYS_INLINE const void * const next(){ return( (void *)entriesEnd() ); }
        } PACK m_NoEvents;

        struct NoMDFeedTypes
        {
            groupSize m_dimension;
            struct Entry
            {
                MDFeedType m_MDFeedType;
                Int8 m_MarketDepth;
                uint8_t m_padding[ 4 - ( sizeof( m_MDFeedType ) + sizeof( m_MarketDepth ) ) ];

                friend std::ostream & operator<<( std::ostream & a_stream , const Entry & a_instance )
                {
                    a_stream << "           m_MDFeedType-->[" << a_instance.m_MDFeedType << "]\n";
                    a_stream << "           m_MarketDepth-->[" << a_instance.m_MarketDepth << "]\n";
                    return( a_stream );
                }
            } PACK m_entries[0];
            ALWAYS_INLINE const size_t elements() const { return( (size_t)m_dimension.m_numInGroup.value() ); }
            ALWAYS_INLINE const auto entriesBegin() const { return( &m_entries[0] ); }
            ALWAYS_INLINE const auto entriesEnd() const { return( &m_entries[ elements() ] ); }
            ALWAYS_INLINE const void * const next(){ return( (void *)entriesEnd() ); }
        } PACK m_NoMDFeedTypes;

        struct NoInstAttrib
        {
            groupSize m_dimension;
            struct Entry
            {
                InstAttribType m_InstAttribType;
                InstAttribValue m_InstAttribValue;
                uint8_t m_padding[ 4 - ( sizeof( m_InstAttribType ) + sizeof( m_InstAttribValue ) ) ];

                friend std::ostream & operator<<( std::ostream & a_stream , const Entry & a_instance )
                {
                    a_stream << "           m_InstAttribType-->[" << a_instance.m_InstAttribType << "]\n";
                    a_stream << "           m_InstAttribValue-->[" << a_instance.m_InstAttribValue << "]\n";
                    return( a_stream );
                }
            } PACK m_entries[0];
            ALWAYS_INLINE const size_t elements() const { return( (size_t)m_dimension.m_numInGroup.value() ); }
            ALWAYS_INLINE const auto entriesBegin() const { return( &m_entries[0] ); }
            ALWAYS_INLINE const auto entriesEnd() const { return( &m_entries[ elements() ] ); }
            ALWAYS_INLINE const void * const next(){ return( (void *)entriesEnd() ); }
        } PACK m_NoInstAttrib;

        struct NoLotTypeRules
        {
            groupSize m_dimension;
            struct Entry
            {
                Int8 m_LotType;
                DecimalQty m_MinLotSize;
                uint8_t m_padding[ 5 - ( sizeof( m_LotType ) + sizeof( m_MinLotSize ) ) ];

                friend std::ostream & operator<<( std::ostream & a_stream , const Entry & a_instance )
                {
                    a_stream << "           m_LotType-->[" << a_instance.m_LotType << "]\n";
                    a_stream << "           m_MinLotSize-->[" << a_instance.m_MinLotSize << "]\n";
                    return( a_stream );
                }
            } PACK m_entries[0];
            ALWAYS_INLINE const size_t elements() const { return( (size_t)m_dimension.m_numInGroup.value() ); }
            ALWAYS_INLINE const auto entriesBegin() const { return( &m_entries[0] ); }
            ALWAYS_INLINE const auto entriesEnd() const { return( &m_entries[ elements() ] ); }
            ALWAYS_INLINE const void * const next(){ return( (void *)entriesEnd() ); }
        } PACK m_NoLotTypeRules;

        friend std::ostream & operator<<( std::ostream & a_stream , const MDInstrumentDefinitionFuture27 & a_instance )
        {
            a_stream << "MDInstrumentDefinitionFuture27-->[" << (void *)&a_instance << "]\n";
            a_stream << "    m_MatchEventIndicator-->[" << a_instance.m_MatchEventIndicator << "]\n";
            a_stream << "    m_TotNumReports-->[" << a_instance.m_TotNumReports << "]\n";
            a_stream << "    m_SecurityUpdateAction-->[" << a_instance.m_SecurityUpdateAction << "]\n";
            a_stream << "    m_LastUpdateTime-->[" << a_instance.m_LastUpdateTime << "]\n";
            a_stream << "    m_MDSecurityTradingStatus-->[" << a_instance.m_MDSecurityTradingStatus << "]\n";
            a_stream << "    m_ApplID-->[" << a_instance.m_ApplID << "]\n";
            a_stream << "    m_MarketSegmentID-->[" << a_instance.m_MarketSegmentID << "]\n";
            a_stream << "    m_UnderlyingProduct-->[" << a_instance.m_UnderlyingProduct << "]\n";
            a_stream << "    m_SecurityExchange-->[" << a_instance.m_SecurityExchange << "]\n";
            a_stream << "    m_SecurityGroup-->[" << a_instance.m_SecurityGroup << "]\n";
            a_stream << "    m_Asset-->[" << a_instance.m_Asset << "]\n";
            a_stream << "    m_Symbol-->[" << a_instance.m_Symbol << "]\n";
            a_stream << "    m_SecurityID-->[" << a_instance.m_SecurityID << "]\n";
            a_stream << "    m_SecurityIDSource-->[" << a_instance.m_SecurityIDSource << "]\n";
            a_stream << "    m_SecurityType-->[" << a_instance.m_SecurityType << "]\n";
            a_stream << "    m_CFICode-->[" << a_instance.m_CFICode << "]\n";
            a_stream << "    m_MaturityMonthYear-->[" << a_instance.m_MaturityMonthYear << "]\n";
            a_stream << "    m_Currency-->[" << a_instance.m_Currency << "]\n";
            a_stream << "    m_SettlCurrency-->[" << a_instance.m_SettlCurrency << "]\n";
            a_stream << "    m_MatchAlgorithm-->[" << a_instance.m_MatchAlgorithm << "]\n";
            a_stream << "    m_MinTradeVol-->[" << a_instance.m_MinTradeVol << "]\n";
            a_stream << "    m_MaxTradeVol-->[" << a_instance.m_MaxTradeVol << "]\n";
            a_stream << "    m_MinPriceIncrement-->[" << a_instance.m_MinPriceIncrement << "]\n";
            a_stream << "    m_DisplayFactor-->[" << a_instance.m_DisplayFactor << "]\n";
            a_stream << "    m_MainFraction-->[" << a_instance.m_MainFraction << "]\n";
            a_stream << "    m_SubFraction-->[" << a_instance.m_SubFraction << "]\n";
            a_stream << "    m_PriceDisplayFormat-->[" << a_instance.m_PriceDisplayFormat << "]\n";
            a_stream << "    m_UnitOfMeasure-->[" << a_instance.m_UnitOfMeasure << "]\n";
            a_stream << "    m_UnitOfMeasureQty-->[" << a_instance.m_UnitOfMeasureQty << "]\n";
            a_stream << "    m_TradingReferencePrice-->[" << a_instance.m_TradingReferencePrice << "]\n";
            a_stream << "    m_SettlPriceType-->[" << a_instance.m_SettlPriceType << "]\n";
            a_stream << "    m_OpenInterestQty-->[" << a_instance.m_OpenInterestQty << "]\n";
            a_stream << "    m_ClearedVolume-->[" << a_instance.m_ClearedVolume << "]\n";
            a_stream << "    m_HighLimitPrice-->[" << a_instance.m_HighLimitPrice << "]\n";
            a_stream << "    m_LowLimitPrice-->[" << a_instance.m_LowLimitPrice << "]\n";
            a_stream << "    m_MaxPriceVariation-->[" << a_instance.m_MaxPriceVariation << "]\n";
            a_stream << "    m_DecayQuantity-->[" << a_instance.m_DecayQuantity << "]\n";
            a_stream << "    m_DecayStartDate-->[" << a_instance.m_DecayStartDate << "]\n";
            a_stream << "    m_OriginalContractSize-->[" << a_instance.m_OriginalContractSize << "]\n";
            a_stream << "    m_ContractMultiplier-->[" << a_instance.m_ContractMultiplier << "]\n";
            a_stream << "    m_ContractMultiplierUnit-->[" << a_instance.m_ContractMultiplierUnit << "]\n";
            a_stream << "    m_FlowScheduleType-->[" << a_instance.m_FlowScheduleType << "]\n";
            a_stream << "    m_MinPriceIncrementAmount-->[" << a_instance.m_MinPriceIncrementAmount << "]\n";
            a_stream << "    m_UserDefinedInstrument-->[" << a_instance.m_UserDefinedInstrument << "]\n";
            a_stream << "    m_TradingReferenceDate-->[" << a_instance.m_TradingReferenceDate << "]\n";
            auto l_block = reinterpret_cast<const void *>( &a_instance.m_groupBegin[ 0 ] );
            {
                auto l_NoEvents = reinterpret_cast<const MDInstrumentDefinitionFuture27::NoEvents *>( l_block );
                auto l_begin = l_NoEvents->entriesBegin();
                auto l_end   = l_NoEvents->entriesEnd();
                auto l_size  = l_NoEvents->elements();
                a_stream << "    " << "NoEvents-->[" << l_size << "]\n";
                for( auto l_entry = l_begin;
                     l_entry != l_end;
                     ++l_entry )
                {
                    a_stream << "        Entry-->[" << ( (l_entry-l_begin) + 1 ) << "/" << l_size << "," << (void *)l_entry << "]\n";
                    a_stream << *l_entry;
                }
                l_block = l_NoEvents->next();
            }

            {
                auto l_NoMDFeedTypes = reinterpret_cast<const MDInstrumentDefinitionFuture27::NoMDFeedTypes *>( l_block );
                auto l_begin = l_NoMDFeedTypes->entriesBegin();
                auto l_end   = l_NoMDFeedTypes->entriesEnd();
                auto l_size  = l_NoMDFeedTypes->elements();
                a_stream << "    " << "NoMDFeedTypes-->[" << l_size << "]\n";
                for( auto l_entry = l_begin;
                     l_entry != l_end;
                     ++l_entry )
                {
                    a_stream << "        Entry-->[" << ( (l_entry-l_begin) + 1 ) << "/" << l_size << "," << (void *)l_entry << "]\n";
                    a_stream << *l_entry;
                }
                l_block = l_NoMDFeedTypes->next();
            }

            {
                auto l_NoInstAttrib = reinterpret_cast<const MDInstrumentDefinitionFuture27::NoInstAttrib *>( l_block );
                auto l_begin = l_NoInstAttrib->entriesBegin();
                auto l_end   = l_NoInstAttrib->entriesEnd();
                auto l_size  = l_NoInstAttrib->elements();
                a_stream << "    " << "NoInstAttrib-->[" << l_size << "]\n";
                for( auto l_entry = l_begin;
                     l_entry != l_end;
                     ++l_entry )
                {
                    a_stream << "        Entry-->[" << ( (l_entry-l_begin) + 1 ) << "/" << l_size << "," << (void *)l_entry << "]\n";
                    a_stream << *l_entry;
                }
                l_block = l_NoInstAttrib->next();
            }

            {
                auto l_NoLotTypeRules = reinterpret_cast<const MDInstrumentDefinitionFuture27::NoLotTypeRules *>( l_block );
                auto l_begin = l_NoLotTypeRules->entriesBegin();
                auto l_end   = l_NoLotTypeRules->entriesEnd();
                auto l_size  = l_NoLotTypeRules->elements();
                a_stream << "    " << "NoLotTypeRules-->[" << l_size << "]\n";
                for( auto l_entry = l_begin;
                     l_entry != l_end;
                     ++l_entry )
                {
                    a_stream << "        Entry-->[" << ( (l_entry-l_begin) + 1 ) << "/" << l_size << "," << (void *)l_entry << "]\n";
                    a_stream << *l_entry;
                }
                l_block = l_NoLotTypeRules->next();
            }

            return( a_stream );
        }
    } PACK;

    struct MDInstrumentDefinitionSpread29
    {
        static constexpr int32_t id() { return( 29 ); }
        static constexpr const char * name() { return( "MDInstrumentDefinitionSpread29" ); }

        MatchEventIndicator m_MatchEventIndicator;
        uInt32NULL m_TotNumReports;
        SecurityUpdateAction m_SecurityUpdateAction;
        uInt64 m_LastUpdateTime;
        SecurityTradingStatus m_MDSecurityTradingStatus;
        Int16 m_ApplID;
        uInt8 m_MarketSegmentID;
        uInt8NULL m_UnderlyingProduct;
        SecurityExchange m_SecurityExchange;
        SecurityGroup m_SecurityGroup;
        Asset m_Asset;
        Symbol m_Symbol;
        Int32 m_SecurityID;
        SecurityIDSource m_SecurityIDSource;
        SecurityType m_SecurityType;
        CFICode m_CFICode;
        MaturityMonthYear m_MaturityMonthYear;
        Currency m_Currency;
        SecuritySubType m_SecuritySubType;
        UserDefinedInstrument m_UserDefinedInstrument;
        CHAR m_MatchAlgorithm;
        uInt32 m_MinTradeVol;
        uInt32 m_MaxTradeVol;
        PRICE m_MinPriceIncrement;
        FLOAT m_DisplayFactor;
        uInt8NULL m_PriceDisplayFormat;
        PRICENULL m_PriceRatio;
        Int8NULL m_TickRule;
        UnitOfMeasure m_UnitOfMeasure;
        PRICENULL m_TradingReferencePrice;
        SettlPriceType m_SettlPriceType;
        Int32NULL m_OpenInterestQty;
        Int32NULL m_ClearedVolume;
        PRICENULL m_HighLimitPrice;
        PRICENULL m_LowLimitPrice;
        PRICENULL m_MaxPriceVariation;
        uInt8NULL m_MainFraction;
        uInt8NULL m_SubFraction;
        LocalMktDate m_TradingReferenceDate;
        uint8_t m_padding[ 195 - ( sizeof( m_MatchEventIndicator ) + sizeof( m_TotNumReports ) + sizeof( m_SecurityUpdateAction ) + sizeof( m_LastUpdateTime ) + sizeof( m_MDSecurityTradingStatus ) + sizeof( m_ApplID ) + sizeof( m_MarketSegmentID ) + sizeof( m_UnderlyingProduct ) + sizeof( m_SecurityExchange ) + sizeof( m_SecurityGroup ) + sizeof( m_Asset ) + sizeof( m_Symbol ) + sizeof( m_SecurityID ) + sizeof( m_SecurityIDSource ) + sizeof( m_SecurityType ) + sizeof( m_CFICode ) + sizeof( m_MaturityMonthYear ) + sizeof( m_Currency ) + sizeof( m_SecuritySubType ) + sizeof( m_UserDefinedInstrument ) + sizeof( m_MatchAlgorithm ) + sizeof( m_MinTradeVol ) + sizeof( m_MaxTradeVol ) + sizeof( m_MinPriceIncrement ) + sizeof( m_DisplayFactor ) + sizeof( m_PriceDisplayFormat ) + sizeof( m_PriceRatio ) + sizeof( m_TickRule ) + sizeof( m_UnitOfMeasure ) + sizeof( m_TradingReferencePrice ) + sizeof( m_SettlPriceType ) + sizeof( m_OpenInterestQty ) + sizeof( m_ClearedVolume ) + sizeof( m_HighLimitPrice ) + sizeof( m_LowLimitPrice ) + sizeof( m_MaxPriceVariation ) + sizeof( m_MainFraction ) + sizeof( m_SubFraction ) + sizeof( m_TradingReferenceDate ) ) ];

        uint8_t m_groupBegin[ 0 ];
        struct NoEvents
        {
            groupSize m_dimension;
            struct Entry
            {
                EventType m_EventType;
                uInt64 m_EventTime;
                uint8_t m_padding[ 9 - ( sizeof( m_EventType ) + sizeof( m_EventTime ) ) ];

                friend std::ostream & operator<<( std::ostream & a_stream , const Entry & a_instance )
                {
                    a_stream << "           m_EventType-->[" << a_instance.m_EventType << "]\n";
                    a_stream << "           m_EventTime-->[" << a_instance.m_EventTime << "]\n";
                    return( a_stream );
                }
            } PACK m_entries[0];
            ALWAYS_INLINE const size_t elements() const { return( (size_t)m_dimension.m_numInGroup.value() ); }
            ALWAYS_INLINE const auto entriesBegin() const { return( &m_entries[0] ); }
            ALWAYS_INLINE const auto entriesEnd() const { return( &m_entries[ elements() ] ); }
            ALWAYS_INLINE const void * const next(){ return( (void *)entriesEnd() ); }
        } PACK m_NoEvents;

        struct NoMDFeedTypes
        {
            groupSize m_dimension;
            struct Entry
            {
                MDFeedType m_MDFeedType;
                Int8 m_MarketDepth;
                uint8_t m_padding[ 4 - ( sizeof( m_MDFeedType ) + sizeof( m_MarketDepth ) ) ];

                friend std::ostream & operator<<( std::ostream & a_stream , const Entry & a_instance )
                {
                    a_stream << "           m_MDFeedType-->[" << a_instance.m_MDFeedType << "]\n";
                    a_stream << "           m_MarketDepth-->[" << a_instance.m_MarketDepth << "]\n";
                    return( a_stream );
                }
            } PACK m_entries[0];
            ALWAYS_INLINE const size_t elements() const { return( (size_t)m_dimension.m_numInGroup.value() ); }
            ALWAYS_INLINE const auto entriesBegin() const { return( &m_entries[0] ); }
            ALWAYS_INLINE const auto entriesEnd() const { return( &m_entries[ elements() ] ); }
            ALWAYS_INLINE const void * const next(){ return( (void *)entriesEnd() ); }
        } PACK m_NoMDFeedTypes;

        struct NoInstAttrib
        {
            groupSize m_dimension;
            struct Entry
            {
                InstAttribType m_InstAttribType;
                InstAttribValue m_InstAttribValue;
                uint8_t m_padding[ 4 - ( sizeof( m_InstAttribType ) + sizeof( m_InstAttribValue ) ) ];

                friend std::ostream & operator<<( std::ostream & a_stream , const Entry & a_instance )
                {
                    a_stream << "           m_InstAttribType-->[" << a_instance.m_InstAttribType << "]\n";
                    a_stream << "           m_InstAttribValue-->[" << a_instance.m_InstAttribValue << "]\n";
                    return( a_stream );
                }
            } PACK m_entries[0];
            ALWAYS_INLINE const size_t elements() const { return( (size_t)m_dimension.m_numInGroup.value() ); }
            ALWAYS_INLINE const auto entriesBegin() const { return( &m_entries[0] ); }
            ALWAYS_INLINE const auto entriesEnd() const { return( &m_entries[ elements() ] ); }
            ALWAYS_INLINE const void * const next(){ return( (void *)entriesEnd() ); }
        } PACK m_NoInstAttrib;

        struct NoLotTypeRules
        {
            groupSize m_dimension;
            struct Entry
            {
                Int8 m_LotType;
                DecimalQty m_MinLotSize;
                uint8_t m_padding[ 5 - ( sizeof( m_LotType ) + sizeof( m_MinLotSize ) ) ];

                friend std::ostream & operator<<( std::ostream & a_stream , const Entry & a_instance )
                {
                    a_stream << "           m_LotType-->[" << a_instance.m_LotType << "]\n";
                    a_stream << "           m_MinLotSize-->[" << a_instance.m_MinLotSize << "]\n";
                    return( a_stream );
                }
            } PACK m_entries[0];
            ALWAYS_INLINE const size_t elements() const { return( (size_t)m_dimension.m_numInGroup.value() ); }
            ALWAYS_INLINE const auto entriesBegin() const { return( &m_entries[0] ); }
            ALWAYS_INLINE const auto entriesEnd() const { return( &m_entries[ elements() ] ); }
            ALWAYS_INLINE const void * const next(){ return( (void *)entriesEnd() ); }
        } PACK m_NoLotTypeRules;

        struct NoLegs
        {
            groupSize m_dimension;
            struct Entry
            {
                Int32 m_LegSecurityID;
                SecurityIDSource m_LegSecurityIDSource;
                LegSide m_LegSide;
                Int8 m_LegRatioQty;
                PRICENULL m_LegPrice;
                DecimalQty m_LegOptionDelta;
                uint8_t m_padding[ 18 - ( sizeof( m_LegSecurityID ) + sizeof( m_LegSecurityIDSource ) + sizeof( m_LegSide ) + sizeof( m_LegRatioQty ) + sizeof( m_LegPrice ) + sizeof( m_LegOptionDelta ) ) ];

                friend std::ostream & operator<<( std::ostream & a_stream , const Entry & a_instance )
                {
                    a_stream << "           m_LegSecurityID-->[" << a_instance.m_LegSecurityID << "]\n";
                    a_stream << "           m_LegSecurityIDSource-->[" << a_instance.m_LegSecurityIDSource << "]\n";
                    a_stream << "           m_LegSide-->[" << a_instance.m_LegSide << "]\n";
                    a_stream << "           m_LegRatioQty-->[" << a_instance.m_LegRatioQty << "]\n";
                    a_stream << "           m_LegPrice-->[" << a_instance.m_LegPrice << "]\n";
                    a_stream << "           m_LegOptionDelta-->[" << a_instance.m_LegOptionDelta << "]\n";
                    return( a_stream );
                }
            } PACK m_entries[0];
            ALWAYS_INLINE const size_t elements() const { return( (size_t)m_dimension.m_numInGroup.value() ); }
            ALWAYS_INLINE const auto entriesBegin() const { return( &m_entries[0] ); }
            ALWAYS_INLINE const auto entriesEnd() const { return( &m_entries[ elements() ] ); }
            ALWAYS_INLINE const void * const next(){ return( (void *)entriesEnd() ); }
        } PACK m_NoLegs;

        friend std::ostream & operator<<( std::ostream & a_stream , const MDInstrumentDefinitionSpread29 & a_instance )
        {
            a_stream << "MDInstrumentDefinitionSpread29-->[" << (void *)&a_instance << "]\n";
            a_stream << "    m_MatchEventIndicator-->[" << a_instance.m_MatchEventIndicator << "]\n";
            a_stream << "    m_TotNumReports-->[" << a_instance.m_TotNumReports << "]\n";
            a_stream << "    m_SecurityUpdateAction-->[" << a_instance.m_SecurityUpdateAction << "]\n";
            a_stream << "    m_LastUpdateTime-->[" << a_instance.m_LastUpdateTime << "]\n";
            a_stream << "    m_MDSecurityTradingStatus-->[" << a_instance.m_MDSecurityTradingStatus << "]\n";
            a_stream << "    m_ApplID-->[" << a_instance.m_ApplID << "]\n";
            a_stream << "    m_MarketSegmentID-->[" << a_instance.m_MarketSegmentID << "]\n";
            a_stream << "    m_UnderlyingProduct-->[" << a_instance.m_UnderlyingProduct << "]\n";
            a_stream << "    m_SecurityExchange-->[" << a_instance.m_SecurityExchange << "]\n";
            a_stream << "    m_SecurityGroup-->[" << a_instance.m_SecurityGroup << "]\n";
            a_stream << "    m_Asset-->[" << a_instance.m_Asset << "]\n";
            a_stream << "    m_Symbol-->[" << a_instance.m_Symbol << "]\n";
            a_stream << "    m_SecurityID-->[" << a_instance.m_SecurityID << "]\n";
            a_stream << "    m_SecurityIDSource-->[" << a_instance.m_SecurityIDSource << "]\n";
            a_stream << "    m_SecurityType-->[" << a_instance.m_SecurityType << "]\n";
            a_stream << "    m_CFICode-->[" << a_instance.m_CFICode << "]\n";
            a_stream << "    m_MaturityMonthYear-->[" << a_instance.m_MaturityMonthYear << "]\n";
            a_stream << "    m_Currency-->[" << a_instance.m_Currency << "]\n";
            a_stream << "    m_SecuritySubType-->[" << a_instance.m_SecuritySubType << "]\n";
            a_stream << "    m_UserDefinedInstrument-->[" << a_instance.m_UserDefinedInstrument << "]\n";
            a_stream << "    m_MatchAlgorithm-->[" << a_instance.m_MatchAlgorithm << "]\n";
            a_stream << "    m_MinTradeVol-->[" << a_instance.m_MinTradeVol << "]\n";
            a_stream << "    m_MaxTradeVol-->[" << a_instance.m_MaxTradeVol << "]\n";
            a_stream << "    m_MinPriceIncrement-->[" << a_instance.m_MinPriceIncrement << "]\n";
            a_stream << "    m_DisplayFactor-->[" << a_instance.m_DisplayFactor << "]\n";
            a_stream << "    m_PriceDisplayFormat-->[" << a_instance.m_PriceDisplayFormat << "]\n";
            a_stream << "    m_PriceRatio-->[" << a_instance.m_PriceRatio << "]\n";
            a_stream << "    m_TickRule-->[" << a_instance.m_TickRule << "]\n";
            a_stream << "    m_UnitOfMeasure-->[" << a_instance.m_UnitOfMeasure << "]\n";
            a_stream << "    m_TradingReferencePrice-->[" << a_instance.m_TradingReferencePrice << "]\n";
            a_stream << "    m_SettlPriceType-->[" << a_instance.m_SettlPriceType << "]\n";
            a_stream << "    m_OpenInterestQty-->[" << a_instance.m_OpenInterestQty << "]\n";
            a_stream << "    m_ClearedVolume-->[" << a_instance.m_ClearedVolume << "]\n";
            a_stream << "    m_HighLimitPrice-->[" << a_instance.m_HighLimitPrice << "]\n";
            a_stream << "    m_LowLimitPrice-->[" << a_instance.m_LowLimitPrice << "]\n";
            a_stream << "    m_MaxPriceVariation-->[" << a_instance.m_MaxPriceVariation << "]\n";
            a_stream << "    m_MainFraction-->[" << a_instance.m_MainFraction << "]\n";
            a_stream << "    m_SubFraction-->[" << a_instance.m_SubFraction << "]\n";
            a_stream << "    m_TradingReferenceDate-->[" << a_instance.m_TradingReferenceDate << "]\n";
            auto l_block = reinterpret_cast<const void *>( &a_instance.m_groupBegin[ 0 ] );
            {
                auto l_NoEvents = reinterpret_cast<const MDInstrumentDefinitionSpread29::NoEvents *>( l_block );
                auto l_begin = l_NoEvents->entriesBegin();
                auto l_end   = l_NoEvents->entriesEnd();
                auto l_size  = l_NoEvents->elements();
                a_stream << "    " << "NoEvents-->[" << l_size << "]\n";
                for( auto l_entry = l_begin;
                     l_entry != l_end;
                     ++l_entry )
                {
                    a_stream << "        Entry-->[" << ( (l_entry-l_begin) + 1 ) << "/" << l_size << "," << (void *)l_entry << "]\n";
                    a_stream << *l_entry;
                }
                l_block = l_NoEvents->next();
            }

            {
                auto l_NoMDFeedTypes = reinterpret_cast<const MDInstrumentDefinitionSpread29::NoMDFeedTypes *>( l_block );
                auto l_begin = l_NoMDFeedTypes->entriesBegin();
                auto l_end   = l_NoMDFeedTypes->entriesEnd();
                auto l_size  = l_NoMDFeedTypes->elements();
                a_stream << "    " << "NoMDFeedTypes-->[" << l_size << "]\n";
                for( auto l_entry = l_begin;
                     l_entry != l_end;
                     ++l_entry )
                {
                    a_stream << "        Entry-->[" << ( (l_entry-l_begin) + 1 ) << "/" << l_size << "," << (void *)l_entry << "]\n";
                    a_stream << *l_entry;
                }
                l_block = l_NoMDFeedTypes->next();
            }

            {
                auto l_NoInstAttrib = reinterpret_cast<const MDInstrumentDefinitionSpread29::NoInstAttrib *>( l_block );
                auto l_begin = l_NoInstAttrib->entriesBegin();
                auto l_end   = l_NoInstAttrib->entriesEnd();
                auto l_size  = l_NoInstAttrib->elements();
                a_stream << "    " << "NoInstAttrib-->[" << l_size << "]\n";
                for( auto l_entry = l_begin;
                     l_entry != l_end;
                     ++l_entry )
                {
                    a_stream << "        Entry-->[" << ( (l_entry-l_begin) + 1 ) << "/" << l_size << "," << (void *)l_entry << "]\n";
                    a_stream << *l_entry;
                }
                l_block = l_NoInstAttrib->next();
            }

            {
                auto l_NoLotTypeRules = reinterpret_cast<const MDInstrumentDefinitionSpread29::NoLotTypeRules *>( l_block );
                auto l_begin = l_NoLotTypeRules->entriesBegin();
                auto l_end   = l_NoLotTypeRules->entriesEnd();
                auto l_size  = l_NoLotTypeRules->elements();
                a_stream << "    " << "NoLotTypeRules-->[" << l_size << "]\n";
                for( auto l_entry = l_begin;
                     l_entry != l_end;
                     ++l_entry )
                {
                    a_stream << "        Entry-->[" << ( (l_entry-l_begin) + 1 ) << "/" << l_size << "," << (void *)l_entry << "]\n";
                    a_stream << *l_entry;
                }
                l_block = l_NoLotTypeRules->next();
            }

            {
                auto l_NoLegs = reinterpret_cast<const MDInstrumentDefinitionSpread29::NoLegs *>( l_block );
                auto l_begin = l_NoLegs->entriesBegin();
                auto l_end   = l_NoLegs->entriesEnd();
                auto l_size  = l_NoLegs->elements();
                a_stream << "    " << "NoLegs-->[" << l_size << "]\n";
                for( auto l_entry = l_begin;
                     l_entry != l_end;
                     ++l_entry )
                {
                    a_stream << "        Entry-->[" << ( (l_entry-l_begin) + 1 ) << "/" << l_size << "," << (void *)l_entry << "]\n";
                    a_stream << *l_entry;
                }
                l_block = l_NoLegs->next();
            }

            return( a_stream );
        }
    } PACK;

    struct SecurityStatus30
    {
        static constexpr int32_t id() { return( 30 ); }
        static constexpr const char * name() { return( "SecurityStatus30" ); }

        uInt64 m_TransactTime;
        SecurityGroup m_SecurityGroup;
        Asset m_Asset;
        Int32NULL m_SecurityID;
        LocalMktDate m_TradeDate;
        MatchEventIndicator m_MatchEventIndicator;
        SecurityTradingStatus m_SecurityTradingStatus;
        HaltReason m_HaltReason;
        SecurityTradingEvent m_SecurityTradingEvent;
        friend std::ostream & operator<<( std::ostream & a_stream , const SecurityStatus30 & a_instance )
        {
            a_stream << "SecurityStatus30-->[" << (void *)&a_instance << "]\n";
            a_stream << "    m_TransactTime-->[" << a_instance.m_TransactTime << "]\n";
            a_stream << "    m_SecurityGroup-->[" << a_instance.m_SecurityGroup << "]\n";
            a_stream << "    m_Asset-->[" << a_instance.m_Asset << "]\n";
            a_stream << "    m_SecurityID-->[" << a_instance.m_SecurityID << "]\n";
            a_stream << "    m_TradeDate-->[" << a_instance.m_TradeDate << "]\n";
            a_stream << "    m_MatchEventIndicator-->[" << a_instance.m_MatchEventIndicator << "]\n";
            a_stream << "    m_SecurityTradingStatus-->[" << a_instance.m_SecurityTradingStatus << "]\n";
            a_stream << "    m_HaltReason-->[" << a_instance.m_HaltReason << "]\n";
            a_stream << "    m_SecurityTradingEvent-->[" << a_instance.m_SecurityTradingEvent << "]\n";
            return( a_stream );
        }
    } PACK;

    struct MDIncrementalRefreshBook32
    {
        static constexpr int32_t id() { return( 32 ); }
        static constexpr const char * name() { return( "MDIncrementalRefreshBook32" ); }

        uInt64 m_TransactTime;
        MatchEventIndicator m_MatchEventIndicator;
        uint8_t m_padding[ 11 - ( sizeof( m_TransactTime ) + sizeof( m_MatchEventIndicator ) ) ];

        uint8_t m_groupBegin[ 0 ];
        struct NoMDEntries
        {
            groupSize m_dimension;
            struct Entry
            {
                PRICENULL m_MDEntryPx;
                Int32NULL m_MDEntrySize;
                Int32 m_SecurityID;
                uInt32 m_RptSeq;
                Int32NULL m_NumberOfOrders;
                uInt8 m_MDPriceLevel;
                MDUpdateAction m_MDUpdateAction;
                MDEntryTypeBook m_MDEntryType;
                uint8_t m_padding[ 32 - ( sizeof( m_MDEntryPx ) + sizeof( m_MDEntrySize ) + sizeof( m_SecurityID ) + sizeof( m_RptSeq ) + sizeof( m_NumberOfOrders ) + sizeof( m_MDPriceLevel ) + sizeof( m_MDUpdateAction ) + sizeof( m_MDEntryType ) ) ];

                friend std::ostream & operator<<( std::ostream & a_stream , const Entry & a_instance )
                {
                    a_stream << "           m_MDEntryPx-->[" << a_instance.m_MDEntryPx << "]\n";
                    a_stream << "           m_MDEntrySize-->[" << a_instance.m_MDEntrySize << "]\n";
                    a_stream << "           m_SecurityID-->[" << a_instance.m_SecurityID << "]\n";
                    a_stream << "           m_RptSeq-->[" << a_instance.m_RptSeq << "]\n";
                    a_stream << "           m_NumberOfOrders-->[" << a_instance.m_NumberOfOrders << "]\n";
                    a_stream << "           m_MDPriceLevel-->[" << a_instance.m_MDPriceLevel << "]\n";
                    a_stream << "           m_MDUpdateAction-->[" << a_instance.m_MDUpdateAction << "]\n";
                    a_stream << "           m_MDEntryType-->[" << a_instance.m_MDEntryType << "]\n";
                    return( a_stream );
                }
            } PACK m_entries[0];
            ALWAYS_INLINE const size_t elements() const { return( (size_t)m_dimension.m_numInGroup.value() ); }
            ALWAYS_INLINE const auto entriesBegin() const { return( &m_entries[0] ); }
            ALWAYS_INLINE const auto entriesEnd() const { return( &m_entries[ elements() ] ); }
            ALWAYS_INLINE const void * const next(){ return( (void *)entriesEnd() ); }
        } PACK m_NoMDEntries;

        struct NoOrderIDEntries
        {
            groupSize8Byte m_dimension;
            struct Entry
            {
                uInt64 m_OrderID;
                uInt64NULL m_MDOrderPriority;
                Int32NULL m_MDDisplayQty;
                uInt8NULL m_ReferenceID;
                OrderUpdateAction m_OrderUpdateAction;
                uint8_t m_padding[ 24 - ( sizeof( m_OrderID ) + sizeof( m_MDOrderPriority ) + sizeof( m_MDDisplayQty ) + sizeof( m_ReferenceID ) + sizeof( m_OrderUpdateAction ) ) ];

                friend std::ostream & operator<<( std::ostream & a_stream , const Entry & a_instance )
                {
                    a_stream << "           m_OrderID-->[" << a_instance.m_OrderID << "]\n";
                    a_stream << "           m_MDOrderPriority-->[" << a_instance.m_MDOrderPriority << "]\n";
                    a_stream << "           m_MDDisplayQty-->[" << a_instance.m_MDDisplayQty << "]\n";
                    a_stream << "           m_ReferenceID-->[" << a_instance.m_ReferenceID << "]\n";
                    a_stream << "           m_OrderUpdateAction-->[" << a_instance.m_OrderUpdateAction << "]\n";
                    return( a_stream );
                }
            } PACK m_entries[0];
            ALWAYS_INLINE const size_t elements() const { return( (size_t)m_dimension.m_numInGroup.value() ); }
            ALWAYS_INLINE const auto entriesBegin() const { return( &m_entries[0] ); }
            ALWAYS_INLINE const auto entriesEnd() const { return( &m_entries[ elements() ] ); }
            ALWAYS_INLINE const void * const next(){ return( (void *)entriesEnd() ); }
        } PACK m_NoOrderIDEntries;

        friend std::ostream & operator<<( std::ostream & a_stream , const MDIncrementalRefreshBook32 & a_instance )
        {
            a_stream << "MDIncrementalRefreshBook32-->[" << (void *)&a_instance << "]\n";
            a_stream << "    m_TransactTime-->[" << a_instance.m_TransactTime << "]\n";
            a_stream << "    m_MatchEventIndicator-->[" << a_instance.m_MatchEventIndicator << "]\n";
            auto l_block = reinterpret_cast<const void *>( &a_instance.m_groupBegin[ 0 ] );
            {
                auto l_NoMDEntries = reinterpret_cast<const MDIncrementalRefreshBook32::NoMDEntries *>( l_block );
                auto l_begin = l_NoMDEntries->entriesBegin();
                auto l_end   = l_NoMDEntries->entriesEnd();
                auto l_size  = l_NoMDEntries->elements();
                a_stream << "    " << "NoMDEntries-->[" << l_size << "]\n";
                for( auto l_entry = l_begin;
                     l_entry != l_end;
                     ++l_entry )
                {
                    a_stream << "        Entry-->[" << ( (l_entry-l_begin) + 1 ) << "/" << l_size << "," << (void *)l_entry << "]\n";
                    a_stream << *l_entry;
                }
                l_block = l_NoMDEntries->next();
            }

            {
                auto l_NoOrderIDEntries = reinterpret_cast<const MDIncrementalRefreshBook32::NoOrderIDEntries *>( l_block );
                auto l_begin = l_NoOrderIDEntries->entriesBegin();
                auto l_end   = l_NoOrderIDEntries->entriesEnd();
                auto l_size  = l_NoOrderIDEntries->elements();
                a_stream << "    " << "NoOrderIDEntries-->[" << l_size << "]\n";
                for( auto l_entry = l_begin;
                     l_entry != l_end;
                     ++l_entry )
                {
                    a_stream << "        Entry-->[" << ( (l_entry-l_begin) + 1 ) << "/" << l_size << "," << (void *)l_entry << "]\n";
                    a_stream << *l_entry;
                }
                l_block = l_NoOrderIDEntries->next();
            }

            return( a_stream );
        }
    } PACK;

    struct MDIncrementalRefreshDailyStatistics33
    {
        static constexpr int32_t id() { return( 33 ); }
        static constexpr const char * name() { return( "MDIncrementalRefreshDailyStatistics33" ); }

        uInt64 m_TransactTime;
        MatchEventIndicator m_MatchEventIndicator;
        uint8_t m_padding[ 11 - ( sizeof( m_TransactTime ) + sizeof( m_MatchEventIndicator ) ) ];

        uint8_t m_groupBegin[ 0 ];
        struct NoMDEntries
        {
            groupSize m_dimension;
            struct Entry
            {
                PRICENULL m_MDEntryPx;
                Int32NULL m_MDEntrySize;
                Int32 m_SecurityID;
                uInt32 m_RptSeq;
                LocalMktDate m_TradingReferenceDate;
                SettlPriceType m_SettlPriceType;
                MDUpdateAction m_MDUpdateAction;
                MDEntryTypeDailyStatistics m_MDEntryType;
                uint8_t m_padding[ 32 - ( sizeof( m_MDEntryPx ) + sizeof( m_MDEntrySize ) + sizeof( m_SecurityID ) + sizeof( m_RptSeq ) + sizeof( m_TradingReferenceDate ) + sizeof( m_SettlPriceType ) + sizeof( m_MDUpdateAction ) + sizeof( m_MDEntryType ) ) ];

                friend std::ostream & operator<<( std::ostream & a_stream , const Entry & a_instance )
                {
                    a_stream << "           m_MDEntryPx-->[" << a_instance.m_MDEntryPx << "]\n";
                    a_stream << "           m_MDEntrySize-->[" << a_instance.m_MDEntrySize << "]\n";
                    a_stream << "           m_SecurityID-->[" << a_instance.m_SecurityID << "]\n";
                    a_stream << "           m_RptSeq-->[" << a_instance.m_RptSeq << "]\n";
                    a_stream << "           m_TradingReferenceDate-->[" << a_instance.m_TradingReferenceDate << "]\n";
                    a_stream << "           m_SettlPriceType-->[" << a_instance.m_SettlPriceType << "]\n";
                    a_stream << "           m_MDUpdateAction-->[" << a_instance.m_MDUpdateAction << "]\n";
                    a_stream << "           m_MDEntryType-->[" << a_instance.m_MDEntryType << "]\n";
                    return( a_stream );
                }
            } PACK m_entries[0];
            ALWAYS_INLINE const size_t elements() const { return( (size_t)m_dimension.m_numInGroup.value() ); }
            ALWAYS_INLINE const auto entriesBegin() const { return( &m_entries[0] ); }
            ALWAYS_INLINE const auto entriesEnd() const { return( &m_entries[ elements() ] ); }
            ALWAYS_INLINE const void * const next(){ return( (void *)entriesEnd() ); }
        } PACK m_NoMDEntries;

        friend std::ostream & operator<<( std::ostream & a_stream , const MDIncrementalRefreshDailyStatistics33 & a_instance )
        {
            a_stream << "MDIncrementalRefreshDailyStatistics33-->[" << (void *)&a_instance << "]\n";
            a_stream << "    m_TransactTime-->[" << a_instance.m_TransactTime << "]\n";
            a_stream << "    m_MatchEventIndicator-->[" << a_instance.m_MatchEventIndicator << "]\n";
            auto l_block = reinterpret_cast<const void *>( &a_instance.m_groupBegin[ 0 ] );
            {
                auto l_NoMDEntries = reinterpret_cast<const MDIncrementalRefreshDailyStatistics33::NoMDEntries *>( l_block );
                auto l_begin = l_NoMDEntries->entriesBegin();
                auto l_end   = l_NoMDEntries->entriesEnd();
                auto l_size  = l_NoMDEntries->elements();
                a_stream << "    " << "NoMDEntries-->[" << l_size << "]\n";
                for( auto l_entry = l_begin;
                     l_entry != l_end;
                     ++l_entry )
                {
                    a_stream << "        Entry-->[" << ( (l_entry-l_begin) + 1 ) << "/" << l_size << "," << (void *)l_entry << "]\n";
                    a_stream << *l_entry;
                }
                l_block = l_NoMDEntries->next();
            }

            return( a_stream );
        }
    } PACK;

    struct MDIncrementalRefreshLimitsBanding34
    {
        static constexpr int32_t id() { return( 34 ); }
        static constexpr const char * name() { return( "MDIncrementalRefreshLimitsBanding34" ); }

        uInt64 m_TransactTime;
        MatchEventIndicator m_MatchEventIndicator;
        uint8_t m_padding[ 11 - ( sizeof( m_TransactTime ) + sizeof( m_MatchEventIndicator ) ) ];

        uint8_t m_groupBegin[ 0 ];
        struct NoMDEntries
        {
            groupSize m_dimension;
            struct Entry
            {
                PRICENULL m_HighLimitPrice;
                PRICENULL m_LowLimitPrice;
                PRICENULL m_MaxPriceVariation;
                Int32 m_SecurityID;
                uInt32 m_RptSeq;
                MDUpdateActionNew m_MDUpdateAction;
                MDEntryTypeLimits m_MDEntryType;
                uint8_t m_padding[ 32 - ( sizeof( m_HighLimitPrice ) + sizeof( m_LowLimitPrice ) + sizeof( m_MaxPriceVariation ) + sizeof( m_SecurityID ) + sizeof( m_RptSeq ) + sizeof( m_MDUpdateAction ) + sizeof( m_MDEntryType ) ) ];

                friend std::ostream & operator<<( std::ostream & a_stream , const Entry & a_instance )
                {
                    a_stream << "           m_HighLimitPrice-->[" << a_instance.m_HighLimitPrice << "]\n";
                    a_stream << "           m_LowLimitPrice-->[" << a_instance.m_LowLimitPrice << "]\n";
                    a_stream << "           m_MaxPriceVariation-->[" << a_instance.m_MaxPriceVariation << "]\n";
                    a_stream << "           m_SecurityID-->[" << a_instance.m_SecurityID << "]\n";
                    a_stream << "           m_RptSeq-->[" << a_instance.m_RptSeq << "]\n";
                    a_stream << "           m_MDUpdateAction-->[" << a_instance.m_MDUpdateAction << "]\n";
                    a_stream << "           m_MDEntryType-->[" << a_instance.m_MDEntryType << "]\n";
                    return( a_stream );
                }
            } PACK m_entries[0];
            ALWAYS_INLINE const size_t elements() const { return( (size_t)m_dimension.m_numInGroup.value() ); }
            ALWAYS_INLINE const auto entriesBegin() const { return( &m_entries[0] ); }
            ALWAYS_INLINE const auto entriesEnd() const { return( &m_entries[ elements() ] ); }
            ALWAYS_INLINE const void * const next(){ return( (void *)entriesEnd() ); }
        } PACK m_NoMDEntries;

        friend std::ostream & operator<<( std::ostream & a_stream , const MDIncrementalRefreshLimitsBanding34 & a_instance )
        {
            a_stream << "MDIncrementalRefreshLimitsBanding34-->[" << (void *)&a_instance << "]\n";
            a_stream << "    m_TransactTime-->[" << a_instance.m_TransactTime << "]\n";
            a_stream << "    m_MatchEventIndicator-->[" << a_instance.m_MatchEventIndicator << "]\n";
            auto l_block = reinterpret_cast<const void *>( &a_instance.m_groupBegin[ 0 ] );
            {
                auto l_NoMDEntries = reinterpret_cast<const MDIncrementalRefreshLimitsBanding34::NoMDEntries *>( l_block );
                auto l_begin = l_NoMDEntries->entriesBegin();
                auto l_end   = l_NoMDEntries->entriesEnd();
                auto l_size  = l_NoMDEntries->elements();
                a_stream << "    " << "NoMDEntries-->[" << l_size << "]\n";
                for( auto l_entry = l_begin;
                     l_entry != l_end;
                     ++l_entry )
                {
                    a_stream << "        Entry-->[" << ( (l_entry-l_begin) + 1 ) << "/" << l_size << "," << (void *)l_entry << "]\n";
                    a_stream << *l_entry;
                }
                l_block = l_NoMDEntries->next();
            }

            return( a_stream );
        }
    } PACK;

    struct MDIncrementalRefreshSessionStatistics35
    {
        static constexpr int32_t id() { return( 35 ); }
        static constexpr const char * name() { return( "MDIncrementalRefreshSessionStatistics35" ); }

        uInt64 m_TransactTime;
        MatchEventIndicator m_MatchEventIndicator;
        uint8_t m_padding[ 11 - ( sizeof( m_TransactTime ) + sizeof( m_MatchEventIndicator ) ) ];

        uint8_t m_groupBegin[ 0 ];
        struct NoMDEntries
        {
            groupSize m_dimension;
            struct Entry
            {
                PRICE m_MDEntryPx;
                Int32 m_SecurityID;
                uInt32 m_RptSeq;
                OpenCloseSettlFlag m_OpenCloseSettlFlag;
                MDUpdateAction m_MDUpdateAction;
                MDEntryTypeStatistics m_MDEntryType;
                Int32NULL m_MDEntrySize;
                uint8_t m_padding[ 24 - ( sizeof( m_MDEntryPx ) + sizeof( m_SecurityID ) + sizeof( m_RptSeq ) + sizeof( m_OpenCloseSettlFlag ) + sizeof( m_MDUpdateAction ) + sizeof( m_MDEntryType ) + sizeof( m_MDEntrySize ) ) ];

                friend std::ostream & operator<<( std::ostream & a_stream , const Entry & a_instance )
                {
                    a_stream << "           m_MDEntryPx-->[" << a_instance.m_MDEntryPx << "]\n";
                    a_stream << "           m_SecurityID-->[" << a_instance.m_SecurityID << "]\n";
                    a_stream << "           m_RptSeq-->[" << a_instance.m_RptSeq << "]\n";
                    a_stream << "           m_OpenCloseSettlFlag-->[" << a_instance.m_OpenCloseSettlFlag << "]\n";
                    a_stream << "           m_MDUpdateAction-->[" << a_instance.m_MDUpdateAction << "]\n";
                    a_stream << "           m_MDEntryType-->[" << a_instance.m_MDEntryType << "]\n";
                    a_stream << "           m_MDEntrySize-->[" << a_instance.m_MDEntrySize << "]\n";
                    return( a_stream );
                }
            } PACK m_entries[0];
            ALWAYS_INLINE const size_t elements() const { return( (size_t)m_dimension.m_numInGroup.value() ); }
            ALWAYS_INLINE const auto entriesBegin() const { return( &m_entries[0] ); }
            ALWAYS_INLINE const auto entriesEnd() const { return( &m_entries[ elements() ] ); }
            ALWAYS_INLINE const void * const next(){ return( (void *)entriesEnd() ); }
        } PACK m_NoMDEntries;

        friend std::ostream & operator<<( std::ostream & a_stream , const MDIncrementalRefreshSessionStatistics35 & a_instance )
        {
            a_stream << "MDIncrementalRefreshSessionStatistics35-->[" << (void *)&a_instance << "]\n";
            a_stream << "    m_TransactTime-->[" << a_instance.m_TransactTime << "]\n";
            a_stream << "    m_MatchEventIndicator-->[" << a_instance.m_MatchEventIndicator << "]\n";
            auto l_block = reinterpret_cast<const void *>( &a_instance.m_groupBegin[ 0 ] );
            {
                auto l_NoMDEntries = reinterpret_cast<const MDIncrementalRefreshSessionStatistics35::NoMDEntries *>( l_block );
                auto l_begin = l_NoMDEntries->entriesBegin();
                auto l_end   = l_NoMDEntries->entriesEnd();
                auto l_size  = l_NoMDEntries->elements();
                a_stream << "    " << "NoMDEntries-->[" << l_size << "]\n";
                for( auto l_entry = l_begin;
                     l_entry != l_end;
                     ++l_entry )
                {
                    a_stream << "        Entry-->[" << ( (l_entry-l_begin) + 1 ) << "/" << l_size << "," << (void *)l_entry << "]\n";
                    a_stream << *l_entry;
                }
                l_block = l_NoMDEntries->next();
            }

            return( a_stream );
        }
    } PACK;

    struct MDIncrementalRefreshVolume37
    {
        static constexpr int32_t id() { return( 37 ); }
        static constexpr const char * name() { return( "MDIncrementalRefreshVolume37" ); }

        uInt64 m_TransactTime;
        MatchEventIndicator m_MatchEventIndicator;
        uint8_t m_padding[ 11 - ( sizeof( m_TransactTime ) + sizeof( m_MatchEventIndicator ) ) ];

        uint8_t m_groupBegin[ 0 ];
        struct NoMDEntries
        {
            groupSize m_dimension;
            struct Entry
            {
                Int32 m_MDEntrySize;
                Int32 m_SecurityID;
                uInt32 m_RptSeq;
                MDUpdateAction m_MDUpdateAction;
                MDEntryTypeVol m_MDEntryType;
                uint8_t m_padding[ 16 - ( sizeof( m_MDEntrySize ) + sizeof( m_SecurityID ) + sizeof( m_RptSeq ) + sizeof( m_MDUpdateAction ) + sizeof( m_MDEntryType ) ) ];

                friend std::ostream & operator<<( std::ostream & a_stream , const Entry & a_instance )
                {
                    a_stream << "           m_MDEntrySize-->[" << a_instance.m_MDEntrySize << "]\n";
                    a_stream << "           m_SecurityID-->[" << a_instance.m_SecurityID << "]\n";
                    a_stream << "           m_RptSeq-->[" << a_instance.m_RptSeq << "]\n";
                    a_stream << "           m_MDUpdateAction-->[" << a_instance.m_MDUpdateAction << "]\n";
                    a_stream << "           m_MDEntryType-->[" << a_instance.m_MDEntryType << "]\n";
                    return( a_stream );
                }
            } PACK m_entries[0];
            ALWAYS_INLINE const size_t elements() const { return( (size_t)m_dimension.m_numInGroup.value() ); }
            ALWAYS_INLINE const auto entriesBegin() const { return( &m_entries[0] ); }
            ALWAYS_INLINE const auto entriesEnd() const { return( &m_entries[ elements() ] ); }
            ALWAYS_INLINE const void * const next(){ return( (void *)entriesEnd() ); }
        } PACK m_NoMDEntries;

        friend std::ostream & operator<<( std::ostream & a_stream , const MDIncrementalRefreshVolume37 & a_instance )
        {
            a_stream << "MDIncrementalRefreshVolume37-->[" << (void *)&a_instance << "]\n";
            a_stream << "    m_TransactTime-->[" << a_instance.m_TransactTime << "]\n";
            a_stream << "    m_MatchEventIndicator-->[" << a_instance.m_MatchEventIndicator << "]\n";
            auto l_block = reinterpret_cast<const void *>( &a_instance.m_groupBegin[ 0 ] );
            {
                auto l_NoMDEntries = reinterpret_cast<const MDIncrementalRefreshVolume37::NoMDEntries *>( l_block );
                auto l_begin = l_NoMDEntries->entriesBegin();
                auto l_end   = l_NoMDEntries->entriesEnd();
                auto l_size  = l_NoMDEntries->elements();
                a_stream << "    " << "NoMDEntries-->[" << l_size << "]\n";
                for( auto l_entry = l_begin;
                     l_entry != l_end;
                     ++l_entry )
                {
                    a_stream << "        Entry-->[" << ( (l_entry-l_begin) + 1 ) << "/" << l_size << "," << (void *)l_entry << "]\n";
                    a_stream << *l_entry;
                }
                l_block = l_NoMDEntries->next();
            }

            return( a_stream );
        }
    } PACK;

    struct SnapshotFullRefresh38
    {
        static constexpr int32_t id() { return( 38 ); }
        static constexpr const char * name() { return( "SnapshotFullRefresh38" ); }

        uInt32 m_LastMsgSeqNumProcessed;
        uInt32 m_TotNumReports;
        Int32 m_SecurityID;
        uInt32 m_RptSeq;
        uInt64 m_TransactTime;
        uInt64 m_LastUpdateTime;
        LocalMktDate m_TradeDate;
        SecurityTradingStatus m_MDSecurityTradingStatus;
        PRICENULL m_HighLimitPrice;
        PRICENULL m_LowLimitPrice;
        PRICENULL m_MaxPriceVariation;
        uint8_t m_padding[ 59 - ( sizeof( m_LastMsgSeqNumProcessed ) + sizeof( m_TotNumReports ) + sizeof( m_SecurityID ) + sizeof( m_RptSeq ) + sizeof( m_TransactTime ) + sizeof( m_LastUpdateTime ) + sizeof( m_TradeDate ) + sizeof( m_MDSecurityTradingStatus ) + sizeof( m_HighLimitPrice ) + sizeof( m_LowLimitPrice ) + sizeof( m_MaxPriceVariation ) ) ];

        uint8_t m_groupBegin[ 0 ];
        struct NoMDEntries
        {
            groupSize m_dimension;
            struct Entry
            {
                PRICENULL m_MDEntryPx;
                Int32NULL m_MDEntrySize;
                Int32NULL m_NumberOfOrders;
                Int8NULL m_MDPriceLevel;
                LocalMktDate m_TradingReferenceDate;
                OpenCloseSettlFlag m_OpenCloseSettlFlag;
                SettlPriceType m_SettlPriceType;
                MDEntryType m_MDEntryType;
                uint8_t m_padding[ 22 - ( sizeof( m_MDEntryPx ) + sizeof( m_MDEntrySize ) + sizeof( m_NumberOfOrders ) + sizeof( m_MDPriceLevel ) + sizeof( m_TradingReferenceDate ) + sizeof( m_OpenCloseSettlFlag ) + sizeof( m_SettlPriceType ) + sizeof( m_MDEntryType ) ) ];

                friend std::ostream & operator<<( std::ostream & a_stream , const Entry & a_instance )
                {
                    a_stream << "           m_MDEntryPx-->[" << a_instance.m_MDEntryPx << "]\n";
                    a_stream << "           m_MDEntrySize-->[" << a_instance.m_MDEntrySize << "]\n";
                    a_stream << "           m_NumberOfOrders-->[" << a_instance.m_NumberOfOrders << "]\n";
                    a_stream << "           m_MDPriceLevel-->[" << a_instance.m_MDPriceLevel << "]\n";
                    a_stream << "           m_TradingReferenceDate-->[" << a_instance.m_TradingReferenceDate << "]\n";
                    a_stream << "           m_OpenCloseSettlFlag-->[" << a_instance.m_OpenCloseSettlFlag << "]\n";
                    a_stream << "           m_SettlPriceType-->[" << a_instance.m_SettlPriceType << "]\n";
                    a_stream << "           m_MDEntryType-->[" << a_instance.m_MDEntryType << "]\n";
                    return( a_stream );
                }
            } PACK m_entries[0];
            ALWAYS_INLINE const size_t elements() const { return( (size_t)m_dimension.m_numInGroup.value() ); }
            ALWAYS_INLINE const auto entriesBegin() const { return( &m_entries[0] ); }
            ALWAYS_INLINE const auto entriesEnd() const { return( &m_entries[ elements() ] ); }
            ALWAYS_INLINE const void * const next(){ return( (void *)entriesEnd() ); }
        } PACK m_NoMDEntries;

        friend std::ostream & operator<<( std::ostream & a_stream , const SnapshotFullRefresh38 & a_instance )
        {
            a_stream << "SnapshotFullRefresh38-->[" << (void *)&a_instance << "]\n";
            a_stream << "    m_LastMsgSeqNumProcessed-->[" << a_instance.m_LastMsgSeqNumProcessed << "]\n";
            a_stream << "    m_TotNumReports-->[" << a_instance.m_TotNumReports << "]\n";
            a_stream << "    m_SecurityID-->[" << a_instance.m_SecurityID << "]\n";
            a_stream << "    m_RptSeq-->[" << a_instance.m_RptSeq << "]\n";
            a_stream << "    m_TransactTime-->[" << a_instance.m_TransactTime << "]\n";
            a_stream << "    m_LastUpdateTime-->[" << a_instance.m_LastUpdateTime << "]\n";
            a_stream << "    m_TradeDate-->[" << a_instance.m_TradeDate << "]\n";
            a_stream << "    m_MDSecurityTradingStatus-->[" << a_instance.m_MDSecurityTradingStatus << "]\n";
            a_stream << "    m_HighLimitPrice-->[" << a_instance.m_HighLimitPrice << "]\n";
            a_stream << "    m_LowLimitPrice-->[" << a_instance.m_LowLimitPrice << "]\n";
            a_stream << "    m_MaxPriceVariation-->[" << a_instance.m_MaxPriceVariation << "]\n";
            auto l_block = reinterpret_cast<const void *>( &a_instance.m_groupBegin[ 0 ] );
            {
                auto l_NoMDEntries = reinterpret_cast<const SnapshotFullRefresh38::NoMDEntries *>( l_block );
                auto l_begin = l_NoMDEntries->entriesBegin();
                auto l_end   = l_NoMDEntries->entriesEnd();
                auto l_size  = l_NoMDEntries->elements();
                a_stream << "    " << "NoMDEntries-->[" << l_size << "]\n";
                for( auto l_entry = l_begin;
                     l_entry != l_end;
                     ++l_entry )
                {
                    a_stream << "        Entry-->[" << ( (l_entry-l_begin) + 1 ) << "/" << l_size << "," << (void *)l_entry << "]\n";
                    a_stream << *l_entry;
                }
                l_block = l_NoMDEntries->next();
            }

            return( a_stream );
        }
    } PACK;

    struct QuoteRequest39
    {
        static constexpr int32_t id() { return( 39 ); }
        static constexpr const char * name() { return( "QuoteRequest39" ); }

        uInt64 m_TransactTime;
        QuoteReqId m_QuoteReqID;
        MatchEventIndicator m_MatchEventIndicator;
        uint8_t m_padding[ 35 - ( sizeof( m_TransactTime ) + sizeof( m_QuoteReqID ) + sizeof( m_MatchEventIndicator ) ) ];

        uint8_t m_groupBegin[ 0 ];
        struct NoRelatedSym
        {
            groupSize m_dimension;
            struct Entry
            {
                Symbol m_Symbol;
                Int32 m_SecurityID;
                Int32NULL m_OrderQty;
                Int8 m_QuoteType;
                Int8NULL m_Side;
                uint8_t m_padding[ 32 - ( sizeof( m_Symbol ) + sizeof( m_SecurityID ) + sizeof( m_OrderQty ) + sizeof( m_QuoteType ) + sizeof( m_Side ) ) ];

                friend std::ostream & operator<<( std::ostream & a_stream , const Entry & a_instance )
                {
                    a_stream << "           m_Symbol-->[" << a_instance.m_Symbol << "]\n";
                    a_stream << "           m_SecurityID-->[" << a_instance.m_SecurityID << "]\n";
                    a_stream << "           m_OrderQty-->[" << a_instance.m_OrderQty << "]\n";
                    a_stream << "           m_QuoteType-->[" << a_instance.m_QuoteType << "]\n";
                    a_stream << "           m_Side-->[" << a_instance.m_Side << "]\n";
                    return( a_stream );
                }
            } PACK m_entries[0];
            ALWAYS_INLINE const size_t elements() const { return( (size_t)m_dimension.m_numInGroup.value() ); }
            ALWAYS_INLINE const auto entriesBegin() const { return( &m_entries[0] ); }
            ALWAYS_INLINE const auto entriesEnd() const { return( &m_entries[ elements() ] ); }
            ALWAYS_INLINE const void * const next(){ return( (void *)entriesEnd() ); }
        } PACK m_NoRelatedSym;

        friend std::ostream & operator<<( std::ostream & a_stream , const QuoteRequest39 & a_instance )
        {
            a_stream << "QuoteRequest39-->[" << (void *)&a_instance << "]\n";
            a_stream << "    m_TransactTime-->[" << a_instance.m_TransactTime << "]\n";
            a_stream << "    m_QuoteReqID-->[" << a_instance.m_QuoteReqID << "]\n";
            a_stream << "    m_MatchEventIndicator-->[" << a_instance.m_MatchEventIndicator << "]\n";
            auto l_block = reinterpret_cast<const void *>( &a_instance.m_groupBegin[ 0 ] );
            {
                auto l_NoRelatedSym = reinterpret_cast<const QuoteRequest39::NoRelatedSym *>( l_block );
                auto l_begin = l_NoRelatedSym->entriesBegin();
                auto l_end   = l_NoRelatedSym->entriesEnd();
                auto l_size  = l_NoRelatedSym->elements();
                a_stream << "    " << "NoRelatedSym-->[" << l_size << "]\n";
                for( auto l_entry = l_begin;
                     l_entry != l_end;
                     ++l_entry )
                {
                    a_stream << "        Entry-->[" << ( (l_entry-l_begin) + 1 ) << "/" << l_size << "," << (void *)l_entry << "]\n";
                    a_stream << *l_entry;
                }
                l_block = l_NoRelatedSym->next();
            }

            return( a_stream );
        }
    } PACK;

    struct MDInstrumentDefinitionOption41
    {
        static constexpr int32_t id() { return( 41 ); }
        static constexpr const char * name() { return( "MDInstrumentDefinitionOption41" ); }

        MatchEventIndicator m_MatchEventIndicator;
        uInt32NULL m_TotNumReports;
        SecurityUpdateAction m_SecurityUpdateAction;
        uInt64 m_LastUpdateTime;
        SecurityTradingStatus m_MDSecurityTradingStatus;
        Int16 m_ApplID;
        uInt8 m_MarketSegmentID;
        uInt8 m_UnderlyingProduct;
        SecurityExchange m_SecurityExchange;
        SecurityGroup m_SecurityGroup;
        Asset m_Asset;
        Symbol m_Symbol;
        Int32 m_SecurityID;
        SecurityIDSource m_SecurityIDSource;
        SecurityType m_SecurityType;
        CFICode m_CFICode;
        PutOrCall m_PutOrCall;
        MaturityMonthYear m_MaturityMonthYear;
        Currency m_Currency;
        PRICENULL m_StrikePrice;
        Currency m_StrikeCurrency;
        Currency m_SettlCurrency;
        PRICENULL m_MinCabPrice;
        CHAR m_MatchAlgorithm;
        uInt32 m_MinTradeVol;
        uInt32 m_MaxTradeVol;
        PRICENULL m_MinPriceIncrement;
        PRICENULL m_MinPriceIncrementAmount;
        FLOAT m_DisplayFactor;
        Int8NULL m_TickRule;
        uInt8NULL m_MainFraction;
        uInt8NULL m_SubFraction;
        uInt8NULL m_PriceDisplayFormat;
        UnitOfMeasure m_UnitOfMeasure;
        PRICENULL m_UnitOfMeasureQty;
        PRICENULL m_TradingReferencePrice;
        SettlPriceType m_SettlPriceType;
        Int32NULL m_ClearedVolume;
        Int32NULL m_OpenInterestQty;
        PRICENULL m_LowLimitPrice;
        PRICENULL m_HighLimitPrice;
        UserDefinedInstrument m_UserDefinedInstrument;
        LocalMktDate m_TradingReferenceDate;
        uint8_t m_padding[ 213 - ( sizeof( m_MatchEventIndicator ) + sizeof( m_TotNumReports ) + sizeof( m_SecurityUpdateAction ) + sizeof( m_LastUpdateTime ) + sizeof( m_MDSecurityTradingStatus ) + sizeof( m_ApplID ) + sizeof( m_MarketSegmentID ) + sizeof( m_UnderlyingProduct ) + sizeof( m_SecurityExchange ) + sizeof( m_SecurityGroup ) + sizeof( m_Asset ) + sizeof( m_Symbol ) + sizeof( m_SecurityID ) + sizeof( m_SecurityIDSource ) + sizeof( m_SecurityType ) + sizeof( m_CFICode ) + sizeof( m_PutOrCall ) + sizeof( m_MaturityMonthYear ) + sizeof( m_Currency ) + sizeof( m_StrikePrice ) + sizeof( m_StrikeCurrency ) + sizeof( m_SettlCurrency ) + sizeof( m_MinCabPrice ) + sizeof( m_MatchAlgorithm ) + sizeof( m_MinTradeVol ) + sizeof( m_MaxTradeVol ) + sizeof( m_MinPriceIncrement ) + sizeof( m_MinPriceIncrementAmount ) + sizeof( m_DisplayFactor ) + sizeof( m_TickRule ) + sizeof( m_MainFraction ) + sizeof( m_SubFraction ) + sizeof( m_PriceDisplayFormat ) + sizeof( m_UnitOfMeasure ) + sizeof( m_UnitOfMeasureQty ) + sizeof( m_TradingReferencePrice ) + sizeof( m_SettlPriceType ) + sizeof( m_ClearedVolume ) + sizeof( m_OpenInterestQty ) + sizeof( m_LowLimitPrice ) + sizeof( m_HighLimitPrice ) + sizeof( m_UserDefinedInstrument ) + sizeof( m_TradingReferenceDate ) ) ];

        uint8_t m_groupBegin[ 0 ];
        struct NoEvents
        {
            groupSize m_dimension;
            struct Entry
            {
                EventType m_EventType;
                uInt64 m_EventTime;
                uint8_t m_padding[ 9 - ( sizeof( m_EventType ) + sizeof( m_EventTime ) ) ];

                friend std::ostream & operator<<( std::ostream & a_stream , const Entry & a_instance )
                {
                    a_stream << "           m_EventType-->[" << a_instance.m_EventType << "]\n";
                    a_stream << "           m_EventTime-->[" << a_instance.m_EventTime << "]\n";
                    return( a_stream );
                }
            } PACK m_entries[0];
            ALWAYS_INLINE const size_t elements() const { return( (size_t)m_dimension.m_numInGroup.value() ); }
            ALWAYS_INLINE const auto entriesBegin() const { return( &m_entries[0] ); }
            ALWAYS_INLINE const auto entriesEnd() const { return( &m_entries[ elements() ] ); }
            ALWAYS_INLINE const void * const next(){ return( (void *)entriesEnd() ); }
        } PACK m_NoEvents;

        struct NoMDFeedTypes
        {
            groupSize m_dimension;
            struct Entry
            {
                MDFeedType m_MDFeedType;
                Int8 m_MarketDepth;
                uint8_t m_padding[ 4 - ( sizeof( m_MDFeedType ) + sizeof( m_MarketDepth ) ) ];

                friend std::ostream & operator<<( std::ostream & a_stream , const Entry & a_instance )
                {
                    a_stream << "           m_MDFeedType-->[" << a_instance.m_MDFeedType << "]\n";
                    a_stream << "           m_MarketDepth-->[" << a_instance.m_MarketDepth << "]\n";
                    return( a_stream );
                }
            } PACK m_entries[0];
            ALWAYS_INLINE const size_t elements() const { return( (size_t)m_dimension.m_numInGroup.value() ); }
            ALWAYS_INLINE const auto entriesBegin() const { return( &m_entries[0] ); }
            ALWAYS_INLINE const auto entriesEnd() const { return( &m_entries[ elements() ] ); }
            ALWAYS_INLINE const void * const next(){ return( (void *)entriesEnd() ); }
        } PACK m_NoMDFeedTypes;

        struct NoInstAttrib
        {
            groupSize m_dimension;
            struct Entry
            {
                InstAttribType m_InstAttribType;
                InstAttribValue m_InstAttribValue;
                uint8_t m_padding[ 4 - ( sizeof( m_InstAttribType ) + sizeof( m_InstAttribValue ) ) ];

                friend std::ostream & operator<<( std::ostream & a_stream , const Entry & a_instance )
                {
                    a_stream << "           m_InstAttribType-->[" << a_instance.m_InstAttribType << "]\n";
                    a_stream << "           m_InstAttribValue-->[" << a_instance.m_InstAttribValue << "]\n";
                    return( a_stream );
                }
            } PACK m_entries[0];
            ALWAYS_INLINE const size_t elements() const { return( (size_t)m_dimension.m_numInGroup.value() ); }
            ALWAYS_INLINE const auto entriesBegin() const { return( &m_entries[0] ); }
            ALWAYS_INLINE const auto entriesEnd() const { return( &m_entries[ elements() ] ); }
            ALWAYS_INLINE const void * const next(){ return( (void *)entriesEnd() ); }
        } PACK m_NoInstAttrib;

        struct NoLotTypeRules
        {
            groupSize m_dimension;
            struct Entry
            {
                Int8 m_LotType;
                DecimalQty m_MinLotSize;
                uint8_t m_padding[ 5 - ( sizeof( m_LotType ) + sizeof( m_MinLotSize ) ) ];

                friend std::ostream & operator<<( std::ostream & a_stream , const Entry & a_instance )
                {
                    a_stream << "           m_LotType-->[" << a_instance.m_LotType << "]\n";
                    a_stream << "           m_MinLotSize-->[" << a_instance.m_MinLotSize << "]\n";
                    return( a_stream );
                }
            } PACK m_entries[0];
            ALWAYS_INLINE const size_t elements() const { return( (size_t)m_dimension.m_numInGroup.value() ); }
            ALWAYS_INLINE const auto entriesBegin() const { return( &m_entries[0] ); }
            ALWAYS_INLINE const auto entriesEnd() const { return( &m_entries[ elements() ] ); }
            ALWAYS_INLINE const void * const next(){ return( (void *)entriesEnd() ); }
        } PACK m_NoLotTypeRules;

        struct NoUnderlyings
        {
            groupSize m_dimension;
            struct Entry
            {
                Int32 m_UnderlyingSecurityID;
                SecurityIDSource m_UnderlyingSecurityIDSource;
                UnderlyingSymbol m_UnderlyingSymbol;
                uint8_t m_padding[ 24 - ( sizeof( m_UnderlyingSecurityID ) + sizeof( m_UnderlyingSecurityIDSource ) + sizeof( m_UnderlyingSymbol ) ) ];

                friend std::ostream & operator<<( std::ostream & a_stream , const Entry & a_instance )
                {
                    a_stream << "           m_UnderlyingSecurityID-->[" << a_instance.m_UnderlyingSecurityID << "]\n";
                    a_stream << "           m_UnderlyingSecurityIDSource-->[" << a_instance.m_UnderlyingSecurityIDSource << "]\n";
                    a_stream << "           m_UnderlyingSymbol-->[" << a_instance.m_UnderlyingSymbol << "]\n";
                    return( a_stream );
                }
            } PACK m_entries[0];
            ALWAYS_INLINE const size_t elements() const { return( (size_t)m_dimension.m_numInGroup.value() ); }
            ALWAYS_INLINE const auto entriesBegin() const { return( &m_entries[0] ); }
            ALWAYS_INLINE const auto entriesEnd() const { return( &m_entries[ elements() ] ); }
            ALWAYS_INLINE const void * const next(){ return( (void *)entriesEnd() ); }
        } PACK m_NoUnderlyings;

        struct NoRelatedInstruments
        {
            groupSize m_dimension;
            struct Entry
            {
                Int32 m_RelatedSecurityID;
                SecurityIDSource m_RelatedSecurityIDSource;
                Symbol m_RelatedSymbol;
                uint8_t m_padding[ 24 - ( sizeof( m_RelatedSecurityID ) + sizeof( m_RelatedSecurityIDSource ) + sizeof( m_RelatedSymbol ) ) ];

                friend std::ostream & operator<<( std::ostream & a_stream , const Entry & a_instance )
                {
                    a_stream << "           m_RelatedSecurityID-->[" << a_instance.m_RelatedSecurityID << "]\n";
                    a_stream << "           m_RelatedSecurityIDSource-->[" << a_instance.m_RelatedSecurityIDSource << "]\n";
                    a_stream << "           m_RelatedSymbol-->[" << a_instance.m_RelatedSymbol << "]\n";
                    return( a_stream );
                }
            } PACK m_entries[0];
            ALWAYS_INLINE const size_t elements() const { return( (size_t)m_dimension.m_numInGroup.value() ); }
            ALWAYS_INLINE const auto entriesBegin() const { return( &m_entries[0] ); }
            ALWAYS_INLINE const auto entriesEnd() const { return( &m_entries[ elements() ] ); }
            ALWAYS_INLINE const void * const next(){ return( (void *)entriesEnd() ); }
        } PACK m_NoRelatedInstruments;

        friend std::ostream & operator<<( std::ostream & a_stream , const MDInstrumentDefinitionOption41 & a_instance )
        {
            a_stream << "MDInstrumentDefinitionOption41-->[" << (void *)&a_instance << "]\n";
            a_stream << "    m_MatchEventIndicator-->[" << a_instance.m_MatchEventIndicator << "]\n";
            a_stream << "    m_TotNumReports-->[" << a_instance.m_TotNumReports << "]\n";
            a_stream << "    m_SecurityUpdateAction-->[" << a_instance.m_SecurityUpdateAction << "]\n";
            a_stream << "    m_LastUpdateTime-->[" << a_instance.m_LastUpdateTime << "]\n";
            a_stream << "    m_MDSecurityTradingStatus-->[" << a_instance.m_MDSecurityTradingStatus << "]\n";
            a_stream << "    m_ApplID-->[" << a_instance.m_ApplID << "]\n";
            a_stream << "    m_MarketSegmentID-->[" << a_instance.m_MarketSegmentID << "]\n";
            a_stream << "    m_UnderlyingProduct-->[" << a_instance.m_UnderlyingProduct << "]\n";
            a_stream << "    m_SecurityExchange-->[" << a_instance.m_SecurityExchange << "]\n";
            a_stream << "    m_SecurityGroup-->[" << a_instance.m_SecurityGroup << "]\n";
            a_stream << "    m_Asset-->[" << a_instance.m_Asset << "]\n";
            a_stream << "    m_Symbol-->[" << a_instance.m_Symbol << "]\n";
            a_stream << "    m_SecurityID-->[" << a_instance.m_SecurityID << "]\n";
            a_stream << "    m_SecurityIDSource-->[" << a_instance.m_SecurityIDSource << "]\n";
            a_stream << "    m_SecurityType-->[" << a_instance.m_SecurityType << "]\n";
            a_stream << "    m_CFICode-->[" << a_instance.m_CFICode << "]\n";
            a_stream << "    m_PutOrCall-->[" << a_instance.m_PutOrCall << "]\n";
            a_stream << "    m_MaturityMonthYear-->[" << a_instance.m_MaturityMonthYear << "]\n";
            a_stream << "    m_Currency-->[" << a_instance.m_Currency << "]\n";
            a_stream << "    m_StrikePrice-->[" << a_instance.m_StrikePrice << "]\n";
            a_stream << "    m_StrikeCurrency-->[" << a_instance.m_StrikeCurrency << "]\n";
            a_stream << "    m_SettlCurrency-->[" << a_instance.m_SettlCurrency << "]\n";
            a_stream << "    m_MinCabPrice-->[" << a_instance.m_MinCabPrice << "]\n";
            a_stream << "    m_MatchAlgorithm-->[" << a_instance.m_MatchAlgorithm << "]\n";
            a_stream << "    m_MinTradeVol-->[" << a_instance.m_MinTradeVol << "]\n";
            a_stream << "    m_MaxTradeVol-->[" << a_instance.m_MaxTradeVol << "]\n";
            a_stream << "    m_MinPriceIncrement-->[" << a_instance.m_MinPriceIncrement << "]\n";
            a_stream << "    m_MinPriceIncrementAmount-->[" << a_instance.m_MinPriceIncrementAmount << "]\n";
            a_stream << "    m_DisplayFactor-->[" << a_instance.m_DisplayFactor << "]\n";
            a_stream << "    m_TickRule-->[" << a_instance.m_TickRule << "]\n";
            a_stream << "    m_MainFraction-->[" << a_instance.m_MainFraction << "]\n";
            a_stream << "    m_SubFraction-->[" << a_instance.m_SubFraction << "]\n";
            a_stream << "    m_PriceDisplayFormat-->[" << a_instance.m_PriceDisplayFormat << "]\n";
            a_stream << "    m_UnitOfMeasure-->[" << a_instance.m_UnitOfMeasure << "]\n";
            a_stream << "    m_UnitOfMeasureQty-->[" << a_instance.m_UnitOfMeasureQty << "]\n";
            a_stream << "    m_TradingReferencePrice-->[" << a_instance.m_TradingReferencePrice << "]\n";
            a_stream << "    m_SettlPriceType-->[" << a_instance.m_SettlPriceType << "]\n";
            a_stream << "    m_ClearedVolume-->[" << a_instance.m_ClearedVolume << "]\n";
            a_stream << "    m_OpenInterestQty-->[" << a_instance.m_OpenInterestQty << "]\n";
            a_stream << "    m_LowLimitPrice-->[" << a_instance.m_LowLimitPrice << "]\n";
            a_stream << "    m_HighLimitPrice-->[" << a_instance.m_HighLimitPrice << "]\n";
            a_stream << "    m_UserDefinedInstrument-->[" << a_instance.m_UserDefinedInstrument << "]\n";
            a_stream << "    m_TradingReferenceDate-->[" << a_instance.m_TradingReferenceDate << "]\n";
            auto l_block = reinterpret_cast<const void *>( &a_instance.m_groupBegin[ 0 ] );
            {
                auto l_NoEvents = reinterpret_cast<const MDInstrumentDefinitionOption41::NoEvents *>( l_block );
                auto l_begin = l_NoEvents->entriesBegin();
                auto l_end   = l_NoEvents->entriesEnd();
                auto l_size  = l_NoEvents->elements();
                a_stream << "    " << "NoEvents-->[" << l_size << "]\n";
                for( auto l_entry = l_begin;
                     l_entry != l_end;
                     ++l_entry )
                {
                    a_stream << "        Entry-->[" << ( (l_entry-l_begin) + 1 ) << "/" << l_size << "," << (void *)l_entry << "]\n";
                    a_stream << *l_entry;
                }
                l_block = l_NoEvents->next();
            }

            {
                auto l_NoMDFeedTypes = reinterpret_cast<const MDInstrumentDefinitionOption41::NoMDFeedTypes *>( l_block );
                auto l_begin = l_NoMDFeedTypes->entriesBegin();
                auto l_end   = l_NoMDFeedTypes->entriesEnd();
                auto l_size  = l_NoMDFeedTypes->elements();
                a_stream << "    " << "NoMDFeedTypes-->[" << l_size << "]\n";
                for( auto l_entry = l_begin;
                     l_entry != l_end;
                     ++l_entry )
                {
                    a_stream << "        Entry-->[" << ( (l_entry-l_begin) + 1 ) << "/" << l_size << "," << (void *)l_entry << "]\n";
                    a_stream << *l_entry;
                }
                l_block = l_NoMDFeedTypes->next();
            }

            {
                auto l_NoInstAttrib = reinterpret_cast<const MDInstrumentDefinitionOption41::NoInstAttrib *>( l_block );
                auto l_begin = l_NoInstAttrib->entriesBegin();
                auto l_end   = l_NoInstAttrib->entriesEnd();
                auto l_size  = l_NoInstAttrib->elements();
                a_stream << "    " << "NoInstAttrib-->[" << l_size << "]\n";
                for( auto l_entry = l_begin;
                     l_entry != l_end;
                     ++l_entry )
                {
                    a_stream << "        Entry-->[" << ( (l_entry-l_begin) + 1 ) << "/" << l_size << "," << (void *)l_entry << "]\n";
                    a_stream << *l_entry;
                }
                l_block = l_NoInstAttrib->next();
            }

            {
                auto l_NoLotTypeRules = reinterpret_cast<const MDInstrumentDefinitionOption41::NoLotTypeRules *>( l_block );
                auto l_begin = l_NoLotTypeRules->entriesBegin();
                auto l_end   = l_NoLotTypeRules->entriesEnd();
                auto l_size  = l_NoLotTypeRules->elements();
                a_stream << "    " << "NoLotTypeRules-->[" << l_size << "]\n";
                for( auto l_entry = l_begin;
                     l_entry != l_end;
                     ++l_entry )
                {
                    a_stream << "        Entry-->[" << ( (l_entry-l_begin) + 1 ) << "/" << l_size << "," << (void *)l_entry << "]\n";
                    a_stream << *l_entry;
                }
                l_block = l_NoLotTypeRules->next();
            }

            {
                auto l_NoUnderlyings = reinterpret_cast<const MDInstrumentDefinitionOption41::NoUnderlyings *>( l_block );
                auto l_begin = l_NoUnderlyings->entriesBegin();
                auto l_end   = l_NoUnderlyings->entriesEnd();
                auto l_size  = l_NoUnderlyings->elements();
                a_stream << "    " << "NoUnderlyings-->[" << l_size << "]\n";
                for( auto l_entry = l_begin;
                     l_entry != l_end;
                     ++l_entry )
                {
                    a_stream << "        Entry-->[" << ( (l_entry-l_begin) + 1 ) << "/" << l_size << "," << (void *)l_entry << "]\n";
                    a_stream << *l_entry;
                }
                l_block = l_NoUnderlyings->next();
            }

            {
                auto l_NoRelatedInstruments = reinterpret_cast<const MDInstrumentDefinitionOption41::NoRelatedInstruments *>( l_block );
                auto l_begin = l_NoRelatedInstruments->entriesBegin();
                auto l_end   = l_NoRelatedInstruments->entriesEnd();
                auto l_size  = l_NoRelatedInstruments->elements();
                a_stream << "    " << "NoRelatedInstruments-->[" << l_size << "]\n";
                for( auto l_entry = l_begin;
                     l_entry != l_end;
                     ++l_entry )
                {
                    a_stream << "        Entry-->[" << ( (l_entry-l_begin) + 1 ) << "/" << l_size << "," << (void *)l_entry << "]\n";
                    a_stream << *l_entry;
                }
                l_block = l_NoRelatedInstruments->next();
            }

            return( a_stream );
        }
    } PACK;

    struct MDIncrementalRefreshTradeSummary42
    {
        static constexpr int32_t id() { return( 42 ); }
        static constexpr const char * name() { return( "MDIncrementalRefreshTradeSummary42" ); }

        uInt64 m_TransactTime;
        MatchEventIndicator m_MatchEventIndicator;
        uint8_t m_padding[ 11 - ( sizeof( m_TransactTime ) + sizeof( m_MatchEventIndicator ) ) ];

        uint8_t m_groupBegin[ 0 ];
        struct NoMDEntries
        {
            groupSize m_dimension;
            struct Entry
            {
                PRICE m_MDEntryPx;
                Int32 m_MDEntrySize;
                Int32 m_SecurityID;
                uInt32 m_RptSeq;
                Int32NULL m_NumberOfOrders;
                AggressorSide m_AggressorSide;
                MDUpdateAction m_MDUpdateAction;
                MDEntryTypeTrade m_MDEntryType;
                uInt32NULL m_MDTradeEntryID;
                uint8_t m_padding[ 32 - ( sizeof( m_MDEntryPx ) + sizeof( m_MDEntrySize ) + sizeof( m_SecurityID ) + sizeof( m_RptSeq ) + sizeof( m_NumberOfOrders ) + sizeof( m_AggressorSide ) + sizeof( m_MDUpdateAction ) + sizeof( m_MDEntryType ) + sizeof( m_MDTradeEntryID ) ) ];

                friend std::ostream & operator<<( std::ostream & a_stream , const Entry & a_instance )
                {
                    a_stream << "           m_MDEntryPx-->[" << a_instance.m_MDEntryPx << "]\n";
                    a_stream << "           m_MDEntrySize-->[" << a_instance.m_MDEntrySize << "]\n";
                    a_stream << "           m_SecurityID-->[" << a_instance.m_SecurityID << "]\n";
                    a_stream << "           m_RptSeq-->[" << a_instance.m_RptSeq << "]\n";
                    a_stream << "           m_NumberOfOrders-->[" << a_instance.m_NumberOfOrders << "]\n";
                    a_stream << "           m_AggressorSide-->[" << a_instance.m_AggressorSide << "]\n";
                    a_stream << "           m_MDUpdateAction-->[" << a_instance.m_MDUpdateAction << "]\n";
                    a_stream << "           m_MDEntryType-->[" << a_instance.m_MDEntryType << "]\n";
                    a_stream << "           m_MDTradeEntryID-->[" << a_instance.m_MDTradeEntryID << "]\n";
                    return( a_stream );
                }
            } PACK m_entries[0];
            ALWAYS_INLINE const size_t elements() const { return( (size_t)m_dimension.m_numInGroup.value() ); }
            ALWAYS_INLINE const auto entriesBegin() const { return( &m_entries[0] ); }
            ALWAYS_INLINE const auto entriesEnd() const { return( &m_entries[ elements() ] ); }
            ALWAYS_INLINE const void * const next(){ return( (void *)entriesEnd() ); }
        } PACK m_NoMDEntries;

        struct NoOrderIDEntries
        {
            groupSize8Byte m_dimension;
            struct Entry
            {
                uInt64 m_OrderID;
                Int32 m_LastQty;
                uint8_t m_padding[ 16 - ( sizeof( m_OrderID ) + sizeof( m_LastQty ) ) ];

                friend std::ostream & operator<<( std::ostream & a_stream , const Entry & a_instance )
                {
                    a_stream << "           m_OrderID-->[" << a_instance.m_OrderID << "]\n";
                    a_stream << "           m_LastQty-->[" << a_instance.m_LastQty << "]\n";
                    return( a_stream );
                }
            } PACK m_entries[0];
            ALWAYS_INLINE const size_t elements() const { return( (size_t)m_dimension.m_numInGroup.value() ); }
            ALWAYS_INLINE const auto entriesBegin() const { return( &m_entries[0] ); }
            ALWAYS_INLINE const auto entriesEnd() const { return( &m_entries[ elements() ] ); }
            ALWAYS_INLINE const void * const next(){ return( (void *)entriesEnd() ); }
        } PACK m_NoOrderIDEntries;

        friend std::ostream & operator<<( std::ostream & a_stream , const MDIncrementalRefreshTradeSummary42 & a_instance )
        {
            a_stream << "MDIncrementalRefreshTradeSummary42-->[" << (void *)&a_instance << "]\n";
            a_stream << "    m_TransactTime-->[" << a_instance.m_TransactTime << "]\n";
            a_stream << "    m_MatchEventIndicator-->[" << a_instance.m_MatchEventIndicator << "]\n";
            auto l_block = reinterpret_cast<const void *>( &a_instance.m_groupBegin[ 0 ] );
            {
                auto l_NoMDEntries = reinterpret_cast<const MDIncrementalRefreshTradeSummary42::NoMDEntries *>( l_block );
                auto l_begin = l_NoMDEntries->entriesBegin();
                auto l_end   = l_NoMDEntries->entriesEnd();
                auto l_size  = l_NoMDEntries->elements();
                a_stream << "    " << "NoMDEntries-->[" << l_size << "]\n";
                for( auto l_entry = l_begin;
                     l_entry != l_end;
                     ++l_entry )
                {
                    a_stream << "        Entry-->[" << ( (l_entry-l_begin) + 1 ) << "/" << l_size << "," << (void *)l_entry << "]\n";
                    a_stream << *l_entry;
                }
                l_block = l_NoMDEntries->next();
            }

            {
                auto l_NoOrderIDEntries = reinterpret_cast<const MDIncrementalRefreshTradeSummary42::NoOrderIDEntries *>( l_block );
                auto l_begin = l_NoOrderIDEntries->entriesBegin();
                auto l_end   = l_NoOrderIDEntries->entriesEnd();
                auto l_size  = l_NoOrderIDEntries->elements();
                a_stream << "    " << "NoOrderIDEntries-->[" << l_size << "]\n";
                for( auto l_entry = l_begin;
                     l_entry != l_end;
                     ++l_entry )
                {
                    a_stream << "        Entry-->[" << ( (l_entry-l_begin) + 1 ) << "/" << l_size << "," << (void *)l_entry << "]\n";
                    a_stream << *l_entry;
                }
                l_block = l_NoOrderIDEntries->next();
            }

            return( a_stream );
        }
    } PACK;

    struct MDIncrementalRefreshOrderBook43
    {
        static constexpr int32_t id() { return( 43 ); }
        static constexpr const char * name() { return( "MDIncrementalRefreshOrderBook43" ); }

        uInt64 m_TransactTime;
        MatchEventIndicator m_MatchEventIndicator;
        uint8_t m_padding[ 11 - ( sizeof( m_TransactTime ) + sizeof( m_MatchEventIndicator ) ) ];

        uint8_t m_groupBegin[ 0 ];
        struct NoMDEntries
        {
            groupSize m_dimension;
            struct Entry
            {
                uInt64NULL m_OrderID;
                uInt64NULL m_MDOrderPriority;
                PRICENULL m_MDEntryPx;
                Int32NULL m_MDDisplayQty;
                Int32 m_SecurityID;
                MDUpdateAction m_MDUpdateAction;
                MDEntryTypeBook m_MDEntryType;
                uint8_t m_padding[ 40 - ( sizeof( m_OrderID ) + sizeof( m_MDOrderPriority ) + sizeof( m_MDEntryPx ) + sizeof( m_MDDisplayQty ) + sizeof( m_SecurityID ) + sizeof( m_MDUpdateAction ) + sizeof( m_MDEntryType ) ) ];

                friend std::ostream & operator<<( std::ostream & a_stream , const Entry & a_instance )
                {
                    a_stream << "           m_OrderID-->[" << a_instance.m_OrderID << "]\n";
                    a_stream << "           m_MDOrderPriority-->[" << a_instance.m_MDOrderPriority << "]\n";
                    a_stream << "           m_MDEntryPx-->[" << a_instance.m_MDEntryPx << "]\n";
                    a_stream << "           m_MDDisplayQty-->[" << a_instance.m_MDDisplayQty << "]\n";
                    a_stream << "           m_SecurityID-->[" << a_instance.m_SecurityID << "]\n";
                    a_stream << "           m_MDUpdateAction-->[" << a_instance.m_MDUpdateAction << "]\n";
                    a_stream << "           m_MDEntryType-->[" << a_instance.m_MDEntryType << "]\n";
                    return( a_stream );
                }
            } PACK m_entries[0];
            ALWAYS_INLINE const size_t elements() const { return( (size_t)m_dimension.m_numInGroup.value() ); }
            ALWAYS_INLINE const auto entriesBegin() const { return( &m_entries[0] ); }
            ALWAYS_INLINE const auto entriesEnd() const { return( &m_entries[ elements() ] ); }
            ALWAYS_INLINE const void * const next(){ return( (void *)entriesEnd() ); }
        } PACK m_NoMDEntries;

        friend std::ostream & operator<<( std::ostream & a_stream , const MDIncrementalRefreshOrderBook43 & a_instance )
        {
            a_stream << "MDIncrementalRefreshOrderBook43-->[" << (void *)&a_instance << "]\n";
            a_stream << "    m_TransactTime-->[" << a_instance.m_TransactTime << "]\n";
            a_stream << "    m_MatchEventIndicator-->[" << a_instance.m_MatchEventIndicator << "]\n";
            auto l_block = reinterpret_cast<const void *>( &a_instance.m_groupBegin[ 0 ] );
            {
                auto l_NoMDEntries = reinterpret_cast<const MDIncrementalRefreshOrderBook43::NoMDEntries *>( l_block );
                auto l_begin = l_NoMDEntries->entriesBegin();
                auto l_end   = l_NoMDEntries->entriesEnd();
                auto l_size  = l_NoMDEntries->elements();
                a_stream << "    " << "NoMDEntries-->[" << l_size << "]\n";
                for( auto l_entry = l_begin;
                     l_entry != l_end;
                     ++l_entry )
                {
                    a_stream << "        Entry-->[" << ( (l_entry-l_begin) + 1 ) << "/" << l_size << "," << (void *)l_entry << "]\n";
                    a_stream << *l_entry;
                }
                l_block = l_NoMDEntries->next();
            }

            return( a_stream );
        }
    } PACK;

    struct SnapshotFullRefreshOrderBook44
    {
        static constexpr int32_t id() { return( 44 ); }
        static constexpr const char * name() { return( "SnapshotFullRefreshOrderBook44" ); }

        uInt32 m_LastMsgSeqNumProcessed;
        uInt32 m_TotNumReports;
        Int32 m_SecurityID;
        uInt32 m_NoChunks;
        uInt32 m_CurrentChunk;
        uInt64 m_TransactTime;
        uint8_t m_padding[ 28 - ( sizeof( m_LastMsgSeqNumProcessed ) + sizeof( m_TotNumReports ) + sizeof( m_SecurityID ) + sizeof( m_NoChunks ) + sizeof( m_CurrentChunk ) + sizeof( m_TransactTime ) ) ];

        uint8_t m_groupBegin[ 0 ];
        struct NoMDEntries
        {
            groupSize m_dimension;
            struct Entry
            {
                uInt64 m_OrderID;
                uInt64NULL m_MDOrderPriority;
                PRICE m_MDEntryPx;
                Int32 m_MDDisplayQty;
                MDEntryTypeBook m_MDEntryType;
                uint8_t m_padding[ 29 - ( sizeof( m_OrderID ) + sizeof( m_MDOrderPriority ) + sizeof( m_MDEntryPx ) + sizeof( m_MDDisplayQty ) + sizeof( m_MDEntryType ) ) ];

                friend std::ostream & operator<<( std::ostream & a_stream , const Entry & a_instance )
                {
                    a_stream << "           m_OrderID-->[" << a_instance.m_OrderID << "]\n";
                    a_stream << "           m_MDOrderPriority-->[" << a_instance.m_MDOrderPriority << "]\n";
                    a_stream << "           m_MDEntryPx-->[" << a_instance.m_MDEntryPx << "]\n";
                    a_stream << "           m_MDDisplayQty-->[" << a_instance.m_MDDisplayQty << "]\n";
                    a_stream << "           m_MDEntryType-->[" << a_instance.m_MDEntryType << "]\n";
                    return( a_stream );
                }
            } PACK m_entries[0];
            ALWAYS_INLINE const size_t elements() const { return( (size_t)m_dimension.m_numInGroup.value() ); }
            ALWAYS_INLINE const auto entriesBegin() const { return( &m_entries[0] ); }
            ALWAYS_INLINE const auto entriesEnd() const { return( &m_entries[ elements() ] ); }
            ALWAYS_INLINE const void * const next(){ return( (void *)entriesEnd() ); }
        } PACK m_NoMDEntries;

        friend std::ostream & operator<<( std::ostream & a_stream , const SnapshotFullRefreshOrderBook44 & a_instance )
        {
            a_stream << "SnapshotFullRefreshOrderBook44-->[" << (void *)&a_instance << "]\n";
            a_stream << "    m_LastMsgSeqNumProcessed-->[" << a_instance.m_LastMsgSeqNumProcessed << "]\n";
            a_stream << "    m_TotNumReports-->[" << a_instance.m_TotNumReports << "]\n";
            a_stream << "    m_SecurityID-->[" << a_instance.m_SecurityID << "]\n";
            a_stream << "    m_NoChunks-->[" << a_instance.m_NoChunks << "]\n";
            a_stream << "    m_CurrentChunk-->[" << a_instance.m_CurrentChunk << "]\n";
            a_stream << "    m_TransactTime-->[" << a_instance.m_TransactTime << "]\n";
            auto l_block = reinterpret_cast<const void *>( &a_instance.m_groupBegin[ 0 ] );
            {
                auto l_NoMDEntries = reinterpret_cast<const SnapshotFullRefreshOrderBook44::NoMDEntries *>( l_block );
                auto l_begin = l_NoMDEntries->entriesBegin();
                auto l_end   = l_NoMDEntries->entriesEnd();
                auto l_size  = l_NoMDEntries->elements();
                a_stream << "    " << "NoMDEntries-->[" << l_size << "]\n";
                for( auto l_entry = l_begin;
                     l_entry != l_end;
                     ++l_entry )
                {
                    a_stream << "        Entry-->[" << ( (l_entry-l_begin) + 1 ) << "/" << l_size << "," << (void *)l_entry << "]\n";
                    a_stream << *l_entry;
                }
                l_block = l_NoMDEntries->next();
            }

            return( a_stream );
        }
    } PACK;

    struct MDIncrementalRefreshBook46
    {
        static constexpr int32_t id() { return( 46 ); }
        static constexpr const char * name() { return( "MDIncrementalRefreshBook46" ); }

        uInt64 m_TransactTime;
        MatchEventIndicator m_MatchEventIndicator;
        uint8_t m_padding[ 11 - ( sizeof( m_TransactTime ) + sizeof( m_MatchEventIndicator ) ) ];

        uint8_t m_groupBegin[ 0 ];
        struct NoMDEntries
        {
            groupSize m_dimension;
            struct Entry
            {
                PRICENULL9 m_MDEntryPx;
                Int32NULL m_MDEntrySize;
                Int32 m_SecurityID;
                uInt32 m_RptSeq;
                Int32NULL m_NumberOfOrders;
                uInt8 m_MDPriceLevel;
                MDUpdateAction m_MDUpdateAction;
                MDEntryTypeBook m_MDEntryType;
                uint8_t m_padding[ 32 - ( sizeof( m_MDEntryPx ) + sizeof( m_MDEntrySize ) + sizeof( m_SecurityID ) + sizeof( m_RptSeq ) + sizeof( m_NumberOfOrders ) + sizeof( m_MDPriceLevel ) + sizeof( m_MDUpdateAction ) + sizeof( m_MDEntryType ) ) ];

                friend std::ostream & operator<<( std::ostream & a_stream , const Entry & a_instance )
                {
                    a_stream << "           m_MDEntryPx-->[" << a_instance.m_MDEntryPx << "]\n";
                    a_stream << "           m_MDEntrySize-->[" << a_instance.m_MDEntrySize << "]\n";
                    a_stream << "           m_SecurityID-->[" << a_instance.m_SecurityID << "]\n";
                    a_stream << "           m_RptSeq-->[" << a_instance.m_RptSeq << "]\n";
                    a_stream << "           m_NumberOfOrders-->[" << a_instance.m_NumberOfOrders << "]\n";
                    a_stream << "           m_MDPriceLevel-->[" << a_instance.m_MDPriceLevel << "]\n";
                    a_stream << "           m_MDUpdateAction-->[" << a_instance.m_MDUpdateAction << "]\n";
                    a_stream << "           m_MDEntryType-->[" << a_instance.m_MDEntryType << "]\n";
                    return( a_stream );
                }
            } PACK m_entries[0];
            ALWAYS_INLINE const size_t elements() const { return( (size_t)m_dimension.m_numInGroup.value() ); }
            ALWAYS_INLINE const auto entriesBegin() const { return( &m_entries[0] ); }
            ALWAYS_INLINE const auto entriesEnd() const { return( &m_entries[ elements() ] ); }
            ALWAYS_INLINE const void * const next(){ return( (void *)entriesEnd() ); }
        } PACK m_NoMDEntries;

        struct NoOrderIDEntries
        {
            groupSize8Byte m_dimension;
            struct Entry
            {
                uInt64 m_OrderID;
                uInt64NULL m_MDOrderPriority;
                Int32NULL m_MDDisplayQty;
                uInt8NULL m_ReferenceID;
                OrderUpdateAction m_OrderUpdateAction;
                uint8_t m_padding[ 24 - ( sizeof( m_OrderID ) + sizeof( m_MDOrderPriority ) + sizeof( m_MDDisplayQty ) + sizeof( m_ReferenceID ) + sizeof( m_OrderUpdateAction ) ) ];

                friend std::ostream & operator<<( std::ostream & a_stream , const Entry & a_instance )
                {
                    a_stream << "           m_OrderID-->[" << a_instance.m_OrderID << "]\n";
                    a_stream << "           m_MDOrderPriority-->[" << a_instance.m_MDOrderPriority << "]\n";
                    a_stream << "           m_MDDisplayQty-->[" << a_instance.m_MDDisplayQty << "]\n";
                    a_stream << "           m_ReferenceID-->[" << a_instance.m_ReferenceID << "]\n";
                    a_stream << "           m_OrderUpdateAction-->[" << a_instance.m_OrderUpdateAction << "]\n";
                    return( a_stream );
                }
            } PACK m_entries[0];
            ALWAYS_INLINE const size_t elements() const { return( (size_t)m_dimension.m_numInGroup.value() ); }
            ALWAYS_INLINE const auto entriesBegin() const { return( &m_entries[0] ); }
            ALWAYS_INLINE const auto entriesEnd() const { return( &m_entries[ elements() ] ); }
            ALWAYS_INLINE const void * const next(){ return( (void *)entriesEnd() ); }
        } PACK m_NoOrderIDEntries;

        friend std::ostream & operator<<( std::ostream & a_stream , const MDIncrementalRefreshBook46 & a_instance )
        {
            a_stream << "MDIncrementalRefreshBook46-->[" << (void *)&a_instance << "]\n";
            a_stream << "    m_TransactTime-->[" << a_instance.m_TransactTime << "]\n";
            a_stream << "    m_MatchEventIndicator-->[" << a_instance.m_MatchEventIndicator << "]\n";
            auto l_block = reinterpret_cast<const void *>( &a_instance.m_groupBegin[ 0 ] );
            {
                auto l_NoMDEntries = reinterpret_cast<const MDIncrementalRefreshBook46::NoMDEntries *>( l_block );
                auto l_begin = l_NoMDEntries->entriesBegin();
                auto l_end   = l_NoMDEntries->entriesEnd();
                auto l_size  = l_NoMDEntries->elements();
                a_stream << "    " << "NoMDEntries-->[" << l_size << "]\n";
                for( auto l_entry = l_begin;
                     l_entry != l_end;
                     ++l_entry )
                {
                    a_stream << "        Entry-->[" << ( (l_entry-l_begin) + 1 ) << "/" << l_size << "," << (void *)l_entry << "]\n";
                    a_stream << *l_entry;
                }
                l_block = l_NoMDEntries->next();
            }

            {
                auto l_NoOrderIDEntries = reinterpret_cast<const MDIncrementalRefreshBook46::NoOrderIDEntries *>( l_block );
                auto l_begin = l_NoOrderIDEntries->entriesBegin();
                auto l_end   = l_NoOrderIDEntries->entriesEnd();
                auto l_size  = l_NoOrderIDEntries->elements();
                a_stream << "    " << "NoOrderIDEntries-->[" << l_size << "]\n";
                for( auto l_entry = l_begin;
                     l_entry != l_end;
                     ++l_entry )
                {
                    a_stream << "        Entry-->[" << ( (l_entry-l_begin) + 1 ) << "/" << l_size << "," << (void *)l_entry << "]\n";
                    a_stream << *l_entry;
                }
                l_block = l_NoOrderIDEntries->next();
            }

            return( a_stream );
        }
    } PACK;

    struct MDIncrementalRefreshOrderBook47
    {
        static constexpr int32_t id() { return( 47 ); }
        static constexpr const char * name() { return( "MDIncrementalRefreshOrderBook47" ); }

        uInt64 m_TransactTime;
        MatchEventIndicator m_MatchEventIndicator;
        uint8_t m_padding[ 11 - ( sizeof( m_TransactTime ) + sizeof( m_MatchEventIndicator ) ) ];

        uint8_t m_groupBegin[ 0 ];
        struct NoMDEntries
        {
            groupSize m_dimension;
            struct Entry
            {
                uInt64NULL m_OrderID;
                uInt64NULL m_MDOrderPriority;
                PRICENULL9 m_MDEntryPx;
                Int32NULL m_MDDisplayQty;
                Int32 m_SecurityID;
                MDUpdateAction m_MDUpdateAction;
                MDEntryTypeBook m_MDEntryType;
                uint8_t m_padding[ 40 - ( sizeof( m_OrderID ) + sizeof( m_MDOrderPriority ) + sizeof( m_MDEntryPx ) + sizeof( m_MDDisplayQty ) + sizeof( m_SecurityID ) + sizeof( m_MDUpdateAction ) + sizeof( m_MDEntryType ) ) ];

                friend std::ostream & operator<<( std::ostream & a_stream , const Entry & a_instance )
                {
                    a_stream << "           m_OrderID-->[" << a_instance.m_OrderID << "]\n";
                    a_stream << "           m_MDOrderPriority-->[" << a_instance.m_MDOrderPriority << "]\n";
                    a_stream << "           m_MDEntryPx-->[" << a_instance.m_MDEntryPx << "]\n";
                    a_stream << "           m_MDDisplayQty-->[" << a_instance.m_MDDisplayQty << "]\n";
                    a_stream << "           m_SecurityID-->[" << a_instance.m_SecurityID << "]\n";
                    a_stream << "           m_MDUpdateAction-->[" << a_instance.m_MDUpdateAction << "]\n";
                    a_stream << "           m_MDEntryType-->[" << a_instance.m_MDEntryType << "]\n";
                    return( a_stream );
                }
            } PACK m_entries[0];
            ALWAYS_INLINE const size_t elements() const { return( (size_t)m_dimension.m_numInGroup.value() ); }
            ALWAYS_INLINE const auto entriesBegin() const { return( &m_entries[0] ); }
            ALWAYS_INLINE const auto entriesEnd() const { return( &m_entries[ elements() ] ); }
            ALWAYS_INLINE const void * const next(){ return( (void *)entriesEnd() ); }
        } PACK m_NoMDEntries;

        friend std::ostream & operator<<( std::ostream & a_stream , const MDIncrementalRefreshOrderBook47 & a_instance )
        {
            a_stream << "MDIncrementalRefreshOrderBook47-->[" << (void *)&a_instance << "]\n";
            a_stream << "    m_TransactTime-->[" << a_instance.m_TransactTime << "]\n";
            a_stream << "    m_MatchEventIndicator-->[" << a_instance.m_MatchEventIndicator << "]\n";
            auto l_block = reinterpret_cast<const void *>( &a_instance.m_groupBegin[ 0 ] );
            {
                auto l_NoMDEntries = reinterpret_cast<const MDIncrementalRefreshOrderBook47::NoMDEntries *>( l_block );
                auto l_begin = l_NoMDEntries->entriesBegin();
                auto l_end   = l_NoMDEntries->entriesEnd();
                auto l_size  = l_NoMDEntries->elements();
                a_stream << "    " << "NoMDEntries-->[" << l_size << "]\n";
                for( auto l_entry = l_begin;
                     l_entry != l_end;
                     ++l_entry )
                {
                    a_stream << "        Entry-->[" << ( (l_entry-l_begin) + 1 ) << "/" << l_size << "," << (void *)l_entry << "]\n";
                    a_stream << *l_entry;
                }
                l_block = l_NoMDEntries->next();
            }

            return( a_stream );
        }
    } PACK;

    struct MDIncrementalRefreshTradeSummary48
    {
        static constexpr int32_t id() { return( 48 ); }
        static constexpr const char * name() { return( "MDIncrementalRefreshTradeSummary48" ); }

        uInt64 m_TransactTime;
        MatchEventIndicator m_MatchEventIndicator;
        uint8_t m_padding[ 11 - ( sizeof( m_TransactTime ) + sizeof( m_MatchEventIndicator ) ) ];

        uint8_t m_groupBegin[ 0 ];
        struct NoMDEntries
        {
            groupSize m_dimension;
            struct Entry
            {
                PRICE9 m_MDEntryPx;
                Int32 m_MDEntrySize;
                Int32 m_SecurityID;
                uInt32 m_RptSeq;
                Int32 m_NumberOfOrders;
                AggressorSide m_AggressorSide;
                MDUpdateAction m_MDUpdateAction;
                MDEntryTypeTrade m_MDEntryType;
                uInt32NULL m_MDTradeEntryID;
                uint8_t m_padding[ 32 - ( sizeof( m_MDEntryPx ) + sizeof( m_MDEntrySize ) + sizeof( m_SecurityID ) + sizeof( m_RptSeq ) + sizeof( m_NumberOfOrders ) + sizeof( m_AggressorSide ) + sizeof( m_MDUpdateAction ) + sizeof( m_MDEntryType ) + sizeof( m_MDTradeEntryID ) ) ];

                friend std::ostream & operator<<( std::ostream & a_stream , const Entry & a_instance )
                {
                    a_stream << "           m_MDEntryPx-->[" << a_instance.m_MDEntryPx << "]\n";
                    a_stream << "           m_MDEntrySize-->[" << a_instance.m_MDEntrySize << "]\n";
                    a_stream << "           m_SecurityID-->[" << a_instance.m_SecurityID << "]\n";
                    a_stream << "           m_RptSeq-->[" << a_instance.m_RptSeq << "]\n";
                    a_stream << "           m_NumberOfOrders-->[" << a_instance.m_NumberOfOrders << "]\n";
                    a_stream << "           m_AggressorSide-->[" << a_instance.m_AggressorSide << "]\n";
                    a_stream << "           m_MDUpdateAction-->[" << a_instance.m_MDUpdateAction << "]\n";
                    a_stream << "           m_MDEntryType-->[" << a_instance.m_MDEntryType << "]\n";
                    a_stream << "           m_MDTradeEntryID-->[" << a_instance.m_MDTradeEntryID << "]\n";
                    return( a_stream );
                }
            } PACK m_entries[0];
            ALWAYS_INLINE const size_t elements() const { return( (size_t)m_dimension.m_numInGroup.value() ); }
            ALWAYS_INLINE const auto entriesBegin() const { return( &m_entries[0] ); }
            ALWAYS_INLINE const auto entriesEnd() const { return( &m_entries[ elements() ] ); }
            ALWAYS_INLINE const void * const next(){ return( (void *)entriesEnd() ); }
        } PACK m_NoMDEntries;

        struct NoOrderIDEntries
        {
            groupSize8Byte m_dimension;
            struct Entry
            {
                uInt64 m_OrderID;
                Int32 m_LastQty;
                uint8_t m_padding[ 16 - ( sizeof( m_OrderID ) + sizeof( m_LastQty ) ) ];

                friend std::ostream & operator<<( std::ostream & a_stream , const Entry & a_instance )
                {
                    a_stream << "           m_OrderID-->[" << a_instance.m_OrderID << "]\n";
                    a_stream << "           m_LastQty-->[" << a_instance.m_LastQty << "]\n";
                    return( a_stream );
                }
            } PACK m_entries[0];
            ALWAYS_INLINE const size_t elements() const { return( (size_t)m_dimension.m_numInGroup.value() ); }
            ALWAYS_INLINE const auto entriesBegin() const { return( &m_entries[0] ); }
            ALWAYS_INLINE const auto entriesEnd() const { return( &m_entries[ elements() ] ); }
            ALWAYS_INLINE const void * const next(){ return( (void *)entriesEnd() ); }
        } PACK m_NoOrderIDEntries;

        friend std::ostream & operator<<( std::ostream & a_stream , const MDIncrementalRefreshTradeSummary48 & a_instance )
        {
            a_stream << "MDIncrementalRefreshTradeSummary48-->[" << (void *)&a_instance << "]\n";
            a_stream << "    m_TransactTime-->[" << a_instance.m_TransactTime << "]\n";
            a_stream << "    m_MatchEventIndicator-->[" << a_instance.m_MatchEventIndicator << "]\n";
            auto l_block = reinterpret_cast<const void *>( &a_instance.m_groupBegin[ 0 ] );
            {
                auto l_NoMDEntries = reinterpret_cast<const MDIncrementalRefreshTradeSummary48::NoMDEntries *>( l_block );
                auto l_begin = l_NoMDEntries->entriesBegin();
                auto l_end   = l_NoMDEntries->entriesEnd();
                auto l_size  = l_NoMDEntries->elements();
                a_stream << "    " << "NoMDEntries-->[" << l_size << "]\n";
                for( auto l_entry = l_begin;
                     l_entry != l_end;
                     ++l_entry )
                {
                    a_stream << "        Entry-->[" << ( (l_entry-l_begin) + 1 ) << "/" << l_size << "," << (void *)l_entry << "]\n";
                    a_stream << *l_entry;
                }
                l_block = l_NoMDEntries->next();
            }

            {
                auto l_NoOrderIDEntries = reinterpret_cast<const MDIncrementalRefreshTradeSummary48::NoOrderIDEntries *>( l_block );
                auto l_begin = l_NoOrderIDEntries->entriesBegin();
                auto l_end   = l_NoOrderIDEntries->entriesEnd();
                auto l_size  = l_NoOrderIDEntries->elements();
                a_stream << "    " << "NoOrderIDEntries-->[" << l_size << "]\n";
                for( auto l_entry = l_begin;
                     l_entry != l_end;
                     ++l_entry )
                {
                    a_stream << "        Entry-->[" << ( (l_entry-l_begin) + 1 ) << "/" << l_size << "," << (void *)l_entry << "]\n";
                    a_stream << *l_entry;
                }
                l_block = l_NoOrderIDEntries->next();
            }

            return( a_stream );
        }
    } PACK;

    struct MDIncrementalRefreshDailyStatistics49
    {
        static constexpr int32_t id() { return( 49 ); }
        static constexpr const char * name() { return( "MDIncrementalRefreshDailyStatistics49" ); }

        uInt64 m_TransactTime;
        MatchEventIndicator m_MatchEventIndicator;
        uint8_t m_padding[ 11 - ( sizeof( m_TransactTime ) + sizeof( m_MatchEventIndicator ) ) ];

        uint8_t m_groupBegin[ 0 ];
        struct NoMDEntries
        {
            groupSize m_dimension;
            struct Entry
            {
                PRICENULL9 m_MDEntryPx;
                Int32NULL m_MDEntrySize;
                Int32 m_SecurityID;
                uInt32 m_RptSeq;
                LocalMktDate m_TradingReferenceDate;
                SettlPriceType m_SettlPriceType;
                MDUpdateAction m_MDUpdateAction;
                MDEntryTypeDailyStatistics m_MDEntryType;
                uint8_t m_padding[ 32 - ( sizeof( m_MDEntryPx ) + sizeof( m_MDEntrySize ) + sizeof( m_SecurityID ) + sizeof( m_RptSeq ) + sizeof( m_TradingReferenceDate ) + sizeof( m_SettlPriceType ) + sizeof( m_MDUpdateAction ) + sizeof( m_MDEntryType ) ) ];

                friend std::ostream & operator<<( std::ostream & a_stream , const Entry & a_instance )
                {
                    a_stream << "           m_MDEntryPx-->[" << a_instance.m_MDEntryPx << "]\n";
                    a_stream << "           m_MDEntrySize-->[" << a_instance.m_MDEntrySize << "]\n";
                    a_stream << "           m_SecurityID-->[" << a_instance.m_SecurityID << "]\n";
                    a_stream << "           m_RptSeq-->[" << a_instance.m_RptSeq << "]\n";
                    a_stream << "           m_TradingReferenceDate-->[" << a_instance.m_TradingReferenceDate << "]\n";
                    a_stream << "           m_SettlPriceType-->[" << a_instance.m_SettlPriceType << "]\n";
                    a_stream << "           m_MDUpdateAction-->[" << a_instance.m_MDUpdateAction << "]\n";
                    a_stream << "           m_MDEntryType-->[" << a_instance.m_MDEntryType << "]\n";
                    return( a_stream );
                }
            } PACK m_entries[0];
            ALWAYS_INLINE const size_t elements() const { return( (size_t)m_dimension.m_numInGroup.value() ); }
            ALWAYS_INLINE const auto entriesBegin() const { return( &m_entries[0] ); }
            ALWAYS_INLINE const auto entriesEnd() const { return( &m_entries[ elements() ] ); }
            ALWAYS_INLINE const void * const next(){ return( (void *)entriesEnd() ); }
        } PACK m_NoMDEntries;

        friend std::ostream & operator<<( std::ostream & a_stream , const MDIncrementalRefreshDailyStatistics49 & a_instance )
        {
            a_stream << "MDIncrementalRefreshDailyStatistics49-->[" << (void *)&a_instance << "]\n";
            a_stream << "    m_TransactTime-->[" << a_instance.m_TransactTime << "]\n";
            a_stream << "    m_MatchEventIndicator-->[" << a_instance.m_MatchEventIndicator << "]\n";
            auto l_block = reinterpret_cast<const void *>( &a_instance.m_groupBegin[ 0 ] );
            {
                auto l_NoMDEntries = reinterpret_cast<const MDIncrementalRefreshDailyStatistics49::NoMDEntries *>( l_block );
                auto l_begin = l_NoMDEntries->entriesBegin();
                auto l_end   = l_NoMDEntries->entriesEnd();
                auto l_size  = l_NoMDEntries->elements();
                a_stream << "    " << "NoMDEntries-->[" << l_size << "]\n";
                for( auto l_entry = l_begin;
                     l_entry != l_end;
                     ++l_entry )
                {
                    a_stream << "        Entry-->[" << ( (l_entry-l_begin) + 1 ) << "/" << l_size << "," << (void *)l_entry << "]\n";
                    a_stream << *l_entry;
                }
                l_block = l_NoMDEntries->next();
            }

            return( a_stream );
        }
    } PACK;

    struct MDIncrementalRefreshLimitsBanding50
    {
        static constexpr int32_t id() { return( 50 ); }
        static constexpr const char * name() { return( "MDIncrementalRefreshLimitsBanding50" ); }

        uInt64 m_TransactTime;
        MatchEventIndicator m_MatchEventIndicator;
        uint8_t m_padding[ 11 - ( sizeof( m_TransactTime ) + sizeof( m_MatchEventIndicator ) ) ];

        uint8_t m_groupBegin[ 0 ];
        struct NoMDEntries
        {
            groupSize m_dimension;
            struct Entry
            {
                PRICENULL9 m_HighLimitPrice;
                PRICENULL9 m_LowLimitPrice;
                PRICENULL9 m_MaxPriceVariation;
                Int32 m_SecurityID;
                uInt32 m_RptSeq;
                MDUpdateActionNew m_MDUpdateAction;
                MDEntryTypeLimits m_MDEntryType;
                uint8_t m_padding[ 32 - ( sizeof( m_HighLimitPrice ) + sizeof( m_LowLimitPrice ) + sizeof( m_MaxPriceVariation ) + sizeof( m_SecurityID ) + sizeof( m_RptSeq ) + sizeof( m_MDUpdateAction ) + sizeof( m_MDEntryType ) ) ];

                friend std::ostream & operator<<( std::ostream & a_stream , const Entry & a_instance )
                {
                    a_stream << "           m_HighLimitPrice-->[" << a_instance.m_HighLimitPrice << "]\n";
                    a_stream << "           m_LowLimitPrice-->[" << a_instance.m_LowLimitPrice << "]\n";
                    a_stream << "           m_MaxPriceVariation-->[" << a_instance.m_MaxPriceVariation << "]\n";
                    a_stream << "           m_SecurityID-->[" << a_instance.m_SecurityID << "]\n";
                    a_stream << "           m_RptSeq-->[" << a_instance.m_RptSeq << "]\n";
                    a_stream << "           m_MDUpdateAction-->[" << a_instance.m_MDUpdateAction << "]\n";
                    a_stream << "           m_MDEntryType-->[" << a_instance.m_MDEntryType << "]\n";
                    return( a_stream );
                }
            } PACK m_entries[0];
            ALWAYS_INLINE const size_t elements() const { return( (size_t)m_dimension.m_numInGroup.value() ); }
            ALWAYS_INLINE const auto entriesBegin() const { return( &m_entries[0] ); }
            ALWAYS_INLINE const auto entriesEnd() const { return( &m_entries[ elements() ] ); }
            ALWAYS_INLINE const void * const next(){ return( (void *)entriesEnd() ); }
        } PACK m_NoMDEntries;

        friend std::ostream & operator<<( std::ostream & a_stream , const MDIncrementalRefreshLimitsBanding50 & a_instance )
        {
            a_stream << "MDIncrementalRefreshLimitsBanding50-->[" << (void *)&a_instance << "]\n";
            a_stream << "    m_TransactTime-->[" << a_instance.m_TransactTime << "]\n";
            a_stream << "    m_MatchEventIndicator-->[" << a_instance.m_MatchEventIndicator << "]\n";
            auto l_block = reinterpret_cast<const void *>( &a_instance.m_groupBegin[ 0 ] );
            {
                auto l_NoMDEntries = reinterpret_cast<const MDIncrementalRefreshLimitsBanding50::NoMDEntries *>( l_block );
                auto l_begin = l_NoMDEntries->entriesBegin();
                auto l_end   = l_NoMDEntries->entriesEnd();
                auto l_size  = l_NoMDEntries->elements();
                a_stream << "    " << "NoMDEntries-->[" << l_size << "]\n";
                for( auto l_entry = l_begin;
                     l_entry != l_end;
                     ++l_entry )
                {
                    a_stream << "        Entry-->[" << ( (l_entry-l_begin) + 1 ) << "/" << l_size << "," << (void *)l_entry << "]\n";
                    a_stream << *l_entry;
                }
                l_block = l_NoMDEntries->next();
            }

            return( a_stream );
        }
    } PACK;

    struct MDIncrementalRefreshSessionStatistics51
    {
        static constexpr int32_t id() { return( 51 ); }
        static constexpr const char * name() { return( "MDIncrementalRefreshSessionStatistics51" ); }

        uInt64 m_TransactTime;
        MatchEventIndicator m_MatchEventIndicator;
        uint8_t m_padding[ 11 - ( sizeof( m_TransactTime ) + sizeof( m_MatchEventIndicator ) ) ];

        uint8_t m_groupBegin[ 0 ];
        struct NoMDEntries
        {
            groupSize m_dimension;
            struct Entry
            {
                PRICE9 m_MDEntryPx;
                Int32 m_SecurityID;
                uInt32 m_RptSeq;
                OpenCloseSettlFlag m_OpenCloseSettlFlag;
                MDUpdateAction m_MDUpdateAction;
                MDEntryTypeStatistics m_MDEntryType;
                Int32NULL m_MDEntrySize;
                uint8_t m_padding[ 24 - ( sizeof( m_MDEntryPx ) + sizeof( m_SecurityID ) + sizeof( m_RptSeq ) + sizeof( m_OpenCloseSettlFlag ) + sizeof( m_MDUpdateAction ) + sizeof( m_MDEntryType ) + sizeof( m_MDEntrySize ) ) ];

                friend std::ostream & operator<<( std::ostream & a_stream , const Entry & a_instance )
                {
                    a_stream << "           m_MDEntryPx-->[" << a_instance.m_MDEntryPx << "]\n";
                    a_stream << "           m_SecurityID-->[" << a_instance.m_SecurityID << "]\n";
                    a_stream << "           m_RptSeq-->[" << a_instance.m_RptSeq << "]\n";
                    a_stream << "           m_OpenCloseSettlFlag-->[" << a_instance.m_OpenCloseSettlFlag << "]\n";
                    a_stream << "           m_MDUpdateAction-->[" << a_instance.m_MDUpdateAction << "]\n";
                    a_stream << "           m_MDEntryType-->[" << a_instance.m_MDEntryType << "]\n";
                    a_stream << "           m_MDEntrySize-->[" << a_instance.m_MDEntrySize << "]\n";
                    return( a_stream );
                }
            } PACK m_entries[0];
            ALWAYS_INLINE const size_t elements() const { return( (size_t)m_dimension.m_numInGroup.value() ); }
            ALWAYS_INLINE const auto entriesBegin() const { return( &m_entries[0] ); }
            ALWAYS_INLINE const auto entriesEnd() const { return( &m_entries[ elements() ] ); }
            ALWAYS_INLINE const void * const next(){ return( (void *)entriesEnd() ); }
        } PACK m_NoMDEntries;

        friend std::ostream & operator<<( std::ostream & a_stream , const MDIncrementalRefreshSessionStatistics51 & a_instance )
        {
            a_stream << "MDIncrementalRefreshSessionStatistics51-->[" << (void *)&a_instance << "]\n";
            a_stream << "    m_TransactTime-->[" << a_instance.m_TransactTime << "]\n";
            a_stream << "    m_MatchEventIndicator-->[" << a_instance.m_MatchEventIndicator << "]\n";
            auto l_block = reinterpret_cast<const void *>( &a_instance.m_groupBegin[ 0 ] );
            {
                auto l_NoMDEntries = reinterpret_cast<const MDIncrementalRefreshSessionStatistics51::NoMDEntries *>( l_block );
                auto l_begin = l_NoMDEntries->entriesBegin();
                auto l_end   = l_NoMDEntries->entriesEnd();
                auto l_size  = l_NoMDEntries->elements();
                a_stream << "    " << "NoMDEntries-->[" << l_size << "]\n";
                for( auto l_entry = l_begin;
                     l_entry != l_end;
                     ++l_entry )
                {
                    a_stream << "        Entry-->[" << ( (l_entry-l_begin) + 1 ) << "/" << l_size << "," << (void *)l_entry << "]\n";
                    a_stream << *l_entry;
                }
                l_block = l_NoMDEntries->next();
            }

            return( a_stream );
        }
    } PACK;

    struct SnapshotFullRefresh52
    {
        static constexpr int32_t id() { return( 52 ); }
        static constexpr const char * name() { return( "SnapshotFullRefresh52" ); }

        uInt32 m_LastMsgSeqNumProcessed;
        uInt32 m_TotNumReports;
        Int32 m_SecurityID;
        uInt32 m_RptSeq;
        uInt64 m_TransactTime;
        uInt64 m_LastUpdateTime;
        LocalMktDate m_TradeDate;
        SecurityTradingStatus m_MDSecurityTradingStatus;
        PRICENULL9 m_HighLimitPrice;
        PRICENULL9 m_LowLimitPrice;
        PRICENULL9 m_MaxPriceVariation;
        uint8_t m_padding[ 59 - ( sizeof( m_LastMsgSeqNumProcessed ) + sizeof( m_TotNumReports ) + sizeof( m_SecurityID ) + sizeof( m_RptSeq ) + sizeof( m_TransactTime ) + sizeof( m_LastUpdateTime ) + sizeof( m_TradeDate ) + sizeof( m_MDSecurityTradingStatus ) + sizeof( m_HighLimitPrice ) + sizeof( m_LowLimitPrice ) + sizeof( m_MaxPriceVariation ) ) ];

        uint8_t m_groupBegin[ 0 ];
        struct NoMDEntries
        {
            groupSize m_dimension;
            struct Entry
            {
                PRICENULL9 m_MDEntryPx;
                Int32NULL m_MDEntrySize;
                Int32NULL m_NumberOfOrders;
                Int8NULL m_MDPriceLevel;
                LocalMktDate m_TradingReferenceDate;
                OpenCloseSettlFlag m_OpenCloseSettlFlag;
                SettlPriceType m_SettlPriceType;
                MDEntryType m_MDEntryType;
                uint8_t m_padding[ 22 - ( sizeof( m_MDEntryPx ) + sizeof( m_MDEntrySize ) + sizeof( m_NumberOfOrders ) + sizeof( m_MDPriceLevel ) + sizeof( m_TradingReferenceDate ) + sizeof( m_OpenCloseSettlFlag ) + sizeof( m_SettlPriceType ) + sizeof( m_MDEntryType ) ) ];

                friend std::ostream & operator<<( std::ostream & a_stream , const Entry & a_instance )
                {
                    a_stream << "           m_MDEntryPx-->[" << a_instance.m_MDEntryPx << "]\n";
                    a_stream << "           m_MDEntrySize-->[" << a_instance.m_MDEntrySize << "]\n";
                    a_stream << "           m_NumberOfOrders-->[" << a_instance.m_NumberOfOrders << "]\n";
                    a_stream << "           m_MDPriceLevel-->[" << a_instance.m_MDPriceLevel << "]\n";
                    a_stream << "           m_TradingReferenceDate-->[" << a_instance.m_TradingReferenceDate << "]\n";
                    a_stream << "           m_OpenCloseSettlFlag-->[" << a_instance.m_OpenCloseSettlFlag << "]\n";
                    a_stream << "           m_SettlPriceType-->[" << a_instance.m_SettlPriceType << "]\n";
                    a_stream << "           m_MDEntryType-->[" << a_instance.m_MDEntryType << "]\n";
                    return( a_stream );
                }
            } PACK m_entries[0];
            ALWAYS_INLINE const size_t elements() const { return( (size_t)m_dimension.m_numInGroup.value() ); }
            ALWAYS_INLINE const auto entriesBegin() const { return( &m_entries[0] ); }
            ALWAYS_INLINE const auto entriesEnd() const { return( &m_entries[ elements() ] ); }
            ALWAYS_INLINE const void * const next(){ return( (void *)entriesEnd() ); }
        } PACK m_NoMDEntries;

        friend std::ostream & operator<<( std::ostream & a_stream , const SnapshotFullRefresh52 & a_instance )
        {
            a_stream << "SnapshotFullRefresh52-->[" << (void *)&a_instance << "]\n";
            a_stream << "    m_LastMsgSeqNumProcessed-->[" << a_instance.m_LastMsgSeqNumProcessed << "]\n";
            a_stream << "    m_TotNumReports-->[" << a_instance.m_TotNumReports << "]\n";
            a_stream << "    m_SecurityID-->[" << a_instance.m_SecurityID << "]\n";
            a_stream << "    m_RptSeq-->[" << a_instance.m_RptSeq << "]\n";
            a_stream << "    m_TransactTime-->[" << a_instance.m_TransactTime << "]\n";
            a_stream << "    m_LastUpdateTime-->[" << a_instance.m_LastUpdateTime << "]\n";
            a_stream << "    m_TradeDate-->[" << a_instance.m_TradeDate << "]\n";
            a_stream << "    m_MDSecurityTradingStatus-->[" << a_instance.m_MDSecurityTradingStatus << "]\n";
            a_stream << "    m_HighLimitPrice-->[" << a_instance.m_HighLimitPrice << "]\n";
            a_stream << "    m_LowLimitPrice-->[" << a_instance.m_LowLimitPrice << "]\n";
            a_stream << "    m_MaxPriceVariation-->[" << a_instance.m_MaxPriceVariation << "]\n";
            auto l_block = reinterpret_cast<const void *>( &a_instance.m_groupBegin[ 0 ] );
            {
                auto l_NoMDEntries = reinterpret_cast<const SnapshotFullRefresh52::NoMDEntries *>( l_block );
                auto l_begin = l_NoMDEntries->entriesBegin();
                auto l_end   = l_NoMDEntries->entriesEnd();
                auto l_size  = l_NoMDEntries->elements();
                a_stream << "    " << "NoMDEntries-->[" << l_size << "]\n";
                for( auto l_entry = l_begin;
                     l_entry != l_end;
                     ++l_entry )
                {
                    a_stream << "        Entry-->[" << ( (l_entry-l_begin) + 1 ) << "/" << l_size << "," << (void *)l_entry << "]\n";
                    a_stream << *l_entry;
                }
                l_block = l_NoMDEntries->next();
            }

            return( a_stream );
        }
    } PACK;

    struct SnapshotFullRefreshOrderBook53
    {
        static constexpr int32_t id() { return( 53 ); }
        static constexpr const char * name() { return( "SnapshotFullRefreshOrderBook53" ); }

        uInt32 m_LastMsgSeqNumProcessed;
        uInt32 m_TotNumReports;
        Int32 m_SecurityID;
        uInt32 m_NoChunks;
        uInt32 m_CurrentChunk;
        uInt64 m_TransactTime;
        uint8_t m_padding[ 28 - ( sizeof( m_LastMsgSeqNumProcessed ) + sizeof( m_TotNumReports ) + sizeof( m_SecurityID ) + sizeof( m_NoChunks ) + sizeof( m_CurrentChunk ) + sizeof( m_TransactTime ) ) ];

        uint8_t m_groupBegin[ 0 ];
        struct NoMDEntries
        {
            groupSize m_dimension;
            struct Entry
            {
                uInt64 m_OrderID;
                uInt64NULL m_MDOrderPriority;
                PRICE9 m_MDEntryPx;
                Int32 m_MDDisplayQty;
                MDEntryTypeBook m_MDEntryType;
                uint8_t m_padding[ 29 - ( sizeof( m_OrderID ) + sizeof( m_MDOrderPriority ) + sizeof( m_MDEntryPx ) + sizeof( m_MDDisplayQty ) + sizeof( m_MDEntryType ) ) ];

                friend std::ostream & operator<<( std::ostream & a_stream , const Entry & a_instance )
                {
                    a_stream << "           m_OrderID-->[" << a_instance.m_OrderID << "]\n";
                    a_stream << "           m_MDOrderPriority-->[" << a_instance.m_MDOrderPriority << "]\n";
                    a_stream << "           m_MDEntryPx-->[" << a_instance.m_MDEntryPx << "]\n";
                    a_stream << "           m_MDDisplayQty-->[" << a_instance.m_MDDisplayQty << "]\n";
                    a_stream << "           m_MDEntryType-->[" << a_instance.m_MDEntryType << "]\n";
                    return( a_stream );
                }
            } PACK m_entries[0];
            ALWAYS_INLINE const size_t elements() const { return( (size_t)m_dimension.m_numInGroup.value() ); }
            ALWAYS_INLINE const auto entriesBegin() const { return( &m_entries[0] ); }
            ALWAYS_INLINE const auto entriesEnd() const { return( &m_entries[ elements() ] ); }
            ALWAYS_INLINE const void * const next(){ return( (void *)entriesEnd() ); }
        } PACK m_NoMDEntries;

        friend std::ostream & operator<<( std::ostream & a_stream , const SnapshotFullRefreshOrderBook53 & a_instance )
        {
            a_stream << "SnapshotFullRefreshOrderBook53-->[" << (void *)&a_instance << "]\n";
            a_stream << "    m_LastMsgSeqNumProcessed-->[" << a_instance.m_LastMsgSeqNumProcessed << "]\n";
            a_stream << "    m_TotNumReports-->[" << a_instance.m_TotNumReports << "]\n";
            a_stream << "    m_SecurityID-->[" << a_instance.m_SecurityID << "]\n";
            a_stream << "    m_NoChunks-->[" << a_instance.m_NoChunks << "]\n";
            a_stream << "    m_CurrentChunk-->[" << a_instance.m_CurrentChunk << "]\n";
            a_stream << "    m_TransactTime-->[" << a_instance.m_TransactTime << "]\n";
            auto l_block = reinterpret_cast<const void *>( &a_instance.m_groupBegin[ 0 ] );
            {
                auto l_NoMDEntries = reinterpret_cast<const SnapshotFullRefreshOrderBook53::NoMDEntries *>( l_block );
                auto l_begin = l_NoMDEntries->entriesBegin();
                auto l_end   = l_NoMDEntries->entriesEnd();
                auto l_size  = l_NoMDEntries->elements();
                a_stream << "    " << "NoMDEntries-->[" << l_size << "]\n";
                for( auto l_entry = l_begin;
                     l_entry != l_end;
                     ++l_entry )
                {
                    a_stream << "        Entry-->[" << ( (l_entry-l_begin) + 1 ) << "/" << l_size << "," << (void *)l_entry << "]\n";
                    a_stream << *l_entry;
                }
                l_block = l_NoMDEntries->next();
            }

            return( a_stream );
        }
    } PACK;

    struct MDInstrumentDefinitionFuture54
    {
        static constexpr int32_t id() { return( 54 ); }
        static constexpr const char * name() { return( "MDInstrumentDefinitionFuture54" ); }

        MatchEventIndicator m_MatchEventIndicator;
        uInt32NULL m_TotNumReports;
        SecurityUpdateAction m_SecurityUpdateAction;
        uInt64 m_LastUpdateTime;
        SecurityTradingStatus m_MDSecurityTradingStatus;
        Int16 m_ApplID;
        uInt8 m_MarketSegmentID;
        uInt8 m_UnderlyingProduct;
        SecurityExchange m_SecurityExchange;
        SecurityGroup m_SecurityGroup;
        Asset m_Asset;
        Symbol m_Symbol;
        Int32 m_SecurityID;
        SecurityIDSource m_SecurityIDSource;
        SecurityType m_SecurityType;
        CFICode m_CFICode;
        MaturityMonthYear m_MaturityMonthYear;
        Currency m_Currency;
        Currency m_SettlCurrency;
        CHAR m_MatchAlgorithm;
        uInt32 m_MinTradeVol;
        uInt32 m_MaxTradeVol;
        PRICE9 m_MinPriceIncrement;
        Decimal9 m_DisplayFactor;
        uInt8NULL m_MainFraction;
        uInt8NULL m_SubFraction;
        uInt8NULL m_PriceDisplayFormat;
        UnitOfMeasure m_UnitOfMeasure;
        Decimal9NULL m_UnitOfMeasureQty;
        PRICENULL9 m_TradingReferencePrice;
        SettlPriceType m_SettlPriceType;
        Int32NULL m_OpenInterestQty;
        Int32NULL m_ClearedVolume;
        PRICENULL9 m_HighLimitPrice;
        PRICENULL9 m_LowLimitPrice;
        PRICENULL9 m_MaxPriceVariation;
        Int32NULL m_DecayQuantity;
        LocalMktDate m_DecayStartDate;
        Int32NULL m_OriginalContractSize;
        Int32NULL m_ContractMultiplier;
        Int8NULL m_ContractMultiplierUnit;
        Int8NULL m_FlowScheduleType;
        PRICENULL9 m_MinPriceIncrementAmount;
        UserDefinedInstrument m_UserDefinedInstrument;
        LocalMktDate m_TradingReferenceDate;
        uint8_t m_padding[ 216 - ( sizeof( m_MatchEventIndicator ) + sizeof( m_TotNumReports ) + sizeof( m_SecurityUpdateAction ) + sizeof( m_LastUpdateTime ) + sizeof( m_MDSecurityTradingStatus ) + sizeof( m_ApplID ) + sizeof( m_MarketSegmentID ) + sizeof( m_UnderlyingProduct ) + sizeof( m_SecurityExchange ) + sizeof( m_SecurityGroup ) + sizeof( m_Asset ) + sizeof( m_Symbol ) + sizeof( m_SecurityID ) + sizeof( m_SecurityIDSource ) + sizeof( m_SecurityType ) + sizeof( m_CFICode ) + sizeof( m_MaturityMonthYear ) + sizeof( m_Currency ) + sizeof( m_SettlCurrency ) + sizeof( m_MatchAlgorithm ) + sizeof( m_MinTradeVol ) + sizeof( m_MaxTradeVol ) + sizeof( m_MinPriceIncrement ) + sizeof( m_DisplayFactor ) + sizeof( m_MainFraction ) + sizeof( m_SubFraction ) + sizeof( m_PriceDisplayFormat ) + sizeof( m_UnitOfMeasure ) + sizeof( m_UnitOfMeasureQty ) + sizeof( m_TradingReferencePrice ) + sizeof( m_SettlPriceType ) + sizeof( m_OpenInterestQty ) + sizeof( m_ClearedVolume ) + sizeof( m_HighLimitPrice ) + sizeof( m_LowLimitPrice ) + sizeof( m_MaxPriceVariation ) + sizeof( m_DecayQuantity ) + sizeof( m_DecayStartDate ) + sizeof( m_OriginalContractSize ) + sizeof( m_ContractMultiplier ) + sizeof( m_ContractMultiplierUnit ) + sizeof( m_FlowScheduleType ) + sizeof( m_MinPriceIncrementAmount ) + sizeof( m_UserDefinedInstrument ) + sizeof( m_TradingReferenceDate ) ) ];

        uint8_t m_groupBegin[ 0 ];
        struct NoEvents
        {
            groupSize m_dimension;
            struct Entry
            {
                EventType m_EventType;
                uInt64 m_EventTime;
                uint8_t m_padding[ 9 - ( sizeof( m_EventType ) + sizeof( m_EventTime ) ) ];

                friend std::ostream & operator<<( std::ostream & a_stream , const Entry & a_instance )
                {
                    a_stream << "           m_EventType-->[" << a_instance.m_EventType << "]\n";
                    a_stream << "           m_EventTime-->[" << a_instance.m_EventTime << "]\n";
                    return( a_stream );
                }
            } PACK m_entries[0];
            ALWAYS_INLINE const size_t elements() const { return( (size_t)m_dimension.m_numInGroup.value() ); }
            ALWAYS_INLINE const auto entriesBegin() const { return( &m_entries[0] ); }
            ALWAYS_INLINE const auto entriesEnd() const { return( &m_entries[ elements() ] ); }
            ALWAYS_INLINE const void * const next(){ return( (void *)entriesEnd() ); }
        } PACK m_NoEvents;

        struct NoMDFeedTypes
        {
            groupSize m_dimension;
            struct Entry
            {
                MDFeedType m_MDFeedType;
                Int8 m_MarketDepth;
                uint8_t m_padding[ 4 - ( sizeof( m_MDFeedType ) + sizeof( m_MarketDepth ) ) ];

                friend std::ostream & operator<<( std::ostream & a_stream , const Entry & a_instance )
                {
                    a_stream << "           m_MDFeedType-->[" << a_instance.m_MDFeedType << "]\n";
                    a_stream << "           m_MarketDepth-->[" << a_instance.m_MarketDepth << "]\n";
                    return( a_stream );
                }
            } PACK m_entries[0];
            ALWAYS_INLINE const size_t elements() const { return( (size_t)m_dimension.m_numInGroup.value() ); }
            ALWAYS_INLINE const auto entriesBegin() const { return( &m_entries[0] ); }
            ALWAYS_INLINE const auto entriesEnd() const { return( &m_entries[ elements() ] ); }
            ALWAYS_INLINE const void * const next(){ return( (void *)entriesEnd() ); }
        } PACK m_NoMDFeedTypes;

        struct NoInstAttrib
        {
            groupSize m_dimension;
            struct Entry
            {
                InstAttribType m_InstAttribType;
                InstAttribValue m_InstAttribValue;
                uint8_t m_padding[ 4 - ( sizeof( m_InstAttribType ) + sizeof( m_InstAttribValue ) ) ];

                friend std::ostream & operator<<( std::ostream & a_stream , const Entry & a_instance )
                {
                    a_stream << "           m_InstAttribType-->[" << a_instance.m_InstAttribType << "]\n";
                    a_stream << "           m_InstAttribValue-->[" << a_instance.m_InstAttribValue << "]\n";
                    return( a_stream );
                }
            } PACK m_entries[0];
            ALWAYS_INLINE const size_t elements() const { return( (size_t)m_dimension.m_numInGroup.value() ); }
            ALWAYS_INLINE const auto entriesBegin() const { return( &m_entries[0] ); }
            ALWAYS_INLINE const auto entriesEnd() const { return( &m_entries[ elements() ] ); }
            ALWAYS_INLINE const void * const next(){ return( (void *)entriesEnd() ); }
        } PACK m_NoInstAttrib;

        struct NoLotTypeRules
        {
            groupSize m_dimension;
            struct Entry
            {
                Int8 m_LotType;
                DecimalQty m_MinLotSize;
                uint8_t m_padding[ 5 - ( sizeof( m_LotType ) + sizeof( m_MinLotSize ) ) ];

                friend std::ostream & operator<<( std::ostream & a_stream , const Entry & a_instance )
                {
                    a_stream << "           m_LotType-->[" << a_instance.m_LotType << "]\n";
                    a_stream << "           m_MinLotSize-->[" << a_instance.m_MinLotSize << "]\n";
                    return( a_stream );
                }
            } PACK m_entries[0];
            ALWAYS_INLINE const size_t elements() const { return( (size_t)m_dimension.m_numInGroup.value() ); }
            ALWAYS_INLINE const auto entriesBegin() const { return( &m_entries[0] ); }
            ALWAYS_INLINE const auto entriesEnd() const { return( &m_entries[ elements() ] ); }
            ALWAYS_INLINE const void * const next(){ return( (void *)entriesEnd() ); }
        } PACK m_NoLotTypeRules;

        friend std::ostream & operator<<( std::ostream & a_stream , const MDInstrumentDefinitionFuture54 & a_instance )
        {
            a_stream << "MDInstrumentDefinitionFuture54-->[" << (void *)&a_instance << "]\n";
            a_stream << "    m_MatchEventIndicator-->[" << a_instance.m_MatchEventIndicator << "]\n";
            a_stream << "    m_TotNumReports-->[" << a_instance.m_TotNumReports << "]\n";
            a_stream << "    m_SecurityUpdateAction-->[" << a_instance.m_SecurityUpdateAction << "]\n";
            a_stream << "    m_LastUpdateTime-->[" << a_instance.m_LastUpdateTime << "]\n";
            a_stream << "    m_MDSecurityTradingStatus-->[" << a_instance.m_MDSecurityTradingStatus << "]\n";
            a_stream << "    m_ApplID-->[" << a_instance.m_ApplID << "]\n";
            a_stream << "    m_MarketSegmentID-->[" << a_instance.m_MarketSegmentID << "]\n";
            a_stream << "    m_UnderlyingProduct-->[" << a_instance.m_UnderlyingProduct << "]\n";
            a_stream << "    m_SecurityExchange-->[" << a_instance.m_SecurityExchange << "]\n";
            a_stream << "    m_SecurityGroup-->[" << a_instance.m_SecurityGroup << "]\n";
            a_stream << "    m_Asset-->[" << a_instance.m_Asset << "]\n";
            a_stream << "    m_Symbol-->[" << a_instance.m_Symbol << "]\n";
            a_stream << "    m_SecurityID-->[" << a_instance.m_SecurityID << "]\n";
            a_stream << "    m_SecurityIDSource-->[" << a_instance.m_SecurityIDSource << "]\n";
            a_stream << "    m_SecurityType-->[" << a_instance.m_SecurityType << "]\n";
            a_stream << "    m_CFICode-->[" << a_instance.m_CFICode << "]\n";
            a_stream << "    m_MaturityMonthYear-->[" << a_instance.m_MaturityMonthYear << "]\n";
            a_stream << "    m_Currency-->[" << a_instance.m_Currency << "]\n";
            a_stream << "    m_SettlCurrency-->[" << a_instance.m_SettlCurrency << "]\n";
            a_stream << "    m_MatchAlgorithm-->[" << a_instance.m_MatchAlgorithm << "]\n";
            a_stream << "    m_MinTradeVol-->[" << a_instance.m_MinTradeVol << "]\n";
            a_stream << "    m_MaxTradeVol-->[" << a_instance.m_MaxTradeVol << "]\n";
            a_stream << "    m_MinPriceIncrement-->[" << a_instance.m_MinPriceIncrement << "]\n";
            a_stream << "    m_DisplayFactor-->[" << a_instance.m_DisplayFactor << "]\n";
            a_stream << "    m_MainFraction-->[" << a_instance.m_MainFraction << "]\n";
            a_stream << "    m_SubFraction-->[" << a_instance.m_SubFraction << "]\n";
            a_stream << "    m_PriceDisplayFormat-->[" << a_instance.m_PriceDisplayFormat << "]\n";
            a_stream << "    m_UnitOfMeasure-->[" << a_instance.m_UnitOfMeasure << "]\n";
            a_stream << "    m_UnitOfMeasureQty-->[" << a_instance.m_UnitOfMeasureQty << "]\n";
            a_stream << "    m_TradingReferencePrice-->[" << a_instance.m_TradingReferencePrice << "]\n";
            a_stream << "    m_SettlPriceType-->[" << a_instance.m_SettlPriceType << "]\n";
            a_stream << "    m_OpenInterestQty-->[" << a_instance.m_OpenInterestQty << "]\n";
            a_stream << "    m_ClearedVolume-->[" << a_instance.m_ClearedVolume << "]\n";
            a_stream << "    m_HighLimitPrice-->[" << a_instance.m_HighLimitPrice << "]\n";
            a_stream << "    m_LowLimitPrice-->[" << a_instance.m_LowLimitPrice << "]\n";
            a_stream << "    m_MaxPriceVariation-->[" << a_instance.m_MaxPriceVariation << "]\n";
            a_stream << "    m_DecayQuantity-->[" << a_instance.m_DecayQuantity << "]\n";
            a_stream << "    m_DecayStartDate-->[" << a_instance.m_DecayStartDate << "]\n";
            a_stream << "    m_OriginalContractSize-->[" << a_instance.m_OriginalContractSize << "]\n";
            a_stream << "    m_ContractMultiplier-->[" << a_instance.m_ContractMultiplier << "]\n";
            a_stream << "    m_ContractMultiplierUnit-->[" << a_instance.m_ContractMultiplierUnit << "]\n";
            a_stream << "    m_FlowScheduleType-->[" << a_instance.m_FlowScheduleType << "]\n";
            a_stream << "    m_MinPriceIncrementAmount-->[" << a_instance.m_MinPriceIncrementAmount << "]\n";
            a_stream << "    m_UserDefinedInstrument-->[" << a_instance.m_UserDefinedInstrument << "]\n";
            a_stream << "    m_TradingReferenceDate-->[" << a_instance.m_TradingReferenceDate << "]\n";
            auto l_block = reinterpret_cast<const void *>( &a_instance.m_groupBegin[ 0 ] );
            {
                auto l_NoEvents = reinterpret_cast<const MDInstrumentDefinitionFuture54::NoEvents *>( l_block );
                auto l_begin = l_NoEvents->entriesBegin();
                auto l_end   = l_NoEvents->entriesEnd();
                auto l_size  = l_NoEvents->elements();
                a_stream << "    " << "NoEvents-->[" << l_size << "]\n";
                for( auto l_entry = l_begin;
                     l_entry != l_end;
                     ++l_entry )
                {
                    a_stream << "        Entry-->[" << ( (l_entry-l_begin) + 1 ) << "/" << l_size << "," << (void *)l_entry << "]\n";
                    a_stream << *l_entry;
                }
                l_block = l_NoEvents->next();
            }

            {
                auto l_NoMDFeedTypes = reinterpret_cast<const MDInstrumentDefinitionFuture54::NoMDFeedTypes *>( l_block );
                auto l_begin = l_NoMDFeedTypes->entriesBegin();
                auto l_end   = l_NoMDFeedTypes->entriesEnd();
                auto l_size  = l_NoMDFeedTypes->elements();
                a_stream << "    " << "NoMDFeedTypes-->[" << l_size << "]\n";
                for( auto l_entry = l_begin;
                     l_entry != l_end;
                     ++l_entry )
                {
                    a_stream << "        Entry-->[" << ( (l_entry-l_begin) + 1 ) << "/" << l_size << "," << (void *)l_entry << "]\n";
                    a_stream << *l_entry;
                }
                l_block = l_NoMDFeedTypes->next();
            }

            {
                auto l_NoInstAttrib = reinterpret_cast<const MDInstrumentDefinitionFuture54::NoInstAttrib *>( l_block );
                auto l_begin = l_NoInstAttrib->entriesBegin();
                auto l_end   = l_NoInstAttrib->entriesEnd();
                auto l_size  = l_NoInstAttrib->elements();
                a_stream << "    " << "NoInstAttrib-->[" << l_size << "]\n";
                for( auto l_entry = l_begin;
                     l_entry != l_end;
                     ++l_entry )
                {
                    a_stream << "        Entry-->[" << ( (l_entry-l_begin) + 1 ) << "/" << l_size << "," << (void *)l_entry << "]\n";
                    a_stream << *l_entry;
                }
                l_block = l_NoInstAttrib->next();
            }

            {
                auto l_NoLotTypeRules = reinterpret_cast<const MDInstrumentDefinitionFuture54::NoLotTypeRules *>( l_block );
                auto l_begin = l_NoLotTypeRules->entriesBegin();
                auto l_end   = l_NoLotTypeRules->entriesEnd();
                auto l_size  = l_NoLotTypeRules->elements();
                a_stream << "    " << "NoLotTypeRules-->[" << l_size << "]\n";
                for( auto l_entry = l_begin;
                     l_entry != l_end;
                     ++l_entry )
                {
                    a_stream << "        Entry-->[" << ( (l_entry-l_begin) + 1 ) << "/" << l_size << "," << (void *)l_entry << "]\n";
                    a_stream << *l_entry;
                }
                l_block = l_NoLotTypeRules->next();
            }

            return( a_stream );
        }
    } PACK;

    struct MDInstrumentDefinitionOption55
    {
        static constexpr int32_t id() { return( 55 ); }
        static constexpr const char * name() { return( "MDInstrumentDefinitionOption55" ); }

        MatchEventIndicator m_MatchEventIndicator;
        uInt32NULL m_TotNumReports;
        SecurityUpdateAction m_SecurityUpdateAction;
        uInt64 m_LastUpdateTime;
        SecurityTradingStatus m_MDSecurityTradingStatus;
        Int16 m_ApplID;
        uInt8 m_MarketSegmentID;
        uInt8 m_UnderlyingProduct;
        SecurityExchange m_SecurityExchange;
        SecurityGroup m_SecurityGroup;
        Asset m_Asset;
        Symbol m_Symbol;
        Int32 m_SecurityID;
        SecurityIDSource m_SecurityIDSource;
        SecurityType m_SecurityType;
        CFICode m_CFICode;
        PutOrCall m_PutOrCall;
        MaturityMonthYear m_MaturityMonthYear;
        Currency m_Currency;
        PRICENULL9 m_StrikePrice;
        Currency m_StrikeCurrency;
        Currency m_SettlCurrency;
        PRICENULL9 m_MinCabPrice;
        CHAR m_MatchAlgorithm;
        uInt32 m_MinTradeVol;
        uInt32 m_MaxTradeVol;
        PRICENULL9 m_MinPriceIncrement;
        PRICENULL9 m_MinPriceIncrementAmount;
        Decimal9 m_DisplayFactor;
        Int8NULL m_TickRule;
        uInt8NULL m_MainFraction;
        uInt8NULL m_SubFraction;
        uInt8NULL m_PriceDisplayFormat;
        UnitOfMeasure m_UnitOfMeasure;
        Decimal9NULL m_UnitOfMeasureQty;
        PRICENULL9 m_TradingReferencePrice;
        SettlPriceType m_SettlPriceType;
        Int32NULL m_ClearedVolume;
        Int32NULL m_OpenInterestQty;
        PRICENULL9 m_LowLimitPrice;
        PRICENULL9 m_HighLimitPrice;
        UserDefinedInstrument m_UserDefinedInstrument;
        LocalMktDate m_TradingReferenceDate;
        uint8_t m_padding[ 213 - ( sizeof( m_MatchEventIndicator ) + sizeof( m_TotNumReports ) + sizeof( m_SecurityUpdateAction ) + sizeof( m_LastUpdateTime ) + sizeof( m_MDSecurityTradingStatus ) + sizeof( m_ApplID ) + sizeof( m_MarketSegmentID ) + sizeof( m_UnderlyingProduct ) + sizeof( m_SecurityExchange ) + sizeof( m_SecurityGroup ) + sizeof( m_Asset ) + sizeof( m_Symbol ) + sizeof( m_SecurityID ) + sizeof( m_SecurityIDSource ) + sizeof( m_SecurityType ) + sizeof( m_CFICode ) + sizeof( m_PutOrCall ) + sizeof( m_MaturityMonthYear ) + sizeof( m_Currency ) + sizeof( m_StrikePrice ) + sizeof( m_StrikeCurrency ) + sizeof( m_SettlCurrency ) + sizeof( m_MinCabPrice ) + sizeof( m_MatchAlgorithm ) + sizeof( m_MinTradeVol ) + sizeof( m_MaxTradeVol ) + sizeof( m_MinPriceIncrement ) + sizeof( m_MinPriceIncrementAmount ) + sizeof( m_DisplayFactor ) + sizeof( m_TickRule ) + sizeof( m_MainFraction ) + sizeof( m_SubFraction ) + sizeof( m_PriceDisplayFormat ) + sizeof( m_UnitOfMeasure ) + sizeof( m_UnitOfMeasureQty ) + sizeof( m_TradingReferencePrice ) + sizeof( m_SettlPriceType ) + sizeof( m_ClearedVolume ) + sizeof( m_OpenInterestQty ) + sizeof( m_LowLimitPrice ) + sizeof( m_HighLimitPrice ) + sizeof( m_UserDefinedInstrument ) + sizeof( m_TradingReferenceDate ) ) ];

        uint8_t m_groupBegin[ 0 ];
        struct NoEvents
        {
            groupSize m_dimension;
            struct Entry
            {
                EventType m_EventType;
                uInt64 m_EventTime;
                uint8_t m_padding[ 9 - ( sizeof( m_EventType ) + sizeof( m_EventTime ) ) ];

                friend std::ostream & operator<<( std::ostream & a_stream , const Entry & a_instance )
                {
                    a_stream << "           m_EventType-->[" << a_instance.m_EventType << "]\n";
                    a_stream << "           m_EventTime-->[" << a_instance.m_EventTime << "]\n";
                    return( a_stream );
                }
            } PACK m_entries[0];
            ALWAYS_INLINE const size_t elements() const { return( (size_t)m_dimension.m_numInGroup.value() ); }
            ALWAYS_INLINE const auto entriesBegin() const { return( &m_entries[0] ); }
            ALWAYS_INLINE const auto entriesEnd() const { return( &m_entries[ elements() ] ); }
            ALWAYS_INLINE const void * const next(){ return( (void *)entriesEnd() ); }
        } PACK m_NoEvents;

        struct NoMDFeedTypes
        {
            groupSize m_dimension;
            struct Entry
            {
                MDFeedType m_MDFeedType;
                Int8 m_MarketDepth;
                uint8_t m_padding[ 4 - ( sizeof( m_MDFeedType ) + sizeof( m_MarketDepth ) ) ];

                friend std::ostream & operator<<( std::ostream & a_stream , const Entry & a_instance )
                {
                    a_stream << "           m_MDFeedType-->[" << a_instance.m_MDFeedType << "]\n";
                    a_stream << "           m_MarketDepth-->[" << a_instance.m_MarketDepth << "]\n";
                    return( a_stream );
                }
            } PACK m_entries[0];
            ALWAYS_INLINE const size_t elements() const { return( (size_t)m_dimension.m_numInGroup.value() ); }
            ALWAYS_INLINE const auto entriesBegin() const { return( &m_entries[0] ); }
            ALWAYS_INLINE const auto entriesEnd() const { return( &m_entries[ elements() ] ); }
            ALWAYS_INLINE const void * const next(){ return( (void *)entriesEnd() ); }
        } PACK m_NoMDFeedTypes;

        struct NoInstAttrib
        {
            groupSize m_dimension;
            struct Entry
            {
                InstAttribType m_InstAttribType;
                InstAttribValue m_InstAttribValue;
                uint8_t m_padding[ 4 - ( sizeof( m_InstAttribType ) + sizeof( m_InstAttribValue ) ) ];

                friend std::ostream & operator<<( std::ostream & a_stream , const Entry & a_instance )
                {
                    a_stream << "           m_InstAttribType-->[" << a_instance.m_InstAttribType << "]\n";
                    a_stream << "           m_InstAttribValue-->[" << a_instance.m_InstAttribValue << "]\n";
                    return( a_stream );
                }
            } PACK m_entries[0];
            ALWAYS_INLINE const size_t elements() const { return( (size_t)m_dimension.m_numInGroup.value() ); }
            ALWAYS_INLINE const auto entriesBegin() const { return( &m_entries[0] ); }
            ALWAYS_INLINE const auto entriesEnd() const { return( &m_entries[ elements() ] ); }
            ALWAYS_INLINE const void * const next(){ return( (void *)entriesEnd() ); }
        } PACK m_NoInstAttrib;

        struct NoLotTypeRules
        {
            groupSize m_dimension;
            struct Entry
            {
                Int8 m_LotType;
                DecimalQty m_MinLotSize;
                uint8_t m_padding[ 5 - ( sizeof( m_LotType ) + sizeof( m_MinLotSize ) ) ];

                friend std::ostream & operator<<( std::ostream & a_stream , const Entry & a_instance )
                {
                    a_stream << "           m_LotType-->[" << a_instance.m_LotType << "]\n";
                    a_stream << "           m_MinLotSize-->[" << a_instance.m_MinLotSize << "]\n";
                    return( a_stream );
                }
            } PACK m_entries[0];
            ALWAYS_INLINE const size_t elements() const { return( (size_t)m_dimension.m_numInGroup.value() ); }
            ALWAYS_INLINE const auto entriesBegin() const { return( &m_entries[0] ); }
            ALWAYS_INLINE const auto entriesEnd() const { return( &m_entries[ elements() ] ); }
            ALWAYS_INLINE const void * const next(){ return( (void *)entriesEnd() ); }
        } PACK m_NoLotTypeRules;

        struct NoUnderlyings
        {
            groupSize m_dimension;
            struct Entry
            {
                Int32 m_UnderlyingSecurityID;
                SecurityIDSource m_UnderlyingSecurityIDSource;
                UnderlyingSymbol m_UnderlyingSymbol;
                uint8_t m_padding[ 24 - ( sizeof( m_UnderlyingSecurityID ) + sizeof( m_UnderlyingSecurityIDSource ) + sizeof( m_UnderlyingSymbol ) ) ];

                friend std::ostream & operator<<( std::ostream & a_stream , const Entry & a_instance )
                {
                    a_stream << "           m_UnderlyingSecurityID-->[" << a_instance.m_UnderlyingSecurityID << "]\n";
                    a_stream << "           m_UnderlyingSecurityIDSource-->[" << a_instance.m_UnderlyingSecurityIDSource << "]\n";
                    a_stream << "           m_UnderlyingSymbol-->[" << a_instance.m_UnderlyingSymbol << "]\n";
                    return( a_stream );
                }
            } PACK m_entries[0];
            ALWAYS_INLINE const size_t elements() const { return( (size_t)m_dimension.m_numInGroup.value() ); }
            ALWAYS_INLINE const auto entriesBegin() const { return( &m_entries[0] ); }
            ALWAYS_INLINE const auto entriesEnd() const { return( &m_entries[ elements() ] ); }
            ALWAYS_INLINE const void * const next(){ return( (void *)entriesEnd() ); }
        } PACK m_NoUnderlyings;

        struct NoRelatedInstruments
        {
            groupSize m_dimension;
            struct Entry
            {
                Int32 m_RelatedSecurityID;
                SecurityIDSource m_RelatedSecurityIDSource;
                Symbol m_RelatedSymbol;
                uint8_t m_padding[ 24 - ( sizeof( m_RelatedSecurityID ) + sizeof( m_RelatedSecurityIDSource ) + sizeof( m_RelatedSymbol ) ) ];

                friend std::ostream & operator<<( std::ostream & a_stream , const Entry & a_instance )
                {
                    a_stream << "           m_RelatedSecurityID-->[" << a_instance.m_RelatedSecurityID << "]\n";
                    a_stream << "           m_RelatedSecurityIDSource-->[" << a_instance.m_RelatedSecurityIDSource << "]\n";
                    a_stream << "           m_RelatedSymbol-->[" << a_instance.m_RelatedSymbol << "]\n";
                    return( a_stream );
                }
            } PACK m_entries[0];
            ALWAYS_INLINE const size_t elements() const { return( (size_t)m_dimension.m_numInGroup.value() ); }
            ALWAYS_INLINE const auto entriesBegin() const { return( &m_entries[0] ); }
            ALWAYS_INLINE const auto entriesEnd() const { return( &m_entries[ elements() ] ); }
            ALWAYS_INLINE const void * const next(){ return( (void *)entriesEnd() ); }
        } PACK m_NoRelatedInstruments;

        friend std::ostream & operator<<( std::ostream & a_stream , const MDInstrumentDefinitionOption55 & a_instance )
        {
            a_stream << "MDInstrumentDefinitionOption55-->[" << (void *)&a_instance << "]\n";
            a_stream << "    m_MatchEventIndicator-->[" << a_instance.m_MatchEventIndicator << "]\n";
            a_stream << "    m_TotNumReports-->[" << a_instance.m_TotNumReports << "]\n";
            a_stream << "    m_SecurityUpdateAction-->[" << a_instance.m_SecurityUpdateAction << "]\n";
            a_stream << "    m_LastUpdateTime-->[" << a_instance.m_LastUpdateTime << "]\n";
            a_stream << "    m_MDSecurityTradingStatus-->[" << a_instance.m_MDSecurityTradingStatus << "]\n";
            a_stream << "    m_ApplID-->[" << a_instance.m_ApplID << "]\n";
            a_stream << "    m_MarketSegmentID-->[" << a_instance.m_MarketSegmentID << "]\n";
            a_stream << "    m_UnderlyingProduct-->[" << a_instance.m_UnderlyingProduct << "]\n";
            a_stream << "    m_SecurityExchange-->[" << a_instance.m_SecurityExchange << "]\n";
            a_stream << "    m_SecurityGroup-->[" << a_instance.m_SecurityGroup << "]\n";
            a_stream << "    m_Asset-->[" << a_instance.m_Asset << "]\n";
            a_stream << "    m_Symbol-->[" << a_instance.m_Symbol << "]\n";
            a_stream << "    m_SecurityID-->[" << a_instance.m_SecurityID << "]\n";
            a_stream << "    m_SecurityIDSource-->[" << a_instance.m_SecurityIDSource << "]\n";
            a_stream << "    m_SecurityType-->[" << a_instance.m_SecurityType << "]\n";
            a_stream << "    m_CFICode-->[" << a_instance.m_CFICode << "]\n";
            a_stream << "    m_PutOrCall-->[" << a_instance.m_PutOrCall << "]\n";
            a_stream << "    m_MaturityMonthYear-->[" << a_instance.m_MaturityMonthYear << "]\n";
            a_stream << "    m_Currency-->[" << a_instance.m_Currency << "]\n";
            a_stream << "    m_StrikePrice-->[" << a_instance.m_StrikePrice << "]\n";
            a_stream << "    m_StrikeCurrency-->[" << a_instance.m_StrikeCurrency << "]\n";
            a_stream << "    m_SettlCurrency-->[" << a_instance.m_SettlCurrency << "]\n";
            a_stream << "    m_MinCabPrice-->[" << a_instance.m_MinCabPrice << "]\n";
            a_stream << "    m_MatchAlgorithm-->[" << a_instance.m_MatchAlgorithm << "]\n";
            a_stream << "    m_MinTradeVol-->[" << a_instance.m_MinTradeVol << "]\n";
            a_stream << "    m_MaxTradeVol-->[" << a_instance.m_MaxTradeVol << "]\n";
            a_stream << "    m_MinPriceIncrement-->[" << a_instance.m_MinPriceIncrement << "]\n";
            a_stream << "    m_MinPriceIncrementAmount-->[" << a_instance.m_MinPriceIncrementAmount << "]\n";
            a_stream << "    m_DisplayFactor-->[" << a_instance.m_DisplayFactor << "]\n";
            a_stream << "    m_TickRule-->[" << a_instance.m_TickRule << "]\n";
            a_stream << "    m_MainFraction-->[" << a_instance.m_MainFraction << "]\n";
            a_stream << "    m_SubFraction-->[" << a_instance.m_SubFraction << "]\n";
            a_stream << "    m_PriceDisplayFormat-->[" << a_instance.m_PriceDisplayFormat << "]\n";
            a_stream << "    m_UnitOfMeasure-->[" << a_instance.m_UnitOfMeasure << "]\n";
            a_stream << "    m_UnitOfMeasureQty-->[" << a_instance.m_UnitOfMeasureQty << "]\n";
            a_stream << "    m_TradingReferencePrice-->[" << a_instance.m_TradingReferencePrice << "]\n";
            a_stream << "    m_SettlPriceType-->[" << a_instance.m_SettlPriceType << "]\n";
            a_stream << "    m_ClearedVolume-->[" << a_instance.m_ClearedVolume << "]\n";
            a_stream << "    m_OpenInterestQty-->[" << a_instance.m_OpenInterestQty << "]\n";
            a_stream << "    m_LowLimitPrice-->[" << a_instance.m_LowLimitPrice << "]\n";
            a_stream << "    m_HighLimitPrice-->[" << a_instance.m_HighLimitPrice << "]\n";
            a_stream << "    m_UserDefinedInstrument-->[" << a_instance.m_UserDefinedInstrument << "]\n";
            a_stream << "    m_TradingReferenceDate-->[" << a_instance.m_TradingReferenceDate << "]\n";
            auto l_block = reinterpret_cast<const void *>( &a_instance.m_groupBegin[ 0 ] );
            {
                auto l_NoEvents = reinterpret_cast<const MDInstrumentDefinitionOption55::NoEvents *>( l_block );
                auto l_begin = l_NoEvents->entriesBegin();
                auto l_end   = l_NoEvents->entriesEnd();
                auto l_size  = l_NoEvents->elements();
                a_stream << "    " << "NoEvents-->[" << l_size << "]\n";
                for( auto l_entry = l_begin;
                     l_entry != l_end;
                     ++l_entry )
                {
                    a_stream << "        Entry-->[" << ( (l_entry-l_begin) + 1 ) << "/" << l_size << "," << (void *)l_entry << "]\n";
                    a_stream << *l_entry;
                }
                l_block = l_NoEvents->next();
            }

            {
                auto l_NoMDFeedTypes = reinterpret_cast<const MDInstrumentDefinitionOption55::NoMDFeedTypes *>( l_block );
                auto l_begin = l_NoMDFeedTypes->entriesBegin();
                auto l_end   = l_NoMDFeedTypes->entriesEnd();
                auto l_size  = l_NoMDFeedTypes->elements();
                a_stream << "    " << "NoMDFeedTypes-->[" << l_size << "]\n";
                for( auto l_entry = l_begin;
                     l_entry != l_end;
                     ++l_entry )
                {
                    a_stream << "        Entry-->[" << ( (l_entry-l_begin) + 1 ) << "/" << l_size << "," << (void *)l_entry << "]\n";
                    a_stream << *l_entry;
                }
                l_block = l_NoMDFeedTypes->next();
            }

            {
                auto l_NoInstAttrib = reinterpret_cast<const MDInstrumentDefinitionOption55::NoInstAttrib *>( l_block );
                auto l_begin = l_NoInstAttrib->entriesBegin();
                auto l_end   = l_NoInstAttrib->entriesEnd();
                auto l_size  = l_NoInstAttrib->elements();
                a_stream << "    " << "NoInstAttrib-->[" << l_size << "]\n";
                for( auto l_entry = l_begin;
                     l_entry != l_end;
                     ++l_entry )
                {
                    a_stream << "        Entry-->[" << ( (l_entry-l_begin) + 1 ) << "/" << l_size << "," << (void *)l_entry << "]\n";
                    a_stream << *l_entry;
                }
                l_block = l_NoInstAttrib->next();
            }

            {
                auto l_NoLotTypeRules = reinterpret_cast<const MDInstrumentDefinitionOption55::NoLotTypeRules *>( l_block );
                auto l_begin = l_NoLotTypeRules->entriesBegin();
                auto l_end   = l_NoLotTypeRules->entriesEnd();
                auto l_size  = l_NoLotTypeRules->elements();
                a_stream << "    " << "NoLotTypeRules-->[" << l_size << "]\n";
                for( auto l_entry = l_begin;
                     l_entry != l_end;
                     ++l_entry )
                {
                    a_stream << "        Entry-->[" << ( (l_entry-l_begin) + 1 ) << "/" << l_size << "," << (void *)l_entry << "]\n";
                    a_stream << *l_entry;
                }
                l_block = l_NoLotTypeRules->next();
            }

            {
                auto l_NoUnderlyings = reinterpret_cast<const MDInstrumentDefinitionOption55::NoUnderlyings *>( l_block );
                auto l_begin = l_NoUnderlyings->entriesBegin();
                auto l_end   = l_NoUnderlyings->entriesEnd();
                auto l_size  = l_NoUnderlyings->elements();
                a_stream << "    " << "NoUnderlyings-->[" << l_size << "]\n";
                for( auto l_entry = l_begin;
                     l_entry != l_end;
                     ++l_entry )
                {
                    a_stream << "        Entry-->[" << ( (l_entry-l_begin) + 1 ) << "/" << l_size << "," << (void *)l_entry << "]\n";
                    a_stream << *l_entry;
                }
                l_block = l_NoUnderlyings->next();
            }

            {
                auto l_NoRelatedInstruments = reinterpret_cast<const MDInstrumentDefinitionOption55::NoRelatedInstruments *>( l_block );
                auto l_begin = l_NoRelatedInstruments->entriesBegin();
                auto l_end   = l_NoRelatedInstruments->entriesEnd();
                auto l_size  = l_NoRelatedInstruments->elements();
                a_stream << "    " << "NoRelatedInstruments-->[" << l_size << "]\n";
                for( auto l_entry = l_begin;
                     l_entry != l_end;
                     ++l_entry )
                {
                    a_stream << "        Entry-->[" << ( (l_entry-l_begin) + 1 ) << "/" << l_size << "," << (void *)l_entry << "]\n";
                    a_stream << *l_entry;
                }
                l_block = l_NoRelatedInstruments->next();
            }

            return( a_stream );
        }
    } PACK;

    struct MDInstrumentDefinitionSpread56
    {
        static constexpr int32_t id() { return( 56 ); }
        static constexpr const char * name() { return( "MDInstrumentDefinitionSpread56" ); }

        MatchEventIndicator m_MatchEventIndicator;
        uInt32NULL m_TotNumReports;
        SecurityUpdateAction m_SecurityUpdateAction;
        uInt64 m_LastUpdateTime;
        SecurityTradingStatus m_MDSecurityTradingStatus;
        Int16 m_ApplID;
        uInt8 m_MarketSegmentID;
        uInt8NULL m_UnderlyingProduct;
        SecurityExchange m_SecurityExchange;
        SecurityGroup m_SecurityGroup;
        Asset m_Asset;
        Symbol m_Symbol;
        Int32 m_SecurityID;
        SecurityIDSource m_SecurityIDSource;
        SecurityType m_SecurityType;
        CFICode m_CFICode;
        MaturityMonthYear m_MaturityMonthYear;
        Currency m_Currency;
        SecuritySubType m_SecuritySubType;
        UserDefinedInstrument m_UserDefinedInstrument;
        CHAR m_MatchAlgorithm;
        uInt32 m_MinTradeVol;
        uInt32 m_MaxTradeVol;
        PRICENULL9 m_MinPriceIncrement;
        Decimal9 m_DisplayFactor;
        uInt8NULL m_PriceDisplayFormat;
        PRICENULL9 m_PriceRatio;
        Int8NULL m_TickRule;
        UnitOfMeasure m_UnitOfMeasure;
        PRICENULL9 m_TradingReferencePrice;
        SettlPriceType m_SettlPriceType;
        Int32NULL m_OpenInterestQty;
        Int32NULL m_ClearedVolume;
        PRICENULL9 m_HighLimitPrice;
        PRICENULL9 m_LowLimitPrice;
        PRICENULL9 m_MaxPriceVariation;
        uInt8NULL m_MainFraction;
        uInt8NULL m_SubFraction;
        LocalMktDate m_TradingReferenceDate;
        uint8_t m_padding[ 195 - ( sizeof( m_MatchEventIndicator ) + sizeof( m_TotNumReports ) + sizeof( m_SecurityUpdateAction ) + sizeof( m_LastUpdateTime ) + sizeof( m_MDSecurityTradingStatus ) + sizeof( m_ApplID ) + sizeof( m_MarketSegmentID ) + sizeof( m_UnderlyingProduct ) + sizeof( m_SecurityExchange ) + sizeof( m_SecurityGroup ) + sizeof( m_Asset ) + sizeof( m_Symbol ) + sizeof( m_SecurityID ) + sizeof( m_SecurityIDSource ) + sizeof( m_SecurityType ) + sizeof( m_CFICode ) + sizeof( m_MaturityMonthYear ) + sizeof( m_Currency ) + sizeof( m_SecuritySubType ) + sizeof( m_UserDefinedInstrument ) + sizeof( m_MatchAlgorithm ) + sizeof( m_MinTradeVol ) + sizeof( m_MaxTradeVol ) + sizeof( m_MinPriceIncrement ) + sizeof( m_DisplayFactor ) + sizeof( m_PriceDisplayFormat ) + sizeof( m_PriceRatio ) + sizeof( m_TickRule ) + sizeof( m_UnitOfMeasure ) + sizeof( m_TradingReferencePrice ) + sizeof( m_SettlPriceType ) + sizeof( m_OpenInterestQty ) + sizeof( m_ClearedVolume ) + sizeof( m_HighLimitPrice ) + sizeof( m_LowLimitPrice ) + sizeof( m_MaxPriceVariation ) + sizeof( m_MainFraction ) + sizeof( m_SubFraction ) + sizeof( m_TradingReferenceDate ) ) ];

        uint8_t m_groupBegin[ 0 ];
        struct NoEvents
        {
            groupSize m_dimension;
            struct Entry
            {
                EventType m_EventType;
                uInt64 m_EventTime;
                uint8_t m_padding[ 9 - ( sizeof( m_EventType ) + sizeof( m_EventTime ) ) ];

                friend std::ostream & operator<<( std::ostream & a_stream , const Entry & a_instance )
                {
                    a_stream << "           m_EventType-->[" << a_instance.m_EventType << "]\n";
                    a_stream << "           m_EventTime-->[" << a_instance.m_EventTime << "]\n";
                    return( a_stream );
                }
            } PACK m_entries[0];
            ALWAYS_INLINE const size_t elements() const { return( (size_t)m_dimension.m_numInGroup.value() ); }
            ALWAYS_INLINE const auto entriesBegin() const { return( &m_entries[0] ); }
            ALWAYS_INLINE const auto entriesEnd() const { return( &m_entries[ elements() ] ); }
            ALWAYS_INLINE const void * const next(){ return( (void *)entriesEnd() ); }
        } PACK m_NoEvents;

        struct NoMDFeedTypes
        {
            groupSize m_dimension;
            struct Entry
            {
                MDFeedType m_MDFeedType;
                Int8 m_MarketDepth;
                uint8_t m_padding[ 4 - ( sizeof( m_MDFeedType ) + sizeof( m_MarketDepth ) ) ];

                friend std::ostream & operator<<( std::ostream & a_stream , const Entry & a_instance )
                {
                    a_stream << "           m_MDFeedType-->[" << a_instance.m_MDFeedType << "]\n";
                    a_stream << "           m_MarketDepth-->[" << a_instance.m_MarketDepth << "]\n";
                    return( a_stream );
                }
            } PACK m_entries[0];
            ALWAYS_INLINE const size_t elements() const { return( (size_t)m_dimension.m_numInGroup.value() ); }
            ALWAYS_INLINE const auto entriesBegin() const { return( &m_entries[0] ); }
            ALWAYS_INLINE const auto entriesEnd() const { return( &m_entries[ elements() ] ); }
            ALWAYS_INLINE const void * const next(){ return( (void *)entriesEnd() ); }
        } PACK m_NoMDFeedTypes;

        struct NoInstAttrib
        {
            groupSize m_dimension;
            struct Entry
            {
                InstAttribType m_InstAttribType;
                InstAttribValue m_InstAttribValue;
                uint8_t m_padding[ 4 - ( sizeof( m_InstAttribType ) + sizeof( m_InstAttribValue ) ) ];

                friend std::ostream & operator<<( std::ostream & a_stream , const Entry & a_instance )
                {
                    a_stream << "           m_InstAttribType-->[" << a_instance.m_InstAttribType << "]\n";
                    a_stream << "           m_InstAttribValue-->[" << a_instance.m_InstAttribValue << "]\n";
                    return( a_stream );
                }
            } PACK m_entries[0];
            ALWAYS_INLINE const size_t elements() const { return( (size_t)m_dimension.m_numInGroup.value() ); }
            ALWAYS_INLINE const auto entriesBegin() const { return( &m_entries[0] ); }
            ALWAYS_INLINE const auto entriesEnd() const { return( &m_entries[ elements() ] ); }
            ALWAYS_INLINE const void * const next(){ return( (void *)entriesEnd() ); }
        } PACK m_NoInstAttrib;

        struct NoLotTypeRules
        {
            groupSize m_dimension;
            struct Entry
            {
                Int8 m_LotType;
                DecimalQty m_MinLotSize;
                uint8_t m_padding[ 5 - ( sizeof( m_LotType ) + sizeof( m_MinLotSize ) ) ];

                friend std::ostream & operator<<( std::ostream & a_stream , const Entry & a_instance )
                {
                    a_stream << "           m_LotType-->[" << a_instance.m_LotType << "]\n";
                    a_stream << "           m_MinLotSize-->[" << a_instance.m_MinLotSize << "]\n";
                    return( a_stream );
                }
            } PACK m_entries[0];
            ALWAYS_INLINE const size_t elements() const { return( (size_t)m_dimension.m_numInGroup.value() ); }
            ALWAYS_INLINE const auto entriesBegin() const { return( &m_entries[0] ); }
            ALWAYS_INLINE const auto entriesEnd() const { return( &m_entries[ elements() ] ); }
            ALWAYS_INLINE const void * const next(){ return( (void *)entriesEnd() ); }
        } PACK m_NoLotTypeRules;

        struct NoLegs
        {
            groupSize m_dimension;
            struct Entry
            {
                Int32 m_LegSecurityID;
                SecurityIDSource m_LegSecurityIDSource;
                LegSide m_LegSide;
                Int8 m_LegRatioQty;
                PRICENULL9 m_LegPrice;
                DecimalQty m_LegOptionDelta;
                uint8_t m_padding[ 18 - ( sizeof( m_LegSecurityID ) + sizeof( m_LegSecurityIDSource ) + sizeof( m_LegSide ) + sizeof( m_LegRatioQty ) + sizeof( m_LegPrice ) + sizeof( m_LegOptionDelta ) ) ];

                friend std::ostream & operator<<( std::ostream & a_stream , const Entry & a_instance )
                {
                    a_stream << "           m_LegSecurityID-->[" << a_instance.m_LegSecurityID << "]\n";
                    a_stream << "           m_LegSecurityIDSource-->[" << a_instance.m_LegSecurityIDSource << "]\n";
                    a_stream << "           m_LegSide-->[" << a_instance.m_LegSide << "]\n";
                    a_stream << "           m_LegRatioQty-->[" << a_instance.m_LegRatioQty << "]\n";
                    a_stream << "           m_LegPrice-->[" << a_instance.m_LegPrice << "]\n";
                    a_stream << "           m_LegOptionDelta-->[" << a_instance.m_LegOptionDelta << "]\n";
                    return( a_stream );
                }
            } PACK m_entries[0];
            ALWAYS_INLINE const size_t elements() const { return( (size_t)m_dimension.m_numInGroup.value() ); }
            ALWAYS_INLINE const auto entriesBegin() const { return( &m_entries[0] ); }
            ALWAYS_INLINE const auto entriesEnd() const { return( &m_entries[ elements() ] ); }
            ALWAYS_INLINE const void * const next(){ return( (void *)entriesEnd() ); }
        } PACK m_NoLegs;

        friend std::ostream & operator<<( std::ostream & a_stream , const MDInstrumentDefinitionSpread56 & a_instance )
        {
            a_stream << "MDInstrumentDefinitionSpread56-->[" << (void *)&a_instance << "]\n";
            a_stream << "    m_MatchEventIndicator-->[" << a_instance.m_MatchEventIndicator << "]\n";
            a_stream << "    m_TotNumReports-->[" << a_instance.m_TotNumReports << "]\n";
            a_stream << "    m_SecurityUpdateAction-->[" << a_instance.m_SecurityUpdateAction << "]\n";
            a_stream << "    m_LastUpdateTime-->[" << a_instance.m_LastUpdateTime << "]\n";
            a_stream << "    m_MDSecurityTradingStatus-->[" << a_instance.m_MDSecurityTradingStatus << "]\n";
            a_stream << "    m_ApplID-->[" << a_instance.m_ApplID << "]\n";
            a_stream << "    m_MarketSegmentID-->[" << a_instance.m_MarketSegmentID << "]\n";
            a_stream << "    m_UnderlyingProduct-->[" << a_instance.m_UnderlyingProduct << "]\n";
            a_stream << "    m_SecurityExchange-->[" << a_instance.m_SecurityExchange << "]\n";
            a_stream << "    m_SecurityGroup-->[" << a_instance.m_SecurityGroup << "]\n";
            a_stream << "    m_Asset-->[" << a_instance.m_Asset << "]\n";
            a_stream << "    m_Symbol-->[" << a_instance.m_Symbol << "]\n";
            a_stream << "    m_SecurityID-->[" << a_instance.m_SecurityID << "]\n";
            a_stream << "    m_SecurityIDSource-->[" << a_instance.m_SecurityIDSource << "]\n";
            a_stream << "    m_SecurityType-->[" << a_instance.m_SecurityType << "]\n";
            a_stream << "    m_CFICode-->[" << a_instance.m_CFICode << "]\n";
            a_stream << "    m_MaturityMonthYear-->[" << a_instance.m_MaturityMonthYear << "]\n";
            a_stream << "    m_Currency-->[" << a_instance.m_Currency << "]\n";
            a_stream << "    m_SecuritySubType-->[" << a_instance.m_SecuritySubType << "]\n";
            a_stream << "    m_UserDefinedInstrument-->[" << a_instance.m_UserDefinedInstrument << "]\n";
            a_stream << "    m_MatchAlgorithm-->[" << a_instance.m_MatchAlgorithm << "]\n";
            a_stream << "    m_MinTradeVol-->[" << a_instance.m_MinTradeVol << "]\n";
            a_stream << "    m_MaxTradeVol-->[" << a_instance.m_MaxTradeVol << "]\n";
            a_stream << "    m_MinPriceIncrement-->[" << a_instance.m_MinPriceIncrement << "]\n";
            a_stream << "    m_DisplayFactor-->[" << a_instance.m_DisplayFactor << "]\n";
            a_stream << "    m_PriceDisplayFormat-->[" << a_instance.m_PriceDisplayFormat << "]\n";
            a_stream << "    m_PriceRatio-->[" << a_instance.m_PriceRatio << "]\n";
            a_stream << "    m_TickRule-->[" << a_instance.m_TickRule << "]\n";
            a_stream << "    m_UnitOfMeasure-->[" << a_instance.m_UnitOfMeasure << "]\n";
            a_stream << "    m_TradingReferencePrice-->[" << a_instance.m_TradingReferencePrice << "]\n";
            a_stream << "    m_SettlPriceType-->[" << a_instance.m_SettlPriceType << "]\n";
            a_stream << "    m_OpenInterestQty-->[" << a_instance.m_OpenInterestQty << "]\n";
            a_stream << "    m_ClearedVolume-->[" << a_instance.m_ClearedVolume << "]\n";
            a_stream << "    m_HighLimitPrice-->[" << a_instance.m_HighLimitPrice << "]\n";
            a_stream << "    m_LowLimitPrice-->[" << a_instance.m_LowLimitPrice << "]\n";
            a_stream << "    m_MaxPriceVariation-->[" << a_instance.m_MaxPriceVariation << "]\n";
            a_stream << "    m_MainFraction-->[" << a_instance.m_MainFraction << "]\n";
            a_stream << "    m_SubFraction-->[" << a_instance.m_SubFraction << "]\n";
            a_stream << "    m_TradingReferenceDate-->[" << a_instance.m_TradingReferenceDate << "]\n";
            auto l_block = reinterpret_cast<const void *>( &a_instance.m_groupBegin[ 0 ] );
            {
                auto l_NoEvents = reinterpret_cast<const MDInstrumentDefinitionSpread56::NoEvents *>( l_block );
                auto l_begin = l_NoEvents->entriesBegin();
                auto l_end   = l_NoEvents->entriesEnd();
                auto l_size  = l_NoEvents->elements();
                a_stream << "    " << "NoEvents-->[" << l_size << "]\n";
                for( auto l_entry = l_begin;
                     l_entry != l_end;
                     ++l_entry )
                {
                    a_stream << "        Entry-->[" << ( (l_entry-l_begin) + 1 ) << "/" << l_size << "," << (void *)l_entry << "]\n";
                    a_stream << *l_entry;
                }
                l_block = l_NoEvents->next();
            }

            {
                auto l_NoMDFeedTypes = reinterpret_cast<const MDInstrumentDefinitionSpread56::NoMDFeedTypes *>( l_block );
                auto l_begin = l_NoMDFeedTypes->entriesBegin();
                auto l_end   = l_NoMDFeedTypes->entriesEnd();
                auto l_size  = l_NoMDFeedTypes->elements();
                a_stream << "    " << "NoMDFeedTypes-->[" << l_size << "]\n";
                for( auto l_entry = l_begin;
                     l_entry != l_end;
                     ++l_entry )
                {
                    a_stream << "        Entry-->[" << ( (l_entry-l_begin) + 1 ) << "/" << l_size << "," << (void *)l_entry << "]\n";
                    a_stream << *l_entry;
                }
                l_block = l_NoMDFeedTypes->next();
            }

            {
                auto l_NoInstAttrib = reinterpret_cast<const MDInstrumentDefinitionSpread56::NoInstAttrib *>( l_block );
                auto l_begin = l_NoInstAttrib->entriesBegin();
                auto l_end   = l_NoInstAttrib->entriesEnd();
                auto l_size  = l_NoInstAttrib->elements();
                a_stream << "    " << "NoInstAttrib-->[" << l_size << "]\n";
                for( auto l_entry = l_begin;
                     l_entry != l_end;
                     ++l_entry )
                {
                    a_stream << "        Entry-->[" << ( (l_entry-l_begin) + 1 ) << "/" << l_size << "," << (void *)l_entry << "]\n";
                    a_stream << *l_entry;
                }
                l_block = l_NoInstAttrib->next();
            }

            {
                auto l_NoLotTypeRules = reinterpret_cast<const MDInstrumentDefinitionSpread56::NoLotTypeRules *>( l_block );
                auto l_begin = l_NoLotTypeRules->entriesBegin();
                auto l_end   = l_NoLotTypeRules->entriesEnd();
                auto l_size  = l_NoLotTypeRules->elements();
                a_stream << "    " << "NoLotTypeRules-->[" << l_size << "]\n";
                for( auto l_entry = l_begin;
                     l_entry != l_end;
                     ++l_entry )
                {
                    a_stream << "        Entry-->[" << ( (l_entry-l_begin) + 1 ) << "/" << l_size << "," << (void *)l_entry << "]\n";
                    a_stream << *l_entry;
                }
                l_block = l_NoLotTypeRules->next();
            }

            {
                auto l_NoLegs = reinterpret_cast<const MDInstrumentDefinitionSpread56::NoLegs *>( l_block );
                auto l_begin = l_NoLegs->entriesBegin();
                auto l_end   = l_NoLegs->entriesEnd();
                auto l_size  = l_NoLegs->elements();
                a_stream << "    " << "NoLegs-->[" << l_size << "]\n";
                for( auto l_entry = l_begin;
                     l_entry != l_end;
                     ++l_entry )
                {
                    a_stream << "        Entry-->[" << ( (l_entry-l_begin) + 1 ) << "/" << l_size << "," << (void *)l_entry << "]\n";
                    a_stream << *l_entry;
                }
                l_block = l_NoLegs->next();
            }

            return( a_stream );
        }
    } PACK;

} // mktdata
