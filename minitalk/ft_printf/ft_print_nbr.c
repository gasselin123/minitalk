/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasselin <gasselin@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 11:46:02 by gasselin          #+#    #+#             */
/*   Updated: 2021/06/22 15:46:45 by gasselin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flags	ft_treat_sign(t_flags flags)
{
	if (flags.space == 1 && flags.plus == 0 && flags.sign == 43)
	{
		ft_putchar(' ');
		flags.width--;
	}
	return (flags);
}

void	ft_print_nbr3(long long int nb, char *str, t_flags flags)
{
	if (nb < 0 && flags.sign == '-')
		ft_putchar('-');
	if (nb >= 0 && flags.plus == 1 && flags.zero == 0)
	{
		ft_putchar('+');
		flags.plus = 0;
	}
	if (flags.dot >= 0)
		ft_treat_width(flags.dot, ft_strlen(str), 1);
	ft_putstr(str);
}

void	ft_print_nbr2(long long int nb, char *str, t_flags flags)
{
	if (nb >= 0 && flags.plus == 1 && (((size_t)flags.width <= ft_strlen(str))
			|| flags.zero == 1))
	{
		ft_putchar('+');
		flags.plus = 0;
	}
	if (flags.minus == 1)
		ft_print_nbr3(nb, str, flags);
	if (flags.dot >= 0 && (size_t)flags.dot < ft_strlen(str))
		flags.dot = ft_strlen(str);
	if (flags.dot >= 0)
	{
		flags.width -= flags.dot;
		if (nb == LLONG_MIN)
			ft_treat_width(flags.width + 1, 0, 0);
		else
			ft_treat_width(flags.width, 0, 0);
	}
	else
		ft_treat_width(flags.width, ft_strlen(str), flags.zero);
	if (flags.minus == 0)
		ft_print_nbr3(nb, str, flags);
	free (str);
}

void	ft_print_nbr(t_flags flags)
{
	long long int	nb2;
	char			*str;

	nb2 = flags.lli;
	flags = ft_treat_sign(flags);
	if (nb2 == 0 && flags.dot == 0)
	{
		if (flags.plus == 1)
			ft_putchar('+');
		ft_treat_width(flags.width, 0, 0);
		return ;
	}
	if (nb2 < 0 && (flags.dot >= 0 || flags.zero == 1))
	{
		if ((flags.zero == 1 && flags.dot <= -1))
		{
			ft_putchar('-');
			flags.sign = 44;
		}
		flags.zero = 1;
	}
	str = ft_ullitoa(flags.ulli);
	ft_print_nbr2(nb2, str, flags);
}

void	ft_parse_idu(int c, va_list arg_list, t_flags flags)
{
	if (c == 'd' || c == 'i')
	{
		if (flags.length <= 0)
			flags.lli = va_arg(arg_list, int);
		if (flags.length == 1)
			flags.lli = va_arg(arg_list, long int);
		if (flags.length >= 2)
			flags.lli = va_arg(arg_list, long long int);
		if (flags.lli < 0)
			flags.sign = '-';
		if (flags.sign == '-' || (flags.sign == '+' && flags.plus == 1))
			flags.width--;
		if (flags.lli >= 0)
			flags.ulli = flags.lli;
		else
			flags.ulli = -flags.lli;
		ft_print_nbr(flags);
	}
	if (c == 'u')
		ft_print_unbr(arg_list, flags);
}
