#include "..\Src\sqliteInt.h"

int main(void)
{
	void *p;

    sqlite3MallocInit();

    p = sqlite3Malloc(256);

    if (!p)
    {
        printf("Malloc failed\n");

        sqlite3MallocEnd();

        return -1;
    }

    sqlite3_free(p);

    sqlite3MallocEnd();

    return 0;
}
