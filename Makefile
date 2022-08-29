CC = gcc
CXX = g++
INCLUDE =
FILES = main.cpp
CFLAGS = -O2 -Wall
CLIBS = -lglfw -lGL -lGLEW

all:
	${CXX} ${CFLAGS} ${CLIBS} ${INCLUDE} ${FILES} -o main