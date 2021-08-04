/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasselin <gasselin@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 14:42:12 by gasselin          #+#    #+#             */
/*   Updated: 2021/08/02 14:42:45 by gasselin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	sig_handler(int sig, siginfo_t *info, void *unused)
{
	static unsigned char	c = 0;
	static int				size = 0;
	int						ret;

	(void)unused;
	if (sig == SIGUSR1)
		c += (1 << size);
	size++;
	if (size == 8)
	{
		write(1, &c, 1);
		if (c == '\0')
		{
			ft_printf("\n");
			ret = kill(info->si_pid, SIGUSR1);
			if (ret == -1)
			{
				ft_printf("kill error\n");
				exit (EXIT_FAILURE);
			}
		}
		size = 0;
		c = 0;
	}
}

void	sig_error(void)
{
	ft_printf("Sigaction error\n");
	exit (EXIT_FAILURE);
}

int	main(void)
{
	struct sigaction	talk;
	int					ret;

	ft_printf("Server PID : ");
	ft_putnbr_fd(getpid(), 1);
	ft_printf("\n");
	talk.sa_sigaction = sig_handler;
	talk.sa_flags = SA_SIGINFO;
	ret = sigaction(SIGUSR1, &talk, 0);
	if (ret == -1)
		sig_error();
	ret = sigaction(SIGUSR2, &talk, 0);
	if (ret == -1)
		sig_error();
	while (1)
		pause();
	return (0);
}
