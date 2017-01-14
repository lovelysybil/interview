all: DeleteNode ReOrderEvenOdd ConvertList FindTailKNode MergeList HasSubTree MirrorTree ConvertToDlist FindPath Permutation DeleteDuplication

DeleteNode: 13.o list.o
	g++ -Wall 13.o list.o -o DeleteNode

FindTailKNode: 15.o list.o
	g++ -Wall 15.o list.o -o FindTailKNode

ConvertList: 16.o list.o
	g++ -Wall 16.o list.o -o ConvertList

MergeList: 17.o list.o
	g++ -Wall 17.o list.o -o MergeList

DeleteDuplication: 57.o list.o
	g++ -Wall 57.o list.o -o DeleteDuplication

HasSubTree: 18.o binaryTree.o
	g++ -Wall 18.o binaryTree.o -o HasSubTree

MirrorTree: 19.o binaryTree.o
	g++ -Wall 19.o binaryTree.o -o MirrorTree

FindPath: 25.o binaryTree.o
	g++ -Wall 25.o binaryTree.o -o FindPath

ConvertToDlist: 27.o binaryTree.o
	g++ -Wall 27.o binaryTree.o -o ConvertToDlist

list.o: list.cpp
	g++ -c -Wall list.cpp

binaryTree.o: binaryTree.cpp
	g++ -c -Wall binaryTree.cpp

ReOrderEvenOdd: 14.cpp
	g++ -Wall 14.cpp -o ReOrderEvenOdd

Permutation: 28.cpp
	g++ -Wall 28.cpp -o Permutation

clean:
	rm -rf *.o a.out DeleteNode ReOrderEvenOdd ConvertList FindTailKNode MergeList HasSubTree MirrorTree ConvertToDlist FindPath Permutation DeleteDuplication
