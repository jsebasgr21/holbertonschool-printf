#include "main.h"

int formatito(char formato, va_list list_of_args)
{
int nchars = 0;

if (formato == '%')
{
write(1, &formato, 1);
nchars++;
}

else if (formato == 'c')
{
char c = va_arg(list_of_args, int);
write(1, &c, 1);
nchars++;
}

else if (formato == 's')
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
return (nchars);
}
