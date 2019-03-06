#include "./tinyxml2-master/tinyxml2.h"

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <stack>
#include <cstdint>
#include <algorithm>

using namespace tinyxml2;

class t_node
{
    private:
    protected:
        struct t_attributes : std::map<std::string,std::string>
        {
            std::string value( const std::string & a_name )
            {
                auto l_iter = find( a_name );
                if ( l_iter != end() )
                {
                    return( l_iter->second );
                }
                return( "" );
            }

            void dump( std::string a_indent )
            {
                std::cout << a_indent << "attributes-->[" << size() << "]" << std::endl;
                for( auto & l_iter : *this )
                {
                    std::cout << a_indent << "    attribute-->[" << l_iter.first << "," << l_iter.second << "]" << std::endl;
                }
            }
        };

        t_attributes getAttributes( const XMLAttribute * a_attribute )
        {
            t_attributes l_attributes;

            for( ;
                 a_attribute != nullptr;
                 a_attribute = a_attribute->Next() )
            {
                l_attributes[ a_attribute->Name() ] = a_attribute->Value();
            }

            return( l_attributes );
        }

        std::string baseType( std::string a_type , const bool a_convertNull )
        {
            static std::map<std::string,std::string> s_mappings =
            {
                { "int8"       , "int8_t"   },
                { "int16"      , "int16_t"  },
                { "int32"      , "int32_t"  },
                { "int64"      , "int64_t"  },
                { "int8null"   , "int8_t"   },
                { "int16null"  , "int16_t"  },
                { "int32null"  , "int32_t"  },
                { "int64null"  , "int64_t"  },
                { "uint8"      , "uint8_t"  },
                { "uint16"     , "uint16_t" },
                { "uint32"     , "uint32_t" },
                { "uint64"     , "uint64_t" },
                { "uint8null"  , "uint8_t"  },
                { "uint16null" , "uint16_t" },
                { "uint32null" , "uint32_t" },
                { "uint64null" , "uint64_t" },
                { "char"       , "char"     }
            };

            std::string l_type{ a_type };
            std::transform( l_type.begin() , l_type.end() , l_type.begin() , ::tolower );

            auto l_iter = s_mappings.find( l_type );
            if ( l_iter != s_mappings.end() )
            {
                if ( l_type.find( "null" ) == std::string::npos )
                {
                    return( l_iter->second );
                }
                else
                if ( a_convertNull )
                {
                    return( l_iter->second );
                }
            }
            return( a_type );
        }

        typedef std::vector<t_node *> t_children;

        t_attributes m_attributes;
        t_children   m_children;
        std::string  m_indentation;

        t_node() = delete;
        t_node( const t_node & ) = delete;

    public:
        t_node( std::string a_type , const XMLAttribute * a_attribute )
        :m_attributes( getAttributes( a_attribute ) )
        {
            addAttribute( "nodeType" , a_type );
        }

        virtual ~t_node()
        {
        }

        void addAttribute( std::string a_name , std::string a_value )
        {
            m_attributes[ a_name ] = a_value;
        }

        void addChild( t_node * a_node )
        {
            m_children.push_back( a_node );
        }

        t_node * getChild( std::string a_nodeType )
        {
            for( auto & l_child : m_children )
            {
                if ( a_nodeType == l_child->value( "nodeType" ) )
                {
                    return( l_child );
                }
            }
            return( nullptr );
        }

        std::string value( std::string a_name )
        {
            return( m_attributes.value( a_name ) );
        }

        void dump( std::string a_indent = "" )
        {
            std::cout << a_indent << "Node-->[" << m_attributes.size() << "," << m_children.size() << "]" <<std::endl;
            m_attributes.dump( a_indent + "    " );
            for( auto & l_child : m_children )
            {
                l_child->dump( a_indent + "    " );
            }
        }

        void setIndentation( std::string a_indentation )
        {
            m_indentation = a_indentation;
        }

        virtual void emitCode()
        {
        }
};

class t_choice : public t_node
{
    private:
    protected:
    public:
        t_choice( const XMLAttribute * a_attribute )
        :t_node( "choice" , a_attribute )
        {
        }

