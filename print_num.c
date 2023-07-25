#include "main.h"

/**
* _isdigit - checks if the character is digit
* @c: the character to check
* 
*Return: 1 if digit, 0 otherwise
*/
int _isdigit(int c)
{
    return (c >= '0' && c <= '9');
}

/**
* _strlen - returns the length of a string
* @s: the string whose length to check
*
* Return: integer length of string
*/
int _strlen(char *s)
{
    int i = 0;

    while (*s++)
        i++;
    return (i);
}

/**
* print_num - prints a number with options
* @str: the base number as a string
* @p: the parameter struct
*
* Return: chars printed
*/
int print_num(char *str, p_t *p)
{
    unsigned int i = _strlen(str);
    int neg = (!p->unsign && *str == '-');

    if (!p->precision && *str == '0' && !str[1])
        str = "";
    if (neg)
    {
        str++;
        i--;
    }
    if (p->precision != UINT_MAX)
        while (i++ < p->precision)
            *--str = '0';
    if (neg)
        *--str = '-';
    if (!p->F_minus)
        return (print_num_Rshift(str, p));
    else 
        return (print_num_Lshift(str, p));
}

/**
* print_num_Rshift - prints a number with options
* @str: the base number as a string
* @p: the parameter struct
*
* Return: chars printed
*/
int print_num_Rshift(char *str, p_t *p)
{
    unsigned int n = 0, neg, neg2, i = _strlen(str);
    char pad_char = ' ';

    if (p->F_zero && !p->F_minus)
        pad_char = '0';
    neg = neg2 = (!p->unsign && *str == '-'); 
    if (neg && i < p->width && pad_char == '0' && !p->F_minus)
        str++;
    else 
        neg = 0;
    if ((p->F_plus && !neg2) || (!p->F_plus && p->F_space && !neg2))
        i++;
    if (neg && pad_char == '0')
        n += _putchar('-');
    if (p->F_plus && !neg2 && pad_char == '0' && !p->unsign)
        n += _putchar('+');
    else if (!p->F_plus && p->F_space && !neg2 && !p->unsign && p->F_zero)
        n += _putchar(' ');
    while (i++ < p->width)
        n += _putchar(pad_char);
    if (neg && pad_char == ' ')
        n += _putchar('-');
    if (p->F_plus && !neg2 && pad_char == ' ' && !p->unsign)
        n += _putchar('+');
    else if (!p->F_plus && p->F_space && !neg2 && !p->unsign && !p->F_zero)
        n += _putchar(' ');
    n += _puts(str);
    return (n);
}

/**
* print_num_Lshift - prints a number with options
* @str: the base number as a string
* @p: the parameter struct
*
* Return: chars printed
*/
int print_num_Lshift(char *str, p_t *p)
{
    unsigned int n = 0, neg, neg2, i = _strlen(str);
    char pad_char = ' ';

    if (p->F_zero && !p->F_minus)
        pad_char = '0';
    neg = neg2 = (!p->unsign && *str == '-');
    if (neg && i < p->width && pad_char == '0' && !p->F_minus)
        str++;
    else
        neg = 0;

    if (p->F_plus && !neg2 && !p->unsign)
        n += _putchar('+'), i++;
    else if (p->F_space && !neg2 && !p->unsign)
        n += _putchar(' '), i++;
    n += _puts(str);
    while (i++ < p->width)
        n += _putchar(pad_char);
    return (n);
}
