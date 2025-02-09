/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 13:56:35 by akyoshid          #+#    #+#             */
/*   Updated: 2025/02/09 04:29:20 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int	get_digit_hex(unsigned long long num)
{
	int	digit;

	digit = 0;
	if (num  == 0)
		return (1);
	while (num > 0)
	{
		num /= 16;
		digit++;
	}
	return (digit);
}

char	*get_num_str_hex(
	t_syntax *syntax, unsigned long long num, int digit, int is_upper)
{
	char	*num_str;
	int		count;

	if (syntax->precision_flag == true
		&& syntax->precision_value == 0 && num == 0)
		return (ft_strdup(""));
	num_str = (char *)malloc(sizeof(char) * (digit + 1 + 2));
	if (num_str == NULL)
		return (NULL);
	count = 0;
	while (count < digit)
	{
		num_str[digit - count - 1] = num % 16 + '0';
		if (num_str[digit - count - 1] > '9' && is_upper == true)
			num_str[digit - count - 1] = num_str[digit - count - 1] - '0' - 10 + 'A';
		else if (num_str[digit - count - 1] > '9' && is_upper == false)
			num_str[digit - count - 1] = num_str[digit - count - 1] - '0' - 10 + 'a';
		num /= 16;
		count++;
	}
	num_str[digit] = '\0';
	return (num_str);
}

char	*append_prefix(char *num_str, int is_upper)
{
	ft_memmove(num_str + 2, num_str, ft_strlen(num_str) + 1);
	num_str[0] = '0';
	if (is_upper == true)
		num_str[1] = 'X';
	else
		num_str[1] = 'x';
	return (num_str);
}
