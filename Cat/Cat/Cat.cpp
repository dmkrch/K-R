#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

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
				fprintf(stderr,	"cat: can't open %s\n", *argv);
				exit(0);
			}
			else
			{
				filecopy(fp, stdout);
				fclose(fp);
			}
		}

	if (ferror(stdout))
	{
		fprintf(stderr, "%s: error writing stdout\n", argv[0]);
		exit(2);
	}

	exit(0);
}

void filecopy(FILE* ifp, FILE* ofp) // ifp - input file pointer , ofp - output file pointer
{
	int c;

	while ((c = getc(ifp)) != EOF)
		putc(c, ofp);
}