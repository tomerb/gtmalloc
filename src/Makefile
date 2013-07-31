CC = gcc

OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Werror -g

SRC = global.c hash.c btree.c pcache.c os_unix.c mutex.c mutex_noop.c mutex_unix.c malloc.c mem0.c mem1.c mem2.c mem3.c mem5.c printf.c sqlite.c util.c

LIB = gtmalloc.a

INCLUDES = -I.

all: $(OBJ)
	ar rcs $(LIB) $(OBJ)

.c.o:
	$(CC) $(INCLUDES) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ) $(LIB)
