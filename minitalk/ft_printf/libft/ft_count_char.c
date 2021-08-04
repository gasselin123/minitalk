/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasselin <gasselin@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 09:38:09 by gasselin          #+#    #+#             */
/*   Updated: 2021/07/12 11:13:03 by gasselin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_count_char(const char *s, const char *set)
{
	int		count;
	int		i;
	int		j;
	size_t	length;

	count = 0;
	i = 0;
	if (!s || !set)
		return (0);
	length = ft_strlen(set);
	while (s[i])
	{
		j = 0;
		while (set[j])
			if (s[i] == set[j++])
				count++;
		i++;
	}
	return (count);
}
