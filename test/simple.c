#include "sqliteInt.h"

#include <stdio.h>

int main(void)
{
    void *pPreAllocation = (char*)malloc(1024);
    void *pNew = 0;

    sqlite3_config(SQLITE_CONFIG_HEAP, pPreAllocation, 1024, 10);

    pNew = sqlite3Malloc(256);

    if (!pNew)
    {
        printf("Malloc failed\n");

        sqlite3MallocEnd();

        return -1;
    }

    sqlite3_free(pNew);
    free(pPreAllocation);

    sqlite3MallocEnd();

    return 0;
}
