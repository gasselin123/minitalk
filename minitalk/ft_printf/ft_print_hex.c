/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasselin <gasselin@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 11:45:51 by gasselin          #+#    #+#             */
/*   Updated: 2021/06/22 16:00:46 by gasselin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_setbase(t_flags flags)
{
	char	*setbase;

	if (flags.conv == 'x')
		setbase = "0123456789abcdef";
	else
		setbase = "0123456789ABCDEF";
	return (setbase);
}

void	ft_putunbr_base(unsigned long long int nb, char *base)
{
	unsigned long long int	nb2;

	nb2 = nb;
	if (nb2 >= 16)
	{
		ft_putunbr_base(nb2 / 16, base);
		ft_putunbr_base(nb2 % 16, base);
	}
	else
		ft_putchar(*(base + nb2));
}

void	ft_print_hex2(unsigned long long int nb, t_flags flags, int length)
{
	char	*base;

	base = ft_setbase(flags);
	if (flags.minus == 1)
	{
		if (flags.dot >= 0)
			ft_treat_width(flags.dot, length, 1);
		ft_putunbr_base(nb, base);
	}
	if (flags.dot >= 0 && flags.dot < length)
		flags.dot = length;
	if (flags.dot >= 0)
	{
		flags.width -= flags.dot;
		ft_treat_width(flags.width, 0, 0);
	}
	else
		ft_treat_width(flags.width, length, flags.zero);
	if (flags.minus == 0)
	{
		if (flags.dot >= 0)
			ft_treat_width(flags.dot, length, 1);
		ft_putunbr_base(nb, base);
	}
}

void	ft_print_hex(va_list arg_list, t_flags flags)
{
	unsigned long long int	nb2;
	int						length;

	if (flags.length <= 0)
		flags.ulli = va_arg(arg_list, unsigned int);
	if (flags.length == 1)
		flags.ulli = va_arg(arg_list, unsigned long int);
	if (flags.length >= 2)
		flags.ulli = va_arg(arg_list, unsigned long long int);
	if (flags.ulli == 0 && flags.dot == 0)
	{
		ft_treat_width(flags.width, 0, 0);
		return ;
	}
	nb2 = flags.ulli;
	length = 0;
	if (nb2 == 0)
		length = 1;
	while (nb2 != 0)
	{
		nb2 /= 16;
		length++;
	}
	ft_print_hex2(flags.ulli, flags, length);
}
