#pragma once
#include "disp_utils.h"

class Segment
{
	disp_seg segment;
	char c;
public:
	Segment(char _c = '0');

	byte get_byte() const;
	char get_char() const;
	void dp_high();
	void dp_low();
};

