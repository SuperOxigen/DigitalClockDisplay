#pragma once

#define MICRO_DELAY 50

typedef unsigned int pin;
typedef unsigned char byte;

typedef union
{
	byte value;
	struct seg
	{
		byte a  : 1,
		byte b  : 1,
		byte c  : 1,
		byte d  : 1,
		byte e  : 1,
		byte f  : 1,
		byte g  : 1,
		byte dp : 1
	};
} seg_disp;
