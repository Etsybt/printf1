#include "main.h"

/**
* print_char - prints character
* @list: argument pointer
* @p: the parameters struct
*
* Return: number chars printed
*/
int print_char(va_list list, p_t *p)
{
    char pad_char = ' ';
    unsigned int pad = 1, sum = 0, ch = va_arg(list, int);

    if (p->F_minus)
        sum += _putchar(ch);
    while (pad++ < p->width)
        sum += _putchar(pad_char);
    if (!p->F_minus)
        sum += _putchar(ch);
    return (sum);
}

/**
* print_int - prints integer
* @list: argument pointer
* @p: the parameters struct
* 
* Return: number chars printed
*/
int print_int(va_list list, p_t *p)
{
    long l;

    if (p->l_length_modifier)
        l = va_arg(list, long);
    else if (p->h_length_modifier)
        l = (short int)va_arg(list, int);
    else
        l = (int)va_arg(list, int);
    return (print_num(convert(l, 10, 0, p), p));
}

/**
* print_string - prints string
* @list: argument pointer
* @p: the pointers struct
*
* Return: number chars printed
*/
int print_string(va_list list, p_t *p)
{
    char *str = va_arg(list, char *), pad_char = ' ';
    unsigned int pad = 0, sum = 0, i = 0, j;

    (void)p;
    switch ((int) (!str))
        case 1:
            str = NULL_STRING;

    j = pad = _strlen(str);
    if (p->precision < pad)
        j = pad = p->precision;

    if (p->F_minus)
    {
        if (p->precision != UINT_MAX)
            for (i = 0; i < pad; i++)
                sum += _putchar(*str++);
        else 
            sum += _putchar(str);
    }
    while (j++ < p->width)
        sum += _putchar(pad_char);
    if (!p->F_minus)
    {
        if (p->precision != UINT_MAX)
            for (i = 0; i < pad; i++)
                sum += _putchar(*str++);
        else
            sum += _puts(str)
    }
    return (sum)
}

/**
* print_percent - prints string
* @list: argument pointer
* @p: the parameters struct
*
* Return: number chars printed
*/
int print_percent(va_list list, p_t *p)
{
    (void)list;
    (void)p;
    return (_putchar('%'));
}

/**
* print_S - custom format specifier
* @list: argument pointer
* @p: the parameters struct
*
* Return: number chars printed
*/
int print_S(va_list list, p_t *p)
{
    char *str = va_arg(list, char *);
    char *hex;
    int sum = 0;

    if ((int)(!str))
        return (_puts(NULL_STRING));
    for (; *str; str++)
    {
        if((*str > 0 && *str < 32) || *str >= 127)
        {
            sum += _putchar('\\');
            sum += _putchar('x');
            hex = convert(*str, 16, 0, p);
            if (!hex[1])
                sum += _putchar('0');
            sum += _puts(hex);
        }
        else 
        {
            sum += _putchar(*str);
        }
    }
    return (sum);
}
