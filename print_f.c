#include "main.h"

int _printf(const char *format, ...)
{
int nchars = 0;
va_list list_of_args;

if (format == NULL)
return (-1);

va_start(list_of_args, format);

while (*format)
{
if (*format != '%')
{
write(1, format, 1);
nchars++;
}
else
{
format++;
if (*format == '\0')
break;

if (*format == '%')
{
write(1, format, 1);
nchars++;
}

else if (*format == 'c')
{
char c = va_arg(list_of_args, int);
write(1, &c, 1);
nchars++;
}

else if (*format == 's')
{
char *str = va_arg(list_of_args, char*);
int str_len = 0;

if (str == NULL)
{
str = "(null)";
}

while (str[str_len] != '\0')
str_len++;

write(1, str, str_len);
nchars += str_len;
}
}

format++;

}

va_end(list_of_args);

return (nchars);
}
