all: compile link

compile: 
	g++ -c Source/*.cpp -I"C:\msys64\SFML-2.5.1\include"

link:
	g++ *.o -o game -L"C:\msys64\SFML-2.5.1\lib" -lsfml-graphics -lsfml-window -lsfml-system