        virtual ~t_choice()
        {
        }

        void emitCode()
        {
            auto l_nodeName = value( "name" );
            std::cout << m_indentation << "ALWAYS_INLINE const bool is" << l_nodeName << "() const { return( m_datum & ( 1 << " << value( "textValue" ) << " ) ); }" << std::endl;
        }

        static t_node * allocate( const XMLAttribute * a_attribute )
        {
            return( new t_choice( a_attribute ) );
        }
};

class t_composite : public t_node
{
    private:
    protected:
    public:
        t_composite( const XMLAttribute * a_attribute )
        :t_node( "composite" , a_attribute )
        {
        }

        virtual ~t_composite()
        {
        }

        void emitCode()
        {
            auto l_nodeName = value( "name" );

            std::cout << m_indentation << "struct " << l_nodeName << std::endl;
            std::cout << m_indentation << "{" << std::endl;
            std::cout << std::endl;

            // generate needed definitions
            for( auto & l_child : m_children )
            {
                l_child->setIndentation( m_indentation + "    " );
                l_child->emitCode();
            }

            // use definitions
            for( auto & l_child : m_children )
            {
                auto l_childName = l_child->value( "name" );
                std::cout << m_indentation << "    " << l_childName << " m_" << l_childName << ";" << std::endl;
                // special case... fix this CME
                if ( ( l_nodeName == "groupSize8Byte" ) && ( l_childName == "blockLength" ) )
                {
                    std::cout << m_indentation << "    uint8_t m_padding[5];" << std::endl;
                }
            }

            std::cout << std::endl;
            std::cout << m_indentation << "    friend std::ostream & operator<<( std::ostream & a_stream , const " << l_nodeName << " & a_instance )" << std::endl;
            std::cout << m_indentation << "    {" << std::endl;
            std::cout << m_indentation << "        a_stream << \"" << l_nodeName << "(\";" << std::endl;
            for( auto & l_child : m_children )
            {
                auto l_childName = l_child->value( "name" );
                std::cout << m_indentation << "        a_stream << \"[\" << " << "a_instance.m_" << l_childName << " << \"]\";" << std::endl;
            }
            std::cout << m_indentation << "        a_stream << \")\";" << std::endl;
            std::cout << m_indentation << "        return( a_stream );" << std::endl;
            std::cout << m_indentation << "    }" << std::endl;

            std::cout << m_indentation << "} PACK;" << std::endl;
            std::cout << std::endl;

            if ( l_nodeName == "messageHeader" )
            {
                std::cout << "    struct Message" << std::endl;
                std::cout << "    {" << std::endl;
                std::cout << "        uint16_t      m_size;" << std::endl;
                std::cout << "        messageHeader m_mh;" << std::endl;
                std::cout << "        uint8_t       m_sbeData[0];" << std::endl;
                std::cout << std::endl;
                std::cout << "        ALWAYS_INLINE Message * next()" << std::endl;
                std::cout << "        {" << std::endl;
                std::cout << "            return( reinterpret_cast<Message *>( (uintptr_t)this + m_size ) );" << std::endl;
                std::cout << "        }" << std::endl;
                std::cout << "    } PACK;" << std::endl;
                std::cout << std::endl;
            }
        }

        static t_node * allocate( const XMLAttribute * a_attribute )
        {
            return( new t_composite( a_attribute ) );
        }
};

class t_enum : public t_node
{
    private:
    protected:
    public:
        t_enum( const XMLAttribute * a_attribute )
        :t_node( "enum" , a_attribute )
        {
        }

        virtual ~t_enum()
        {
        }

