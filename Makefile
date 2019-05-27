.PHONY: all

#global const's
TARGETS=test animation
GCC=gcc
#global var's
UNAME=$(shell uname)
ifeq ($(UNAME),Darwin)
#Mac OS
GCCKEYS=-L/System/Library/Frameworks -framework GLUT -framework OpenGL
else
#Linux
GCCKEYS=-D LINUX -lglut -lGL -lm
endif
#procedures
all: animation
	#./test
	./animation


#main
%: %.cpp
	$(GCC) $< $(GCCKEYS) -o $@
