#include "main.h"

/**
 * print_unsigned - printing unsigned no
 * @types: arguments list
 * @buffer: an array to handle the  print
 * @flags:computation of active flags
 * @width: obtain teh  width.
 * @precision:specifier of precision.
 * @size: specifier of size.
 * Return: xters printed
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

/**
 * print_octa - Prining unsigned no. in octal notation
 * @types:listing of arguments
 * @buffer: an array to handle the print
 * @flags: calc. active flags.
 * @width: obtain the width
 * @precision:speciy precicion
 * @size: specify the size
 * Return:the no. of chaacters printed
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

/**
 * print_hexadecimal - printinn unsigned num in hexa decimal notation
 * @types :arguments list.
 * @buffer: array handling print.
 * @flags:computing  active flags.
 * @width:obtain width
 * @precision: the precision specifiication.
 * @size: specifier of size
 * Return: characters printed
 */
int print_hexadecimal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789abcdef", buffer,
		flags, 'x', width, precision, size));
}

/**
 * print_hexa_upper - to print unsigned number in upper hexa_decimal notation
 * @types: arguments listing
 * @buffer: the array for  handling print.
 * @flags:active flags computation
 * @width: width obtaining
 * @precision: specifier for precision
 * @size: specifier of s!ze
 * Return: the no off characters printed
 */
int print_hexa_upper(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789ABCDEF", buffer,
		flags, 'X', width, precision, size));
}

/**
 * print_hex - to print hexadecimal number in lower or upper case
 * @types:arguments listing.
 * @map_to:an array of values  onto map the no
 * @buffer: the  array to handle print
 * @flag_ch:active flags computation
 * @flags: computes active flags.
 * @width:obtain the width
 * @precision: specification of precision
 * @size: the s!ze specifierr
 * Return: get the characters printed
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
