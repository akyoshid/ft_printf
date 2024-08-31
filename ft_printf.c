/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 17:22:21 by akyoshid          #+#    #+#             */
/*   Updated: 2024/08/31 01:42:13 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_varg(char const fmt, va_list *app, int *const cp)
{
	if (fmt == 'c')
		ft_print_char((char)va_arg(*app, int), cp);
	else if (fmt == 's')
		ft_print_str(va_arg(*app, char *), cp);
	else if (fmt == 'd' || fmt == 'i')
		ft_print_signed_dec(va_arg(*app, int), cp);
	else if (fmt == 'u')
		ft_print_unsigned_dec(va_arg(*app, unsigned int), cp);
	else if (fmt == 'x')
		ft_print_hex(va_arg(*app, unsigned int), 0, cp);
	else if (fmt == 'X')
		ft_print_hex(va_arg(*app, unsigned int), 1, cp);
	else if (fmt == 'p')
		ft_print_ptr(va_arg(*app, void *), cp);
	else if (fmt == '%')
		ft_print_char('%', cp);
	else
		ft_print_char(fmt, cp);
}

int	ft_printf(const char *fmt, ...)
{
	va_list	ap;
	int		count;

	va_start(ap, fmt);
	count = 0;
	while (*fmt != '\0')
	{
		if (*fmt == '%')
		{
			fmt++;
			while (*fmt == ' ')
				fmt++;
			if (*fmt != '\0')
				ft_print_varg(*(fmt), &ap, &count);
		}
		else
			ft_print_char(*fmt, &count);
		if (count == -1)
			return (-1);
		if (*fmt != '\0')
			fmt++;
	}
	va_end(ap);
	return (count);
}
