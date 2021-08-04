/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasselin <gasselin@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 11:48:53 by gasselin          #+#    #+#             */
/*   Updated: 2021/06/22 16:24:34 by gasselin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnstr(char *str, int n)
{
	int	i;

	i = 0;
	while (str[i] && i < n)
		ft_putchar(str[i++]);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
	ft_printed(1, 0);
}

void	ft_putunschar(unsigned char c)
{
	write(1, &c, 1);
	ft_printed(1, 0);
}

void	ft_putstr(char *str)
{
	while (*str)
		ft_putchar(*str++);
}
