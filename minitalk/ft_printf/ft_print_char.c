/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasselin <gasselin@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 11:07:29 by gasselin          #+#    #+#             */
/*   Updated: 2021/06/22 11:44:58 by gasselin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_char(va_list arg_list, t_flags flags)
{
	int		c;
	wint_t	wc;

	if (flags.length == 1)
	{
		wc = va_arg(arg_list, wint_t);
		ft_putwchar(wc);
		return ;
	}
	c = va_arg(arg_list, int);
	if (flags.minus == 1)
		ft_putchar(c);
	ft_treat_width(flags.width, 1, 0);
	if (flags.minus == 0)
		ft_putchar(c);
}
