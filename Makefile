CC = g++
CFLAGS = -g -Wall
LIBS = -lGL -lGLU -lglut
SRC = engine.cpp tetris.cpp main.cpp
OUTPUT = tetris

all:$(SRC)
	$(CC) -o $(OUTPUT) $(SRC) $(CFLAGS) $(LIBS)


