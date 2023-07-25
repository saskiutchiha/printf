#include <string.h>
#include "main.h"
#include <stdarg.h>
#include <stddef.h>
/**
 * _printf- Entry point
 *@format : variable to pass to _printf function
 * Return: integer (Success)
 */
int _printf(const char *format, ...)
{
char *x, z;
int i, j, a = strlen(format), b, c = 0, r, y, new_y = 0, binary_y = 0, n = 0, numzero = 0;
va_list args;
va_start(args,format);
if (format == NULL)
{
return (-1);
}
for (i = 0; i < a; i++)
{
if(*(format + i) == '%' && *(format + i + 1) == 'c')
{
z = va_arg(args, int);
_putchar(z);
i++;
c++;
}
else if (*(format + i) == '%' && *(format + i + 1) == 's')
{
x = va_arg(args, char*);
b = strlen(x);
for (j = 0; j < b; j++)
{
_putchar(*(x + j));
c++;
}
i++;
}
else if (*(format + i) == '%' && *(format + i + 1) == '%')
{
_putchar('%');
i++;
c++;
}
else if (*(format + i) == '%' && (*(format + i + 1) == 'd' || *(format + i + 1) == 'i'))
{
y = va_arg(args, int);
if (y < 0)
{
y = -y;
_putchar('-');
c++;
}
for (j = 0; y != 0; j++)
{
r = y % 10;
y = y / 10;   
new_y = new_y * 10 + r;
}
for (j = 0; new_y != 0; j++)
{
r = new_y % 10;
new_y = new_y / 10;
_putchar(r + 48);
c++;
}
i++;
}
else if (*(format + i) == '%' && *(format + i + 1) == 'b')
{
y = va_arg(args, unsigned int);
for (j = 0; y != 0; j++)
{
r = y % 2;
if (r == 1)
{
n = 1;
}
if (n == 0)
{
numzero++;
}
y = y / 2;
binary_y =  binary_y * 10 + r;     
}
for (j = 0; binary_y != 0; j++)
{
r = binary_y % 10;
binary_y = binary_y / 10;
_putchar(r + 48);
c++;
}
for (j = 0;j < numzero; j++)
{
_putchar('0');
c++;
}
i++;
}
else
{
_putchar(*(format + i));
c++;
}
}
va_end(args);
return (c);
}
