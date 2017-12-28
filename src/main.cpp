#include <ncurses.h>
#include <fstream>
#include <stdlib.h>
#include <vector>
#include "Color.h"
#include "Screen.h"
#include "Rectangle.h"
#include "Coordinate.h"

int main(){
	Screen screen;
	int centerX = screen.getColumns()/2;
	int centerY = screen.getRows()/2;
	ifstream infile; 
	infile.open("../files/3.txt");
	if(!infile.is_open()){
		printw("ERROR: Unable to open file");
		screen.~Screen();
		exit(EXIT_FAILURE);
	}
	int LENGTH = 8;
	int WIDTH = 16;
	vector< vector<Rectangle> > rectangle;
	vector< vector<Coordinate> > coordinate;
	for(int i=0; i<LENGTH; i++){
		vector<Rectangle> R_row;
		vector<Coordinate> C_row;
		for(int j=0; j<WIDTH; j++){
			R_row.push_back(*(new Rectangle(1,1)));
			C_row.push_back(*(new Coordinate(centerY-LENGTH/2+i, centerX-WIDTH/2+j)));
		}
		rectangle.push_back(R_row);
		coordinate.push_back(C_row);
	}
	
	Color color;	
	init_pair(1, COLOR_RED, COLOR_RED);
	init_pair(2, COLOR_GREEN, COLOR_GREEN);
	init_pair(3, COLOR_YELLOW, COLOR_YELLOW);
	init_pair(4, COLOR_BLUE,  COLOR_BLUE);
	init_pair(5, COLOR_MAGENTA, COLOR_MAGENTA);
	init_pair(6, COLOR_CYAN,  COLOR_CYAN);
	init_pair(7, COLOR_WHITE, COLOR_WHITE);	

	int mode = 49;
	int pairNum = 1;
	bool running = true;
	while(running){
		while(!screen.kbhit()){
			//infile.seekg(0) won't work as intended. So file pointer is reset by closing
			// and repopening the file
			if(infile.eof()) {
				infile.close(); 
				infile.open("../files/3.txt");
			}
			infile >> color.r >> color.g >> color.b;
			color.convert();
			init_color(pairNum,  color.r, color.g, color.b);	

			switch(mode){
				case 49: 
					for(int i=0; i<LENGTH; i++){
						for(int j=0; j<WIDTH; j++){
							rectangle[i][j].print(screen, coordinate[i][j], pairNum);
						}napms(100);
					}break;
				case 50:
					for(int i=LENGTH-1; i>=0; i--){
						for(int j=WIDTH-1; j>=0; j--){
							rectangle[i][j].print(screen, coordinate[i][j], pairNum);
						}napms(100);
					}break;	
				default:	
					for(int i=0; i<LENGTH; i++){
						for(int j=0; j<WIDTH; j++){
							rectangle[i][j].print(screen, coordinate[i][j], pairNum);
						}
					}napms(100); break;

			}
			if(pairNum >= 7) pairNum=1; else pairNum++; 
		}

		mode = getch();
		if(mode == 'x' || mode == 'X')
			running = false;
	}
	

/*
	
	for(int i=0; i<length; i++){
		for(int j=0; j<width; j++){
			coordinate[i][j].setX(centerX-5+j);
			coordinate[i][j].setY(centerY-2+i);
		}
	}
	Color color;
	int pairNum = 0;
		
	
	int mode = 49;
	while(mode != 'X' && mode != 'x'){	
		while(!screen.kbhit()){
			switch(mode){
				case 49:
					for(int i=0; i<length; i++){
						infile >> color.r >> color.g >> color.b; color.convert(); 
						init_color(i, color.r, color.g, color.b);
						for(int j=0; j<width; j++){
							rectangle[i][j].print(screen, coordinate[i][j], pairNum); 
						} 
					 	pairNum++; napms(500);
					}
					pairNum = 0; infile.close(); infile.open("../files/3.txt");
					for(int i=length-1; i>=0; i--){
						infile >> color.r >> color.g >> color.b; color.convert();
						init_color(i, color.r, color.g, color.b);
						for(int j=width-1; j>=0; j--){
							rectangle[i][j].print(screen, coordinate[i][j], pairNum); 
						} 
					 	pairNum++; napms(500);
					}

							


					break; 
				case 50: break;
				default: break;
			}
		}
		mode = getch();
	}

*/





/*
	Color colors[6];
	int mode;
	int i=0;	
	infile >> mode;
	while(!infile.eof() && i<6){
		infile >> colors[i].r; 
		infile >> colors[i].g;
		infile >> colors[i].b;
		colors[i].convert();
		i++;
	}
	
	Coordinate center(screen.getRows()/2, screen.getColumns()/2);
	Rectangle r1(4, 10);Coordinate cr1(center.getY()-r1.getLength()/2, center.getX()-r1.getWidth()/2);
	
	init_pair(2, COLOR_BLACK, COLOR_BLACK);
	int choice=1;
	while(!screen.kbhit()){
		switch(choice){
			case 1: {
				if(i >= 6) choice = 2;
				else i++;
			} break;
			
			case 2: {
				if(i <=0) choice = 1;
				else i--;
			} break;	
		}
		init_color(COLOR_BLACK, colors[i].r, colors[i].g, colors[i].b);
		r1.print(screen, cr1, 2);
		napms(100);
	}
*/

/*
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
*/	
	return 0;
}

