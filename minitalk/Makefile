# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gasselin <gasselin@student.42quebec.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/27 15:05:29 by gasselin          #+#    #+#              #
#    Updated: 2021/08/02 15:09:29 by gasselin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CLIENT	= client
SERVER	= server

CLIENT_BONUS = client_bonus
SERVER_BONUS = server_bonus

all :
	make -C ./ft_printf
	gcc -Wall -Wextra -Werror client.c ./ft_printf/libftprintf.a -o $(CLIENT)
	gcc -Wall -Wextra -Werror server.c ./ft_printf/libftprintf.a -o $(SERVER)

bonus : all
	gcc -Wall -Wextra -Werror client_bonus.c ./ft_printf/libftprintf.a -o $(CLIENT_BONUS)
	gcc -Wall -Wextra -Werror server_bonus.c ./ft_printf/libftprintf.a -o $(SERVER_BONUS)

clean :
	make clean -C ./ft_printf
	rm -rf client.o server.o client_bonus.o server_bonus.o

fclean : clean
	make fclean -C ./ft_printf
	rm -rf $(CLIENT) $(SERVER) $(CLIENT_BONUS) $(SERVER_BONUS)

re : fclean all