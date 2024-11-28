TARGET = enseash

CC = GCC 

SRCS = $(wildcard *.c)
OBJ = $(SRCS:.c=.o)
BIN = $(patsubst %.c,%,$(SRC))

CFLAGS += -Werror -Wall -Wextra -g
#CFLAGS += --std=c99

#all: $(BIN)
all: $(TARGET)

$(TARGET):$(OBJ)
	cc $(CFLAGS) -o $@ $^

%.o: %.c
	cc $(CFLAGS) -c $< -o $@

clean:
	rm -f $(BIN)
	rm -f *.o
	rm -f *~

indent:
	indent -linux -i4 -nut -ts2 *.c

.PHONY: all clean indent
