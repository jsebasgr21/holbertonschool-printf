#include "main.h"
/**
 * _printf - printf function
 * @format: a format string with the formats
 * Return: the number of characters printed
*/
int _printf(const char *format, ...)
{
int nchars = 0;
va_list list_of_args;
const char *frmt = format;

if (format == NULL || (format[0] == '%' && format[1] =='\0'))
return (-1);
va_start(list_of_args, format);
while (*frmt)
{
if (*frmt != '%')
{
write(1, frmt, 1);
nchars++;
}
else
{   
frmt++;
nchars += formatito(*frmt, list_of_args);
if (*frmt == '%' || *frmt == 'c' || *frmt == 's')
{

}
else
{
frmt--;
write(1, frmt, 1);
nchars++;
}
frmt++;
}
}
va_end(list_of_args);
return (nchars);
}
