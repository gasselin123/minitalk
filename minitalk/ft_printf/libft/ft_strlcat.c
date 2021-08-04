/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasselin <gasselin@student.42quebec.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 09:14:22 by gasselin          #+#    #+#             */
/*   Updated: 2021/05/17 12:02:38 by gasselin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t n)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = ft_strlen(dest);
	j = ft_strlen(src);
	k = 0;
	if (n == 0)
		return (j);
	while ((src[k] != '\0') && ((i + k) < (n - 1)))
	{
		dest[i + k] = src[k];
		k++;
	}
	dest[i + k] = '\0';
	if (n > i)
		return (i + j);
	return (n + j);
}
