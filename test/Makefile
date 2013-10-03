CC = gcc

OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Werror -g

SRC = simple.c

LIBS = -L.. -lgtmalloc -lpthread -ldl

INCLUDES = -I. -I../include -I../include/unix

APP = simple_test

all: $(OBJ)

.c.o:
	$(CC) $(INCLUDES) $(CFLAGS) $< -o $(APP) $(LIBS)

clean:
	rm -rf $(OBJ) $(APP)
