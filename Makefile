CFLAGS = -Wall -g 
CC = g++
MAIN=generator
VER=verifier
ALT=alter
SRCS=main.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(MAIN) $(VER) $(ALT)

$(MAIN): generator.o
	$(CC) generator.o -o $(MAIN) 

$(VER): verifier.o
	$(CC) verifier.o -o $(VER) 

$(ALT):alter.o
	$(CC) alter.o -o $(ALT)

.cpp.o:
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f *.o $(MAIN)