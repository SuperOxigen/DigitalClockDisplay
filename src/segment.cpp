#include "segment.h"

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
 *       
 */

#define DP_BIT 0x01

byte char_to_segment(char c)
{
    byte segment = 0;
    switch (c)
    {
    case 'a':
    case 'A':
        segment = 0xEE;
        break;
    case 'b':
    case 'B':
        segment = 0x3E;
        break;
    case 'c':
    case 'C':
        segment = 0x1A;
        break;
    case 'd':
    case 'D':
        segment = 0x78;
        break;
    case 'e':
    case 'E':
        segment = 0x9E;
        break;
    case 'f':
    case 'F':
        segment = 0x8E;
        break;
    case '0':
        segment = 0xFC;
        break;
    case '1':
        segment = 0x60;
        break;
    case '2':
        segment = 0xDA;
        break;
    case '3':
        segment = 0xF2;
        break;
    case '4':
        segment = 0x66;
        break;
    case '5':
        segment = 0xB6;
        break;
    case '6':
        segment = 0xBE;
        break;
    case '7':
        segment = 0xE0;
        break;
    case '8':
        segment = 0xFE;
        break;
    case '9':
        segment = 0xF6;
        break;
    default:
        segment = 0xFF;
        break;
    }

    return segment;
} 

Segment::Segment(char _c = '0') : c(_c)
{
    this->segment.value = char_to_segment(c);
}

byte Segment::get_byte() const
{
    return this->segment.value;
}

char Segment::get_char() const
{
    return this->c;
}

void Segment::dp_high()
{
    this->segment.value = this->segment.value | DP_BIT;
}

void Segment::dp_low()
{
    this->segment.value = this->segment.value & ~DP_BIT;
}
