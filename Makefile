# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/28 17:24:00 by akyoshid          #+#    #+#              #
#    Updated: 2025/02/08 15:12:39 by akyoshid         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		libftprintf.a

INC_DIR =	inc/
SRC_DIR =	src/
OBJ_DIR =	obj/
LIBFT_DIR =	libft/

LIBFT_A =	$(LIBFT_DIR)/libft.a

INC =		$(INC_DIR)ft_printf.h

SRC = \
			$(SRC_DIR)ft_printf.c\
			$(SRC_DIR)ft_print_char.c\
			$(SRC_DIR)ft_print_hex.c\
			$(SRC_DIR)ft_print_invalid_type.c\
			$(SRC_DIR)ft_print_signed_dec.c\
			$(SRC_DIR)ft_print_str.c\
			$(SRC_DIR)ft_print_unsigned_dec.c\
			$(SRC_DIR)parse_syntax.c\
			$(SRC_DIR)print_hex_utils.c\
			$(SRC_DIR)print_num_utils.c\
			$(SRC_DIR)print_signed_dec_utils.c\
			$(SRC_DIR)print_unsigned_dec_utils.c\

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
	@mkdir -p $(OBJ_DIR)/libft_objs
	@cd $(OBJ_DIR)/libft_objs && ar x ../../$(LIBFT_A)
	$(AR) $(NAME) $(OBJ) $(OBJ_DIR)/libft_objs/*.o

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

