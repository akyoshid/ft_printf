/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_invalid_type.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 17:33:44 by akyoshid          #+#    #+#             */
/*   Updated: 2025/02/06 17:35:50 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void	ft_print_invalid_type(t_syntax *syntax, int *const cp)
{
	ft_print_char('%', cp);
	if (*cp != -1 && syntax->hash_flag == true)
		ft_print_char('#', cp);
	if (*cp != -1 && syntax->plus_flag == true)
		ft_print_char('+', cp);
	else if (*cp != -1 && syntax->space_flag == true)
		ft_print_char(' ', cp);
	if (*cp != -1 && syntax->minus_flag == true)
		ft_print_char('-', cp);
	else if (*cp != -1 && syntax->zero_flag == true)
		ft_print_char('0', cp);
	// if (*cp != -1 && syntax->width_flag == true)
	// 	ft_print_signed_dec(syntax->width_value, cp);
	// if (*cp != -1 && syntax->precision_flag == true)
	// 	ft_print_char('.', cp);
	// if (*cp != -1 && syntax->precision_flag == true)
	// 	ft_print_signed_dec(syntax->precision_value, cp);
	if (*cp != -1)
		ft_print_char(syntax->type, cp);
}
