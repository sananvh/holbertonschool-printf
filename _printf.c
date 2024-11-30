#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
 * _print_number - prints an integer to stdout
 * @n: the integer to print
 *
 * Return: number of characters printed
 */
int _print_number(int n)
{
	int count = 0;
	char c;

	if (n < 0)
	{
		count += write(1, "-", 1);
		n = -n;
	}

	if (n / 10)
		count += _print_number(n / 10);

	c = (n % 10) + '0';
	count += write(1, &c, 1);

	return (count);
}

/**
 * _printf - produces output according to a format
 * @format: format string containing the characters and specifiers
 *
 * Return: the number of characters printed (excluding the null byte)
 */
int _printf(const char *format, ...)
{
	va_list args;
	int i = 0, count = 0;
	char c, *s;

	if (!format)
		return (-1);

	va_start(args, format);

	while (format && format[i])
	{
		if (format[i] == '%')
		{
			i++;
			switch (format[i])
			{
			case 'c': /* Character */
				c = va_arg(args, int);
				count += write(1, &c, 1);
				break;
			case 's': /* String */
				s = va_arg(args, char *);
				if (!s)
					s = "(null)";
				while (*s)
					count += write(1, s++, 1);
				break;
			case '%': /* Percent */
				count += write(1, "%", 1);
				break;
			case 'd': /* Decimal integer */
			case 'i': /* Integer */
				count += _print_number(va_arg(args, int));
				break;
			default: /* Unknown specifier */
				count += write(1, "%", 1);
				count += write(1, &format[i], 1);
				break;
			}
		}
		else
		{
			count += write(1, &format[i], 1);
		}
		i++;
	}

	va_end(args);
	return (count);
}

