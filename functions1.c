#include "main.h"

/*************** PRINT UNSI******************/
/**
 * print_unsigned - Function that prints an
 * unsigned number
 * @types: data types
 * @buffer: temporary storage space
 * @flags: Boolean variable
 * @width:integer dtm btw % and d
 * @precision: printing the real numbers
 * @size: Size determined
 * Return: No of unsi
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

/** Printing octal of unsigned numbers**/
/**
 * print_octal - Prints an unsigned num.
 * @types: data types
 * @buffer: temporary storage
 * @flags:Boolean variable
 * @width: integer added btw % and d
 * @precision:printing the real numbers
 * @size: data type size
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

/** printing hexadecimal **/
/**
 * print_hexadecimal - Prints hexadecimal
 * @types: data types
 * @buffer: temporary storage
 * @flags:  boolean variable
 * @width: integer btw % and d
 * @precision:raelness of number
 * @size: data size
 * Return: hexadecimals
 */
int print_hexadecimal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789abcdef", buffer,
		flags, 'x', width, precision, size));
}

/** Printing unsigned number in upper hexa**/
/**
 * print_hexa_upper - Function that prints an unsigned num.
 * @types: data types
 * @buffer: temporary storage
 * @flags: boolean variable
 * @width: integer btw % and d
 * @precision: realness of a number
 * @size: Sizeof 
 * Return: No of upper hexa
 */
int print_hexa_upper(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789ABCDEF", buffer,
		flags, 'X', width, precision, size));
}

/************** Printing hexa in upper and lower **************/
/**
 * print_hexa - prints hexa in upper or lowercase.
 *
 * @types: data types
 * @map_to: map to array
 * @buffer: temporary storage
 * @flags: boolean variable
 * @flag_ch: counts active boolean variables
 * @width: integer btw % and d
 * @precision: realness of a number
 * @size: Sizeof
 * Return: printed hexa in upp and low
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
