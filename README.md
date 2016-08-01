# DigitalDisplay

A segment display library for a [Arduino](https://www.arduino.cc/) based system.

## Example

The overall API for this system is very simple.  The two main classes is the
**DispIO** and **SegmentDisplay**.  Although, **DispIO** is only needed for the
initialization.

To initialize the display:

```cpp
// Initialize hardware pins and communication.
DispIO display_io(SERIAL_PIN, OUTSEG_CLK, SERIAL_CLK, SERIAL_CLR);

// Create segment display for writing to board. (assuming 4 digits)
SegmentDisplay<4> display(display_io);

// Test string
display.write("0123");
```

## Hardware Specification

For the hardware setup of the digital display, 2 components are required (not
counting wires and resistors).

A 7 segment display LED (optional with decimal). Currently only supporting
common anode.

To reduce the number Arduino wires used, and to allow of easy scalability (the
addition of digits), serial 8-bit shift registers are used to control the digit
segments.  

## API Reference
