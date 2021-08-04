/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nil.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasselin <gasselin@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 11:46:21 by gasselin          #+#    #+#             */
/*   Updated: 2021/06/22 15:49:29 by gasselin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_nil(va_list arg_list, t_flags flags)
{
	int			*arg;
	long		*larg;
	long long	*llarg;

	if (flags.length == 0)
	{
		arg = va_arg(arg_list, int *);
		if (arg)
			*arg = ft_printed(0, 0);
	}
	else if (flags.length == 1)
	{
		larg = va_arg(arg_list, long *);
		if (larg)
			*larg = (long)ft_printed(0, 0);
	}
	else if (flags.length == 2)
	{
		llarg = va_arg(arg_list, long long *);
		if (llarg)
			*llarg = (long long)ft_printed(0, 0);
	}
}
