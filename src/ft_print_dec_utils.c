/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_dec_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 13:24:30 by akyoshid          #+#    #+#             */
/*   Updated: 2025/02/08 13:42:20 by akyoshid         ###   ########.fr       */
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

int	get_digit(int num)
{
	int	digit;

	digit = 0;
	if (num == INT_MIN)
		return (10);
	else if (num < 0)
		num *= -1;
	else if (num  == 0)
		return (1);
	while (num > 0)
	{
		num /= 10;
		digit++;
	}
	return (digit);
}

char	*get_num_str(t_syntax *syntax, int num, int digit)
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

char	*proc_precision(t_syntax *syntax, char *num_str, int digit)
{
	int		zero_padding_len;
	char	*temp;
	int		i;

	zero_padding_len = syntax->precision_value - digit;
	temp = (char *)malloc(sizeof(char) * (zero_padding_len + digit + 1 + 1));
	if (temp == NULL)
		return (free(num_str), NULL);
	i = 0;
	while (i < zero_padding_len)
	{
		temp[i] = '0';
		i++;
	}
	ft_strlcpy(temp + i, num_str, digit + 1 + 1);
	return (free(num_str), temp);
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

char	*proc_width(t_syntax *syntax, char *num_str)
{
	int		len;
	char	*temp;

	len = ft_strlen(num_str);
	if (syntax->width_value <= len)
		return (num_str);
	temp = (char *)malloc(sizeof(char) * syntax->width_value + 1 + 1);
	if (temp == NULL)
		return (free(num_str), NULL);
	else if (syntax->minus_flag == true)
	{
		ft_strlcpy(temp, num_str, syntax->width_value + 1 + 1);
		ft_memset(temp + len, ' ', syntax->width_value - len);
		temp[syntax->width_value] = '\0';
	}
	else
	{
		if (syntax->zero_flag == true && syntax->precision_flag == false)
			ft_memset(temp, '0', syntax->width_value - len);
		else
			ft_memset(temp, ' ', syntax->width_value - len);
		ft_strlcpy(temp + syntax->width_value - len,
			num_str, syntax->width_value + 1 + 1);
	}
	return (free(num_str), temp);
}
