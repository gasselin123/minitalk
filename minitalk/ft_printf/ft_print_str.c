/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasselin <gasselin@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 11:46:42 by gasselin          #+#    #+#             */
/*   Updated: 2021/06/22 16:15:19 by gasselin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_str2(char *str, t_flags flags)
{
	if (flags.dot >= 0)
	{
		ft_treat_width(flags.dot, ft_strlen(str), 0);
		ft_putnstr(str, flags.dot);
	}
	else
		ft_putstr(str);
}

void	ft_print_str(va_list arg_list, t_flags flags)
{
	char	*str;
	wchar_t	*wstr;

	if (ft_strncmp(flags.conv2, "ls", 2) == 0)
	{
		wstr = va_arg(arg_list, wchar_t *);
		ft_putwstr(wstr);
		return ;
	}
	str = va_arg(arg_list, char *);
	if (!str)
		str = "(null)";
	if (flags.dot >= 0 && (size_t)flags.dot > ft_strlen(str))
		flags.dot = ft_strlen(str);
	if (flags.minus == 1)
		ft_print_str2(str, flags);
	if (flags.dot >= 0)
		ft_treat_width(flags.width, flags.dot, 0);
	else
		ft_treat_width(flags.width, ft_strlen(str), 0);
	if (flags.minus == 0)
		ft_print_str2(str, flags);
}
