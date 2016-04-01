#pragma once

#include "disp_utils.h"

class DispIO
{
	pin ser; // Data pin
	pin rc_clk; // Segment refresh clock
	pin ser_clk; // Serial load clock
	pin ser_clr; // Serial clear

	void serial_clk();
	void serial_write_byte(byte data);

public:
	DispIO(pin _ser, pin _rc_clk, pin _ser_clk, pin _ser_clr);

	void serial_write(byte * data, size_t const N);
	void serial_load();
	void serial_write_load(byte * data, size_t const N);
	void serial_clear();
	void clear();
};
