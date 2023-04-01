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
	char *p, *sval, c;
	int count = -1;

	if (format == NULL || strlen(format) == 1 && *format == '%')
		return (-1);
	va_start(ap, format); /* make ap point to 1st unnamed arg */
	for (p = (char *)format; p != NULL && *p != '\0'; p++)
	{
		if (*p != '%')
		{
			count = print_and_count(p, 1, count);
			continue;
		}
		switch (*++p)
		{
			case 'c':
				c = va_arg(ap, int);
				count = print_and_count(&c, 1, count);
				break;
			case 's':
				sval = va_arg(ap, char *);
				if (sval == NULL)
					sval = "(null)";
				count = print_and_count(sval, strlen(sval), count);
				break;
			case '%':
				count = print_and_count(p, 1, count);
				break;
			default:
				if (p != NULL && *p != '\0')
				{
					count = print_and_count(p - 1, 1, count);
					count = print_and_count(p, 1, count);
				}
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
 * @size: the width of c
 * @count: the running total of the characters
 *
 * Return: total characters
 */
int print_and_count(char *c, int size, int count)
{
	int i = 0;

	if (count < 0)
		count = 0;
	if (size == 1)
	{
		write(1, c, 1);
		count++;
		return (count);
	}
	while (i < size)
	{
		write(1, (c + i), 1);
		count++;
		i++;
	}

	return (count);
}
