/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_syntax.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 17:37:09 by akyoshid          #+#    #+#             */
/*   Updated: 2025/02/07 10:19:30 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void	init_syntax(t_syntax *syntax)
{
	syntax->type = 0;
	syntax->hash_flag = false;
	syntax->plus_flag = false;
	syntax->space_flag = false;
	syntax->minus_flag = false;
	syntax->zero_flag = false;
	syntax->width_flag = false;
	syntax->width_value = 0;
	syntax->precision_flag = false;
	syntax->precision_value = 0;
}

void	parse_flag(char const **fmt_p, t_syntax *syntax)
{
	while (**fmt_p == '#'
		|| **fmt_p == '+' || **fmt_p == ' '
		|| **fmt_p == '-' || **fmt_p == '0')
	{
		if (**fmt_p == '#')
			syntax->hash_flag = true;
		else if (**fmt_p == '+')
			syntax->plus_flag = true;
		else if (**fmt_p == ' ')
			syntax->space_flag = true;
		else if (**fmt_p == '-')
			syntax->minus_flag = true;
		else if (**fmt_p == '0')
			syntax->zero_flag = true;
		(*fmt_p)++;
	}
	if (syntax->plus_flag == true)
		syntax->space_flag = false;
	if (syntax->minus_flag == true)
		syntax->zero_flag = false;
}

int	parse_width(char const **fmt_p, t_syntax *syntax)
{
	int	temp;

	temp = 0;
	while (**fmt_p >= '0' && **fmt_p <= '9')
	{
		syntax->width_flag = true;
		if (temp >= 214748365 ||
			(temp == 214748364 && (**fmt_p >= '8' && **fmt_p <= '9')))
			return (-1);
		temp *= 10;
		temp += **fmt_p - '0';
		(*fmt_p)++;
	}
	syntax->width_value = temp;
	return (0);
}

int	parse_precision(char const **fmt_p, t_syntax *syntax)
{
	int	temp;

	syntax->precision_flag = true;
	(*fmt_p)++;
	temp = 0;
	while (**fmt_p >= '0' && **fmt_p <= '9')
	{
		if (temp >= 214748365 ||
			(temp == 214748364 && (**fmt_p >= '8' && **fmt_p <= '9')))
			return (-1);
		temp *= 10;
		temp += **fmt_p - '0';
		(*fmt_p)++;
	}
	syntax->precision_value = temp;
	return (0);
}

int	parse_syntax(char const **fmt_p, t_syntax *syntax)
{
	(*fmt_p)++;
	parse_flag(fmt_p, syntax);
	if (parse_width(fmt_p, syntax) == -1)
		return (-1);
	if (**fmt_p == '.')
	{
		if (parse_precision(fmt_p, syntax) == -1)
			return (-1);
	}
	if (**fmt_p == '\0')
		return (-1);
	syntax->type = **fmt_p;
	(*fmt_p)++;
	return (0);
}
