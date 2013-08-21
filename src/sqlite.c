

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


void sqlite3_log(int iErrCode, const char *zFormat, ...){

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

void sqlite3_win32_sleep(long milliseconds){

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
	va_list ap;
	va_start(ap, op);
	switch (op)
	{
		case SQLITE_CONFIG_MALLOC: {
			/* Specify an alternative malloc implementation */
			sqlite3Config.m = *va_arg(ap, sqlite3_mem_methods*);
			break;
		}

		case SQLITE_CONFIG_MEMSTATUS: {
			/* Enable or disable the malloc status collection */
			sqlite3Config.bMemstat = va_arg(ap, int);
			break;
		}

		case SQLITE_CONFIG_HEAP: {
		  /* Designate a buffer for heap memory space */
		  sqlite3Config.pHeap = va_arg(ap, void*);
		  sqlite3Config.nHeap = va_arg(ap, int);
		  sqlite3Config.mnReq = va_arg(ap, int);

		  if( sqlite3Config.mnReq<1 ){
			sqlite3Config.mnReq = 1;
		  }else if( sqlite3Config.mnReq>(1<<12) ){
			/* cap min request size at 2^12 */
			sqlite3Config.mnReq = (1<<12);
		  }

		  if( sqlite3Config.pHeap==0 ){
			/* If the heap pointer is NULL, then restore the malloc implementation
			** back to NULL pointers too.  This will cause the malloc to go
			** back to its default implementation when sqlite3_initialize() is
			** run.
			*/
			memset(&sqlite3Config.m, 0, sizeof(sqlite3Config.m));
		  }else{
			sqlite3Config.m = *sqlite3MemGetMemsys5();
		  }

		  sqlite3Config.m.xInit(0);
		  break;
		}
	}

	va_end(ap);

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
