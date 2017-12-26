#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Shape.h"

class Rectangle : public Shape{
private:
	int length;	//Vertical 
	int width;	//Horizontal
public:
	Rectangle();
	Rectangle(int length, int width);
	int getLength() { return length; } 
	int getWidth() { return width; }
};

#endif
