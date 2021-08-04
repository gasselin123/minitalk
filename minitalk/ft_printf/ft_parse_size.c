/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_size.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasselin <gasselin@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 11:01:11 by gasselin          #+#    #+#             */
/*   Updated: 2021/06/22 11:44:30 by gasselin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_parse_size2(const char *str, int *i, t_flags *flags, int nbchar)
{
	if (nbchar == 1)
	{
		(flags->conv2)[0] = str[(*i)];
		(*i)++;
		(flags->length) = 1;
		if ((flags->conv2)[0] == 104)
			(flags->length) = -1;
		return (1);
	}
	else
	{
		(flags->conv2)[0] = str[(*i)];
		(flags->conv2)[1] = str[(*i) + 1];
		(*i) += 2;
		(flags->length) = 2;
		if ((flags->conv2)[0] == 104)
			(flags->length) = -2;
		return (2);
	}
}

int	ft_parse_size(const char *str, int *i, t_flags *flags)
{
	if (str[(*i)] == 'h' && str[(*i) + 1] == 'h')
		return (ft_parse_size2(str, i, flags, 2));
	else if (str[(*i)] == 'h')
		return (ft_parse_size2(str, i, flags, 1));
	else if (str[(*i)] == 'l' && str[(*i) + 1] == 'l')
		return (ft_parse_size2(str, i, flags, 2));
	else if (str[(*i)] == 'l')
		return (ft_parse_size2(str, i, flags, 1));
	return (0);
}