        void emitCode()
        {
            auto        l_nodeName     = value( "name" );
            auto        l_encodingType = value( "encodingType" );
            auto        l_baseType     = baseType( l_encodingType , true );
            std::string l_encasing;

            if ( l_baseType == "char" )
            {
                l_encasing = "'";
            }
            std::cout << m_indentation << "struct " << l_nodeName << std::endl;
            std::cout << m_indentation << "{" << std::endl;
            for( t_children::iterator l_child = m_children.begin();
                 l_child != m_children.end();
                 ++l_child )
            {
                auto l_childName = (*l_child)->value( "name" );
                std::cout << m_indentation << "    " << "static constexpr " << l_baseType << " " << l_childName << " = " << l_encasing << (*l_child)->value( "textValue" ) << l_encasing << ";" << std::endl;
            }
            std::cout << m_indentation << "    " << l_baseType << " m_datum;" << std::endl;
            std::cout << m_indentation << "    " << "ALWAYS_INLINE const " << l_baseType << " value() const { return( m_datum ); }" << std::endl;
            std::cout << m_indentation << "    " << "NEVER_INLINE static const char * text( const " << l_baseType << " a_value )" << std::endl;
            std::cout << m_indentation << "    " << "{" << std::endl;
            std::cout << m_indentation << "        " << "switch( a_value )" << std::endl;
            std::cout << m_indentation << "        " << "{" << std::endl;
            for( t_children::iterator l_child = m_children.begin();
                 l_child != m_children.end();
                 ++l_child )
            {
                auto l_childName = (*l_child)->value( "name" );
                std::cout << m_indentation << "        " << "    case " << l_childName << ": return( \"" << l_childName << "\" );" << std::endl;
            }
            std::cout << m_indentation << "        " << "    default: return( \"wtf\" );" << std::endl;
            std::cout << m_indentation << "        " << "}" << std::endl;
            std::cout << m_indentation << "    " << "}" << std::endl;

            std::cout << m_indentation << "    " << "ALWAYS_INLINE const char * text() const { return( text( m_datum ) ); }" << std::endl;

            std::cout << m_indentation << "    friend std::ostream & operator<<( std::ostream & a_stream , const " << l_nodeName << " & a_instance )" << std::endl;
            std::cout << m_indentation << "    {" << std::endl;
            std::cout << m_indentation << "        a_stream << \"" << l_nodeName << "(\" << a_instance.text() << \")\";" << std::endl;
            std::cout << m_indentation << "        return( a_stream );" << std::endl;
            std::cout << m_indentation << "    }" << std::endl;
            std::cout << m_indentation << "} PACK;" << std::endl;
            std::cout << std::endl;
        }

        static t_node * allocate( const XMLAttribute * a_attribute )
        {
            return( new t_enum( a_attribute ) );
        }
};

class t_field : public t_node
{
    private:
    protected:
    public:
        t_field( const XMLAttribute * a_attribute )
        :t_node( "field" , a_attribute )
        {
        }

        virtual ~t_field()
        {
        }

        void emitCode()
        {
            auto l_nodeName = value( "name" );
            std::cout << m_indentation << value( "type" ) << " m_" << l_nodeName << ";" << std::endl;
        }

        static t_node * allocate( const XMLAttribute * a_attribute )
        {
            return( new t_field( a_attribute ) );
        }
};

class t_group : public t_node
{
    private:
    protected:
    public:
        t_group( const XMLAttribute * a_attribute )
        :t_node( "group" , a_attribute )
        {
        }

        virtual ~t_group()
        {
        }

