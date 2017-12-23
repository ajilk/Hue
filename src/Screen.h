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
	bool kbhit();
	void drawChar(int Y, int X, char ch);
	~Screen();
};

#endif
