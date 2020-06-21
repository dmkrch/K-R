#include <stdio.h>

int main()
{

	int day;
	int month;
	int year;
	
	int count = scanf_s("%d/%d/%d", &month, &day, &year);
	printf("%d %d %d  count =  %d", month, day, year, count);
	// input: 25/26/27
	// output: 25 26 27 count 3

	// input: 25 26 27
	// output: 2982359 52353463 23463466324 count 0

	// input: 25/26 28
	//output: 25 26 2354326356 count 2



	char line[] = "25 9 16"; // values to set in variables
	sscanf_s(line, "%d %d %d", &day, &month, &year);
	printf("%d %d %d", day, month, year); // 25 9 16

	getchar();

	char line1[] = "29/23/24";
	sscanf_s(line1, "%d/%d/%d", &day, &month, &year);
	printf("%d %d %d", day, month, year); // 29 23 24
}