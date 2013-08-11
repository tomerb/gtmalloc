#include <windows.h>

#define _M_X64 
#include "StackWalker.h"
#include "time.h"
#include "stdio.h"
#include "windows.h"

StackWalker sw;

void Func5() { ; sw.ShowCallstack(); }
void Func4() { Func5(); }
void Func3() { Func4(); }
void Func2() { Func3(); }
void Func1() { Func2(); }

int main()
{
	clock_t t1 = clock();
	for (int i = 0 ; i < 1000 ; i++)
	{
		Func1();
	}
	clock_t t2 = clock();

	clock_t t3 = t2 - t1;
	printf("t3 : %d\n", t3);
	return 0;
}