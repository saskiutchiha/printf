#include <string.h>
#include "main.h"
#include <stdarg.h>
#include <stddef.h>
int _printf(const char *format, ...)
{
char *x,z;
int i,j,a= strlen(format),b,c=0;
va_list args;

va_start(args,format);
if (format == NULL)
{
return -1;
}
for (i=0;i<a;i++)
{
if(*(format+i) == '%' && *(format+i+1) == 'c')
{
z = va_arg(args,int);
_putchar(z);
i++;
c++;
}
else if (*(format+i) == '%' && *(format+i+1) == 's')
{
  x = va_arg(args,char*);
  b = strlen(x);
for (j=0; j <b;j++)
  {
  _putchar(*(x+j));
    c++;
  }
  i++;
}
else
{
_putchar(*(format+i));
c++;
}
}
va_end(args);
return (c);
}
