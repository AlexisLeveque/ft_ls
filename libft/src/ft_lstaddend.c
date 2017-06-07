/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleveque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 16:22:01 by aleveque          #+#    #+#             */
/*   Updated: 2017/03/20 15:45:55 by aleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <string.h>

void	ft_lstaddend(t_list **list, t_list *new)
{
	t_list *lst;

	lst = *list;
	if (lst == NULL)
		*list = new;
	else
	{
		while (lst->next != NULL)
			lst = lst->next;
		lst->next = new;
	}
}
