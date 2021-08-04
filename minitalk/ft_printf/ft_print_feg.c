/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_feg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasselin <gasselin@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 11:45:26 by gasselin          #+#    #+#             */
/*   Updated: 2021/06/23 09:32:55 by gasselin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_convfeg	ft_init_dbl(void)
{
	t_convfeg	dbl;

	dbl.nb = 0.0;
	dbl.ulli = 0;
	dbl.int_part = 0;
	dbl.dec_part = 0.0;
	dbl.dec_int = 0;
	dbl.dec_int_size = 0;
	dbl.strlen = 0;
	dbl.e_nbr = 0;
	dbl.dot_minus = 0;
	dbl.a = NULL;
	dbl.a2 = NULL;
	dbl.a3 = NULL;
	dbl.d = NULL;
	dbl.d2 = NULL;
	dbl.tmp = NULL;
	return (dbl);
}

t_flags	ft_precnil(t_flags flags)
{
	if (flags.dot == -1)
		flags.dot = 6;
	return (flags);
}

void	ft_print_dbl2(t_convfeg dbl, t_flags flags)
{
	if (flags.dot >= 0 && (size_t)flags.dot < ft_strlen(dbl.a))
		flags.dot = ft_strlen(dbl.a);
	ft_treat_width(flags.width, ft_strlen(dbl.a), flags.zero);
	if (flags.minus == 0)
	{
		if (flags.sign == 45 && flags.zero == 0)
			ft_putchar('-');
		if (flags.dot >= 0)
			ft_treat_width(flags.dot, ft_strlen(dbl.a), 1);
		ft_putstr(dbl.a);
	}
	free (dbl.a);
}

void	ft_print_dbl(t_convfeg dbl, t_flags flags)
{
	if (flags.sign == 43 && flags.plus == 1)
	{
		ft_putchar('+');
		flags.width--;
		flags.plus = 0;
	}
	if (flags.sign == 45 && flags.zero == 1)
		ft_putchar('-');
	if (flags.minus == 1)
	{
		if (flags.sign == 45 && flags.zero == 0)
			ft_putchar('-');
		if (flags.dot >= 0)
			ft_treat_width(flags.dot, ft_strlen(dbl.a), 1);
		ft_putstr(dbl.a);
	}
	ft_print_dbl2(dbl, flags);
}

void	ft_print_feg(const char c, va_list arg_list, t_flags flags)
{
	double		nb;
	t_convfeg	dbl;

	dbl = ft_init_dbl();
	nb = va_arg(arg_list, double);
	if (nb < 0)
		flags.sign = 45;
	if (flags.sign == '-')
		flags.width--;
	flags = ft_treat_sign(flags);
	if (ft_treat_infnan(nb, flags))
		return ;
	dbl.nb = nb;
	if (dbl.nb < 0)
		dbl.nb = -dbl.nb;
	dbl.ulli = dbl.nb;
	flags = ft_precnil(flags);
	if (c == 'f')
		dbl = ft_print_f(dbl, flags);
	if (c == 'e')
		dbl = ft_print_e(dbl, flags);
	if (c == 'g')
		ft_print_g(dbl, flags);
	if (c == 'f' || c == 'e')
		ft_print_dbl(dbl, flags);
}