        void emitCode()
        {
            auto l_nodeName = value( "name" );
            std::cout << m_indentation << "struct " << l_nodeName << std::endl;
            std::cout << m_indentation << "{" << std::endl;
            std::cout << m_indentation << "    " << value( "dimensionType" ) << " m_dimension;" << std::endl;
            std::cout << m_indentation << "    struct Entry" << std::endl;
            std::cout << m_indentation << "    {" << std::endl;
            std::string l_sizes;
            for( auto & l_child : m_children )
            {
                auto l_childName = l_child->value( "name" );
                l_child->setIndentation( m_indentation + "        " );
                l_child->emitCode();
                l_sizes += std::string( "sizeof( m_" ) + l_childName + " ) + ";
            }
            l_sizes.pop_back(); // space
            l_sizes.pop_back(); // +
            std::cout << m_indentation << "        uint8_t m_padding[ " << value( "blockLength" ) << " - ( " << l_sizes << ") ];" << std::endl;
            std::cout << std::endl;

            // stream insertion operator
            std::cout << m_indentation << "        friend std::ostream & operator<<( std::ostream & a_stream , const Entry & a_instance )" << std::endl;
            std::cout << m_indentation << "        {" << std::endl;
            for( auto & l_child : m_children )
            {
                auto l_childName = l_child->value( "name" );
                std::cout << m_indentation << "            a_stream << \"           m_" << l_childName << "-->[\" << a_instance.m_" << l_childName << " << \"]\\n\";" << std::endl;
            }
            std::cout << m_indentation << "            return( a_stream );" << std::endl;
            std::cout << m_indentation << "        }" << std::endl;
            std::cout << m_indentation << "    } PACK m_entries[0];" << std::endl;
            std::cout << m_indentation << "    ALWAYS_INLINE const size_t elements() const { return( (size_t)m_dimension.m_numInGroup.value() ); }" << std::endl;
            std::cout << m_indentation << "    ALWAYS_INLINE const auto entriesBegin() const { return( &m_entries[0] ); }" << std::endl;
            std::cout << m_indentation << "    ALWAYS_INLINE const auto entriesEnd() const { return( &m_entries[ elements() ] ); }" << std::endl;
            std::cout << m_indentation << "    ALWAYS_INLINE const void * next() const { return( (void *)entriesEnd() ); }" << std::endl;
            std::cout << m_indentation << "} PACK m_" << l_nodeName << ";" << std::endl;
            std::cout << std::endl;
        }

        static t_node * allocate( const XMLAttribute * a_attribute )
        {
            return( new t_group( a_attribute ) );
        }
};

class t_message : public t_node
{
    private:
    protected:
    public:
        t_message( const XMLAttribute * a_attribute )
        :t_node( "message" , a_attribute )
        {
        }

        virtual ~t_message()
        {
        }

        void emitCode()
        {
            auto l_nodeName = value( "name" );
            std::cout << m_indentation << "struct " << l_nodeName << std::endl;
            std::cout << m_indentation << "{" << std::endl;
            std::cout << m_indentation << "    static constexpr int32_t id() { return( " << value( "id" ) << " ); }" << std::endl;
            std::cout << m_indentation << "    static constexpr const char * name() { return( \"" << l_nodeName << "\" ); }" << std::endl;
            std::cout << std::endl;
            std::string l_sizes;
            for( auto & l_child : m_children )
            {
                auto l_childName = l_child->value( "name" );
                l_child->setIndentation( m_indentation + "    " );
                if ( l_child->value( "nodeType" ) == "field" )
                {
                    l_sizes += std::string( "sizeof( m_" ) + l_childName + " ) + ";
                }
                else
                if ( l_sizes.length() != 0 )
                {
                    l_sizes.pop_back(); // space
                    l_sizes.pop_back(); // +
                    std::cout << m_indentation << "    uint8_t m_padding[ " << value( "blockLength" ) << " - ( " << l_sizes << ") ];" << std::endl;
                    std::cout << std::endl;
                    l_sizes = "";
                }
                l_child->emitCode();
            }

            // stream insertion operator
            std::cout << m_indentation << "    friend std::ostream & operator<<( std::ostream & a_stream , const " << value("name") << " & a_instance )" << std::endl;
            std::cout << m_indentation << "    {" << std::endl;
            std::cout << m_indentation << "        a_stream << \"" << l_nodeName << "-->[\" << (void *)&a_instance << " << "\"]\\n\";" << std::endl;
            bool l_firstTime = true;
            for( auto & l_child : m_children )
            {
                auto l_childName = l_child->value( "name" );
                if ( l_child->value( "nodeType" ) == "field" )
                {
                    std::cout << m_indentation << "        a_stream << \"    m_" << l_childName << "-->[\" << a_instance.m_" << l_childName << " << \"]\\n\";" << std::endl;
                }
                else
                {
                    if ( l_firstTime )
                    {
                        l_firstTime = false;
                        std::cout << m_indentation << "        a_stream << \"    m_padding-->[\" << sizeof( a_instance.m_padding ) << \"]\\n\";" << std::endl;
                        std::cout << std::endl;
                        std::cout << m_indentation << "        auto l_group = reinterpret_cast<const void *>( &a_instance.m_" << l_childName << " );" << std::endl;
                    }
                    auto l_groupName = "l_" + l_childName;
                    std::cout << m_indentation << "        { // group " << l_childName << std::endl;
                    std::cout << m_indentation << "            auto " << l_groupName << " = reinterpret_cast<const " << l_nodeName << "::" << l_childName << " *>( l_group );" << std::endl;
                    std::cout << m_indentation << "            auto l_begin = " << l_groupName << "->entriesBegin();" << std::endl;
                    std::cout << m_indentation << "            auto l_end   = " << l_groupName << "->entriesEnd();" << std::endl;
                    std::cout << m_indentation << "            auto l_size  = " << l_groupName << "->elements();" << std::endl;
                    std::cout << m_indentation << "            a_stream << \"    \" << " << "\"" << l_childName << "-->[\" << l_size << \"]\\n\";" << std::endl;
                    std::cout << m_indentation << "            for( auto l_entry = l_begin;" << std::endl;
                    std::cout << m_indentation << "                 l_entry != l_end;" << std::endl;
                    std::cout << m_indentation << "                 ++l_entry )" << std::endl;
                    std::cout << m_indentation << "            {" << std::endl;
                    std::cout << m_indentation << "                a_stream << \"        Entry-->[\" << ( (l_entry-l_begin) + 1 ) << \"/\" << l_size << \",\" << (void *)l_entry << \"]\\n\";" << std::endl;
                    std::cout << m_indentation << "                a_stream << *l_entry;" << std::endl;
                    std::cout << m_indentation << "            }" << std::endl;
                    std::cout << m_indentation << "            l_group = " << l_groupName << "->next();" << std::endl;
                    std::cout << m_indentation << "        }" << std::endl;
                    std::cout << std::endl;
                }
            }
            std::cout << m_indentation << "        return( a_stream );" << std::endl;
            std::cout << m_indentation << "    }" << std::endl;
            std::cout << m_indentation << "} PACK;" << std::endl;
            std::cout << std::endl;
        }

