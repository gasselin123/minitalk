# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gasselin <gasselin@student.42quebec.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/22 11:49:55 by gasselin          #+#    #+#              #
#    Updated: 2021/06/23 09:46:21 by gasselin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a

RM			= rm -rf
CC			= gcc
FLAGS		= -Wall -Wextra -Werror
INCS		= .

SRCS		= ft_printf.c \
				ft_parser.c \
				ft_parse_flags.c \
				ft_parse_size.c \
				ft_print_char.c \
				ft_print_hex.c \
				ft_print_nbr.c \
				ft_print_pct.c \
				ft_print_ptr.c \
				ft_print_str.c \
				ft_print_wchar.c \
				ft_print_wchar2.c \
				ft_print_unbr.c \
				ft_print_nil.c \
				ft_print_feg.c \
				ft_print_f.c \
				ft_print_e.c \
				ft_print_g.c \
				ft_ftoa.c \
				ft_print_width.c \
				ft_putchar.c \
				ft_uitoa.c \
				ft_isinfnan.c \
				ft_utils.c \
				ft_utils2.c

OBJS		= ${SRCS:.c=.o}

.c.o:
			${CC} ${FLAGS} -c $< -o ${<:.c=.o} -I${INCS}

${NAME} : ${OBJS}
			$(MAKE) bonus -C ./libft
			cp libft/libft.a $(NAME)
			ar -rcs ${NAME} ${OBJS}

bonus:	all

all : ${NAME}

clean :
			$(MAKE) clean -C ./libft
			${RM} ${OBJS}

fclean : clean
			$(MAKE) fclean -C ./libft
			${RM} ${NAME}

re : fclean all