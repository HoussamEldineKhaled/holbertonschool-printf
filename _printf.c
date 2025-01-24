#include "main.h"
#include <stdarg.h>
#include <unistd.h>

int _printf(const char *format, ...)
{
  int i = 0;
  int count = 0;
  char c;
  char *s;
  va_list args;

  va_start(args, format);

  if (!format)
    {
      return (-1);
    }
  while(format && format[i])
    {
      if (format[i] == '%')
	{
	  i++;
	  if (format[i] == 'c')
	    {
	      c = (char) va_arg(args, int);
	      write(1, &c, 1);
	      count++;
	    }
	  else if (format[i] == 's')
	    {
	      s = va_arg(args, char *);
	      if (!s)
		{
		  s = "(null)";
		}
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
  va_end(args);
      return (count);
}
