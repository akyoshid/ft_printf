/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned_dec.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 14:08:39 by akyoshid          #+#    #+#             */
/*   Updated: 2025/02/08 14:11:37 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void	ft_print_unsigned_dec(unsigned int num, int *const cp)
{
	char	remainder;

	remainder = num % 10 + '0';
	if (num / 10 > 0)
		ft_print_unsigned_dec(num / 10, cp);
	if (*cp != -1)
		ft_print_char(remainder, cp);
}

void	ft_wrapped_print_unsigned_dec(
	t_syntax *syntax, unsigned int num, int *const cp)
{
	int		digit;
	char	*num_str;

	digit = get_digit_unsigned_dec(num);
	num_str = get_num_str_unsiged_dec(syntax, num, digit);
	if (num_str == NULL)
		return ;
	if (syntax->precision_flag == true && syntax->precision_value > digit)
		num_str = proc_precision(syntax, num_str, digit);
	if (num_str == NULL)
		return ;
	if (syntax->width_flag == true)
		num_str = proc_width(syntax, num_str);
	if (num_str == NULL)
		return ;
	ft_print_str(num_str, cp);
	free(num_str);
}
