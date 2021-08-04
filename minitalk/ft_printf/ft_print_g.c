/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_g.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasselin <gasselin@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 11:45:32 by gasselin          #+#    #+#             */
/*   Updated: 2021/06/23 09:44:22 by gasselin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_convfeg	ft_remove_0s2(t_convfeg dbl)
{
	int	i;

	if (ft_strchr(dbl.tmp, 101) && !(ft_strchr(dbl.a, 101)))
	{
		i = ft_strlen(dbl.tmp);
		dbl.d2 = ft_substr(dbl.tmp, i - 4, 4);
		dbl.a3 = ft_strjoin(dbl.a, dbl.d2);
		free (dbl.a);
		free (dbl.d2);
		dbl.a = dbl.a3;
	}
	free (dbl.tmp);
	return (dbl);
}

t_convfeg	ft_remove_0s(t_convfeg dbl)
{
	int	i;

	i = ft_strlen(dbl.a);
	dbl.tmp = ft_strdup(dbl.a);
	if (ft_strchr(dbl.a, 46))
	{
		if (ft_strchr(dbl.a, 101))
			i -= 4;
		while (--i >= 0)
		{
			if (!(dbl.a[i] == '0' || dbl.a[i] == '.'))
				break ;
			if (dbl.a[i] == '.')
			{
				dbl.a[i] = '\0';
				break ;
			}
			if (dbl.a[i] == '0')
			{
				dbl.a[i] = '\0';
				(dbl.dot_minus)++;
			}
		}
	}
	return (ft_remove_0s2(dbl));
}

t_convfeg	ft_manage_g(t_convfeg dbl, t_flags flags)
{
	int	i;

	dbl.dec_part *= ft_pow(10, flags.dot);
	dbl.ulli = dbl.dec_part;
	i = dbl.ulli % 10;
	if (i < (dbl.a[ft_strlen(dbl.a) - 5] - '0'))
		return (dbl);
	dbl.dec_part -= dbl.ulli;
	dbl.dec_part *= 10;
	if (dbl.dec_part >= 5.0)
		dbl.a[ft_strlen(dbl.a) - 5]++;
	return (dbl);
}

t_convfeg	ft_get_exp(t_convfeg dbl)
{
	long double	nb;
	int			exp;

	exp = 0;
	nb = dbl.nb;
	if (nb >= 1.0)
	{
		while (nb >= 10)
		{
			nb /= 10;
			exp++;
		}
	}
	else
	{
		while (nb < 1.0)
		{
			nb *= 10;
			exp++;
		}
		if (exp > 0)
			exp = -exp;
	}
	dbl.e_nbr = exp;
	return (dbl);
}

void	ft_print_g(t_convfeg dbl, t_flags flags)
{
	int	p;

	p = flags.dot;
	if (p == 0)
		p = 1;
	if (dbl.nb != 0.0)
		dbl = ft_get_exp(dbl);
	if (dbl.e_nbr >= p || dbl.e_nbr < -4)
	{
		flags.dot = p - 1;
		dbl = ft_print_e(dbl, flags);
		dbl = ft_remove_0s(dbl);
		flags.dot -= dbl.dot_minus;
		dbl = ft_manage_g(dbl, flags);
		ft_print_dbl(dbl, flags);
	}
	else
	{
		flags.dot = p - (dbl.e_nbr + 1);
		dbl = ft_print_f(dbl, flags);
		dbl = ft_remove_0s(dbl);
		flags.dot -= dbl.dot_minus;
		ft_print_dbl(dbl, flags);
	}
}
