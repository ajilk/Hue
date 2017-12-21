#ifndef SCREEN_H
#define SCREEN_H

#include <ncurses.h>

class Screen{
private:
	int rows;
	int columns;
public:
	Screen();
	int getRows();
	int getColumns();
	~Screen();
};

#endif