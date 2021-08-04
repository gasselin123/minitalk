/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasselin <gasselin@student.42quebec.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 09:24:34 by gasselin          #+#    #+#             */
/*   Updated: 2021/05/10 09:24:41 by gasselin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*elem;
	t_list	*temp;

	if (!lst)
		return ;
	elem = *lst;
	while (elem)
	{
		temp = elem->next;
		ft_lstdelone(elem, del);
		elem = temp;
	}
	*lst = NULL;
}
