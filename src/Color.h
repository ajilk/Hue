#ifndef COLOR_H
#define COLOR_H

#include <string>
using namespace std;

class Color{
public:
	short r;
	short g;
	short b;
	Color() { r=0; g=0; b=0; }	
	Color(short r, short g, short b) : r(r), g(g), b(b) {}
	void convert() {
		r *= 3.9015;
		g *= 3.9015;
		b *= 3.9015;
	}
};

#endif
