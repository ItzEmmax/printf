#include "main.h"

/************************* PRINT UNSIGNED NUMBER *************************/
/**
 * print_unsigned - Prints unsigned number
 * @types: Argument List
 * @buffer: Buffer array
 * @flags:  To calculate active flags
 * @width: width
 * @precision: Precision of the specs
 * @size: Specifies size
 * Return: Number of characters to be printed.
 */
int print_unsigned(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	int m = BUFF_SIZE - 2;
	unsigned long int n = va_arg(types, unsigned long int);

	n = convert_size_unsgnd(n, size);

	if (n == 0)
		buffer[m--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (n > 0)
	{
		buffer[m--] = (n % 10) + '0';
		n /= 10;
	}

	m++;

	return (write_unsgnd(0, m, buffer, flags, width, precision, size));
}

/************* PRINT UNSIGNED NUMBER IN OCTAL  ****************/
/**
 * print_octal - Prints unsigned number in octal
 * * @types: Argument List
 * @buffer: Buffer array
 * @flags:  To calculate active flags
 * @width: width
 * @precision: Specification of precision
 * @size: Specifies size
 * Return: Number of characters to be printed
 */
int print_octal(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{

	int m = BUFF_SIZE - 2;
	unsigned long int n = va_arg(types, unsigned long int);
	unsigned long int init_num = n;

	UNUSED(width);

	n = convert_size_unsgnd(num, size);

	if (n == 0)
		buffer[m--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (n > 0)
	{
		buffer[m--] = (n % 8) + '0';
		n /= 8;
	}

	if (flags & F_HASH && init_n != 0)
		buffer[m--] = '0';

	i++;

	return (write_unsgnd(0, m, buffer, flags, width, precision, size));
}

/************** PRINT UNSIGNED NUMBER IN HEXADECIMAL **************/
/**
 * print_hexadecimal - Prints unsigned number in hexadecimal
 * @types: Argument list
 * @buffer: Buffer array
 * @flags:  To calculate active flags
 * @width: width
 * @precision: Specification precision
 * @size: Specifies size
 * Return: Number of characters to be printed
 */
int print_hexadecimal(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789abcdef", buffer,
				flags, 'x', width, precision, size));
}

/************* PRINT UNSIGNED NUMBER IN UPPER HEXADECIMAL **************/
/**
 * print_hexa_upper - Prints unsigned number in upper hexadecimal
 * @types: Argument list
 * @buffer: Buffer array
 * @flags:  To calculate active flags
 * @width: width
 * @precision: Specification precision
 * @size: Specifies size
 * Return: Number of characters to be printed
 */
int print_hexa_upper(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789ABCDEF", buffer,
				flags, 'X', width, precision, size));
}

/************** PRINT HEXX NUM IN LOWER OR UPPER **************/
/**
 * print_hexa - Prints a hexadecimal number in lowercase or uppercase
 * @types: Argument list
 * @map_to: Array of values to map number to
 * @buffer: Buffer array
 * @flags:  To calculate active flags
 * @flag_ch: To calculate active flags
 * @width: width
 * @precision: Specification precision
 * @size: Specifies size
 * @size: Specification size
 * Return: Number of characters to be printed
 */
int print_hexa(va_list types, char map_to[], char buffer[],
		int flags, char flag_ch, int width, int precision, int size)
{
	int m = BUFF_SIZE - 2;
	unsigned long int n = va_arg(types, unsigned long int);
	unsigned long int init_n = n;

	UNUSED(width);

	n = convert_size_unsgnd(n, size);

	if (n == 0)
		buffer[n--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (n > 0)
	{
		buffer[m--] = map_to[n % 16];
		n /= 16;
	}

	if (flags & F_HASH && init_n != 0)
	{
		buffer[m--] = flag_ch;
		buffer[m--] = '0';
	}

	m++;

	return (write_unsgnd(0, m, buffer, flags, width, precision, size));
}



