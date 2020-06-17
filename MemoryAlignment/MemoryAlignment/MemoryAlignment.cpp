#include <stdio.h>

// https://tproger.ru/translations/art-of-structure-packing/
// https://habr.com/ru/post/142662/



struct Test
{
	char a;			// 1
	// 3 
	int d;			// size 4
	char b;			// size 1
	// 7
	long long g;	// 8

	char e;			// 1

	// now total is 25. Adding 7 more to be 32 | 8
	// so final size of struct is 32
};

struct test
{
	long long g;	// 8
	int d;			// 4
	char a;			// 1
	char b;			// 1
	char e;			// 1


	// now total is 15. Adding 1 more to be 16 | 8
	// so final size of struct is 16
};

struct Key
{
	const char* name; // 4
	int count;		  // 4
	char a;			  // 1
	//3

	// final size of struct is 12
};


void Print_Array_Size(Key arr[])
{
	printf("size of array in function: %d\n", sizeof(arr));
}

int main()
{
	Key keyArray[] = { {"return", 0}, {"int", 0}, {"float", 0} };

	printf("size of array in main: %d\n", sizeof(keyArray)); // shows 36

	Print_Array_Size(keyArray); // shows 4
}