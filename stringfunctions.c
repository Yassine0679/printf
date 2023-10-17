#include "main.h"

/**
 *  * _putchar - writes a character to standard output buffer
 *   * @character: character to write, passed as an int to avoid casting errors
 *    * Return: 1 or -1
 *    */

int _putchar(int character)
{
	return (write(1, &character, 1));
}

/**
 *  * sPrinter - prints the entire string passed as parameter exactly as is
 *   * often used in conjunction with the %s format in _printf
 *    * @string: string to print
 *     * Return: Amount of characters printed
 *     */

int sPrinter(char *string)
{
	int i = 0;

	if (string == NULL)
	{
		_putchar('(');
		_putchar('n');
		_putchar('u');
		_putchar('l');
		_putchar('l');
		_putchar(')');
		return (6);
	}

	while (string[i] != '\0')
	{
		if (string[i])
		{
			_putchar(string[i]);
		}
		i++;
	}

	return (i);
}
