/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 05:21:51 by akyoshid          #+#    #+#             */
/*   Updated: 2025/02/07 16:58:59 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void	ft_print_char(char const c, int *const cp)
{
	if ((write(1, &c, 1)) == -1)
		*cp = -1;
	else
		(*cp)++;
}

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

void	ft_wrapped_print_char(t_syntax *syntax, char const c, int *const cp)
{
	int	i;

	if (syntax->width_flag == true)
	{
		i = 0;
		while (i < syntax->width_value)
		{
			if (syntax->minus_flag == true && i == 0)
				ft_print_char(c, cp);
			else if (syntax->minus_flag == false && i == syntax->width_value - 1)
				ft_print_char(c, cp);
			else
				ft_print_char(' ', cp);
			if (*cp == -1)
				return ;
			i++;
		}
	}
	else
		ft_print_char(c, cp);
}

void	ft_wrapped_print_str(t_syntax *syntax, char *str, int *const cp)
{
	int		i;
	int		len;
	bool	malloc_flag;

	if (str == NULL && syntax->precision_flag == true && syntax->precision_value < 6)
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
	if (malloc_flag == true)
		free(str);
}
