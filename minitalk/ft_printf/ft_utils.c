/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasselin <gasselin@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 11:49:39 by gasselin          #+#    #+#             */
/*   Updated: 2021/06/29 10:19:39 by gasselin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_printed(int n, int reset)
{
	static size_t	nb;

	if (reset)
		nb = 0;
	nb += n;
	return (nb);
}

int	ft_isconvt(int c)
{
	return ((c == 'c') || (c == 's') || (c == 'p') || (c == 'd')
		|| (c == 'i') || (c == 'u') || (c == 'x') || (c == 'X')
		|| (c == '%') || (c == 'f') || (c == 'e') || (c == 'g')
		|| (c == 'n') || (c == 'h') || (c == 'l'));
}

int	ft_isdigit(int c)
{
	return ((c >= '0') && (c <= '9'));
}

int	ft_isflags(int c)
{
	return ((c == ' ') || (c == '-') || (c == '0')
		|| (c == '.') || (c == '*') || (c == '#') || (c == '+'));
}

/*size_t	ft_strlen(const char *s)
{
	size_t	count;

	count = 0;
	if (!s)
		return (0);
	while (*s++)
		count++;
	return (count);
}*/
