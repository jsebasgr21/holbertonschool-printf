#include "main.h"

int _printf(const char *format, ...)
{
int nchars = 0;

va_list list_of_args;

if(format == NULL)
return (-1);

va_start(list_of_args, format);

while(*format)
{
if(*format != '%')
{
write(1, format, 1);
}
else
{
format++;
}
if(format == 'c')
{}
if(format == 's')
{}
if(format == '%')
{}

}
}