#include <iostream>

int main()
{
	float b = 5.003453;
	printf("%-20.3f\n", b); // __________5.003

	int number = 1;

	for (int i = 1; i <= 10; ++i, ++number)
		printf("%*d\n", i, number); // 1 \n\t 2 \n\t\t 3 ...



	char str[] = "Message from hello";
	printf("%*.*s\n", 40, 10, str); // ______________Message from h


	char str1[100];
	sprintf_s(str1, 100, "Hello, %s", str);

	printf("%s", str1); // Hello, Message from hello
}