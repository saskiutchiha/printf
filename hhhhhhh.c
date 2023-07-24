#include <string.h>
#include "main.h"
int _printf(const char *format, ...)
{
int i,a= strlen(format);
for (i=0;i<a;i++)
{
_putchar(*(format+i));
}
return (a);
}
