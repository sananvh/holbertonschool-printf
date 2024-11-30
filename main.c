#include "main.h"

/**
 * main - Entry point for testing _printf
 *
 * Return: Always 0
 */
int main(void)
{
	_printf("Character: %c\n", 'A');
	_printf("String: %s\n", "Hello, world!");
	_printf("Percent: %%\n");
	_printf("Integer (d): %d\n", 12345);
	_printf("Integer (i): %i\n", -67890);
	_printf("Unknown specifier: %x\n");
	return (0);
}

