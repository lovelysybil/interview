all: DeleteNode

DeleteNode: 13.o list.o
	g++ -Wall 13.o list.o -o DeleteNode

13.o: 13.cpp
	g++ -c -Wall 13.cpp

list.o: list.cpp
	g++ -c -Wall list.cpp

clean:
	rm -rf *.o DeleteNode 
