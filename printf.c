#include <stdarg.h>
#include "main.h"
#include <stddef.h>

/**
 * get_op - select function for char conversion
 * @c: char to check
 *
 * Return: pointer to function
 */
int (*get_op(const char c))(va_list)
{

int k = 0;

flags_p fp[] = {
	{"c", print_char},
	{"s", print_str},
	{"i", print_nbr},
	{"d", promt_nbr},
	{"b", print_binary},
	{"o", print_octal},
	{"x", print_hexa_lower},
	{"X", print_hexa_upper},
	{"u", print_unsigned},
	{"S", print_str_unprintable},
	{"r", print_str_reverse},
	{"p", print_ptr},
	{"R", print_rot13},
	{"%", print_percent},

};

while (k < 14)
{
if (c == fp[k].c[0])
{
return (fp[k].f);

}
k++;
}

return (NULL);
}

/**
 * _printf - emulates the behavior of a printf function
 * @format: format string
 *
 * Return: Value of printed characters
 */

int _printf(const char *format, ...)
{
va_list ap;
int sum = 0;
int = k;
int (*func)();

if (!format || (format[0] == '%' && format[1] == '\0'))
return (-1)
va_start(ap, format);

while (format[k])
{
if (format[k] == '%')
{
if (format[k + 1] != '\0')
func = get_op(format[k + 1]);
if (func == NULL)
{
_putchar(format[k]);
sum++;
k++;
}
else
{
sum += func(ap);
k += 2;
continue;

}
}
else
{
_putcharformat[k];
k++;

}
}

va_end(ap);
return (sum);

}