        static t_node * allocate( const XMLAttribute * a_attribute )
        {
            return( new t_message( a_attribute ) );
        }
};

class t_messageSchema : public t_node
{
    private:
    protected:
    public:
        t_messageSchema( const XMLAttribute * a_attribute )
        :t_node( "messageSchema" , a_attribute )
        {
        }

        virtual ~t_messageSchema()
        {
        }

        void emitCode()
        {
            std::cout << "#pragma once" << std::endl;
            std::cout << std::endl;
            std::cout << "#include <iostream>" << std::endl;
            std::cout << "#include <cstdint>" << std::endl;
            std::cout << "#include <string>" << std::endl;
            std::cout << "#include <iomanip>" << std::endl;
            std::cout << std::endl;
            std::cout << "#define ALWAYS_INLINE inline __attribute__((always_inline))" << std::endl;
            std::cout << "#define NEVER_INLINE  __attribute__((noinline))" << std::endl;
            std::cout << "#define PACK          __attribute__((packed))" << std::endl;
            std::cout << "#define HOT           __attribute__((hot))" << std::endl;
            std::cout << std::endl;
            std::cout << "namespace " << value( "package" ) << std::endl;
            std::cout << "{" << std::endl;
            std::cout << std::endl;
            std::cout << "    static constexpr int32_t g_version = " << value( "version" ) << ";" << std::endl;
            std::cout << std::endl;
            std::cout << "    static NEVER_INLINE void copy( char * a_dst , const char * a_src , size_t a_size )" << std::endl;
            std::cout << "    {" << std::endl;
            std::cout << "        while( ( *a_src != \'\\0\' ) && ( a_size ) )" << std::endl;
            std::cout << "        {" << std::endl;
            std::cout << "            *a_dst++ = *a_src++;" << std::endl;
            std::cout << "            --a_size;" << std::endl;
            std::cout << "        }" << std::endl;
            std::cout << "        *a_dst = \'\\0\';" << std::endl;
            std::cout << "    }" << std::endl;
            std::cout << std::endl;
            std::cout << "    static NEVER_INLINE std::string asString( const char * a_data , size_t a_size )" << std::endl;
            std::cout << "    {" << std::endl;
            std::cout << "        std::string l_string;" << std::endl;
            std::cout << "        while( ( *a_data != \'\\0\' ) && ( a_size ) )" << std::endl;
            std::cout << "        {" << std::endl;
            std::cout << "            l_string += *a_data;" << std::endl;
            std::cout << "            ++a_data;" << std::endl;
            std::cout << "            --a_size;" << std::endl;
            std::cout << "        }" << std::endl;
            std::cout << "        return( l_string );" << std::endl;
            std::cout << "    }" << std::endl;
            std::cout << std::endl;

            for( auto & l_child : m_children )
            {
                l_child->setIndentation( "    " );
                l_child->emitCode();
            }

            std::cout << "} // " << value( "package" ) << std::endl;
        }

