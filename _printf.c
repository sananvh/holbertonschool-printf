#include "main.h"
#include <stdarg.h>
#include <unistd.h>

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

