CC = g++
CFLAGS = -g -w -Wall

main: main.o util.o
	$(CC) $(CFLAGS) -o main main.o util.o

util.o: util.hpp util.cpp
	$(CC) $(CFLAGS) -c util.cpp

# BitStream.o: BitStream.hpp BitStream.cpp
# 	$(CC) $(CFLAGS) -c BitStream.cpp

clean:
	rm -f core *.o main