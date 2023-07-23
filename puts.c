#include "main.h"

/**
  * _puts - prints str
  * @str: string
  * Return: void
  */
int _puts(char *str)
{
	char *m = str;

	while (*str)
		_putchar(*str++);
	return (str - m);
}

/**
  * _putchar - writes c
  * @c: character
  * Return: 1
  */
int _putchar(int c)
{
	static int l;
	static char buff[BUFF_SIZE];

	if (c == BUFF_FLUSH || l >= BUFF_SIZE)
	{
		write(1, buff, l);
		l = 0;
	}
	if (c != BUFF_FLUSH)
		buff[l++] = c;
	return (1);
}
