#include "main.h"

/**
  * get_precision - get the precision from n
  * @n: format str
  * @p: parameter
  * @list: arg pointer
  * Return: pointer
  */
char *get_precision(char *n, p_t *p, va_list list)
{
	int j = 0;

	if (*n != '.')
		return (n);
	n++;
	if (*n == '*')
	{
		j = va_arg(list, int);
		n++;
	}
	else
	{
		while (_isdigit(*n))
			j = j * 10 + (*n++ - '0');
	}
	p->precision = j;
	return (n);
}
