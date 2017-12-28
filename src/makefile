TARGET = color 
CXXFLAGS = -Wall -std=C++11 -Wc++11-extensions -lncurses
CC = g++

OBJFILES = main.o Color.o Screen.o Coordinate.o Shape.o Rectangle.o

$(TARGET): $(OBJFILES)
	$(CC) -o $(TARGET) $(CXXFLAGS) $(OBJFILES)

main.o: main.cpp
	$(CC) -c main.cpp
Color.o: Color.cpp Color.h
	$(CC) -c Color.cpp
Screen.o: Screen.h Screen.cpp
	$(CC) -c Screen.cpp
Coordinate.o: Coordinate.cpp Coordinate.h
	$(CC) -c Coordinate.cpp
Shape.o: Shape.cpp Shape.h
	$(CC) -c Shape.cpp
Rectangle.o: Rectangle.cpp Rectangle.h
	$(CC) -c Rectangle.cpp 

.PHONY: clean
clean:
	rm $(OBJFILES) $(TARGET)
