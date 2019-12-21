.PHONY: all docs

#global const's
TARGETS=test animation
GCC=gcc
#global var's
UNAME=$(shell uname)
ifeq ($(UNAME),Darwin)
#Mac OS
GCCKEYS=-L/System/Library/Frameworks -framework GLUT -framework OpenGL -std=c99
else
#Linux
GCCKEYS=-D LINUX -lglut -lGL -lm
endif
#procedures
all: animation
	#./test
	./animation
docs: README.html


#main
%: %.c
	$(GCC) $< $(GCCKEYS) -o $@
%: %.cpp
	$(GCC) $< $(GCCKEYS) -o $@
