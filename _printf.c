#include "main.h"
#include <stdarg.h>
#include <unistd.h>
#include <limits.h>
/**
 * increase - increase count
 * @count: counter
 * @i: iterator
 * @numb: integer
 * @c: character
 * @s: string
 * @format: string format
 * @args: arguments
 * Return: -1 or count
*/
int increase(int count, int i, int numb, char c, char *s,
const char *format, va_list args)
{
int j, isnegative = 0;
char buffer[12];
while (format && format[i])
{
if (format[i] == '%')
{
i++;
if (format[i] == '\0')
return (-1);
if (format[i] == 'c')
{
c = (char) va_arg(args, int);
write(1, &c, 1);
count++;
}
else if (format[i] == 'd' || format[i] == 'i')
{
numb = va_arg(args, int);
j = 0;
if (numb == 0)
{
buffer[j++] = '0';
} 
else if (numb < 0)
{
isnegative = 1;
if (numb == INT_MIN)
{
buffer[j++] = '8';
numb = -(numb / 10);
}
else
{
numb = -numb;
}
}
while (numb > 0)
{
buffer[j++] = (numb % 10) + '0';
numb /= 10;
}
if (isnegative)
{
buffer[j++] = '-';
}
while (j > 0)
{
write(1, &buffer[--j], 1);
count++;     
}
}
else if (format[i] == 's')
{
s = va_arg(args, char *);
if (!s)
s = "(null)";
while (*s)
{
write(1, s, 1);
count++;
s++;
}
}
else if (format[i] == '%')
{
write(1, "%", 1);
count++;
}
else
{
write(1, "%", 1);
write(1, &format[i], 1);
count += 2;
}
}
else
{
write(1, &format[i], 1);
count++;
}
i++;
}
return (count);
}
/**
 * _printf - printing s, c, and %
 * @format: string format
 * Return: -1 or count
*/
int _printf(const char *format, ...)
{
int i = 0;
int count = 0;
char c = 'a';
char *s = "";
int num = 0;
va_list args;
va_start(args, format);
if (!format)
{
return (-1);
}
count = increase(count, i, num, c, s, format, args);
va_end(args);
return (count);
}
