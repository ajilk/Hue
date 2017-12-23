#ifndef SHAPE_H
#define SHAPE_H

#include <ncurses.h>
#include <vector>
#include "Screen.h"
#include "Coordinate.h"

class Shape{
protected:
	int size;
	std::vector<Coordinate> shape;
public: 
	void print(Screen& screen, Coordinate leftCorner, int pairNumber);
};

#endif
