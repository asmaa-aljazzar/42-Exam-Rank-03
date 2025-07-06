#include <stdarg.h> 
#include <stdio.h>  
#include <ctype.h> 

int match_space(FILE *f)
{
	return 0;
}

/* Match a specific character in the input */
int match_char(FILE *f, char c) {

    return 0;
}

/* Read a single character and store it */
int scan_char(FILE *f, va_list ap)
{

	return 1;
}

/* Read an integer (supports optional sign) and store it */
int scan_int(FILE *f, va_list ap)
{
    
    return 1;
}

/* Read a word (non-space sequence) and store it in a buffer */
int scan_string(FILE *f, va_list ap)
{
    
    return 1;
}

/* Match and handle conversion specifier (%d, %s, %c) */
int match_conv(FILE *f, const char **format, va_list ap)
{
	switch (**format)
	{
		case 'c':
			return scan_char(f, ap);
		case 'd':
			match_space(f);  // Skip whitespace before reading
			return scan_int(f, ap);
		case 's':
			match_space(f);  // Skip whitespace before reading
			return scan_string(f, ap);
		case '\0':
			return -1;
		default:
			return -1;
	}
}

/* Core parsing logic (similar to vscanf) */
int ft_vfscanf(FILE *f, const char *format, va_list ap)
{
	int nconv = 0;  // Number of successful conversions

	int c = fgetc(f);
	if (c == EOF)
		return EOF;
	ungetc(c, f);  // Start fresh

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (match_conv(f, &format, ap) != 1)
				break;
			nconv++;
		}
		else if (isspace(*format))
		{
			if (match_space(f) == -1)
				break;
		}
		else if (match_char(f, *format) != 1)
			break;

		format++;
	}

	if (ferror(f))
		return EOF;

	return nconv;
}

/* Main public function (like scanf) */
int ft_scanf(const char *format, ...)
{
	int ret = ft_vfscanf(stdin, format, ap);
	return ret;
}

/****************************************************************************************/
/*                                      Test Program                                    */
/****************************************************************************************/

int main(void)
{
	int a = 5;
	char b = 'z';
	char str[100];

	printf("Enter int, char, string: ");
	ft_scanf("%d %c %s", &a, &b, str);
	printf("Parsed values:\n");
	printf("Integer: %d\n", a);
	printf("Char: %c\n", b);
	printf("String: %s\n", str);
	return 0;
}