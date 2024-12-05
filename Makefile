LowestCommonAncestor: LowestCommonAncestor.o
	g++ -g -o LowestCommonAncestor.exe LowestCommonAncestor.o -pthread    

LowestCommonAncestor.o: LowestCommonAncestor/LowestCommonAncestor.cpp
	g++ -g  -c -pthread LowestCommonAncestor/LowestCommonAncestor.cpp
