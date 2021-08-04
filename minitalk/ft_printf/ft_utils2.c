/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasselin <gasselin@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 11:49:47 by gasselin          #+#    #+#             */
/*   Updated: 2021/06/23 09:05:09 by gasselin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long double	ft_pow(long double n, unsigned int pow)
{
	long double	nb;

	nb = n;
	if (pow <= 1)
		return (n);
	while (--pow)
		n *= nb;
	return (n);
}

static int	ft_numlen(unsigned long long int n)
{
	int	count;

	count = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

static void	ft_strrev(char *s)
{
	char	temp;
	char	*front;
	char	*back;

	front = s;
	back = s + ft_strlen(s) - 1;
	while (front < back)
	{
		temp = *front;
		*front = *back;
		*back = temp;
		front++;
		back--;
	}
}

char	*ft_ullitoa(unsigned long long int n)
{
	char	*str;
	int		i;

	str = (char *)ft_calloc((ft_numlen(n) + 1), sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	str[i] = 48;
	while (n != 0)
	{
		str[i++] = 48 + n % 10;
		n /= 10;
	}
	ft_strrev(str);
	return (str);
}

void	ft_putunbr(unsigned long long int n)
{
	if (n > 9)
		ft_putunbr(n / 10);
	ft_putchar(48 + n % 10);
}
