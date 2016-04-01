#pragma once
#include "disp_utils.h"

class Segment
{
protected:
	seg_disp segment;
public:
	Segment(byte seg = 0);

	byte get_byte() const;
	void dp_high();
	void dp_low();
};

class CharSegment : public Segment
{
	char c;
public:
	CharSegment(char _c = '0');
	char get_char() const;
};
