#include "disp_io.h"
#include <Arduino.h>

DispIO::DispIO(pin _ser, pin _rc_clk, pin _ser_clk, pin _ser_clr):
	ser(_ser), rc_clk(_rc_clk), ser_clk(_ser_clk), ser_clr(_ser_clr)
{
	pinMode(ser, OUTPUT);
	pinMode(rc_clk, OUTPUT);
	pinMode(ser_clk, OUTPUT);
	pinMode(ser_clr, OUTPUT);

	digitalWrite(ser, LOW);
	digitalWrite(rc_clk, LOW);
	digitalWrite(ser_clk, LOW);
	digitalWrite(ser_clr, LOW);

	this->clear();
}

void inline pulse(pin p, size_t del)
{
	digitalWrite(p, HIGH);
	delayMicroseconds(del);
	digitalWrite(p, LOW);
	delayMicroseconds(del);
}

void DispIO::serial_clk()
{
	pulse(ser_clk, MICRO_DELAY);
}

void DispIO::serial_write_byte(byte data)
{
	byte mask = 0x80u;

	while (mask)
	{
		if (data & mask)
			digitalWrite(ser, HIGH);
		else
			digitalWrite(ser, LOW);
		this->serial_clk();
		mask = mask >> 1;
	}
}

void DispIO::serial_write(byte * data, size_t const N)
{
	size_t i;
	for (i = 0; i < N; i++)
	{
		this->serial_write_byte(data[i]);
	}
}

void DispIO::serial_load()
{
	pulse(rc_clk, MICRO_DELAY);
}

void DispIO::serial_write_load(byte * data, size_t const N)
{
	this->serial_write(data, N);
	this->serial_load();
}

void DispIO::serial_clear()
{
	pulse(ser_clr, MICRO_DELAY);
}

void DispIO::clear()
{
	serial_clear();
	serial_load();
}
