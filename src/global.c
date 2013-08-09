/*
** 2008 June 13
**
** The author disclaims copyright to this source code.  In place of
** a legal notice, here is a blessing:
**
**    May you do good and not evil.
**    May you find forgiveness for yourself and forgive others.
**    May you share freely, never taking more than you give.
**
*************************************************************************
**
** This file contains definitions of global variables and contants.
*/
#include "sqliteInt.h"

#ifndef SQLITE_USE_URI
# define  SQLITE_USE_URI 0
#endif

#ifndef SQLITE_ALLOW_COVERING_INDEX_SCAN
# define SQLITE_ALLOW_COVERING_INDEX_SCAN 1
#endif

/*
** The following singleton contains the global configuration for
** the SQLite library.
*/
SQLITE_WSD struct Sqlite3Config sqlite3Config = {
   SQLITE_DEFAULT_MEMSTATUS,  /* bMemstat */
   1,                         /* bCoreMutex */
   SQLITE_THREADSAFE==1,      /* bFullMutex */
   SQLITE_USE_URI,            /* bOpenUri */
   SQLITE_ALLOW_COVERING_INDEX_SCAN,   /* bUseCis */
   0x7ffffffe,                /* mxStrlen */
   128,                       /* szLookaside */
   500,                       /* nLookaside */
   {0,0,0,0,0,0,0,0},         /* m */
   {0,0,0,0,0,0,0,0,0},       /* mutex */
   {0,0,0,0,0,0,0,0,0,0,0,0,0},/* pcache2 */
   (void*)0,                  /* pHeap */
   0,                         /* nHeap */
   0, 0,                      /* mnHeap, mxHeap */
   SQLITE_DEFAULT_MMAP_SIZE,  /* szMmap */
   SQLITE_MAX_MMAP_SIZE,      /* mxMmap */
   (void*)0,                  /* pScratch */
   0,                         /* szScratch */
   0,                         /* nScratch */
   (void*)0,                  /* pPage */
   0,                         /* szPage */
   0,                         /* nPage */
   0,                         /* mxParserStack */
   0,                         /* sharedCacheEnabled */
   /* All the rest should always be initialized to zero */
   0,                         /* isInit */
   0,                         /* inProgress */
   0,                         /* isMutexInit */
   0,                         /* isMallocInit */
   0,                         /* isPCacheInit */
   0,                         /* pInitMutex */
   0,                         /* nRefInitMutex */
   0,                         /* xLog */
   0,                         /* pLogArg */
   0,                         /* bLocaltimeFault */
#ifdef SQLITE_ENABLE_SQLLOG
   0,                         /* xSqllog */
   0                          /* pSqllogArg */
#endif
};


/*
** Hash table for global functions - functions common to all
** database connections.  After initialization, this table is
** read-only.
*/
SQLITE_WSD FuncDefHash sqlite3GlobalFunctions;

/*
** Constant tokens for values 0 and 1.
*/
const Token sqlite3IntTokens[] = {
   { "0", 1 },
   { "1", 1 }
};


/*
** The value of the "pending" byte must be 0x40000000 (1 byte past the
** 1-gibabyte boundary) in a compatible database.  SQLite never uses
** the database page that contains the pending byte.  It never attempts
** to read or write that page.  The pending byte page is set assign
** for use by the VFS layers as space for managing file locks.
**
** During testing, it is often desirable to move the pending byte to
** a different position in the file.  This allows code that has to
** deal with the pending byte to run on files that are much smaller
** than 1 GiB.  The sqlite3_test_control() interface can be used to
** move the pending byte.
**
** IMPORTANT:  Changing the pending byte to any value other than
** 0x40000000 results in an incompatible database file format!
** Changing the pending byte during operating results in undefined
** and dileterious behavior.
*/
#ifndef SQLITE_OMIT_WSD
int sqlite3PendingByte = 0x40000000;
#endif

//#include "opcodes.h"
/*
** Properties of opcodes.  The OPFLG_INITIALIZER macro is
** created by mkopcodeh.awk during compilation.  Data is obtained
** from the comments following the "case OP_xxxx:" statements in
** the vdbe.c file.  
*/
//const unsigned char sqlite3OpcodeProperty[] = OPFLG_INITIALIZER;
