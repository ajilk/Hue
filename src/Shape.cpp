#include "Shape.h"

void Shape::print(Screen& screen, Coordinate leftCorner, int pairNumber){
	for(int i=0; i<size; i++){
		int Y = shape[i].getY()+leftCorner.getY();
		int X = shape[i].getX()+leftCorner.getX();
		attron(COLOR_PAIR(pairNumber));
		screen.drawChar(Y, X, ' ');
		attroff(COLOR_PAIR(pairNumber));	
	}
}
