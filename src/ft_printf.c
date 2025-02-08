/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 17:22:21 by akyoshid          #+#    #+#             */
/*   Updated: 2025/02/08 15:24:42 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void	ft_print_varg(t_syntax *syntax, va_list *app, int *const cp)
{
	if (syntax->type == 'c')
		ft_wrapped_print_char(syntax, (char)va_arg(*app, int), cp);
	else if (syntax->type == 's')
		ft_wrapped_print_str(syntax, va_arg(*app, char *), cp);
	else if (syntax->type == 'd' || syntax->type == 'i')
		ft_wrapped_print_signed_dec(syntax, va_arg(*app, int), cp);
	else if (syntax->type == 'u')
		ft_wrapped_print_unsigned_dec(syntax, va_arg(*app, unsigned int), cp);
	else if (syntax->type == 'x')
		ft_print_hex(syntax, va_arg(*app, unsigned int), 0, cp);
	else if (syntax->type == 'X')
		ft_print_hex(syntax, va_arg(*app, unsigned int), 1, cp);
	// else if (syntax->type == 'p')
	// 	ft_print_ptr(va_arg(*app, void *), cp);
	else if (syntax->type == '%')
		ft_print_char('%', cp);
	else
		ft_print_invalid_type(syntax, cp);
}

int	ft_printf(const char *fmt, ...)
{
	va_list		ap;
	int			count;
	t_syntax	syntax;

	va_start(ap, fmt);
	count = 0;
	if (fmt == NULL)
		return (-1);
	while (*fmt != '\0')
	{
		if (*fmt == '%')
		{
			init_syntax(&syntax);
			if (parse_syntax(&fmt, &syntax) == -1)
				return (-1);
			ft_print_varg(&syntax, &ap, &count);
		}
		else
			ft_print_char(*fmt++, &count);
		if (count == -1)
			return (-1);
	}
	va_end(ap);
	return (count);
}
