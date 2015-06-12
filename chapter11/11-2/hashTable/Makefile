TARGET=hashTest
SRCS=main.cc\
	 hash_table_test.cc
OBJS=$(SRCS:.cc=.o)
LIBS=-lcppunit
INCS=-I./
CC=g++

$(TARGET):$(OBJS)
	$(CC) $^ -g $(LIBS) $(INCS) -o $@

%.o:%.cc %.h
	$(CC) $< -g -c $(LIBS) $(INCS) -o $@

.PHONY:clean

clean:
	-rm -f -r *.o
