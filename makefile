all: compile link run

delete:
	del *.o

compile:
	g++ -c main.cpp src/class/*.cpp src/controller/*.cpp src/functions/*.cpp

link:
	g++ *.o -o main 

run:
	./main.exe
