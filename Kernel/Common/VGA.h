#pragma once

#include "uints.h"

namespace kernel::VGA {
	/* Hardware text mode color constants. */
	enum Color {
		BLACK = 0,
		BLUE = 1,
		GREEN = 2,
		CYAN = 3,
		RED = 4,
		MAGENTA = 5,
		BROWN = 6,
		LIGHT_GREY = 7,
		DARK_GREY = 8,
		LIGHT_BLUE = 9,
		LIGHT_GREEN = 10,
		LIGHT_CYAN = 11,
		LIGHT_RED = 12,
		LIGHT_MAGENTA = 13,
		LIGHT_BROWN = 14,
		WHITE = 15,
	};

	static inline u8 Entry_Color(enum Color fg, enum Color bg) 
	{
		return fg | bg << 4;
	}
	
	static inline u16 Entry(unsigned char uc, u8 color) 
	{
		return (u16) uc | (u16) color << 8;
	}

}