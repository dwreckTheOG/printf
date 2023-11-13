#include "main.h"

/**
 * _printf - Produces output according to a format.
 * @format: The format string
 *
 * Return: The number of characters printed (excluding the null byte
 *         used to end output to strings)
 */
int _printf(const char *format, ...)
{
    va_list args;
    va_start(args, format);
    int i = 0;
    const char *str;

    while (*format)
    {
        if (*format == '%')
        {
            switch (*format)
            {
            case 'c':
                _putchar(va_arg(args, int));
                i++;
                break;
            
            case 's':
                str = va_arg(args, const char *);
                while (*str)
                {
                    _putchar(*str);
                    str++;
                    i++;
                }
                break;
            case '%':
                    putchar('%');
                    i++;
                    break;
            default:
                    putchar('%');
                    putchar(*format);
                    i += 2;
            }
        }
        else
        {
            _putchar(*format);
            i++;
        }
        format++;
    }
    va_end(args);
    return (i);
}