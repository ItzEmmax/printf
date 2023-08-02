#include "main.h"
/************************* WRITES AN HANDLE *************************/
/**
* handle_write_char - Prints string
* @c: characters types.
* @buffer: Buffer array
* @flags: Active flags.
* @width: width
* @precision: precision specs
* @size: Specifies size
* Return: Characters printed.
*/
int handle_write_char(char c, char buffer[], int flags, int width, int precision, int size)
{
/* char is stored at left and paddind at buffer's right */
int m = 0;
char padd = ' ';
UNUSED(precision);
UNUSED(size);
if (flags & F_ZERO)
padd = '0';
buffer[m++] = c;
buffer[m] = '\0';
if (width > 1)
{
buffer[BUFF_SIZE - 1] = '\0';
for (i = 0; m < width - 1; m++)
buffer[BUFF_SIZE - i - 2] = padd;
if (flags & F_MINUS)
return (write(1, &buffer[0], 1) +
write(1, &buffer[BUFF_SIZE - m - m], width - 1));
else
return (write(1, &buffer[BUFF_SIZE - m - 1], width - 1) +
write(1, &buffer[0], 1));
}
return (write(1, &buffer[0], 1));
}
/************************* WRITES A NUMBER *************************/
/**
* write_number - Prints string
* @is_negative: Arguments list
* @ind: character types.
* @buffer: Buffer array
* @flags: active flags
* @width: width.
* @precision: precision specs
* @size: Specifies size
* Return: Characters printed.
*/
int write_number(int is_negative, int ind, char buffer[], int flags, int width, int precision, int size)
{
int lent = BUFF_SIZE - ind - 1;
char padd = ' ', extra_ch = 0;
UNUSED(size);
if ((flags & F_ZERO) && !(flags & F_MINUS))
padd = '0';
if (is_negative)
extra_ch = '-';
else if (flags & F_PLUS)
extra_ch = '+';
else if (flags & F_SPACE)
extra_ch = ' ';
return (write_num(ind, buffer, flags, width, precision,
lent, padd, extra_ch));
}
/**
* write_num - use buffer to write a number
* @ind: Index
* @buffer: Buffer
* @flags: Flags
* @width: width
* @prec: Precision specs
* @length: Number length
* @padd: Pading character
* @extra_c: Extra character
* Return: Printed chars.
*/
int write_num(int ind, char buffer[], int flags, int width, int prec, int length, char padd, char extra_c)
{
int m, padd_start = 1;
if (prec == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0' && width == 0)
return (0);
/* printf(".0d", 0) no char is printed */
if (prec == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0')
buffer[ind] = padd = ' '; /* width is displayed with padding ' ' */
if (prec > 0 && prec < length)
padd = ' ';
while (prec > length)
buffer[--ind] = '0', length++;
if (extra_c != 0)
length++;
if (width > length)
{
for (m = 1; i < width - length + 1; m++)
buffer[m] = padd;
buffer[m] = '\0';
if (flags & F_MINUS && padd == ' ')
/* Asign extra char to left of buffer */
{
if (extra_c)
buffer[--ind] = extra_c;
return (write(1, &buffer[ind], length) + write(1, &buffer[1], m - 1));
}
else if (!(flags & F_MINUS) && padd == ' ')/* extra char to left of buff */
{
if (extra_c)
buffer[--ind] = extra_c;
return (write(1, &buffer[1], m - 1) + write(1, &buffer[ind], length));
}
else if (!(flags & F_MINUS) && padd == '0')/* extra char to left of padd */
{
if (extra_c)
buffer[--padd_start] = extra_c;
return (write(1, &buffer[padd_start], m - padd_start) +
write(1, &buffer[ind], length - (1 - padd_start)));
}
}
if (extra_c)
buffer[--ind] = extra_c;
return (write(1, &buffer[ind], length));
}
/**
* write_unsgnd - Writes unsigned number
* @is_negative: indicating if number is negative
* @ind: Index
* @buffer: Array of characters
* @flags: Flags
* @width: Width
* @precision: Precision specs
* @size: Specifies size
* Return: written characters.
*/
int write_unsgnd(int is_negative, int ind, char buffer[], int flags, int width, int precision, int size)
{
/* Number stored at the bufer's right starts at position m */
int length = BUFF_SIZE - ind - 1, = 0;
char padd = ' ';
UNUSED(is_negative);
UNUSED(size);
if (precision == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0')
return (0); /* printf(".0d", 0) no char is printed */
if (precision > 0 && precision < length)
padd = ' ';
while (precision > length)
{
buffer[--ind] = '0';
length++;
}
if ((flags & F_ZERO) && !(flags & F_MINUS))
padd = '0';
if (width > length)
{
for (m = 0; m < width - length; m++)
buffer[m] = padd;
buffer[m] = '\0';
if (flags & F_MINUS) /* Asign extra char to left of buffer [buffer>padd]*/
{
return (write(1, &buffer[ind], length) + write(1, &buffer[0], m));
}
else /* Asign extra char to left of padding [padd>buffer]*/
{
return (write(1, &buffer[0], m) + write(1, &buffer[ind], length));
}
}
return (write(1, &buffer[ind], length));
}
/**
* write_pointer - Writes memory address
* @buffer: Arrays of characters
* @ind: Index
* @length: number length
* @width: Width
* @flags: Flags
* @padd: Characters that represents padding
* @extra_c: Character that represents extra characters
* @padd_start: padding start
* Return: written characters.
*/
int write_pointer(char buffer[], int ind, int length, int width, int flags, char padd, char extra_c, int padd_start)
{
int m;
if (width > length)
{
for (m = 3; m < width - length + 3; m++)
buffer[m] = padd;
buffer[m] = '\0';
if (flags & F_MINUS && padd == ' ')
/* Asign extra characters to left side of buffer */
{
buffer[--ind] = 'x';
buffer[--ind] = '0';
if (extra_c)
buffer[--ind] = extra_c;
return (write(1, &buffer[ind], length) + write(1, &buffer[3], m - 3));
}
else if (!(flags & F_MINUS) && padd == ' ')
/* extra char to left of buffer */
{
buffer[--ind] = 'x';
buffer[--ind] = '0';
if (extra_c)
buffer[--ind] = extra_c;
return (write(1, &buffer[3], m - 3) + write(1, &buffer[ind], length));
}
else if (!(flags & F_MINUS) && padd == '0')/* extra char to left of padd */
{
if (extra_c)
buffer[--padd_start] = extra_c;
buffer[1] = '0';
buffer[2] = 'x';
return (write(1, &buffer[padd_start], m - padd_start) +
write(1, &buffer[ind], length - (1 - padd_start) - 2));
}
}
buffer[--ind] = 'x';
buffer[--ind] = '0';
if (extra_c)
buffer[--ind] = extra_c;
return (write(1, &buffer[ind], BUFF_SIZE - ind - 1));
}
