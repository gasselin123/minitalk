/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_wchar.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasselin <gasselin@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 11:47:09 by gasselin          #+#    #+#             */
/*   Updated: 2021/06/23 09:15:39 by gasselin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_wstr_size(const wchar_t *s)
{
	size_t	size;

	size = 0;
	while (*s)
		size += ft_wchar_size((wint_t)(*s++));
	return (size);
}

size_t	ft_wstrnlen(const wchar_t *s, size_t maxlen)
{
	size_t	len;

	len = 0;
	while (len < maxlen)
	{
		if (!s[len])
			break ;
		++len;
	}
	return (len);
}

size_t	ft_wstrlen(const wchar_t *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		++len;
	return (len);
}

void	ft_putwchar(wint_t c)
{
	unsigned int	header;
	unsigned int	mask;
	int				shift;

	header = get_header(c);
	mask = get_mask(c);
	shift = get_shift(c);
	if (ft_wchar_size(c) == 1)
		ft_putchar((char)c);
	else
	{
		ft_putchar(header | (((c >> shift) & mask)));
		shift -= 6;
	}
	while (shift >= 0)
	{
		ft_putchar(0x80 | ((c >> shift) & 0x3F));
		shift -= 6;
	}
}

void	ft_putwstr(const wchar_t *s)
{
	while (*s)
		ft_putwchar((wint_t)(*s++));
}
