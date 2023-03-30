#include <unistd.h>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#include "main.h"
/**
 * _printf - prints formatted output
 *
 * @format: format to be displayed
 * @...: variadic arguments
 *
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list ap;
	const char *p = format;
	unsigned long long int count = 0;
	char c, *s;
	int x;

	va_start(ap, format);
	while (p && *p)
	{
		if (*p == '%')
		{
			p++;
			switch (*p)
			{
				case 'c':
					c = va_arg(ap, int);
					count = print_and_count(&c, count);
					break;
				case 's':
					s = va_arg(ap, char *);
					if (s == NULL)
					{
						write(1, "(null)", 6);
						count += 6;
						break;
					}
					write(1, s, strlen(s));
					count += strlen(s);
					break;
				default:
					count = print_and_count(p, count);
			}
		}
		else
			count = print_and_count(p, count);
		p++;
	}
	va_end(ap);
	return (count);
}
/**
 * print_and_count - prints a character and counts it
 *
 * @c: character to be printed
 * @count: the running total of the characters
 *
 * Return: total characters
 */
int print_and_count(char *c, int count)
{
	write(1, c, 1);
	count++;

	return (count);
}
