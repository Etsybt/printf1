---- simple_printers----

#include "main.h"

/**
* print_start_end - print a range of char addresses
* @start: starting address
* @end: ending address
* @except: except address
*
* Return: number bytes printed
*/
int print_start_end(char *start, char *end, char *except)
{
int sum = 0;

while (start <= end)
{
    if (start != except)
        sum += _putchar(*start);
    start++;
}
return (sum);
}

/**
* print_rev - prints string in reverse
* @list: string
* @p: the parameters struct
*
*Return: number bytes printed
*/
int print_rev(va_list list, p_t *p)
{
    int len, sum = 0;
    char *str = va_arg(list, char *);
    (void)p;

    if (str)
    {
        for (len = 0; *str; str++)
            len++;
        str--;
        for (; len > 0; len--; str--)
            sum += _putchar(*str);
    }
    return (sum);
}

/**
* print_rot13 - prints string in rot13
* @list: string
* @p: the parameters struct
*
* Return: number bytes printed
*/
int print_rot13(va_list list, p_t *p)
{
    int i, index;
    int count = 0;
    char arr[] = 
        "NOPQRSTUVWXYZABCDEFGHIJKLM      nopqrstuvwxyzabcdefghijklm";
    char *a = va_arg(list, char *);
    (void)p;

    i = 0;
    index = 0;
    while (a[i])
    {
        if ((a[i] >= 'A' && a[i] <= 'Z') || (a[i] >= 'a' && a[i] <= 'z'))
        {
            index = a[i] - 65;
            count += _putchar(arr[index]);
        }
        else 
            count += _putchar(a[i]);
        i++;
    }
    return (count);
}
