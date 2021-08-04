/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasselin <gasselin@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 10:50:10 by gasselin          #+#    #+#             */
/*   Updated: 2021/06/22 11:44:10 by gasselin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flags	ft_flag_minus(t_flags flags)
{
	flags.minus = 1;
	flags.zero = 0;
	return (flags);
}

t_flags	ft_flag_plus(t_flags flags)
{
	flags.plus = 1;
	return (flags);
}

t_flags	ft_flag_digit(char c, t_flags flags)
{
	flags.width = (flags.width * 10) + (c - '0');
	return (flags);
}

int	ft_flag_dot(const char *str, int i, t_flags *flags, va_list arg_list)
{
	int	j;

	j = i + 1;
	if (str[j] == '*')
	{
		flags->dot = va_arg(arg_list, int);
		if (flags->dot < 0)
			flags->dot = -1;
		j++;
	}
	else
	{
		flags->dot = 0;
		while (ft_isdigit(str[j]))
			flags->dot = (flags->dot * 10) + (str[j++] - '0');
	}
	return (j);
}

t_flags	ft_flag_width(va_list arg_list, t_flags flags)
{
	flags.star = 1;
	flags.width = va_arg(arg_list, int);
	if (flags.width < 0)
	{
		flags.minus = 1;
		flags.zero = 0;
		flags.width *= -1;
	}
	return (flags);
}
