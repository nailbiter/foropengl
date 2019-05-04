.PHONY: all Debug debug

#global const's
TARGETS=test
GCCKEYS=-L/System/Library/Frameworks -framework GLUT -framework OpenGL
GCC=gcc
#global var's

all: Debug
Debug: debug
debug: $(TARGETS)
	./test

%: %.cpp
	$(GCC) -o $@ $< $(GCCKEYS)
