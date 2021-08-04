/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_wchar2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasselin <gasselin@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 09:09:07 by gasselin          #+#    #+#             */
/*   Updated: 2021/06/23 09:16:13 by gasselin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_wchar_size(wint_t c)
{
	if (c > 0x3FFFFFF)
		return (5);
	if (c > 0xFFFF)
		return (4);
	else if (c > 0x7FF)
		return (3);
	else if (c > 0x7F)
		return (2);
	else
		return (1);
}

unsigned int	get_header(wint_t c)
{
	if (c > 0x3FFFFFF)
		return (0xF1);
	if (c > 0xFFFF)
		return (0xF0);
	else if (c > 0x7FF)
		return (0xE0);
	else if (c > 0x7F)
		return (0xC0);
	else
		return (0x00);
}

unsigned int	get_mask(wint_t c)
{
	if (c > 0x3FFFFFF)
		return (0x03);
	if (c > 0xFFFF)
		return (0x07);
	else if (c > 0x7FF)
		return (0x0F);
	else if (c > 0x7F)
		return (0x1F);
	else
		return (0x00);
}

int	get_shift(wint_t c)
{
	if (c > 0x3FFFFFF)
		return (24);
	if (c > 0xFFFF)
		return (18);
	else if (c > 0x7FF)
		return (12);
	else if (c > 0x7F)
		return (6);
	else
		return (-1);
}
