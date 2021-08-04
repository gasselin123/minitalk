/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_e.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasselin <gasselin@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 11:08:11 by gasselin          #+#    #+#             */
/*   Updated: 2021/08/02 09:57:53 by gasselin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_convfeg	ft_get_enbr(t_convfeg dbl)
{
	while (dbl.ulli >= 10)
	{
		(dbl.e_nbr)++;
		dbl.ulli /= 10;
	}
	return (dbl);
}

t_convfeg	get_nbr0_e(t_convfeg dbl, t_flags flags)
{
	int		i;
	char	*tmp;
	char	*tmp2;

	i = 0;
	if (flags.width > 0)
		flags.width--;
	while (dbl.nb < 1.0 && dbl.nb > -1.0)
	{
		i++;
		dbl.nb *= 10;
	}
	tmp = (char *)ft_calloc(3, sizeof(char));
	tmp[0] = dbl.a[i + 1];
	tmp[1] = '.';
	tmp2 = ft_substr(dbl.a, i + 2, ft_strlen(dbl.a) - i - 2);
	if (tmp2[0] == '\0')
		tmp[1] = '\0';
	free (dbl.a);
	dbl.a = ft_strjoin(tmp, tmp2);
	free (tmp);
	free (tmp2);
	dbl.e[1] = 45;
	dbl.e_nbr = -i;
	return (dbl);
}

t_convfeg	get_nbr_e(t_convfeg dbl, t_flags flags, int *i)
{
	dbl = ft_get_enbr(dbl);
	dbl = ft_ftoa(dbl, flags);
	*i = ft_strlen(dbl.a);
	ft_strlcpy(dbl.e, "e+", 3);
	while (--(*i) >= 0)
	{
		if (dbl.a[*i] == '.' && *i >= 2)
		{
			dbl.a[*i] = dbl.a[(*i) - 1];
			dbl.a[(*i) - 1] = '.';
		}
	}
	dbl.int_part = dbl.a[0] - '0';
	dbl.dec_part = (dbl.nb / ft_pow(10, dbl.e_nbr)) - dbl.int_part;
	if (ft_strlen(dbl.a) > dbl.strlen)
	{
		dbl.d = ft_substr(dbl.a, 0, dbl.strlen);
		dbl.e_nbr = ft_strlen(dbl.a) - dbl.strlen;
		free (dbl.a);
		dbl.a = dbl.d;
	}
	return (dbl);
}

t_convfeg	ft_print_e2(t_convfeg dbl, t_flags flags)
{
	if (dbl.nb < 1.0 && dbl.nb > -1.0 && dbl.nb != 0.0)
	{
		dbl = get_nbr0_e(dbl, flags);
		if (flags.dot > 0)
			flags.dot--;
	}
	if (dbl.e_nbr < 0)
		dbl.e_nbr *= -1;
	dbl.d = ft_ullitoa(dbl.e_nbr);
	if (ft_strlen(dbl.d) == 1 && ft_strlcat(dbl.e, "0", 4))
		ft_strlcat(dbl.e, dbl.d, 5);
	else
		ft_strlcat(dbl.e, dbl.d, 5);
	free (dbl.d);
	return (dbl);
}

t_convfeg	ft_print_e(t_convfeg dbl, t_flags flags)
{
	int			i;
	long double	dec;

	dec = dbl.nb;
	dbl.e_nbr = 0;
	while (dec < 1.0 && dec > -1.0 && dec != 0.0)
	{
		(flags.dot)++;
		dec *= 10;
	}
	if (flags.dot)
		dbl.strlen = (size_t)flags.dot + 2;
	else
		dbl.strlen = 1;
	dbl = get_nbr_e(dbl, flags, &i);
	dbl = ft_print_e2(dbl, flags);
	dbl.tmp = ft_strjoin(dbl.a, dbl.e);
	free (dbl.a);
	dbl.a = dbl.tmp;
	return (dbl);
}
