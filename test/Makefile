CC = gcc

OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Werror -g

SRC = simple.c

LIBS = -L../src -lgtmalloc -lpthread

INCLUDES = -I. -I../src

APP = simple_test

all: $(OBJ)

.c.o:
	$(CC) $(INCLUDES) $(CFLAGS) $< -o $(APP) $(LIBS)

clean:
	rm -rf $(OBJ) $(APP)
