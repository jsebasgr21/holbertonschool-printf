#include "main.h"

int _printf(const char *format, ...)
{
int nchars = 0;
va_list list_of_args;
const char *frmt = format;

if (format == NULL || format[0] == '%' && format[1] =='\0')
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
if (*frmt == '\0')
break;

if (*frmt == '%')
{
write(1, frmt, 1);
nchars++;
}

else if (*frmt == 'c')
{
char c = va_arg(list_of_args, int);
write(1, &c, 1);
nchars++;
}

else if (*frmt == 's')
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

frmt++;

}

va_end(list_of_args);

return (nchars);
}
