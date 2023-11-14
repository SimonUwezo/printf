#include "main.h"

/************************* PRINT UNSI*********************/
/**
 * print_unsigned - Function that prints an
 * unsigned number
 *
 * @types: Arguments
 * @buffer: an array to handle print
 * @flags:  No of active flags
 * @width: The width
 * @precision: Precision specifier
 * @size: Size specifier
 * Return: No of chars.
 */
int print_unsigned(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}

	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}

/************* PRINT UNSIGNED NUMBER IN OCTAL  ****************/
/**
 * print_octal - Prints an unsigned num.
 * @types: No of arguments
 * @buffer: An array to handle the print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specifier
 * @size: Size specifier
 * Return: No of chars.
 */
int print_octal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{

	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = (num % 8) + '0';
		num /= 8;
	}

	if (flags & F_HASH && init_num != 0)
		buffer[i--] = '0';

	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}

/************** PRINT UNSIGNED NUMBER IN HEXADECIMAL **************/
/**
 * print_hexadecimal - Prints an unsigned num
 * @types: No of arguments
 * @buffer: An array to handle the print
 * @flags:  Active flags
 * @width: The width
 * @precision: Precision specifier
 * @size: Size specifier
 * Return: No of chars.
 */
int print_hexadecimal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789abcdef", buffer,
		flags, 'x', width, precision, size));
}

/************* PRINT UNSIGNED NUMBER IN UPPER HEXADECIMAL **************/
/**
 * print_hexa_upper - Function that prints an unsigned num.
 * @types: No of args
 * @buffer: An array to handle the print
 * @flags:  Active flags
 * @width: The width
 * @precision: Precision specifier
 * @size: Size specifier
 * Return: No of chars.
 */
int print_hexa_upper(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789ABCDEF", buffer,
		flags, 'X', width, precision, size));
}

/************** PRINT HEXX NUM IN LOWER OR UPPER **************/
/**
 * print_hexa - Function that prints a hexadecimal num
 * in lower or upper case.
 *
 * @types: The arguments
 * @map_to: Array of values to map the num
 * @buffer: An array to handle print
 * @flags:  Active flags
 * @flag_ch: Calculates active flags
 * @width: get width
 * @precision: Precision specifier
 * @size: Size specifier
 * Return: No of chars printed
 */
int print_hexa(va_list types, char map_to[], char buffer[],
	int flags, char flag_ch, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = map_to[num % 16];
		num /= 16;
	}

	if (flags & F_HASH && init_num != 0)
	{
		buffer[i--] = flag_ch;
		buffer[i--] = '0';
	}

	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}
