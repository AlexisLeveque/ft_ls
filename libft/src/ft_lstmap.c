/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleveque <aleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 14:17:23 by aleveque          #+#    #+#             */
/*   Updated: 2017/06/13 19:17:50 by aleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <string.h>

t_dir	*ft_lstmap(t_dir *lst, t_dir *(*f)(t_dir *elem))
{
	t_dir *new;
	t_dir *next;

	if (!(new = f(lst)))
		return (NULL);
	next = new;
	while (lst->next != NULL)
	{
		lst = lst->next;
		if (!(new->next = f(lst)))
			return (NULL);
		new = new->next;
	}
	return (next);
}
