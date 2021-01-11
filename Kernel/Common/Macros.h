#pragma once

#include <stddef.h>

#define PACKED [[gnu::packed]]
#define __NORETURN __attribute__ ((noreturn))
#define __MALLOC __attribute__ ((malloc))
#define __PACKED __attribute__ ((packed))
#ifdef __cplusplus
#define _C_EXTERN extern "C" {
#define _C_END }
#endif

#define va_start(argsPointer, param) __builtin_va_start(argsPointer, param)
#define va_arg(argsPointer, type) __builtin_va_arg(argsPointer, type)
#define va_end(argsPointer) __builtin_va_end(argsPointer)
	using va_list = __builtin_va_list;

#define OS_DEBUG
#if defined(OS_DEBUG)
#define ASSERT(x, msg)													\
		if (!(x))															\
		{																	\
			write_string("Assertion failed ('");							\
			write_string(#msg);												\
			write_string("')\n"); 											\
			write_string((const char*)__FILE__, 0x4); 						\
			write_string((unsigned)__LINE__, 0x4); 						\
			sti();															\
		}
#else
#define ASSERT(x, msg)
#endif

#define BIT(x) (1 << (x))

#define cli()  asm volatile("cli" ::: "memory")
#define sti() asm volatile("sti" ::: "memory")
#define hlt()  asm volatile("hlt" ::: "memory")
#define hang() for (;;) { cli(); hlt(); } 
