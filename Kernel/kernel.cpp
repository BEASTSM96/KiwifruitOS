#include "Common/uints.h"
#include "Common/Macros.h"

#if defined(__linux__)
#error "You are not using a cross-compiler!"
#endif

#if !defined(__i386__)
#error "This needs to be compiled with a ix86-elf compiler!"
#endif


using Constructor = void( * )( );
Constructor Constructors_begin;
Constructor Constructors_end;

namespace kernel {
	void run( void )
	{

		cli();
		write_string("Hello World!");
		sti();
	}
	void ctor( void ) 
	{
		for( Constructor* ctor = &Constructors_begin; ctor < &Constructors_end; ++ctor ) {
			( *ctor )( );
		}

		//write_string("ctor Completed");
	}
}