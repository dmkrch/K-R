#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string>

#define MAX 100


int main(int argc, char* argv[])
{
	if (argc == 3)
	{
		FILE* firstFile;
		FILE* secondFile;

		if ((firstFile = fopen(argv[1], "r")) == NULL || (secondFile = fopen(argv[2], "r")) == NULL)
		{
			fprintf(stderr, "can't open file");
			return 0;
		}

		char lineForCompare1[MAX];
		char lineForCompare2[MAX];

		do
		{
			if (fgets(lineForCompare1, MAX, firstFile) == NULL || fgets(lineForCompare2, MAX, secondFile) == NULL) // fgets
				break;
		} while (strcmp(lineForCompare1, lineForCompare2) == 0);

		if (strcmp(lineForCompare1, lineForCompare2) != 0)
			printf("files are different in these lines: 1st: %s\n2nd: %s\n", lineForCompare1, lineForCompare2);
		else
			puts("files are equal\n"); // example for puts
	}

	else
		fprintf(stderr, "error with arguments");

	return 0;
}
