/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasselin <gasselin@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 10:23:51 by gasselin          #+#    #+#             */
/*   Updated: 2021/06/22 15:57:05 by gasselin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flags	ft_init_flags(void)
{
	t_flags	flags;

	flags.width = 0;
	flags.minus = 0;
	flags.zero = 0;
	flags.dot = -1;
	flags.star = 0;
	flags.plus = 0;
	flags.space = 0;
	flags.hashtag = 0;
	flags.sign = 43;
	flags.conv = 0;
	flags.length = 0;
	flags.ulli = 0;
	flags.lli = 0;
	flags.pad = '\0';
	flags.str = NULL;
	ft_bzero(flags.conv2, 4);
	return (flags);
}

void	ft_formater(int c, t_flags flags, va_list arg_list)
{
	if (c == 'd' || c == 'i' || c == 'u')
		ft_parse_idu(c, arg_list, flags);
	else if (c == 'c')
		ft_print_char(arg_list, flags);
	else if (c == 's')
		ft_print_str(arg_list, flags);
	else if (c == 'p')
		ft_print_ptr(arg_list, flags);
	else if (c == 'x' || c == 'X')
		ft_print_hex(arg_list, flags);
	else if (c == '%')
		ft_print_pct(flags);
	else if (c == 'f' || c == 'e' || c == 'g')
		ft_print_feg(c, arg_list, flags);
	else if (c == 'n')
		ft_print_nil(arg_list, flags);
}

int	ft_parse_flags(const char *str, int i, t_flags *flags, va_list arg_list)
{
	while (str[i])
	{
		if (!ft_isdigit(str[i]) && !ft_isflags(str[i]) && !ft_isconvt(str[i]))
			break ;
		if (str[i] == '-')
			*flags = ft_flag_minus(*flags);
		if (str[i] == '0' && flags->width == 0 && flags->minus == 0)
			flags->zero = 1;
		if (str[i] == ' ')
			flags->space = 1;
		if (str[i] == '#')
			flags->hashtag = 1;
		if (str[i] == '.')
			i = ft_flag_dot(str, i, flags, arg_list);
		if (str[i] == '*')
			*flags = ft_flag_width(arg_list, *flags);
		if (str[i] == '+')
			*flags = ft_flag_plus(*flags);
		if (ft_isdigit(str[i]))
			*flags = ft_flag_digit(str[i], *flags);
		if (ft_isconvt(str[i]))
			break ;
		i++;
	}
	return (i);
}

void	ft_parser(const char *format, va_list arg_list)
{
	int		i;
	int		i2;
	t_flags	flags;

	i = 0;
	while (format[i] != '\0')
	{
		flags = ft_init_flags();
		if (format[i] == '%' && format[i + 1])
		{
			i = ft_parse_flags(format, ++i, &flags, arg_list);
			i2 = ft_parse_size(format, &i, &flags);
			if (ft_isconvt(format[i]) && format[i] != 104 && format[i] != 108)
			{
				flags.conv = format[i];
				flags.conv2[i2] = format[i];
				ft_formater(format[i], flags, arg_list);
			}
			else if (format[i])
				ft_putchar(format[i]);
		}
		else
			ft_putchar(format[i]);
		i++;
	}
}
