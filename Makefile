# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/28 17:24:00 by akyoshid          #+#    #+#              #
#    Updated: 2025/02/07 16:28:11 by akyoshid         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		libftprintf.a

INC_DIR =	inc/
SRC_DIR =	src/
OBJ_DIR =	obj/
LIBFT_DIR =	libft/

INC =		$(INC_DIR)ft_printf.h

SRC = \
			$(SRC_DIR)ft_printf.c\
			$(SRC_DIR)ft_print_char.c\
			$(SRC_DIR)ft_print_dec.c\
			$(SRC_DIR)ft_print_hex.c\
			$(SRC_DIR)ft_print_invalid_type.c\
			$(SRC_DIR)parse_syntax.c\

OBJ =		$(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SRC))

CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBFT_LIB = -L ./libft -lft
RM = rm -f
AR = ar rcs

all: $(NAME)

bonus: $(NAME)

$(NAME): $(OBJ)
	@make -C $(LIBFT_DIR)
	$(AR) $(NAME) $(OBJ)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(INC)
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

clean:
	$(RM) -r $(OBJ_DIR)
	@make clean -C $(LIBFT_DIR)

fclean: clean
	$(RM) $(NAME)
	@make fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re bonus

