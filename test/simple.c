#include "sqliteInt.h"

int main(void)
{
    sqlite3MallocInit();

    void *p = sqlite3Malloc(100);
    if (!p)
    {
        printf("Malloc failed\n");
        return -1;
    }

    sqlite3_free(p);

    sqlite3MallocEnd();

    return 0;
}
