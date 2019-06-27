CC = g++
CFLAGS = -std=c11

output: buffer.o main.o
	$(CC) main.o buffer.o -o buf

main.o: main.cpp
	$(CC) -c -g  main.cpp

buffer.o: buffer.cpp buffer.h
	$(CC) -c -g buffer.cpp

clear:
	rm -f *.o output