#include "main.h"
/**
  * get_spec - get the fomat function
  * @i: str
  * Return: num of bytes
  */
int (*get_spec(char *i))(va_list list, p_t p)
{
	spec_t spec[] = {
		{"c", print_char},
		{"s", print_string},
		{"%", print_percent},
		{"d", print_int},
		{"i", print_int},
		{"b", print_binary},
		{"u", print_unsigned},
		{"o", print_octal},
		{"X", print_hexa_upper},
		{"x", print_hex},
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
  * @i: str
  * @list: arg point
  * @p: parameter
  * Return: number of bytes
  */
int get_print_func(char *i, va_list list, p_t *p)
{
	int (*func)(va_list, p_t *) = get_spec(i);

	if (func)
		return (func(list, p));
	return (0);
}

/**
  * get_flags - get the flag function
  * @i: format str
  * @p: parameter
  * Return: checks if the flag is valid
  */
int get_flags(char *i, p_t *p)
{
	int n = 0;

	switch (*i)
	{
		case '+':
			n = p->F_plus = 1;
			break;
		case ' ':
			n = p->F_space = 1;
			break;
		case '#':
			n = p->F_hash = 1;
			break;
		case '-':
			n = p->F_minus = 1;
			break;
		case '0':
			n = p->F_zero = 1;
			break;
	}
	return (n);
}

/**
  * get_width - gets the width
  * @i: str
  * @p: parameter
  * @list: arg point
  * Return: pointer
  */
char *get_width(char *i, p_t *p, va_list list)
{
	int j = 0;

	if (*i == '*')
	{
		j = va_arg(list, int);
		i++;
	}
	else
	{
		while (_isdigit(*i))
			j = j * 10 + (*i++ - '0');
	}
	p->width = j;
	return (i);
}
