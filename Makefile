all: DeleteNode ReOrderEvenOdd ConvertList FindTailKNode

DeleteNode: 13.o list.o
	g++ -Wall 13.o list.o -o DeleteNode

FindTailKNode: 15.o list.o
	g++ -Wall 15.o list.o -o FindTailKNode

ConvertList: 16.o list.o
	g++ -Wall 16.o list.o -o ConvertList

13.o: 13.cpp
	g++ -c -Wall 13.cpp

list.o: list.cpp
	g++ -c -Wall list.cpp

ReOrderEvenOdd: 14.cpp
	g++ -Wall 14.cpp -o ReOrderEvenOdd

clean:
	rm -rf *.o a.out DeleteNode ReOrderEvenOdd ConvertList FindTailKNode 
