run:
	./testRange
testRange: test.o ranges.o
	g++ *.o -o testRange
test.o: test.cpp
	g++ -c test.cpp
ranges.o: ranges.cpp
	g++ -c -std=c++11 ranges.cpp
