# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kristori <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/21 10:46:44 by kristori          #+#    #+#              #
#    Updated: 2022/10/24 15:19:41 by kristori         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a

SRC	= ft_printf.c  ft_putchar.c  ft_putnbr.c  ft_putstr.c  ft_print_unsigned_decimal.c  ft_printhex.c  ft_printptr.c

OBJ	= $(SRC:.c=.o)


all:	$(NAME)

$(NAME) : $(SRC)
	@gcc -Wall -Werror -Wextra -c $(SRC)
	@ar rc $(NAME) $(OBJ)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all
