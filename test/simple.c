#include "..\Src\sqliteInt.h"

int main(void)
{
	void *pPreAllocation = (char*)malloc(10000);
	void *pNew = 0;

	sqlite3_config(SQLITE_CONFIG_HEAP, pPreAllocation, 10000, 10);

	sqlite3MutexInit();
    sqlite3MallocInit();

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