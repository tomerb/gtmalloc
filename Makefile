CC = gcc

OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -g -DSQLITE_ENABLE_MEMSYS5 -DSQLITE_OS_UNIX=1

SRC = src/global.c src/hash.c src/pcache.c src/unix/os_unix.c src/mutex.c src/mutex_noop.c src/unix/mutex_unix.c src/malloc.c src/mem0.c src/mem1.c src/mem2.c src/mem5.c src/main.c src/status.c src/util.c src/printf.c src/os.c src/btree.c src/pager.c src/vdbeaux.c src/btmutex.c src/callback.c src/random.c src/pcache.c src/pcache1.c src/fault.c src/build.c src/expr.c src/insert.c src/update.c src/trigger.c src/fkey.c src/auth.c src/vtab.c src/where.c src/resolve.c src/walker.c src/select.c src/prepare.c src/utf.c src/vdbemem.c src/vdbe.c src/vdbetrace.c src/rowset.c src/vacuum.c src/vdbeapi.c src/vdbesort.c src/analyze.c src/backup.c src/tokenize.c src/parse.c src/alter.c src/attach.c src/pragma.c src/func.c src/date.c src/delete.c src/wal.c src/bitvec.c src/memjournal.c src/loadext.c src/vdbeblob.c src/complete.c src/legacy.c src/table.c src/ctime.c src/opcodes.c

LIB = libgtmalloc.a

INCLUDES = -Iinclude -Iinclude/unix

all: $(OBJ)
	ar rcs $(LIB) $(OBJ)

.c.o:
	$(CC) $(INCLUDES) $(CFLAGS) -c $< -o $@

clean:
	rm -rf src/$(OBJ) $(LIB)
