#include "main.h"

/**
* get_precision - Extracts the precision for printing from the format string
* @format: Formatted string containing conversion specifiers
* @i: Pointer to the current position in the format string
* @list: List of arguments for variable precision
*
* Return: Precision value for printing
*/
int get_precision(const char *format, int *i, va_list list)
{
int curr_i = *i + 1;
int precision = -1;

/* Check if precision is present */
if (format[curr_i] != '.')
return (precision);

precision = 0;

/* Parse the precision value */
for (curr_i += 1; format[curr_i] != '\0'; curr_i++)
{
if (is_digit(format[curr_i]))
{
precision *= 10;
precision += format[curr_i] - '0';
}
else if (format[curr_i] == '*')
{
curr_i++;
precision = va_arg(list, int);
break;
}
else
break;
}

*i = curr_i - 1;
return (precision);
}
