#include <ncurses.h>
#include <fstream>
#include <stdlib.h>
#include <vector>
#include <string>
#include "Color.h"
#include "Screen.h"
#include "Rectangle.h"
#include "Coordinate.h"

int main(){
	Screen screen;
	int centerX = screen.getColumns()/2;
	int centerY = screen.getRows()/2;
	ifstream infile; 
	string filename = "../files/1.txt";
	infile.open(filename);
	if(!infile.is_open()){
		printw("ERROR: Unable to open file");
		screen.~Screen();
		exit(EXIT_FAILURE);
	}
	int LENGTH = 10;
	int WIDTH = 21;
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

	int mode = 'h';
	int pairNum = 1;
	bool running = true;
	while(running){
		while(!screen.kbhit()){
			infile >> color.r >> color.g >> color.b; 
			//File has reached end of file. So random numbers are read which are thrown away
			if(color.r > 255 || color.b > 255 || color.b > 255){
				//infile.seekg(0) won't work as intended. So file pointer is reset by closing
				// and repopening the file <-- BAD IDEA
				infile.close(); 
				infile.open(filename);
				infile >> color.r >> color.g >> color.b; 
			}
			color.convert();
			//Notice pair num acts as a color identifier.
			//Ex. COLOR_WHITE = 7 Pair = 7. Intended.
			init_color(pairNum,  color.r, color.g, color.b);	
			switch(mode){
				//Top to bottom
				case 'j':
				case 'J': 
					for(int i=0; i<LENGTH; i++){
						for(int j=0; j<WIDTH; j++){
							rectangle[i][j].print(screen, coordinate[i][j], pairNum);
						}napms(50);
					}break;
				//Bottom to Top
				case 'k':
				case 'K':
					for(int i=LENGTH-1; i>=0; i--){
						for(int j=WIDTH-1; j>=0; j--){
							rectangle[i][j].print(screen, coordinate[i][j], pairNum);
						}napms(50);
					}break;	
				//Left to Right
				case 'l':
				case 'L':
					for(int j=0; j<WIDTH; j++){
						for(int i=0; i<LENGTH; i++){
							rectangle[i][j].print(screen, coordinate[i][j], pairNum);
						}napms(25);
					}break;	
				//Right to Left
				case 'h':
				case 'H':
					for(int j=WIDTH-1; j>=0; j--){
						for(int i=LENGTH-1; i>=0; i--){
							rectangle[i][j].print(screen, coordinate[i][j], pairNum);
						}napms(25);
					}break;	
				case 'a':
				case 'A':
					for(int i=0, j=0; i<LENGTH; i++, j+=2){
						rectangle[i][j].print(screen, coordinate[i][j], pairNum);
						napms(25);
					}
					for(int i=0, j=WIDTH-1; i<LENGTH; i++, j-=2){
						rectangle[i][j].print(screen, coordinate[i][j], pairNum);
						napms(25);
					}
					break;
				//Front to back	
				default:	
					for(int i=0; i<LENGTH; i++){
						for(int j=0; j<WIDTH; j++){
							rectangle[i][j].print(screen, coordinate[i][j], pairNum);
						}
					}napms(200); break;

			}if(pairNum >= 7) pairNum=1; else pairNum++; 
		}
		mode = getch();
		if(mode == 'x' || mode == 'X')
			running = false;
	}
	return 0;
}
