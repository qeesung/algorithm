TARGET=stack
SRCS=c_stack.c\
	c_stack_test.c\
	c_stack_int.c

OBJS=$(SRCS:.c=.o)

$(TARGET):$(OBJS)
	gcc $^ -g -o $@

$(OBJS):%.o:%.c %.h
	gcc -c $< -g -o $@
