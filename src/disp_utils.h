#pragma once

#include <stddef.h>

#define MICRO_DELAY 50

typedef unsigned int pin;
typedef unsigned char byte;

typedef union
{
	byte value;
	struct seg
	{
		byte a  : 1;
		byte b  : 1;
		byte c  : 1;
		byte d  : 1;
		byte e  : 1;
		byte f  : 1;
		byte g  : 1;
		byte dp : 1;
	};
} seg_disp;

/*
 *      ### A ###
 *     #         #
 *     #         #
 *     F         B
 *     #         #
 *     #         #
 *      ### G ###
 *     #         #
 *     #         #
 *     E         C
 *     #         #
 *     #         #    ##
 *      ### D ###   # DP #
 *                    ##
 *
 * byte: A|B|C|D|E|F|G|DP
 */

#define SEG_A 0xEE
#define SEG_B 0x3E
#define SEG_C 0x1A
#define SEG_D 0x7A
#define SEG_E 0x9E
#define SEG_F 0x8E

#define SEG_0 0xFC
#define SEG_1 0x60
#define SEG_2 0xDA
#define SEG_3 0xF2
#define SEG_4 0x66
#define SEG_5 0xB6
#define SEG_6 0xBE
#define SEG_7 0xE0
#define SEG_8 0xFE
#define SEG_9 0xF6

#define SEG_FLASH 0xFF
