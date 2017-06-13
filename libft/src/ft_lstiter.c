/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleveque <aleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 14:13:19 by aleveque          #+#    #+#             */
/*   Updated: 2017/06/13 19:17:39 by aleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <string.h>

void	ft_lstiter(t_dir *lst, void (*f)(t_dir *elem))
{
	t_dir *list;

	list = lst;
	while (list != NULL)
	{
		f(list);
		list = list->next;
	}
}
