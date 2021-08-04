/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasselin <gasselin@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 11:49:31 by gasselin          #+#    #+#             */
/*   Updated: 2021/06/22 16:26:22 by gasselin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_numlen(unsigned int n)
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

char	*ft_uitoa(unsigned int n)
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
