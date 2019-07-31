CC = g++
AR = ar
LIB = libeBMP
ARFLAGS = -crv
FLAGS = -Wfatal-errors -std=c++11

SRC = $(wildcard *.cpp)

lib:
	$(CC) -c $(filter-out main.cpp, $(SRC))
	$(AR) $(ARFLAGS) $(LIB) $(wildcard *.o)
