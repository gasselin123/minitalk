/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasselin <gasselin@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 11:09:07 by gasselin          #+#    #+#             */
/*   Updated: 2021/08/02 15:14:09 by gasselin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_message(int pid, int c)
{
	int	j;
	int	ret;

	j = 0;
	while (j < 8)
	{
		usleep(75);
		if ((c >> j) & 1)
			ret = kill(pid, SIGUSR1);
		else
			ret = kill(pid, SIGUSR2);
		if (ret == -1)
		{
			ft_printf("wrong PID");
			exit (EXIT_FAILURE);
		}
		j++;
	}
}

void	success(int sig)
{
	(void)sig;
	ft_printf("Data has been received\n");
	exit (EXIT_SUCCESS);
}

int	main(int argc, char **argv)
{
	int					pid;
	int					i;

	i = 0;
	if (argc != 3)
		return (ft_printf("Usage: ./client [PID] [message]\n"));
	pid = ft_atoi(argv[1]);
	signal(SIGUSR1, success);
	while (argv[2][i])
	{
		send_message(pid, argv[2][i]);
		i++;
	}
	send_message(pid, argv[2][i]);
	while (1)
		pause();
	exit(EXIT_SUCCESS);
}
