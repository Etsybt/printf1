#include "main.h"

/**
* convert - converter functions, a clone of itoa
* @num: number
* @b: b
* @flags: argument flags
*
* Return: string
*/
char *convert(long int num, int b, int flags, p_t *p)
{
    static char *array;
    static char buffer[50];
    char sign = 0;
    char *ptr;
    unsigned long n = num;
    (void)p;

    if (!(flags & CONVER_U) && num < 0)
    {
        n = -num;
        sign = '-';
    }
    array = flags & CONVER_L ? "0123456789abcdef" : "0123456789ABCDEF";
    ptr = &buffer[49];
    *ptr = '\0';

    do {
        *--ptr = array[n % b];
        n /= b;
    } while (n != 0);

    if(sign)
        *--ptr = sign;
    return (ptr);
}

/**
* print_unsigned - prints unsigned integer numbers
* @list: argument pointer
* @p: the parameters struct
*
* Return: bytes printed
*/
int print_unsigned(va_list list, p_t *p)
{
    unsigned long l;

    if (p->l_length_modifier)
        l = (unsigned long)va_arg(list, unsigned long);
    else if (p->h_length_modifier)
        l = (unsigned short int)va_arg(list, unsigned int);
    else 
        l = (unsigned int)va_arg(list, unsigned int);
    p->unsign = 1;
    return (print_num(convert(l, 10, CONVER_U, p), p));
}

/**
* print_address - prints address
* @list: argument pointer
* @p: the parameters struct
*
* Return: bytes printed
*/
int print_address(va_list list, p_t *p)
{
    unsigned long int n = va_arg(list, unsigned long int);
    char *str;

    if (!n)
        return (_puts("(nil)"));
    str = convert(n, 16, CONVER_U | CONVER_L, p);
    *--str = 'x';
    *--str = '0';
    return (print_num(str, p));
}
