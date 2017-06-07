/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleveque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 14:07:13 by aleveque          #+#    #+#             */
/*   Updated: 2017/03/19 20:27:18 by aleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <string.h>

void	ft_lstdel(t_list **alst)
{
	t_list	*list;
	t_list	*old;

	while (*alst != NULL)
	{
		old = *alst;
		list = old->next;
		ft_lstdelone(alst);
		*alst = list;
	}
	*alst = NULL;
}
