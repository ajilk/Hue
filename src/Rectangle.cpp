#include "Rectangle.h"
Rectangle::Rectangle(){
	length=1; width=1;
	size = length*width;
	Coordinate coordinate; 
	int pos = 0;
	for(int i=0; i<length; i++){
		for(int j=0; j<width; j++){
			shape.push_back(coordinate);
			shape[pos].setY(i);
			shape[pos].setX(j);
			pos++;
		}
	}
}	

Rectangle::Rectangle(int length, int width) : length(length), width(width){
	size = length*width;
	Coordinate coordinate; 
	int pos = 0;
	for(int i=0; i<length; i++){
		for(int j=0; j<width; j++){
			shape.push_back(coordinate);
			shape[pos].setY(i);
			shape[pos].setX(j);
			pos++;
		}
	}

}
