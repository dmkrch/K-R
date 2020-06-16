#include <stdio.h>

struct Test
{
	// alignment works like this:
	// 1. If it is the last declaration: we check if total amount of bytes can be divided by size of biggest type
	// 2. If it is not the last declaration: 
	// we declare type and then check next type
	// if curr. type size > prev. type size
	// we allocate here a pad to allign memory, so that  (size(previous) + size(curr)) | size(curr);

	char a; // size 1
	// next is int - has size 4. So we need to allocate 3 more for total amount of 4. And 4 is divided by 4.
	int b; // size 4
	// next is char - has size 1. So we dont need to allocate anything.

	//now total is 5. if we end declaring - total is 5 and 5 cant be divided by 4. So we add pad of 3 to has 8 bytes, and 8 can be diveded by 4.
	// but in our case, it is not the end of declaration variables. So we dont add anything and total size is still 5

	char g; // size 1
	// next is size 8, so we add a pad of 7 bytes. Now total is 14
	long long d; // size 8. Total is 22.
	// here is the end of declaration. Total is 22. Its cant be divided by the biggest type - 8. So we add 2 more bytes and get 24.

	//total size of Test is 24.
	// but in fact char + int + char + long long == 1 + 4 + 1 + 8 = 14. 
};

struct Key
{
	const char* name;
	int count;
	char a;
};


void Print_Array_Size(Key arr[])
{
	printf("size of array in function: %d\n", sizeof(arr));
}

int main()
{
	printf("%d", sizeof(Test)); // shows 24


	Key keyArray[] = { {"return", 0}, {"int", 0}, {"float", 0} };

	printf("size of array in main: %d\n", sizeof(keyArray)); // shows 8

	Print_Array_Size(keyArray); // shows 4
}