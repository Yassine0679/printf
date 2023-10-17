#include "main.h"

/**
 * handleString - Handles string formatting and prints to standard output.
 *
 * @specifier1: The format specifier character (e.g., 'c', 's', '%').
 * @stringEnd: A character that marks the end of the string.
 * @params: A va_list containing the variadic arguments.
 *
 * Return: The number of characters printed or an error code:
 * - 1 for 'c' or '%' specifiers
 * - The return value of sPrinter for 's' specifier
 * - -2 if an unknown specifier is encountered
 * - -1 if an error occurs
 */

int handleString(char specifier1, char stringEnd, va_list params)
{
	int iserror = 0, tempholder = 0;
	if (!params)
		return (0);
	switch (specifier1)
	{
		case 'c':
			_putchar(va_arg(params, int));
			return (1);
		case 's':
			tempholder = sPrinter(va_arg(params, char *));
			return (tempholder);
			break;
		case '%':
			_putchar(37);
			return (1);
			break;
		case '\0':
			iserror = 1;
			break;
		default:
			if (!stringEnd && stringEnd == '\0')
			{
				iserror = 1;
			}
			else
			{
				_putchar(37);
				return (-2);
			}
			break;
	}
	if (iserror == 1)
		return (-1);
	return (0);
}


/**
 *  * _printf - a replica of printf from stdio
 *   * Procudes an output according to a format and additional arguments
 *    * @format: the formatting string to use
 *     * Return: the number of characters printed
 *     */

int _printf(const char *format, ...)
{
	int i = 0, number_printed = 0, tempholder = 0, iserror = 0;
	va_list params;
	va_start(params, format);
	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	while (format[i] != '\0')
	{
		switch (format[i])
		{
			case '%':
				tempholder = handleString(format[i + 1], format[i + 2], params);
				if (tempholder == -1)
				{
					iserror = 1;
					i++;
				}
				else if (tempholder == -2)
				{
					tempholder = 1;
					i++;
				}
				else
					i += 2;
				number_printed += tempholder - 1;
				break;
			default:
				_putchar(format[i]);
				i++;
				break;
		}
		number_printed++;
	}
	va_end(params);
	if (iserror == 1)
		return (-1);
	return (number_printed);
}
