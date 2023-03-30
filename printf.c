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
	va_list ap; /* points to each unnamed arg in turn */
	char c, *p, *sval;
	int count = 0;

	if (format == NULL)
		return (-1);
	va_start(ap, format); /* make ap point to 1st unnamed arg */
	for (p = format; p != NULL && *p != '\0'; p++)
	{
		if (*p != '%')
		{
			count = print_and_count(p, count);
			continue;
		}
		switch (*++p)
		{
			case 'c':
				c = va_arg(ap, int);
				count = print_and_count(&c, count);
				break;
			case 's':
				sval = va_arg(ap, char *);
				if (sval == NULL)
					sval = "(null)";
				for (; *sval; sval++)
					count = print_and_count(sval, count);
				break;
			default:
				if (*p != '\0')
					count = print_and_count(p, count);
				else
					return (count);
				break;
		}
	}
	va_end(ap); /* clean up when done */
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
