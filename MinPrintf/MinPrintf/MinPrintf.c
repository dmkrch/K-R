#include <iostream>
#include <stdarg.h>


void MinPrintf(char* fmt, ...)
{
	va_list ap; /* argument pointer - variable is actually a pointer to unnamed argument */

	char* p = NULL;
	char *sval = NULL;
	int ival;
	double dval;

	va_start(ap, fmt); /* initialize ap to first argument without name */

	for (p = fmt; *p; p++) /* p is pointer to string fmt. *p is single symbol of string */
	{
		if (*p != '%')
		{
			putchar(*p);
			continue;
		}

		switch (*++p) /* if *p is not % */
		{
		case 'd':
			ival = va_arg(ap, int); /* va_arg sequentially returns unnamed arguments one by one s*/
			printf("%d", ival);
			break;
		case 'f':
			dval = va_arg(ap, double);
			printf("%f", dval);
			break;
		case 's':
			for (sval = va_arg(ap, char*); *sval; sval++)
				putchar(*sval);
			break;
		default:
			putchar(*sval);
			break;
		}
	}
	
	va_end(ap);
}


int main()
{
	char message[] = "how are u?";


	char str[] = "hello, %d, %s";
	MinPrintf(str, 5, message); // hello, 5, how are u?
}