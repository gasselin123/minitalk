/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_f.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasselin <gasselin@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 11:45:15 by gasselin          #+#    #+#             */
/*   Updated: 2021/06/22 11:51:11 by gasselin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_convfeg	ft_print_f(t_convfeg dbl, t_flags flags)
{
	dbl = ft_ftoa(dbl, flags);
	return (dbl);
}
