#include <string.h>
int _printf(const char *format, ...)
{
int i,a= strlen(format);
for (i=0;i<a;i++)
{
_putchar(*(format+i));
}
_putchar('\n');
return (a);
}