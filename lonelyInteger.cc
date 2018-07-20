#include <iostream>
#include <vector>
#include <type_traits>

// getting jiggy with c++, lambda's and assembly code
// g++ -O3 -std=c++14

int main( int a_argc , char * a_argv[] )
{
    // smoking fast lonely integer determiner
    // probably as fast as can be without using SIMD instructions
    auto lonelyInteger = []( auto * a_data , size_t a_size )
    {
        // get the type of "auto" that a_data is pointing to
        typedef typename std::remove_pointer<typename std::remove_reference<decltype(a_data)>::type>::type t_type;

        register size_t l_typeSize{ sizeof( t_type ) };
        register t_type l_value{ 0 };

        //
        // extra credit 1
        // why is lea used in the loop, instead of an add ?
        //
        // extra credit 2
        // why is the assembly sequence sub, jnc used ?
        //
        asm volatile
        (
                "jmp   l_loop%=;"
            "l_top%=:;"
                "xor   (%[a_data]),%[l_value];"
                "lea   (%[l_typeSize],%[a_data],1),%[a_data];"
            "l_loop%=:;"
                "sub   $1,%[a_size];"
                "jnc   l_top%=;"
                : [l_value] "+r" (l_value) , [a_data] "+r" (a_data) , [a_size] "+r" (a_size) 
                : [l_typeSize] "r" (l_typeSize)
                : "cc"
        );

        return( l_value );
    };

    std::vector<int> l_data = {1,2,4,3,1,2,3};
//    std::vector<int> l_data = {}; // extra credit 2 hint...
    std::cout << lonelyInteger( l_data.data() , l_data.size() ) << std::endl;
}
