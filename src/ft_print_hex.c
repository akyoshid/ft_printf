/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 05:23:58 by akyoshid          #+#    #+#             */
/*   Updated: 2025/02/23 12:43:55 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void	ft_print_hex_with_prefix(
	t_syntax *syntax, char *num_str, int is_upper, int *const cp)
{
	syntax->width_value = syntax->width_value - 2;
	if (syntax->width_flag == true)
		num_str = proc_width(syntax, num_str);
	if (num_str == NULL)
		return ;
	num_str = append_prefix(num_str, is_upper);
	ft_print_str(num_str, cp);
	free(num_str);
}

void	ft_print_hex(
	t_syntax *syntax, unsigned long long num, int is_upper, int *const cp)
{
	int		digit;
	char	*num_str;

	digit = get_digit_hex(num);
	num_str = get_num_str_hex(syntax, num, digit, is_upper);
	if (num_str == NULL)
		return ;
	if (syntax->precision_flag == true && syntax->precision_value > digit)
		num_str = proc_precision(syntax, num_str, digit);
	if (num_str == NULL)
		return ;
	if (syntax->hash_flag == true && num != 0)
		ft_print_hex_with_prefix(syntax, num_str, is_upper, cp);
	else
	{
		if (syntax->width_flag == true)
			num_str = proc_width(syntax, num_str);
		if (num_str == NULL)
			return ;
		ft_print_str(num_str, cp);
		free(num_str);
	}
}

void	ft_print_ptr_with_prefix(
	t_syntax *syntax, char *num_str, int is_upper, int *const cp)
{
	if (syntax->zero_flag == true && syntax->precision_flag == false)
	{
		syntax->width_value = syntax->width_value - 2;
		if (syntax->width_flag == true)
			num_str = proc_width(syntax, num_str);
		if (num_str == NULL)
			return ;
		num_str = append_prefix(num_str, is_upper);
	}
	else
	{
		num_str = append_prefix(num_str, is_upper);
		if (syntax->width_flag == true)
			num_str = proc_width(syntax, num_str);
		if (num_str == NULL)
			return ;
	}
	ft_print_str(num_str, cp);
	free(num_str);
}

void	ft_print_ptr(t_syntax *syntax, void *ptr, int *const cp)
{
	int		digit;
	char	*num_str;

	if (ptr == NULL)
	{
		ft_wrapped_print_str(syntax, "(nil)", cp);
		return ;
	}
	digit = get_digit_hex((unsigned long long)ptr);
	num_str = get_num_str_hex(syntax, (unsigned long long)ptr, digit, false);
	if (num_str == NULL)
		return ;
	if (syntax->precision_flag == true && syntax->precision_value > digit)
		num_str = proc_precision(syntax, num_str, digit);
	if (num_str == NULL)
		return ;
	ft_print_ptr_with_prefix(syntax, num_str, false, cp);
}
