main:treeArray.o main.o reversePair.o
	gcc treeArray.o main.o reversePair.o -o main.exe

treeArray.o:treeArray.h
main.o:treeArray.h reversePair.h
reversePair.o:reversePair.h

.PHONY:clean

clean:
	rm -f *.o *.exe