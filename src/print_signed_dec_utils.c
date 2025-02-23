/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_signed_dec_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 13:24:30 by akyoshid          #+#    #+#             */
/*   Updated: 2025/02/23 12:39:30 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int	get_digit_signed_dec(int num)
{
	int	digit;

	digit = 0;
	if (num == INT_MIN)
		return (10);
	else if (num < 0)
		num *= -1;
	else if (num == 0)
		return (1);
	while (num > 0)
	{
		num /= 10;
		digit++;
	}
	return (digit);
}

char	*get_num_str_signed_dec(t_syntax *syntax, int num, int digit)
{
	char	*num_str;
	int		count;

	if (syntax->precision_flag == true
		&& syntax->precision_value == 0 && num == 0)
		return (ft_strdup(""));
	num_str = (char *)malloc(sizeof(char) * (digit + 1 + 1));
	if (num_str == NULL)
		return (NULL);
	if (num == INT_MIN)
	{
		ft_strlcpy(num_str, "2147483648", digit + 1 + 1);
		return (num_str);
	}
	if (num < 0)
		num *= -1;
	count = 0;
	while (count < digit)
	{
		num_str[digit - count - 1] = num % 10 + '0';
		num /= 10;
		count++;
	}
	num_str[digit] = '\0';
	return (num_str);
}

char	*append_sign(t_syntax *syntax, char *num_str, bool minus_flag)
{
	ft_memmove(num_str + 1, num_str, ft_strlen(num_str) + 1);
	if (minus_flag == true)
		num_str[0] = '-';
	else if (syntax->plus_flag == true)
		num_str[0] = '+';
	else if (syntax->space_flag == true)
		num_str[0] = ' ';
	return (num_str);
}
