#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdarg.h>
#include <limits.h>
#include <stdlib.h>
#include <unistd.h>

#define BUFF_FLUSH -1
#define BUFF_SIZE 1024

#define NULL_STR "(null)"
#define F_init (0, 0, 0, 0, 0, 0, 0, 0, 0, 0)
/**
  * struct p - struct of parameters
  * @F_plus: flag if + specified
  * @F_space: flag if space specified
  * @F_hash: flag if # specified
  * @F_zero: flag if 0 specified
  * @F_minus: flag if - specified
  * @l_length_modifier: flag
  * @h_length_modifier: flag
  * @width: flag
  * @precision: flag
  * @unsign: flag
 */
typedef struct p
{
	unsigned int F_plus : 1;
	unsigned int F_space : 1;
	unsigned int F_hash : 1;
	unsigned int F_zero : 1;
	unsigned int F_minus : 1;

	unsigned int l_length_modifier : 1;
	unsigned int h_length_modifier : 1;

	unsigned int width : 1;
	unsigned int precision : 1;

	unsigned int unsign : 1;

} p_t;

#define CONVER_L 1
#define CONVER_U 2

/**
  * struct spec - strcut of specifiers
  * @spec: format
  * @func: function
  */
typedef struct spec
{
	char *spec;
	int (*func)(va_list, p_t *);
} spec_t;


/* printf */
int _printf(const char *format, ...);
/* print c, s, % */

int print_char(va_list list, p_t *p);
int print_string(va_list list, p_t *p);
int print_percent(va_list list, p_t *p);

/* putchar */
int _puts(char *str);
int _putchar(int c);

/* Functions to print numbers */
int print_int(va_list list, p_t *p);
int print_binary(va_list list, p_t *p);
int print_unsigned(va_list list, p_t *p);
int print_octal(va_list list, p_t *p);
int print_hexa_upper(va_list list, p_t *p);
int print_hex(va_list list, p_t *p);
int print_S(va_list list, p_t *p);
int print_address(va_list list, p_t *p);


int print_start_end(char *start, char *end, char *except);

/* Funciotns to handle other specifiers */
int (*get_spec(char *i))(va_list list, p_t *p);
int get_print_func(char *i, va_list list, p_t *p);

int get_flags(char *i, p_t *p);
int get_modifiers(char *i, p_t *p);
char *get_width(char *i, p_t *p, va_list list);
char *get_precision(char *n, p_t *p, va_list list);

/*Function to print string in reverse*/
int print_rev(va_list list, p_t *p);

/*Function to print a string in rot 13*/
int print_rot13(va_list list, p_t *p);

char *convert(long int num, int b, int flags, p_t *p);

int _isdigit(int c);
int _strlen(char *i);
int print_num(char *str, p_t *p);
int print_num_Rshift(char *str, p_t *p);
int print_num_Lshift(char *str, p_t *p);

void init_params(p_t *p, va_list list);

#endif
