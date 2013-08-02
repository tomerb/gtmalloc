#include "sqliteInt.h"

int main(void)
{
    sqlite3MallocInit();

    void *p = sqlite3Malloc(100);
    if (!p)
    {
        printf("Not a valid library.\n");
        return -1;
    }

    sqlite3MallocEnd();

    return 0;
}