        static t_node * allocate( const XMLAttribute * a_attribute )
        {
            return( new t_messageSchema( a_attribute ) );
        }
};

class t_set : public t_node
{
    private:
    protected:
    public:
        t_set( const XMLAttribute * a_attribute )
        :t_node( "set" , a_attribute )
        {
        }

        virtual ~t_set()
        {
        }

        void emitCode()
        {
            auto l_nodeName = value( "name" );
            std::cout << m_indentation << "struct " << l_nodeName << std::endl;
            std::cout << m_indentation << "{" << std::endl;
            std::cout << m_indentation << "    " << baseType( value( "encodingType" ) , true ) << " m_datum;" << std::endl;
            std::cout << m_indentation << "    " << baseType( value( "encodingType" ) , true ) << " value() const { return( m_datum ); }" << std::endl;
            for( auto & l_child : m_children )
            {
                l_child->setIndentation( m_indentation + "    " );
                l_child->emitCode();
            }

            std::cout << m_indentation << "    friend std::ostream & operator<<( std::ostream & a_stream , const " << l_nodeName << " & a_instance )" << std::endl;
            std::cout << m_indentation << "    {" << std::endl;
            std::cout << m_indentation << "        a_stream << \"" << l_nodeName << "(0x\" << std::hex << std::setw(2*sizeof(a_instance.m_datum)) << std::setfill('0') << +a_instance.m_datum << ',' << std::dec;" << std::endl;
            for( auto & l_child : m_children )
            {
                auto l_childName = l_child->value( "name" );
                std::cout << m_indentation << "        if ( a_instance.is" << l_childName << "() )" << std::endl;
                std::cout << m_indentation << "        {"<< std::endl;
                std::cout << m_indentation << "            a_stream << \"" << l_childName << ",\";" << std::endl;
                std::cout << m_indentation << "        }"<< std::endl;
            }
            std::cout << m_indentation << "        a_stream << \")\";" << std::endl;
            std::cout << m_indentation << "        return( a_stream );" << std::endl;
            std::cout << m_indentation << "    }" << std::endl;

            std::cout << m_indentation << "} PACK;" << std::endl;
            std::cout << std::endl;
        }

        static t_node * allocate( const XMLAttribute * a_attribute )
        {
            return( new t_set( a_attribute ) );
        }
};

class t_type : public t_node
{
    private:
    protected:
    public:
        t_type( const XMLAttribute * a_attribute )
        :t_node( "type" , a_attribute )
        {
        }

        virtual ~t_type()
        {
        }

