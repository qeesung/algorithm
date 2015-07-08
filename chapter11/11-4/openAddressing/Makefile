TARGET=testOpenAddressing
SRCS=./open_addressing_test.cc\
	 ./main.cc
OBJS=$(SRCS:.cc=.o)
LIBS=-lcppunit
INCS=-I./
CC=g++

$(TARGET):$(OBJS)
		$(CC) $^ $(INCS) $(LIBS) -g -o $@

%.o:%.cc %.h
		$(CC) -g -c $< $(INCS) $(LIBS) -o $@

.PHONY:clean

clean:
		-rm -f *.o
