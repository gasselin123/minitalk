/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasselin <gasselin@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 10:27:17 by gasselin          #+#    #+#             */
/*   Updated: 2021/06/22 11:42:21 by gasselin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_convfeg	ft_manage_decimal(t_convfeg dbl, t_flags flags)
{
	int		diff;
	char	*str;

	diff = flags.dot - dbl.dec_int_size;
	dbl.d = ft_ullitoa(dbl.dec_int);
	if (diff > 0)
	{
		dbl.d2 = dbl.d;
		str = (char *)malloc(sizeof(char) * diff + 1);
		if (!str)
			return (dbl);
		str[diff] = '\0';
		ft_memset(str, 48, diff);
		dbl.d = ft_strjoin(str, dbl.d2);
		free (str);
		free (dbl.d2);
	}
	return (dbl);
}

t_convfeg	ft_rounding(t_convfeg dbl, t_flags flags)
{
	unsigned long long int	rnd;

	rnd = dbl.dec_part * ft_pow(10, flags.dot + 1);
	if (rnd > 0)
	{
		if ((rnd % 10) >= 5)
			rnd = (rnd / 10) + 1;
		else
			rnd = rnd / 10;
	}
	dbl.dec_int = rnd;
	return (dbl);
}

t_convfeg	ft_no_precision(t_convfeg dbl)
{
	long double	rounder;

	if ((!(dbl.dec_part < 0.5) || (dbl.dec_part > 0.5)) && (dbl.int_part % 2))
		(dbl.int_part)++;
	else if (dbl.dec_part != 0.5)
	{
		rounder = dbl.dec_part * 10;
		if (rounder >= 5.0)
			(dbl.int_part)++;
	}
	return (dbl);
}

t_convfeg	ft_ftoa(t_convfeg dbl, t_flags flags)
{
	dbl.int_part = dbl.nb;
	dbl.dec_part = dbl.nb - dbl.int_part;
	dbl.dec_int = dbl.dec_part * ft_pow(10, flags.dot);
	dbl.dec_int_size = 1;
	while ((dbl.dec_int) >= 10)
	{
		(dbl.dec_int_size)++;
		dbl.dec_int /= 10;
	}
	dbl = ft_rounding(dbl, flags);
	if (flags.dot == 0)
		dbl = ft_no_precision(dbl);
	dbl.a = ft_ullitoa(dbl.int_part);
	if (flags.dot != 0)
	{
		dbl.a3 = dbl.a;
		dbl.a2 = ft_strjoin(dbl.a3, ".");
		dbl = ft_manage_decimal(dbl, flags);
		dbl.a = ft_strjoin(dbl.a2, dbl.d);
		free (dbl.d);
		free (dbl.a3);
		free (dbl.a2);
	}
	return (dbl);
}
