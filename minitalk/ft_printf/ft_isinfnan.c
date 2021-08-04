/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isinfnan.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasselin <gasselin@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 10:42:24 by gasselin          #+#    #+#             */
/*   Updated: 2021/06/22 16:05:11 by gasselin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_treatnan(t_flags flags)
{
	if (flags.minus == 1)
		ft_putstr("nan");
	ft_treat_width(flags.width, 3, 0);
	if (flags.minus == 0)
		ft_putstr("nan");
}

int	ft_isnan(double d)
{
	return (d != d);
}

void	ft_treatinf(t_flags flags)
{
	if (flags.minus == 1)
	{
		if (flags.sign == 45)
			ft_putchar(45);
		ft_putstr("inf");
	}
	ft_treat_width(flags.width, 3, 0);
	if (flags.minus == 0)
	{
		if (flags.sign == 45)
			ft_putchar(45);
		ft_putstr("inf");
	}
}

int	ft_isinf(double d)
{
	return (!ft_isnan(d) && ft_isnan(d - d));
}

int	ft_treat_infnan(double d, t_flags flags)
{
	if (ft_isnan(d) || ft_isinf(d))
	{
		if (ft_isnan(d))
			ft_treatnan(flags);
		if (ft_isinf(d))
			ft_treatinf(flags);
		return (1);
	}
	return (0);
}
