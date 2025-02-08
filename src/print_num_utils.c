/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_num_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 13:54:38 by akyoshid          #+#    #+#             */
/*   Updated: 2025/02/08 15:07:24 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

char	*proc_precision(t_syntax *syntax, char *num_str, int digit)
{
	int		zero_padding_len;
	char	*temp;
	int		i;

	zero_padding_len = syntax->precision_value - digit;
	temp = (char *)malloc(sizeof(char) * (zero_padding_len + digit + 1 + 2));
	if (temp == NULL)
		return (free(num_str), NULL);
	i = 0;
	while (i < zero_padding_len)
	{
		temp[i] = '0';
		i++;
	}
	ft_strlcpy(temp + i, num_str, digit + 1 + 2);
	return (free(num_str), temp);
}

char	*proc_width(t_syntax *syntax, char *num_str)
{
	int		len;
	char	*temp;

	len = ft_strlen(num_str);
	if (syntax->width_value <= len)
		return (num_str);
	temp = (char *)malloc(sizeof(char) * syntax->width_value + 1 + 2);
	if (temp == NULL)
		return (free(num_str), NULL);
	else if (syntax->minus_flag == true)
	{
		ft_strlcpy(temp, num_str, syntax->width_value + 1 + 2);
		ft_memset(temp + len, ' ', syntax->width_value - len);
		temp[syntax->width_value] = '\0';
	}
	else
	{
		if (syntax->zero_flag == true && syntax->precision_flag == false)
			ft_memset(temp, '0', syntax->width_value - len);
		else
			ft_memset(temp, ' ', syntax->width_value - len);
		ft_strlcpy(temp + syntax->width_value - len,
			num_str, syntax->width_value + 1 + 2);
	}
	return (free(num_str), temp);
}
