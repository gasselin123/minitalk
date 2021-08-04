/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasselin <gasselin@student.42quebec.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 09:20:54 by gasselin          #+#    #+#             */
/*   Updated: 2021/05/10 09:21:01 by gasselin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_wordcount(char const *s, char c)
{
	int		count;
	size_t	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		if (i == 0 && s[i] != c)
			count++;
		if (s[i] != c && s[i - 1] == c && i > 0)
			count++;
		i++;
	}
	return (count);
}

static char	*ft_make_words(char const *s, int *index, char c)
{
	char	*word;
	int		i;
	int		start;
	int		end;

	i = *index;
	while (s[i] == c && s[i])
		i++;
	start = i - 1;
	while (s[i] != c && s[i])
		i++;
	end = i;
	*index = i;
	word = (char *)malloc((end - start + 1) * sizeof(char));
	if (!word)
		return (NULL);
	i = 0;
	while (++start < end)
		word[i++] = s[start];
	word[i] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	int		count;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	count = ft_wordcount(s, c);
	split = (char **)malloc(sizeof(*split) * (count + 1));
	if (!split)
		return (NULL);
	while (i < count)
	{
		split[i] = ft_make_words(s, &j, c);
		i++;
	}
	split[i] = NULL;
	return (split);
}
