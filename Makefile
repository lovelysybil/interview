all: DeleteNode ReOrderEvenOdd

DeleteNode: 13.o list.o
	g++ -Wall 13.o list.o -o DeleteNode

13.o: 13.cpp
	g++ -c -Wall 13.cpp

list.o: list.cpp
	g++ -c -Wall list.cpp

ReOrderEvenOdd: 14.cpp
	g++ -Wall 14.cpp -o ReOrderEvenOdd

clean:
	rm -rf *.o DeleteNode ReOrderEvenOdd a.out 
