#pragma once

#include "Common/uints.h"

namespace kernel {

    class IO
    {
    public:
        static void out8(u16 p, u8 data) 
        {
            asm volatile("outb %0, %1" :: "a"(data), "Nd"(p));
        }

        static void out16(u16 p, u16 data) 
        {
            asm volatile("outw %0, %1" :: "a"(data), "Nd"(p));
        }

        static void out32(u16 p,u32 data) 
        {
            asm volatile("outl %0, %1" :: "a"(data), "Nd"(p));
        }

        static u8 in8(u16 p) 
        {
            u8 data;
            asm volatile("inb %1, %0" :: "=a"(data), "Nd"(p));
            return data;
        }

        static u16 in16(u16 p) 
        {
            u16 data;
            asm volatile("inw %1, %0" :: "=a"(data), "Nd"(p));
            return data;
        }

        static u32 in32(u16 p) 
        {
            u32 data;
            asm volatile("inl %1, %0" :: "=a"(data), "Nd"(p));
            return data;
        }
    };
}