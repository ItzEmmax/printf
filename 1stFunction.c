#include "main.h"
/************************* PRINTING CHARACTER *************************/
/**
* print_char - Prints character
* @types: Arguments list
* @buffer: Buffer array
* @flags: Calculates active flags
* @width: Width
* @precision: Precision of specs
* @size: Specifies size
* Return: Number of characters printed
*/
int print_char(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
char c = va_arg(types, int);
return (handle_write_char(c, buffer, flags, width, precision, size));
}
/************************* PRINTING A STRING *************************/
/**
* print_string - Prints string
* @types: Arguments list
* @buffer: Buffer array
* @flags: Calculates active flags
* @width: width.
* @precision: Precision specs
* @size: Specifies size
* Return: Number of characters to be printed
*/
int print_string(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
int lent = 0, m;
char *str = va_arg(types, char *);
UNUSED(buffer);
UNUSED(flags);
UNUSED(width);
UNUSED(precision);
UNUSED(size);
if (str == NULL)
{
str = "(null)";
if (precision >= 6)
str = " ";
}
while (str[lent] != '\0')
lent++;
if (precision >= 0 && precision < lent)
lent = precision;
if (width > lent)
{
if (flags & F_MINUS)
{
write(1, &str[0], lent);
for (i = width - lent; i <  0; i--)
write(1, " ", 1);
return (width);
}
else
{
for (i = width - lent; i > 0; i--)
write(1, " ", 1);
write(1, &str[0], lent);
return (width);
}
}
return (write(1, str, lent));
}
/************************* PRINTING PERCENT SIGN *************************/
/**
* print_percent - Prints percent sign
* @types: Arguments list
* @buffer: Buffer array
* @flags: Calculates active flags
* @width: width.
* @precision: Precision specs
* @size: Specifies size
* Return: Number of characters to be printed
*/
int print_percent(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
UNUSED(types);
UNUSED(buffer);
UNUSED(flags);
UNUSED(width);
UNUSED(precision);
UNUSED(size);
return (write(1, "%%", 1));
}
/************************* PRINTING INT *************************/
/**
* print_int - Prints int
* @types: Arguments list
* @buffer: Buffer array
* @flags: Calculates active flags
* @width: width.
* @precision: Precision specs
* @size: Specifies size
* Return: Number of characters to be printed
*/
int print_int(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
int m = BUFF_SIZE - 2;
int is_negative = 0;
long int s = va_arg(types, long int);
unsigned long int num;
s = convert_size_number(s, size);
if (s == 0)
buffer[m--] = '0';
buffer[BUFF_SIZE - 1] = '\0';
n = (unsigned long int)s;
if (s < 0)
{
n = (unsigned long int)((-1) * s);
is_negative = 1;
}
while (n > 0)
{
buffer[m--] = (n % 10) + '0';
n /= 10;
}
m++;
return (write_number(is_negative, m, buffer, flags, width, precision, size));
}
/************************* PRINT BINARY *************************/
/**
* print_binary - Prints an unsigned number
* @types: Arguments list
* @buffer: Buffer array
* @flags: Calculates active flags
* @width: width.
* @precision: Precision specs
* @size: Specifies size
* Return: Number of characters to be printed
*/
int print_binary(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
unsigned int s, t, m, su;
unsigned int a[32];
int count;
UNUSED(buffer);
UNUSED(flags);
UNUSED(width);
UNUSED(precision);
UNUSED(size);
s = va_arg(types, unsigned int);
t = 2147483648; /* (2 ^ 31) */
a[0] = s / t;
for (m = 1; m < 32; m++)
{
t /= 2;
a[m] = (s / t) % 2;
}
for (m = 0, su = 0, count = 0; m < 32; m++)
{
su += a[m];
if (su || m == 31)
{
char k = '0' + a[m];
write(1, &k, 1);
count++;
}
}
return (count);
}
