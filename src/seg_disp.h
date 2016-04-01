#pragma once

#include "disp_io.h"
#include "segment.h"
#include "disp_utils.h"

template<size_t N>
class SegmentDisplay
{
	DispIO & disp_io;
	Segment segments[N];

	void write_to_display();
public:
	SegmentDisplay(DispIO & _disp_io);

	void write_segment(byte * data, size_t n);
	void write(char * data);
	void clear();
	void refresh();
	void csr();
	void csl();
};

template<size_t N>
SegmentDisplay<N>::SegmentDisplay(DispIO & _disp_io):
	disp_io(_disp_io)
{
	for (size_t i = 0; i < N; i++)
	{
		segments[i] = Segment();
	}
	disp_io.clear();
}

template<size_t N>
void SegmentDisplay<N>::write_to_display()
{
	byte buffer[N];
	for (size_t i = 0; i < N; i++)
	{
		buffer[i] = segments[i].get_byte();
	}
	disp_io.serial_write_load(buffer, N);
}

template<size_t N>
void SegmentDisplay<N>::write_segment(byte * data, size_t n)
{
	if (!data) return;
	size_t i;

	for (i = 0; i < n && i < N; i++)
	{
		segments[i] = Segment(data[i]);
	}

	for (; i < N; i++)
	{
		segments[i] = Segment();
	}

	write_to_display();
}

template<size_t N>
void SegmentDisplay<N>::write(char * data)
{
	if (!data) return;
	size_t i;

	for (i = 0; i < N && data[i]; i++)
	{
		segments[i] = CharSegment(data[i]);
	}

	for (; i < N; i++)
	{
		segments[i] = Segment();
	}

	write_to_display();
}

template<size_t N>
void SegmentDisplay<N>::clear()
{
	for (size_t i = 0; i < N; i++)
	{
		segments[i] = Segment();
	}

	disp_io.clear();
}

template<size_t N>
void SegmentDisplay<N>::refresh()
{
	write_to_display();
}

template<size_t N>
void SegmentDisplay<N>::csl()
{
	if (!N) return;

	Segment temp = segments[0];

	for (size_t i = 0; i < N - 1; i++)
	{
		segments[i] = segments[i+1];
	}

	segments[N-1] = temp;

	write_to_display();
}

template<size_t N>
void SegmentDisplay<N>::csr()
{
	if (!N) return;

	Segment temp = segments[N-1];

	for (size_t i = N-1; i != 0; i++)
	{
		segments[i] = segments[i-1];
	}
	segments[0] = temp;

	write_to_display();
}