        void emitCode()
        {
            auto l_nodeName      = value( "name" );
            auto l_presence      = value( "presence" );
            auto l_primitiveType = baseType( value( "primitiveType" ) , true );

            std::cout << m_indentation << "struct " << l_nodeName << std::endl;
            std::cout << m_indentation << "{" << std::endl;

            if ( l_presence == "constant" )
            {
                std::cout << m_indentation << "    uint8_t m_datum[0];  // forces sizeof( *this ) to return 0" << std::endl;
                if ( l_primitiveType == "char" )
                {
                    std::cout << m_indentation << "    ALWAYS_INLINE const " << l_primitiveType << " value() const { return( '" << value( "textValue" ) << "' ); }" << std::endl;
                }
                else
                {
                    std::cout << m_indentation << "    ALWAYS_INLINE const " << l_primitiveType << " value() const { return( " << value( "textValue" ) << " ); }" << std::endl;
                }
                std::cout << m_indentation << "    friend std::ostream & operator<<( std::ostream & a_stream , const " << l_nodeName << " & a_instance )" << std::endl;
                std::cout << m_indentation << "    {" << std::endl;
                if ( l_primitiveType.find( "int8" ) != std::string::npos )
                {
                    std::cout << m_indentation << "        a_stream << \"" << l_nodeName << "(\" << +a_instance.value() << \")\";" << std::endl;
                }
                else
                {
                    std::cout << m_indentation << "        a_stream << \"" << l_nodeName << "(\" << a_instance.value() << \")\";" << std::endl;
                }
                std::cout << m_indentation << "        return( a_stream );" << std::endl;
                std::cout << m_indentation << "    }" << std::endl;
            }
            else
            if ( l_presence == "optional" )
            {
                auto l_nullValue = value( "nullValue" );
                std::cout << m_indentation << "    " << l_primitiveType << " m_datum;" << std::endl;
                std::cout << m_indentation << "    ALWAYS_INLINE const " << l_primitiveType << " value() const { return( m_datum ); }" << std::endl;
                std::cout << m_indentation << "    ALWAYS_INLINE const bool isNull() const { return( m_datum == " << l_nullValue << ( l_primitiveType == "uint64_t" ? "ULL" : "" ) << " ); }" << std::endl;
                std::cout << m_indentation << "    friend std::ostream & operator<<( std::ostream & a_stream , const " << l_nodeName << " & a_instance )" << std::endl;
                std::cout << m_indentation << "    {" << std::endl;
                std::cout << m_indentation << "        if ( a_instance.isNull() )" << std::endl;
                std::cout << m_indentation << "        {" << std::endl;
                std::cout << m_indentation << "            a_stream << \"" << l_nodeName << "(NULL)\";" << std::endl;
                std::cout << m_indentation << "        }" << std::endl;
                std::cout << m_indentation << "        else" << std::endl;
                std::cout << m_indentation << "        {" << std::endl;
                if ( l_primitiveType.find( "int8" ) != std::string::npos )
                {
                    std::cout << m_indentation << "            a_stream << \"" << l_nodeName << "(\" << +a_instance.value() << \")\";" << std::endl;
                }
                else
                {
                    std::cout << m_indentation << "            a_stream << \"" << l_nodeName << "(\" << a_instance.value() << \")\";" << std::endl;
                }
                std::cout << m_indentation << "        }" << std::endl;
                std::cout << m_indentation << "        return( a_stream );" << std::endl;
                std::cout << m_indentation << "    }" << std::endl;
            }
            else
            {
                auto l_length = value( "length" );
                if ( l_length.size() != 0 )
                {
                    std::cout << m_indentation << "    " << l_primitiveType << " m_datum[" << l_length << "];" << std::endl;
                    if ( l_primitiveType == "char" )
                    {
                        std::cout << m_indentation << "    ALWAYS_INLINE const std::string value() const { return( asString( m_datum , size() ) ); }" << std::endl;
                    }
                    else
                    {
                        std::cout << m_indentation << "    ALWAYS_INLINE const " << l_primitiveType << " * value() const { return( m_datum ); }" << std::endl;
                    }
                    std::cout << m_indentation << "    ALWAYS_INLINE const size_t size() const { return( sizeof( *this ) ); }" << std::endl;
                }
                else
                {
                    std::cout << m_indentation << "    " << l_primitiveType << " m_datum;" << std::endl;
                    std::cout << m_indentation << "    ALWAYS_INLINE const " << l_primitiveType << " value() const { return( m_datum ); }" << std::endl;
                }
                std::cout << m_indentation << "    friend std::ostream & operator<<( std::ostream & a_stream , const " << l_nodeName << " & a_instance )" << std::endl;
                std::cout << m_indentation << "    {" << std::endl;
                if ( l_primitiveType.find( "int8" ) != std::string::npos )
                {
                    std::cout << m_indentation << "        a_stream << \"" << l_nodeName << "(\" << +a_instance.value() << \")\";" << std::endl;
                }
                else
                {
                    std::cout << m_indentation << "        a_stream << \"" << l_nodeName << "(\" << a_instance.value() << \")\";" << std::endl;
                }
                std::cout << m_indentation << "        return( a_stream );" << std::endl;
                std::cout << m_indentation << "    }" << std::endl;
            }
            std::cout << m_indentation << "} PACK;" << std::endl;
            std::cout << std::endl;
        }

