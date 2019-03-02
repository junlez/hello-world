#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE	256



float getNum(char* equation, int* index, int* op)
{
	char subStr[SIZE];
	int length = 1;

	while(1)
	{
		if(equation[*index + length] == '+')
		{
			*op = 1;
			memcpy(subStr, &equation[*index], length);
			subStr[length] = '\0';
			*index = *index + length + 1;
			printf("%s\n", subStr);
			float temp = atof(subStr);
			printf("temp: %.6f\n", temp);
			return temp;
		}
		else if(equation[*index + length] == '-')
		{
			*op = 2;
			memcpy(subStr, &equation[*index], length);
			subStr[length] = '\0';
			
			*index = *index + length + 1;
			printf("%s\n", subStr);
			
			float temp = atof(subStr);
			printf("temp: %.6f\n", temp);
			return temp;
		}
		else if(equation[*index + length] == '*')
		{
			*op = 3;
			memcpy(subStr, &equation[*index], length);
			subStr[length] = '\0';
			//printf("%d\n", (*index));
			*index = *index + length + 1;
			//printf("%d\n", (*index));
			printf("%s\n", subStr);
			//while(1);
			float temp = atof(subStr);
			printf("temp: %.6f\n", temp);
			return temp;
		}
		else if(equation[*index + length] == '/')
		{
			*op = 4;
			memcpy(subStr, &equation[*index], length);
			subStr[length] = '\0';
			*index = *index + length + 1;
			printf("%s\n", subStr);
			float temp = atof(subStr);
			printf("temp: %.6f\n", temp);
			return temp;
		}
		else if(equation[*index + length] == '\0')
		{
			*op = 0;
			memcpy(subStr, &equation[*index], length);
			subStr[length] = '\0';
			*index = *index + length;
			printf("%s\n", subStr);

			// printf("\n\n%d\n", (*index));
			// while(1);

			float temp = atof(subStr);
			printf("temp: %.6f\n", temp);
			return temp;
		}
		else
			length++;
	}
}


float process(char* equation, int* index)
{
	float num;
	int op;

	num = getNum(equation, index, &op);

	while(op != 0)
	{
		if(op == 3)
		{
			num *= getNum(equation, index, &op);
			printf("num: %.6f\n", num);
		}
		else if(op == 4)
		{
			num /= getNum(equation, index, &op);
			printf("num: %.6f\n", num);
		}
		else if(op == 1)
		{
			num += process(equation, index);
			printf("num: %.6f\n", num);
		}
		else if(op == 2)
		{
			num -= process(equation, index);
			printf("num: %.6f\n", num);
		}

		if(equation[*index] == '\0')
			op = 0;
	}

	return num;
}


int main()
{
	char equation[SIZE] = "2*3+5/6*3+15";
	int index = 0;

	float temp = process(equation, &index);

	printf("The computed output is: %.6f\n", temp);

}
