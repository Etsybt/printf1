#include "main.h"
/**
  */
int (*get_spec(char *i))(va_list list, p_t p)
{
	spect_t spec[] = 
	{
		{"c", print_char},
		{"s", print_string},
		{"%", print_percent},
		{"d", print_int},
		{"i", print_int},
		{"b", print_binary},
		{"u", print_unsigned},
		{"o", print_octal},
		{"X", print_hexa_upper},
		{"x", print_hexa},
		{"S", print_S},
		{"p", print_address},
		{"r", print_rev},
		{"R", print_rot13},
		{NULL, NULL}
	};
	int n = 0;

	while (spec[n].spec)
	{
		if (*i == spec[n].spec[0])
		{
			return (spec[n].func);
		}
		n++;
	}
	return (NULL);
}

/**
  * get_print_func - get thr format function
  * @s: str
  * @list: arg point
  * @p: parameter
  * Return: number of bytes
  */
int get_print_func(char *s, va_list list, p_t *p)
{
	int (*func)(va_list, p_t *) = get_spec(s);

	if (func)
		return (func(list, p));
	return (0);
}


