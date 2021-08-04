/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unbr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasselin <gasselin@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 11:46:58 by gasselin          #+#    #+#             */
/*   Updated: 2021/06/22 16:18:32 by gasselin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_unbr4(char *str, t_flags flags)
{
	if (flags.dot >= 0)
		ft_treat_width(flags.dot, ft_strlen(str), 1);
	ft_putstr(str);
}

void	ft_print_unbr3(char *str, t_flags flags)
{
	if (flags.minus == 1)
		ft_print_unbr4(str, flags);
	if (flags.dot >= 0 && (size_t)flags.dot < ft_strlen(str))
		flags.dot = ft_strlen(str);
	if (flags.dot >= 0)
	{
		flags.width -= flags.dot;
		ft_treat_width(flags.width, 0, 0);
	}
	else
		ft_treat_width(flags.width, ft_strlen(str), flags.zero);
	if (flags.minus == 0)
		ft_print_unbr4(str, flags);
}

void	ft_print_unbr2(t_flags flags)
{
	char	*str;

	if (flags.ulli == 0 && flags.dot == 0)
	{
		ft_treat_width(flags.width, 0, 0);
		return ;
	}
	str = ft_ullitoa(flags.ulli);
	ft_print_unbr3(str, flags);
	free(str);
}

void	ft_print_unbr(va_list arg_list, t_flags flags)
{
	if (flags.length <= 0)
		flags.ulli = va_arg(arg_list, unsigned int);
	if (flags.length == 1)
		flags.ulli = va_arg(arg_list, unsigned long int);
	if (flags.length >= 2)
		flags.ulli = va_arg(arg_list, unsigned long long int);
	ft_print_unbr2(flags);
}
