#include <stdio.h>

void myFuncSet();
void myFuncPrint();

static int a;// = 123;

void myFuncSet()
{
	a = 111;
}

void myFuncPrint()
{
	printf("helper a: %d\n", a);
}
