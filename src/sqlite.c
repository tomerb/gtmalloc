

#ifdef _HAVE_SQLITE_CONFIG_H
#include "config.h"
#endif

#include "sqliteInt.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stddef.h>


#ifndef SQLITE_MAX_LENGTH
# define SQLITE_MAX_LENGTH 1000000000
#endif


#define SQLITE_CORE 1
#define SQLITE_AMALGAMATION 1
#ifndef SQLITE_PRIVATE
# define SQLITE_PRIVATE static
#endif
#ifndef SQLITE_API
# define SQLITE_API
#endif


SQLITE_API int sqlite3_initialize(void){

	return -1;
}


int sqlite3StatusValue(int s){
	return -1;
}

void sqlite3StatusAdd(int s, int n){
}

void sqlite3StatusSet(int s, int n){
}

SQLITE_API int sqlite3_status(int op, int *pCurrent, int *pHighwater, int resetFlag){
	return -1;
}


/*
** This API allows applications to modify the global configuration of
** the SQLite library at run-time.
**
** This routine should only be called when there are no outstanding
** database connections or memory allocations.  This routine is not
** threadsafe.  Failure to heed these warnings can lead to unpredictable
** behavior.
*/
SQLITE_API int sqlite3_config(int op, ...){
  return -1;
}

SQLITE_API void sqlite3ValueSetStr(
	sqlite3_value *v,     /* Value to be set */
	int n,                /* Length of string z */
	const void *z,        /* Text of the new string */
	u8 enc,               /* Encoding to use */
	void (*xDel)(void*)   /* Destructor for the string */
	){
		
}