#include "main.h"

/**
  * init_params - func
  * @p: parameter
  * @list: arg pointer
  * Return: void
  */
void init_params(p_t *p, va_list list)
{
	p->unsign = 0;

	p->F_plus = 0;
	p->F_space = 0;
	p->F_hash = 0;
	p->F_zero = 0;
	p->F_minus = 0;

	p->width = 0;
	p->precision = UINT_MAX;

	p->h_length_modifier = 0;
	p->l_length_modifier = 0;

	(void)list;
}
