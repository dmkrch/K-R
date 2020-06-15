#include <stdio.h>

void Swap(void* a, void* b)
{
	void* temp;
}


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
	int a = 5;
	int b = 7;

	printf("\n%d + %d = %d", a, b, Calculate(a, b, Sum));
	printf("\n%d - %d = %d", a, b, Calculate(a, b, Subtr));

	void* p = &a;

	printf("%d", *(int*)p);
}