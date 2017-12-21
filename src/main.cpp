#include <ncurses.h>
#include "Color.h"
#include "Screen.h"
void print(int num){
	attron(COLOR_PAIR(num));
	mvprintw(0,0, "     ");
	mvprintw(1,0, "     ");
	attroff(COLOR_PAIR(num));
	refresh();
	napms(1);
}
int main(){
	//init_pair(1, COLOR_WHITE, COLOR_WHITE);
	//for(int i=0; i<1000; i++){
	//	init_color(COLOR_WHITE, i, i, i);
//		print(1);
//	}
	Screen screen;
	printw("ROW:%d\tCOL:%d", screen.getRows(),screen.getColumns());	
	return 0;
}


