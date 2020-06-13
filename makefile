all: main

CC = g++
CFLAGS = -g -w -Wall

main: main.o BitStream.o FrequencyCounter.o HuffmanTree.o
	$(CC) $(CFLAGS) -o main main.o BitStream.o FrequencyCounter.o HuffmanTree.o

BitStream.o: BitStream.cpp BitStream.hpp
	g++ -c BitStream.cpp

FrequencyCounter.o: FrequencyCounter.cpp FrequencyCounter.hpp
	g++ -c FrequencyCounter.cpp

HuffmansTree.o: HuffmanTree.cpp HuffmanTree.hpp
	g++ -c HuffmanTree.cpp


# BitStream.o: BitStream.hpp BitStream.cpp
# 	$(CC) $(CFLAGS) -c BitStream.cpp

clean:
	rm -f core *.o main