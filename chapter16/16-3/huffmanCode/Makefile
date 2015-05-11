TARGET=huffman

OBJS=priorityQueue.o\
	 main.o\
	 treeNode.o\
	 huffmanCode.o

SRCS=$(OBJS:.o=.cc)

$(TARGET):$(OBJS)
	g++ $^ -o $@

%.o:%.cc %.h
	g++ -c $< -o $@
