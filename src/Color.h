#ifndef COLOR_H
#define COLOR_H

#include <string>
using namespace std;

class Color{
private:
	string hex;
	short r;
	short g;
	short b;	
public:
	Color(string hex, short r, short g, short b) : hex(hex), r(r), g(g), b(b) {}
};

#endif
