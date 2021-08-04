/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasselin <gasselin@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 11:46:28 by gasselin          #+#    #+#             */
/*   Updated: 2021/06/22 15:50:24 by gasselin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_pct(t_flags flags)
{
	if (flags.minus == 1)
		ft_putchar(37);
	ft_treat_width(flags.width, 1, flags.zero);
	if (flags.minus == 0)
		ft_putchar(37);
}
