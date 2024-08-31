/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 05:29:50 by akyoshid          #+#    #+#             */
/*   Updated: 2024/08/31 10:10:56 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void	ft_check_error(int a, int b)
{
	if (a != b)
		printf("\x1b[31mThe return values are different!\n");
}

int	main(void)
{
	int				printf_count = 0;
	int				ft_printf_count = 0;
	char			c = 'c';
	int				i = 2147483491;
	unsigned int	ui = 4294967139;
	char			str[] = "string";
	char			empty[] = "";
	char			*np = NULL;

	printf("\n=== %%c ===\n");
	printf_count += printf("%c\n", c);
	ft_printf_count += ft_printf("%c\n", c);
	ft_check_error(printf_count, ft_printf_count);
	printf_count += printf("%c\n", i);
	ft_printf_count += ft_printf("%c\n", i);
	ft_check_error(printf_count, ft_printf_count);
	printf_count += printf("%c\n", ui);
	ft_printf_count += ft_printf("%c\n", ui);
	ft_check_error(printf_count, ft_printf_count);
	printf("\n=== %%s ===\n");
	printf_count += printf("%s\n", str);
	ft_printf_count += ft_printf("%s\n", str);
	ft_check_error(printf_count, ft_printf_count);
	printf_count += printf("%s\n", empty);
	ft_printf_count += ft_printf("%s\n", empty);
	ft_check_error(printf_count, ft_printf_count);
	printf_count += printf("%s\n", np);
	ft_printf_count += ft_printf("%s\n", np);
	ft_check_error(printf_count, ft_printf_count);
	printf("\n=== %%d ===\n");
	printf_count += printf("%d\n", 0);
	ft_printf_count += ft_printf("%d\n", 0);
	ft_check_error(printf_count, ft_printf_count);
	printf_count += printf("%d\n", -100);
	ft_printf_count += ft_printf("%d\n", -100);
	ft_check_error(printf_count, ft_printf_count);
	printf_count += printf("%d\n", INT_MAX);
	ft_printf_count += ft_printf("%d\n", INT_MAX);
	ft_check_error(printf_count, ft_printf_count);
	printf_count += printf("%d\n", INT_MIN);
	ft_printf_count += ft_printf("%d\n", INT_MIN);
	ft_check_error(printf_count, ft_printf_count);
	printf_count += printf("%d\n", ui);
	ft_printf_count += ft_printf("%d\n", ui);
	ft_check_error(printf_count, ft_printf_count);
	printf("\n=== %%i ===\n");
	printf_count += printf("%i\n", 0);
	ft_printf_count += ft_printf("%i\n", 0);
	ft_check_error(printf_count, ft_printf_count);
	printf_count += printf("%i\n", -100);
	ft_printf_count += ft_printf("%i\n", -100);
	ft_check_error(printf_count, ft_printf_count);
	printf_count += printf("%i\n", INT_MAX);
	ft_printf_count += ft_printf("%i\n", INT_MAX);
	ft_check_error(printf_count, ft_printf_count);
	printf_count += printf("%i\n", INT_MIN);
	ft_printf_count += ft_printf("%i\n", INT_MIN);
	ft_check_error(printf_count, ft_printf_count);
	printf_count += printf("%i\n", ui);
	ft_printf_count += ft_printf("%i\n", ui);
	ft_check_error(printf_count, ft_printf_count);
	printf("\n=== %%u ===\n");
	printf_count += printf("%u\n", 0);
	ft_printf_count += ft_printf("%u\n", 0);
	ft_check_error(printf_count, ft_printf_count);
	printf_count += printf("%u\n", UINT_MAX);
	ft_printf_count += ft_printf("%u\n", UINT_MAX);
	ft_check_error(printf_count, ft_printf_count);
	printf_count += printf("%u\n", -100);
	ft_printf_count += ft_printf("%u\n", -100);
	ft_check_error(printf_count, ft_printf_count);
	printf("\n=== %%x ===\n");
	printf_count += printf("%x\n", 0);
	ft_printf_count += ft_printf("%x\n", 0);
	ft_check_error(printf_count, ft_printf_count);
	printf_count += printf("%x\n", UINT_MAX);
	ft_printf_count += ft_printf("%x\n", UINT_MAX);
	ft_check_error(printf_count, ft_printf_count);
	printf_count += printf("%x\n", -100);
	ft_printf_count += ft_printf("%x\n", -100);
	ft_check_error(printf_count, ft_printf_count);
	printf("\n=== %%X ===\n");
	printf_count += printf("%X\n", 0);
	ft_printf_count += ft_printf("%X\n", 0);
	ft_check_error(printf_count, ft_printf_count);
	printf_count += printf("%X\n", UINT_MAX);
	ft_printf_count += ft_printf("%X\n", UINT_MAX);
	ft_check_error(printf_count, ft_printf_count);
	printf_count += printf("%X\n", -100);
	ft_printf_count += ft_printf("%X\n", -100);
	ft_check_error(printf_count, ft_printf_count);
	printf("\n=== %%p ===\n");
	printf_count += printf("%p\n", str);
	ft_printf_count += ft_printf("%p\n", str);
	ft_check_error(printf_count, ft_printf_count);
	printf_count += printf("%p\n", &c);
	ft_printf_count += ft_printf("%p\n", &c);
	ft_check_error(printf_count, ft_printf_count);
	printf_count += printf("%p\n", np);
	ft_printf_count += ft_printf("%p\n", np);
	ft_check_error(printf_count, ft_printf_count);
	printf("=== %%%% ===\n");
	printf_count += printf("%");
	ft_printf_count += ft_printf("%");
	ft_check_error(printf_count, ft_printf_count);
	printf_count += printf("%   ");
	ft_printf_count += ft_printf("%   ");
	ft_check_error(printf_count, ft_printf_count);
	printf_count += printf("%\n");
	ft_printf_count += ft_printf("%\n");
	ft_check_error(printf_count, ft_printf_count);
	printf_count += printf("%%\n");
	ft_printf_count += ft_printf("%%\n");
	ft_check_error(printf_count, ft_printf_count);
	printf_count += printf("%%%\n");
	ft_printf_count += ft_printf("%%%\n");
	ft_check_error(printf_count, ft_printf_count);
	printf_count += printf("' '	: %   c\n", 'a');
	ft_printf_count += ft_printf("' '	: %   c\n", 'a');
	ft_check_error(printf_count, ft_printf_count);
	printf_count += printf("'\\t'	: %\t\t\tc\n", 'a');
	ft_printf_count += ft_printf("'\\t'	: %\t\t\tc\n", 'a');
	ft_check_error(printf_count, ft_printf_count);
	printf_count += printf("'\\v'	: %\v\v\vc\n", 'a');
	ft_printf_count += ft_printf("'\\v'	: %\v\v\vc\n", 'a');
	ft_check_error(printf_count, ft_printf_count);
	printf_count += printf("'\\n'	: %\n\n\nc\n", 'a');
	ft_printf_count += ft_printf("'\\n'	: %\n\n\nc\n", 'a');
	ft_check_error(printf_count, ft_printf_count);
	printf_count += printf("'\\r'	: %\r\r\rc\n", 'a');
	ft_printf_count += ft_printf("'\\r'	: %\r\r\rc\n", 'a');
	ft_check_error(printf_count, ft_printf_count);
	printf_count += printf("'\\f'	: %\f\f\fc\n", 'a');
	ft_printf_count += ft_printf("'\\f'	: %\f\f\fc\n", 'a');
	ft_check_error(printf_count, ft_printf_count);
	printf("\n=== Undefined conversion specification ===\n");
	printf_count += printf("%b%k%r%w%y% %B%H%J%K%M%N%P%Q%R%T%V%W%Y\n");
	ft_printf_count += ft_printf("%b%k%r%w%y% %B%H%J%K%M%N%P%Q%R%T%V%W%Y\n");
	ft_check_error(printf_count, ft_printf_count);
	printf("\n=== If undefined conversion specifications & %%%% are included in fmt, can it correctly take va? ===\n");
	printf_count += printf("| %c | %s | %% | %d | %i | %u | %b | %x | %X | %p |\n", c, str, INT_MIN, INT_MIN + 1, UINT_MAX, UINT_MAX, UINT_MAX - 1, str);
	ft_printf_count += ft_printf("| %c | %s | %% | %d | %i | %u | %b | %x | %X | %p |\n", c, str, INT_MIN, INT_MIN + 1, UINT_MAX, UINT_MAX, UINT_MAX - 1, str);
	ft_check_error(printf_count, ft_printf_count);
	printf("\n=== More VAs than conversion specifications ===\n");
	printf_count += printf("| %c | %s | %% | %d | %i | %u | %b |\n", c, str, INT_MIN, INT_MIN + 1, UINT_MAX, UINT_MAX, UINT_MAX - 1, str);
	ft_printf_count += ft_printf("| %c | %s | %% | %d | %i | %u | %b |\n", c, str, INT_MIN, INT_MIN + 1, UINT_MAX, UINT_MAX, UINT_MAX - 1, str);
	ft_check_error(printf_count, ft_printf_count);
	printf("\n=== When an empty string is passed to fmt ===\n");
	printf_count += printf("");
	ft_printf_count += ft_printf("");
	ft_check_error(printf_count, ft_printf_count);
	// printf("\n=== When a NULL pointer is passed to fmt ===\n");
	// printf_count += printf(np);
	// ft_printf_count += ft_printf(np);
	return (0);
}
