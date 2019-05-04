.PHONY: all

all: test
	./$<

test: test.cpp
	#g++ $< -lglut -o $@
	gcc -o $@ $< -L/System/Library/Frameworks -framework GLUT -framework OpenGL
