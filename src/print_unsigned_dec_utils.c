/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned_dec_utils.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 13:56:35 by akyoshid          #+#    #+#             */
/*   Updated: 2025/02/08 13:57:10 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int	get_digit_unsigned_dec(unsigned int num)
{
	int	digit;

	digit = 0;
	if (num  == 0)
		return (1);
	while (num > 0)
	{
		num /= 10;
		digit++;
	}
	return (digit);
}

char	*get_num_str_unsiged_dec(t_syntax *syntax, unsigned int num, int digit)
{
	char	*num_str;
	int		count;

	if (syntax->precision_flag == true
		&& syntax->precision_value == 0 && num == 0)
		return (ft_strdup(""));
	num_str = (char *)malloc(sizeof(char) * (digit + 1));
	if (num_str == NULL)
		return (NULL);
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
