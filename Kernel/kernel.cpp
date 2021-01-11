#include "Common/uints.h"
#include "Common/Macros.h"

#if defined(__linux__)
#error "You are not using a cross-compiler!"
#endif

#if !defined(__i386__)
#error "This needs to be compiled with a ix86-elf compiler!"
#endif

static constexpr kernel::u32 video_memory = 0xB8000;

static const size_t VGA_WIDTH = 80;
static const size_t VGA_HEIGHT = 25;

void write_string( const char* string, kernel::u8 color = 0xF )
{
	static kernel::u16* memory = reinterpret_cast< kernel::u16* >( video_memory );

	while( *string )
	{
		if( *string == '\n' )
		{
			if( *( ++memory ) )
			{
				*( ++memory ) = 1 * VGA_WIDTH + VGA_HEIGHT;
				return;
			}
			return;
		}

		kernel::u16 colored_char = *( string++ );
		colored_char |= color << 8;

		*( memory++ ) = colored_char;
	}
}

using Constructor = void( * )( );
Constructor Constructors_begin;
Constructor Constructors_end;

namespace kernel {
	void run( void )
	{
		for( Constructor* ctor = &Constructors_begin; ctor < &Constructors_end; ++ctor )
			( *ctor )( );

		cli();
		write_string("Hello World!");
		sti();
	}
}