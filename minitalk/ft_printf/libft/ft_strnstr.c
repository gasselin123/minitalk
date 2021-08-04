/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasselin <gasselin@student.42quebec.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 09:16:21 by gasselin          #+#    #+#             */
/*   Updated: 2021/05/10 09:16:34 by gasselin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	size_t	n1;
	size_t	n2;

	n1 = 0;
	if (*needle == '\0')
		return ((char *)haystack);
	while (haystack[n1] != '\0' && n1 < n)
	{
		n2 = 0;
		while (needle[n2] == haystack[n1 + n2] && n1 + n2 < n)
		{
			if (needle[n2 + 1] == '\0')
				return ((char *)haystack + n1);
			n2++;
		}
		n1++;
	}
	return (NULL);
}
