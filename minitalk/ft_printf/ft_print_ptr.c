/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasselin <gasselin@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 11:46:35 by gasselin          #+#    #+#             */
/*   Updated: 2021/06/22 15:56:05 by gasselin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_count_length(unsigned long ptr)
{
	int	count;

	count = 0;
	while (ptr != 0)
	{
		ptr /= 16;
		count++;
	}
	return (count + 2);
}

char	*ft_treat_base(char *str, unsigned long ptr, int length)
{
	str[0] = '0';
	str[1] = 'x';
	while (ptr != 0)
	{
		if ((ptr % 16) < 10)
			str[length - 1] = (ptr % 16) + 48;
		else
			str[length - 1] = (ptr % 16) + 87;
		ptr /= 16;
		length--;
	}
	return (str);
}

void	ft_print_ptr2(char *str, t_flags flags)
{
	if (flags.dot >= 0)
	{
		ft_treat_width(flags.dot, ft_strlen(str), 1);
		ft_putnstr(str, flags.dot);
	}
	else
		ft_putstr(str);
}

void	ft_print_ptr(va_list arg_list, t_flags flags)
{
	unsigned long	ptr;
	char			*str;
	int				length;

	ptr = va_arg(arg_list, unsigned long);
	if (ptr == 0)
		str = ft_strdup("0x0");
	else
	{
		length = ft_count_length(ptr);
		str = (char *)malloc(sizeof(char) * (length + 1));
		if (!str)
			return ;
		str[length] = '\0';
		str = ft_treat_base(str, ptr, length);
	}
	if ((size_t)flags.dot < ft_strlen(str))
		flags.dot = ft_strlen(str);
	if (flags.minus == 1)
		ft_print_ptr2(str, flags);
	ft_treat_width(flags.width, ft_strlen(str), 0);
	if (flags.minus == 0)
		ft_print_ptr2(str, flags);
	free(str);
}
