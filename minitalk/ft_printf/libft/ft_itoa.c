/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasselin <gasselin@student.42quebec.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 09:21:13 by gasselin          #+#    #+#             */
/*   Updated: 2021/05/10 09:21:16 by gasselin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_numlen(int n)
{
	int	count;

	count = 1;
	if (n < 0)
		count++;
	else
		n *= -1;
	while (n <= -10)
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

char	*ft_itoa(int n)
{
	char	*str;
	int		i;

	str = (char *)ft_calloc((ft_numlen(n) + 1), sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	str[i] = 48;
	if (n < 0)
	{
		str[i++] = 45;
		str[i++] = 48 - n % 10;
		n /= -10;
	}
	while (n != 0)
	{
		str[i++] = 48 + n % 10;
		n /= 10;
	}
	if (str[0] == 45)
		ft_strrev(str + 1);
	else
		ft_strrev(str);
	return (str);
}
