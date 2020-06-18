#include <stdio.h>
#include <string>


int Sum(int a, int b)
{
	return (a + b);
}

int Subtr(int a, int b)
{
	return (a - b);
}

int Calculate(int a, int b, int(*op)(int a, int b))
{
	return (*op)(a, b);
}

int main()
{
	/* 1st example */
	int a = 5;
	int b = 7;

	printf("\n%d + %d = %d", a, b, Calculate(a, b, Sum));	// 12
	printf("\n%d - %d = %d", a, b, Calculate(a, b, Subtr)); // -2

	/* 2nd example */
	int (*strcompare)(const char*, const char*);
	strcompare = strcmp;

	char* str1;
	char* str2;

	char arr1[] = "hello";
	char arr2[] = "how";

	str1 = arr1;
	str2 = arr2;

	printf("%d", (*strcompare)(str1, str2));	// -1
}