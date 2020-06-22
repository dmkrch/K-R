#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(int argc, char* argv[])
{
	/* stdin is standart stream for input from user */
	/* stdout is standart stream for output - typically screen of monitor */

	FILE* fp; // file pointer
	void filecopy(FILE*, FILE*);

	if (argc == 1) // no arguments, standart stream
		filecopy(stdin, stdout);
	else
		while (--argc > 0)
		{
			if ((fp = fopen(*++argv, "r")) == NULL)
			{
				printf("cat: can't open %s\n", *argv);
				return 1;
			}
			else
			{
				filecopy(fp, stdout);
				fclose(fp);
			}
		}

	return 0;
}

void filecopy(FILE* ifp, FILE* ofp) // ifp - input file pointer , ofp - output file pointer
{
	int c;

	while ((c = getc(ifp)) != EOF)
		putc(c, ofp);
}