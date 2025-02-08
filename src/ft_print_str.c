/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 06:51:30 by akyoshid          #+#    #+#             */
/*   Updated: 2025/02/08 07:00:01 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void	ft_print_str(char const *str, int *const cp)
{
	if (str == NULL)
	{
		ft_print_str("(null)", cp);
		return ;
	}
	while (*str != '\0')
	{
		ft_print_char(*str, cp);
		if (*cp == -1)
			return ;
		str++;
	}
}

void	ft_wrapped_print_str_core(
	t_syntax *syntax, char *str, int len, int *const cp)
{
	int		i;

	if (syntax->width_flag == true && syntax->width_value > len)
	{
		i = 0;
		while (i < syntax->width_value || i < len)
		{
			if (syntax->minus_flag == true && i < len)
				ft_print_char(str[i], cp);
			else if (syntax->minus_flag == 0 && i >= syntax->width_value - len)
				ft_print_char(str[i - (syntax->width_value - len)], cp);
			else
				ft_print_char(' ', cp);
			if (*cp == -1)
				return ;
			i++;
		}
	}
	else
		ft_print_str(str, cp);
}

void	ft_wrapped_print_str(t_syntax *syntax, char *str, int *const cp)
{
	int		len;
	bool	malloc_flag;

	if (str == NULL
		&& syntax->precision_flag == true && syntax->precision_value < 6)
		return ;
	if (str == NULL)
		return (ft_wrapped_print_str(syntax, "(null)", cp));
	len = ft_strlen(str);
	malloc_flag = false;
	if (syntax->precision_flag == true && syntax->precision_value < len)
	{
		len = syntax->precision_value;
		str = ft_strdup(str);
		if (str == NULL)
			return ;
		malloc_flag = true;
		str[syntax->precision_value] = '\0';
	}
	ft_wrapped_print_str_core(syntax, str, len, cp);
	if (malloc_flag == true)
		free(str);
}
