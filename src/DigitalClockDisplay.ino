#include <Arduino.h>
#include "seg_disp.h"
#include "disp_io.h"
#include "stdio.h"

#include <stdio.h>

typedef SegmentDisplay<4u> SegDisp;

#define SERIAL_PIN 4
#define SERIAL_CLK 6
#define OUTSEG_CLK 5
#define SERIAL_CLR 7

#define ONE_SECOND 1000

DispIO display_io(SERIAL_PIN, OUTSEG_CLK, SERIAL_CLK, SERIAL_CLR);
SegDisp display(display_io);

void setup()
{
	// display_io = DispIO(SERIAL_PIN, OUTSEG_CLK, SERIAL_CLK, SERIAL_CLR);
	// display = SegDisp(display_io);

}

char numbuf[5];
unsigned int counter = 0;

void loop()
{
    sprintf(numbuf, "%04u", counter);
    display.write(numbuf);
    counter++;
    delay(ONE_SECOND / 100);
	// display.write("0123");
	// delay(ONE_SECOND * 5);
	// display.write("4567");
	// delay(ONE_SECOND * 5);
	// display.write("89AB");
	// delay(ONE_SECOND * 5);
	// display.write("CDEF");
	// delay(ONE_SECOND * 5);
}
