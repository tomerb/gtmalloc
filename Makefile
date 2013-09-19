CC = gcc

OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -g

SRC = src/global.c src/hash.c src/btree.c src/pcache.c src/unit/os_unix.c src/mutex.c src/mutex_noop.c src/unit/mutex_unix.c src/malloc.c src/mem0.c src/mem1.c src/mem2.c src/mem3.c src/mem5.c src/printf.c src/sqlite.c src/util.c

LIB = libgtmalloc.a

INCLUDES = -Iinclude -Iinclude/unix

all: $(OBJ)
	ar rcs $(LIB) $(OBJ)

.c.o:
	$(CC) $(INCLUDES) $(CFLAGS) -c $< -o $@

clean:
	rm -rf src/$(OBJ) $(LIB)