        static t_node * allocate( const XMLAttribute * a_attribute )
        {
            return( new t_type( a_attribute ) );
        }
};

class t_types : public t_node
{
    private:
    protected:
    public:
        t_types( const XMLAttribute * a_attribute )
        :t_node( "types" , a_attribute )
        {
        }

        virtual ~t_types()
        {
        }

        void emitCode()
        {
            for( auto & l_child : m_children )
            {
                l_child->setIndentation( "    " );
                l_child->emitCode();
            }
        }

        static t_node * allocate( const XMLAttribute * a_attribute )
        {
            return( new t_types( a_attribute ) );
        }
};

class t_validValue : public t_node
{
    private:
    protected:
    public:
        t_validValue( const XMLAttribute * a_attribute )
        :t_node( "validValue" , a_attribute )
        {
        }

        virtual ~t_validValue()
        {
        }

        void emitCode()
        {
        }

        static t_node * allocate( const XMLAttribute * a_attribute )
        {
            return( new t_validValue( a_attribute ) );
        }
};

class nodeVisitor : public XMLVisitor
{
    private:
        typedef t_node * (* t_allocator)( const XMLAttribute * );

        std::map<std::string,t_allocator> m_allocators;
        std::stack<t_node *>              m_stack;
        t_node *                          m_root;
        t_node *                          m_currentNode;

    protected:
    public:
        nodeVisitor()
        :m_root( new t_node( "root" , nullptr ) ),
         m_currentNode( m_root )
        {
            m_allocators[ "choice"            ] = &t_choice::allocate;
            m_allocators[ "composite"         ] = &t_composite::allocate;
            m_allocators[ "enum"              ] = &t_enum::allocate;
            m_allocators[ "field"             ] = &t_field::allocate;
            m_allocators[ "group"             ] = &t_group::allocate;
            m_allocators[ "ns2:message"       ] = &t_message::allocate;
            m_allocators[ "ns2:messageSchema" ] = &t_messageSchema::allocate;
            m_allocators[ "set"               ] = &t_set::allocate;
            m_allocators[ "type"              ] = &t_type::allocate;
            m_allocators[ "types"             ] = &t_types::allocate;
            m_allocators[ "validValue"        ] = &t_validValue::allocate;
        }

        bool VisitEnter( const XMLElement & a_element , const XMLAttribute * a_attribute )
        {
            // get a new node
            auto l_node = (*m_allocators[ a_element.Value() ])( a_attribute );
            m_currentNode->addChild( l_node );

            // save where we were
            m_stack.push( m_currentNode );

            // start using the new node
            m_currentNode = l_node;

            return( true );
        }

        bool VisitExit( const XMLElement & a_element )
        {
            m_currentNode = m_stack.top();
            m_stack.pop();

            return( true );
        }

        bool Visit( const XMLText & a_text )
        {
            m_currentNode->addAttribute( "textValue" , a_text.Value() );

            return( true );
        }

        t_node * root()
        {
            return( m_root );
        }
};

int main( int a_argc , char * a_argv[] )
{
    if ( a_argc != 2 )
    {
        std::cout << "Usage: " << a_argv[0] << " " << "templatefile" << std::endl;
        exit(0);
    }

    XMLDocument doc;
    doc.LoadFile( a_argv[1] );

    nodeVisitor l_visitor;
    doc.Accept( &l_visitor );

    auto l_schema = l_visitor.root()->getChild( "messageSchema" );
#ifdef PARSE_TREE
    l_schema->dump();
#else
    l_schema->emitCode();
#endif
    exit(0);
}
