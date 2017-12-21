#include "Screen.h"

Screen::Screen(){
	initscr();
	getmaxyx(stdscr, rows, columns);
	curs_set(0);
	cbreak();
	noecho();
	if(!has_colors()){
		clear();
		mvprintw(0,0,"ERROR: TERMINAL DOES NOT SUPPORT COLOR");
		refresh();
		getch();
		endwin();
		//exit (EXIT_FAILURE);
	}else if(!can_change_color()){
		clear();
		mvprintw(0,0,"ERROR: TERMINAL CAN NOT CHANGE COLOR");
		refresh();
		getch();
		endwin();
		//exit (EXIT_FAILURE);	
	}else
		start_color();
	nodelay(stdscr, TRUE);	
}

int Screen::getRows(){
	return rows;
}

int Screen::getColumns(){
	return columns;
}

Screen::~Screen(){
	refresh();
	nodelay(stdscr, FALSE);
	getch();
	endwin();
}
