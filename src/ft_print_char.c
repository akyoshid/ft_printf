/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 05:21:51 by akyoshid          #+#    #+#             */
/*   Updated: 2025/02/07 13:30:25 by akyoshid         ###   ########.fr       */
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
