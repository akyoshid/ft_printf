/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 17:24:02 by akyoshid          #+#    #+#             */
/*   Updated: 2025/02/08 13:28:49 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <limits.h>
# include <stdbool.h>
# include "../libft/inc/libft.h"
# include "../libft/inc/get_next_line_bonus.h"

typedef struct s_syntax
{
	char	type;
	bool	hash_flag;
	bool	plus_flag;
	bool	space_flag;
	bool	minus_flag;
	bool	zero_flag;
	bool	width_flag;
	int		width_value;
	bool	precision_flag;
	int		precision_value;
}			t_syntax;

// ft_printf.c
void	ft_print_varg(t_syntax *syntax, va_list *app, int *const cp);
int		ft_printf(const char *fmt, ...);
// ft_print_char.c
void	ft_print_char(char const c, int *const cp);
void	ft_wrapped_print_char(t_syntax *syntax, char const c, int *const cp);
// ft_print_dec_utils.c
int		get_digit(int num);
char	*get_num_str(t_syntax *syntax, int num, int digit);
char	*proc_precision(t_syntax *syntax, char *num_str, int digit);
char	*append_sign(t_syntax *syntax, char *num_str, bool minus_flag);
char	*proc_width(t_syntax *syntax, char *num_str);
// ft_print_dec.c
void	ft_wrapped_print_signed_dec_core(
			t_syntax *syntax, char *num_str, bool minus_flag, int *const cp);
void	ft_wrapped_print_signed_dec(t_syntax *syntax, int num, int *const cp);
void	ft_print_signed_dec(int num, int *const cp);
void	ft_print_unsigned_dec(unsigned int num, int *const cp);
// ft_printt_hex.c
void	ft_print_hex_char(char const num, int is_upper, int *const cp);
void	ft_print_hex(unsigned long long num, int is_upper, int *const cp);
void	ft_print_ptr(void *ptr, int *const cp);
// ft_print_invalid_type.c
void	ft_print_invalid_type(t_syntax *syntax, int *const cp);
// ft_print_str.c
void	ft_print_str(char const *str, int *const cp);
void	ft_wrapped_print_str_core(
			t_syntax *syntax, char *str, int len, int *const cp);
void	ft_wrapped_print_str(t_syntax *syntax, char *str, int *const cp);
// parse_syntax.c
void	init_syntax(t_syntax *syntax);
void	parse_flag(char const **fmt_p, t_syntax *syntax);
int		parse_width(char const **fmt_p, t_syntax *syntax);
int		parse_precision(char const **fmt_p, t_syntax *syntax);
int		parse_syntax(char const **fmt_p, t_syntax *syntax);

#endif
