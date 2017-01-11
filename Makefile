all: DeleteNode ReOrderEvenOdd ConvertList FindTailKNode MergeList HasSubTree

DeleteNode: 13.o list.o
	g++ -Wall 13.o list.o -o DeleteNode

FindTailKNode: 15.o list.o
	g++ -Wall 15.o list.o -o FindTailKNode

ConvertList: 16.o list.o
	g++ -Wall 16.o list.o -o ConvertList

MergeList: 17.o list.o
	g++ -Wall 17.o list.o -o MergeList

HasSubTree: 18.o binaryTree.o
	g++ -Wall 18.o binaryTree.o -o HasSubTree

list.o: list.cpp
	g++ -c -Wall list.cpp

binaryTree.o: binaryTree.cpp
	g++ -c -Wall binaryTree.cpp

ReOrderEvenOdd: 14.cpp
	g++ -Wall 14.cpp -o ReOrderEvenOdd

clean:
	rm -rf *.o a.out DeleteNode ReOrderEvenOdd ConvertList FindTailKNode MergeList HasSubTree
