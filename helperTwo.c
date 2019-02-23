#include <stdio.h>

void myFuncTwoSet();
void myFuncTwoPrint();

static int a;// = 234;
extern int b = 0;//int b;

void myFuncTwoSet()
{
	a = 222;
	b = 69;
}

void myFuncTwoPrint()
{
	printf("helperTwo a: %d\n", a);
}
