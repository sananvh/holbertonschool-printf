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
	_printf("Unknown specifier: %x\n");
	return (0);
}

