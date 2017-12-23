#include <ncurses.h>
#include <fstream>
#include "Color.h"
#include "Screen.h"
#include "Rectangle.h"
#include "Coordinate.h"

int main(){
	Screen screen;
	Coordinate center(screen.getRows()/2, screen.getColumns()/2);

	Rectangle r1(1,11); Coordinate cr1(center.getY(), center.getX()-r1.getWidth()/2);
	Rectangle r2(1,11); Coordinate cr2(center.getY()+1, center.getX()-r2.getWidth()/2);
	Rectangle r3(1,11); Coordinate cr3(center.getY()+2, center.getX()-r3.getWidth()/2);	
	Rectangle r4(1,11); Coordinate cr4(center.getY()+3, center.getX()-r4.getWidth()/2);

	init_pair(1, COLOR_WHITE, COLOR_WHITE);
	init_pair(2, COLOR_BLUE, COLOR_BLUE);
	init_pair(3, COLOR_RED, COLOR_RED);
	init_pair(4, COLOR_YELLOW, COLOR_YELLOW);

	int choice=1;
	while(!screen.kbhit()){
		switch(choice){
			case 1: {
				for(int i=20; i<1000; i++){
					napms(1);	
					init_color(COLOR_WHITE, i,i,i);
					init_color(COLOR_BLUE, i-20, i-20, i-20);
					init_color(COLOR_RED, i-40, i-40, i-40);
					init_color(COLOR_YELLOW, i-60, i-60, i-60);
	
					r1.print(screen, cr1, 1);
					r2.print(screen, cr2, 2);
					r3.print(screen, cr3, 3);
					r4.print(screen, cr4, 4);
	 			}
			} choice=2; break; 
		
			case 2: {
				for(int i=1000; i>20; i--){
					napms(1);	
	  				init_color(COLOR_WHITE, i,i,i);
					init_color(COLOR_BLUE, i-20, i-20, i-20);
					init_color(COLOR_RED, i-40, i-40, i-40);
					init_color(COLOR_YELLOW, i-60, i-60, i-60);
				
					r1.print(screen, cr1, 4);
					r2.print(screen, cr2, 3);
					r3.print(screen, cr3, 2);
					r4.print(screen, cr4, 1);
	 			}
			} choice=1; break;
		}
	}
	
	return 0;
}

