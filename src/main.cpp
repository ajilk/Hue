#include <ncurses.h>
#include <string>
void setup(){
	initscr();
	curs_set(0);
	noecho();
	if(!has_colors()){
		clear();
		mvprintw(0,0,"ERROR: TERMINAL DOES NOT SUPPORT COLOR");
		refresh();
		getch();
		endwin();
		exit (EXIT_FAILURE);
	}else if(!can_change_color()){
		clear();
		mvprintw(0,0,"ERROR: TERMINAL CAN NOT CHANGE COLOR");
		refresh();
		getch();
		endwin();
		exit (EXIT_FAILURE);	
	}else
		start_color();		
}
struct color{
	std::string hex;
	short r;
	short g;
	short b;
};

void print(int num){
	getmaxyx(stdscr, Y, X);
	attron(COLOR_PAIR(num));
	mvprintw(0,0, "     ");
	mvprintw(1,0, "     ");
	attroff(COLOR_PAIR(num));
	refresh();
	napms(1);
}
int main(){
	setup();	
	color c1; 
	c1.hex="#455e7a";
	c1.r=950; c1.g=654; c1.b=754;
	init_pair(1, COLOR_WHITE, COLOR_WHITE);
	
	for(int i=0; i<1000; i++){
		init_color(COLOR_WHITE, i, i, i);
		print(1);
	}
	refresh();
	getch();
	endwin();
	return 0;
}


