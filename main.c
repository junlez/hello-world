//rawrr
#include <stdio.h>

void myFuncSet();
void myFuncPrint();
void myFuncTwoSet();
void myFuncTwoPrint();

int a;
extern int b;

int main()
{
	// printf("Hello, World! \n");
	// myFunc();

	// a = 1;
	printf("helloWorld a: %d\n", a);

	myFuncSet();

	printf("helloWorld a: %d\n", a);

	myFuncTwoSet();

	printf("helloWorld a: %d\n", a);

	myFuncPrint();
	myFuncTwoPrint();

	printf("helloWorld b: %d\n", b);
	b = 8;
	printf("helloWorld b: %d\n", b);

	// printf("helloWorld a: %d\n", a);

	return 0;
}

// //if included, this gives error (multiple definitions)
// void myFunc()
// {
// 	printf("running the helloWorld function!\n");
// }
