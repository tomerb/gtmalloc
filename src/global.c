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

/*
** The following singleton contains the global configuration for
** the SQLite library.
*/
struct Sqlite3Config sqlite3Config = {
   SQLITE_DEFAULT_MEMSTATUS,  /* bMemstat 
   {0,0,0,0,0,0,0,0},         /* m */
   (void*)0,                  /* pHeap */
   0,                         /* nHeap */
   0, 0,                      /* mnHeap, mxHeap */
};

