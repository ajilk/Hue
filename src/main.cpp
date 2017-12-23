#include <ncurses.h>
#include <fstream>
#include "Color.h"
#include "Screen.h"
#include "Rectangle.h"
#include "Coordinate.h"

int main(){
	Screen screen;

	int X=screen.getColumns()/2;
	int Y=screen.getRows()/2;
	Coordinate center(Y, X);
	Rectangle rectangle(1,11);
	
	init_pair(1, COLOR_WHITE, COLOR_WHITE);
	init_pair(2, COLOR_BLUE, COLOR_BLUE);
	for(int i=0; i<1000; i++){
		init_color(COLOR_WHITE, i, i, i);
		rectangle.print(screen, *(new Coordinate(Y,X)), 1);
		napms(1);	
	}

	//printw("ROW:%d\tCOL:%d", screen.getRows(),screen.getColumns());	
	return 0;
}

