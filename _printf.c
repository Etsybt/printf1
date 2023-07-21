#include "main.h"

void print_buffer(char buffer[], int *buff_ind);

/**
  * _printf - function that produces output according to a format
  * @format: character string
  * Return: the number of characters printed
  */
int _printf(const char *format, ...)
{
	int n, p = 0, p_char = 0;
	int flags, width, size, precision, buff_ind = 0;
	va_list a;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(a, format);

	for (n = 0; format && format[n] != '\0'; n++)
	{
		if (format[n] != '%')
		{
			buffer[buff_ind++] = format[n];
			if (buff_ind == BUFF_SIZE)
				print_buffer(buffer, &buff_ind);
			p_char++;
		}
		else
		{
			print_buffer(buffer, &buff_ind);
			flags = flags(format, &n);
			width = width(format, &n, a);
			precision = precision(format, &n, a);
			size = size(format, &n);
			n++;
			p = handle_print(format, &n, a, buffer, flags, width, precision, size);
			if (p == -1)
				return (-1);
			p_char += p;
		}
	}

	print_buffer(buffer, &buff_ind);

	va_end(a);

	return (p_char);
}

/**
  * print_buffer - prints the buffer
  * @buffer: char array
  * @buff_ind: index, means the length
  */

void print_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
		write(1, &buffer[0], *buff_ind);

	*buff_ind = 0;
}
