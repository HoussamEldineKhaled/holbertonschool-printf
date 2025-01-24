#include "main.h"
#include <stdarg.h>
#include <unistd.h>
int _printf(const char *format, ...)
{
  int count = 0;
  char c;
  char *s;
  va_list args;

  va_start(args, format);
  while(*format != '\0')
    {
      if (*format == '%')
	{
	  format++;
	  if (*format == '%')
	    {
	      write(1, "%", 1);
	      format++;
	      count++;
	    }
	  else if (*format == 'c')
	    {
	      c = (char) va_arg(args, int);
	      write(1, &c, 1);
	      format++;
	      count++;
	    }
	  else if(*format == 's')
	    {
	      s = va_arg(args, char *);
	      while (*s)
		{	
	      write(1, s, 1);
	      s++;
	      count++;
		}
	      format++;
	    }
	}

    }
  va_end(args);
      return (count);
}
