
main: main.cpp
	g++ -o main main.cpp src/*.cpp src/glad.c -lglfw -I./include -L./lib


test: test.cpp
	g++ -o test test.cpp -lraylib -I./include -L./lib