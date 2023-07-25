#include "main.h"

/**
  * _printf - function that produces output according to a format
  * @format: character string
  * Return: result = sum
  */
int _printf(const char *format, ...)
{
	int result = 0;
	va_list list;
	char *n, *start;
	p_t p = init_params;

	va_start(list, format);

	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);
	for (n = (char *)format; *n; n++)
	{
		init_params(&p, list);
		if (*n != '%')
		{
			result += _putchar(*n);
			continue;
		}
		start = n;
		n++;
		while (get_flags(n, &p))
		{
			n++;
		}
		n = get_width(n, &p, list);
		n = get_precision(n, &p, list);
		if (get_modifiers(n, &p))
			n++;
		if (!get_spec(n))
			result += print_start_end(start, n,
					p.l_length_modifier || p.h_length_modifier ? n - 1 : 0);
		else
			result += get_print_func(n, list, &p);
	}
	_putchar(BUFF_FLUSH);
	va_end(list);
	return (result);
}
