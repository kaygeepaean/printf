#include "main.h"
/**
* get_flags - Extracts and calculates active flags from the format string
* @format: Formatted string containing conversion specifiers
* @i: Pointer to the current position in the format string
* Return: Flags representing active flags
*/
int get_flags(const char *format, int *i)
{
int j, curr_i;
int flags = 0;
const char flags_chars[] = {'-', '+', '0', '#', ' ', '\0'};
const int flags_values[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

for (curr_i = *i + 1; format[curr_i] != '\0'; curr_i++)
{
for (j = 0; flags_chars[j] != '\0'; j++)
{
if (format[curr_i] == flags_chars[j])
{
flags |= flags_values[j];
break;
}
}
if (flags_chars[j] == '\0')
break;
}

*i = curr_i - 1;

return (flags);
}
