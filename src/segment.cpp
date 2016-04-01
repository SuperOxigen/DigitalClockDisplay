#include "segment.h"

#define DP_BIT 0x01

byte char_to_segment(char c)
{
    byte segment = 0;
    switch (c)
    {
    case 'a':
    case 'A':
        segment = SEG_A;
        break;
    case 'b':
    case 'B':
        segment = SEG_B;
        break;
    case 'c':
    case 'C':
        segment = SEG_C;
        break;
    case 'd':
    case 'D':
        segment = SEG_D;
        break;
    case 'e':
    case 'E':
        segment = SEG_E;
        break;
    case 'f':
    case 'F':
        segment = SEG_F;
        break;
    case '0':
        segment = SEG_0;
        break;
    case '1':
        segment = SEG_1;
        break;
    case '2':
        segment = SEG_2;
        break;
    case '3':
        segment = SEG_3;
        break;
    case '4':
        segment = SEG_4;
        break;
    case '5':
        segment = SEG_5;
        break;
    case '6':
        segment = SEG_6;
        break;
    case '7':
        segment = SEG_7;
        break;
    case '8':
        segment = SEG_8;
        break;
    case '9':
        segment = SEG_9;
        break;
    default:
        segment = SEG_FLASH;
        break;
    }

    return segment;
}

Segment::Segment(byte seg)
{
    segment.value = seg;
}

byte Segment::get_byte() const
{
    return this->segment.value;
}

void Segment::dp_high()
{
    this->segment.value = this->segment.value | DP_BIT;
}

void Segment::dp_low()
{
    this->segment.value = this->segment.value & ~DP_BIT;
}

CharSegment::CharSegment(char _c):
    Segment(char_to_segment(_c)), c(_c) {}

char CharSegment::get_char() const
{
    return this->c;
}
