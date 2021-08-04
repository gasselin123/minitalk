/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasselin <gasselin@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 10:17:30 by gasselin          #+#    #+#             */
/*   Updated: 2021/06/22 16:23:51 by gasselin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	arg_list;

	ft_printed(0, 1);
	va_start(arg_list, format);
	ft_parser(format, arg_list);
	va_end(arg_list);
	return (ft_printed(0, 0));
}
