CC = g++
CFLAGS = -W -Wall -g
LDFLAGS = -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

SRC = $(wildcard src/*.cpp)
OBJS = $(SRC:.cpp=.o)
HEADER = $(SRC:.cpp=.hpp)
 
all : sortman clean

sortman : $(OBJS)
	$(CC) -o $@ $^ $(LDFLAGS)

%.o : %.c
	$(CC) -o $@ -c $< $(CFLAGS)

clean:
	rm src/*.o