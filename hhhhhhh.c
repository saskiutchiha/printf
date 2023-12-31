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
char *x, z,base_sexteen[10];
int i, j, a = strlen(format), b, c = 0, r, y, new_y = 0, binary_y = 0, n = 0, numzero = 0,octale_y,k;
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
else if (*(format + i) == '%' && *(format + i + 1) == 'S')
{
x = va_arg(args, char*);
b = strlen(x);
for (j = 0; j < b; j++)
{
if (*(x + j) < 32 || *(x + j) >=127)
{
  _putchar(92);
  _putchar(120);
  _putchar('0');
  c++;
  y = *(x + j);
for (k = 0; y != 0; k++)
{
r = y % 16;
y = y /16;
if (r<10)
{
base_sexteen[j]=r +48;
}
else
{
base_sexteen[j]=r + 55;
}
}
k--;
for(;k>=0;k--)
  {
    _putchar(base_sexteen[j]);
    c++;
  }

}
  else{
    _putchar(*(x + j));
    c++;
  }
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
new_y =0;
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
n=0;
binary_y =0;
}

else if (*(format + i) == '%' && *(format + i + 1) == 'X')
{
  y = va_arg(args,int);
for (j = 0; y != 0; j++)
{
r = y % 16;
y = y /16;
if (r<10)
{
base_sexteen[j]=r +48;
}
else
{
base_sexteen[j]=r + 55;
}
}
j--;
for(;j>=0;j--)
  {
    _putchar(base_sexteen[j]);
    c++;
  }
  i++;
}
else if (*(format + i) == '%' && *(format + i + 1) == 'x')
{
  y = va_arg(args,int);
for (j = 0; y != 0; j++)
{
r = y % 16;
y = y /16;
if (r<10)
{
base_sexteen[j]=r +48;
}
else
{
base_sexteen[j]=r + 87;
}
}
j--;
for(;j>=0;j--)
  {
    _putchar(base_sexteen[j]);
    c++;
  }
  i++;
}
  else if (*(format + i) == '%' && *(format + i + 1) == 'o')
{
y = va_arg(args, unsigned int);
for (j = 0; y != 0; j++)
{
r = y % 8;
if (r != 1)
{
n = 1;
}
if (n == 0)
{
numzero++;
}
y = y / 8;
octale_y =  octale_y * 10 + r;     
}
for (j = 0; octale_y != 0; j++)
{
r = octale_y % 10;
octale_y = octale_y / 10;
_putchar(r + 48);
c++;
}
for (j = 0;j < numzero; j++)
{
_putchar('0');
c++;
}
i++;
n=0;
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
