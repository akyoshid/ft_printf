/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_signed_dec.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 05:23:06 by akyoshid          #+#    #+#             */
/*   Updated: 2025/02/08 14:12:24 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void	ft_print_signed_dec(int num, int *const cp)
{
	char	remainder;

	if (num == INT_MIN)
	{
		ft_print_str("-2147483648", cp);
		return ;
	}
	if (num < 0)
	{
		ft_print_char('-', cp);
		if (*cp == -1)
			return ;
		num *= -1;
	}
	remainder = num % 10 + '0';
	if (num / 10 > 0)
		ft_print_signed_dec(num / 10, cp);
	if (*cp != -1)
		ft_print_char(remainder, cp);
}

void	ft_wrapped_print_signed_dec_core(
	t_syntax *syntax, char *num_str, bool minus_flag, int *const cp)
{
	if (syntax->zero_flag == true && syntax->precision_flag == false
		&& syntax->width_flag == true && minus_flag == true)
	{
		syntax->width_value--;
		if (syntax->width_flag == true)
			num_str = proc_width(syntax, num_str);
		if (num_str == NULL)
			return ;
		if (minus_flag == true
			|| syntax->plus_flag == true || syntax->space_flag == true)
			num_str = append_sign(syntax, num_str, minus_flag);
	}
	else
	{
		if (minus_flag == true
			|| syntax->plus_flag == true || syntax->space_flag == true)
			num_str = append_sign(syntax, num_str, minus_flag);
		if (syntax->width_flag == true)
			num_str = proc_width(syntax, num_str);
		if (num_str == NULL)
			return ;
	}
	ft_print_str(num_str, cp);
	free(num_str);
}

void	ft_wrapped_print_signed_dec(t_syntax *syntax, int num, int *const cp)
{
	bool	minus_flag;
	int		digit;
	char	*num_str;

	minus_flag = false;
	if (num < 0)
		minus_flag = true;
	digit = get_digit_signed_dec(num);
	num_str = get_num_str_signed_dec(syntax, num, digit);
	if (num_str == NULL)
		return ;
	if (syntax->precision_flag == true && syntax->precision_value > digit)
		num_str = proc_precision(syntax, num_str, digit);
	if (num_str == NULL)
		return ;
	ft_wrapped_print_signed_dec_core(syntax, num_str, minus_flag, cp);
}
