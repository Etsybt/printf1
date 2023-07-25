#include "main.h"

/**
* print_hex - prints unsigned hex numbers in lowercase
* @list: the argument pointer
* @p: the parameters struct
*
* Return: bytes printed
*/
int print_hex(va_list list, p_t  *p)
{
    unsigned long l;
    int c = 0;
    char *str;

    if (p->l_length_modifier)
        l = (unsigned long)va_arg(list, unsigned long);
    else if (p->h_length_modifier)
        l = (unsigned short int)va_arg(list, unsigned int);
    else 
        l = (unsigned int)va_arg(list, unsigned int);

    str = convert(l, 16, CONVER_U | CONVER_L, p);
    if (p->F_hash && l)
    {
        *--str = 'x';
        *--str = '0';
    }
    p->unsign = 1;
    return (c += print_num(str, p));
}

/**
* print_hexa_upper - prints unsigned hex numbers in uppercase
* @list: the argument pointer
* @params: the parameters struct
*
* Return: bytes printed
*/
int print_hexa_upper(va_list list, p_t *p)
{
    unsigned long l;
    int c = 0;
    char *str;

    if (p->l_length_modifier)
        l = (unsigned long)va_arg(list, unsigned long);
    else if (p->h_length_modifier)
        l = (unsigned short int)va_arg(list, unsigned int);
    else 
        l = (unsigned int)va_arg(list, unsigned int);
    
    str = convert(l, 16, CONVER_U, p);
    if (p->F_hash && l)
    {
        *--str = 'X';
        *--str = '0';
    }
    p->unsign = 1;
    return (c += print_num(str, p));
}

/**
* print_binary - prints unsigned binary number
* @list: the argument pointer
* @params: the parameters struct
*
* Return: bytes printed 
*/
int print_binary(va_list list, p_t *p)
{
    unsigned int n = va_arg(list, unsigned int);
    char *str = convert(n, 2, CONVER_U, p);
    int c = 0;

    if (p->F_hash && n)
        *--str = '0';
    p->unsign = 1;
    return (c += print_num(str, p));
}

/**
* print_octal - prints unsigned octal numbers
* @list: the argument pointer
* @params: the parameters struct
*
* Return: bytes printed
*/
int print_octal(va_list list, p_t *p)
{
    unsigned long l;
    char *str;
    int c = 0;

    if (p->l_length_modifier)
        l = (unsigned long)va_arg(list, unsigned long);
    else if (p->h_length_modifier)
        l = (unsigned short int)va_arg(list, unsigned int);
    else
        l = (unsigned int)va_arg(list, unsigned int);
    str = convert(l, CONVER_U, p);

    if(p->F_hash && l)
        *--str = '0';
    p->unsign = 1;
    return (c += print_num(str, p));
}
