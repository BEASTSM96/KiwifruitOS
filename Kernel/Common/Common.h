#pragma once

#include "uints.h"

namespace kernel {

	void* memset( void* dest, unsigned char val, int count )
	{
		/* Add code here to set 'count' bytes in 'dest' to 'val'.
		 * Again, return 'dest' */
		unsigned char* destC = ( unsigned char* )dest;
		int i;
		for( i = 0; i < count; i++ )
			destC[ i ] = val;
		return dest;
	}

	static constexpr u32 video_memory = 0xB8000;

	static const size_t VGA_WIDTH = 80;
	static const size_t VGA_HEIGHT = 25;

	void write_string( const char* string, u8 color = 0xF )
	{
		static u16* memory = reinterpret_cast< u16* >( video_memory );

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

			u16 colored_char = *( string++ );
			colored_char |= color << 8;

			*( memory++ ) = colored_char;
		}
	}

}