all: get_line

clean:
	rm -f get_line main.o line.o

get_line: main.o line.o
	c++ -o get_line main.o line.o

main.o: main.cpp line.h
	c++ -c main.cpp

line.o: line.cpp line.h
	c++ -c line.cpp
