CC = gcc

OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -g -DSQLITE_ENABLE_MEMSYS5

SRC = src/global.c src/hash.c src/pcache.c src/unix/os_unix.c src/mutex.c src/mutex_noop.c src/unix/mutex_unix.c src/malloc.c src/mem0.c src/mem1.c src/mem2.c src/mem5.c src/sqlite.c

LIB = libgtmalloc.a

INCLUDES = -Iinclude -Iinclude/unix

all: $(OBJ)
	ar rcs $(LIB) $(OBJ)

.c.o:
	$(CC) $(INCLUDES) $(CFLAGS) -c $< -o $@

clean:
	rm -rf src/$(OBJ) $(LIB)
