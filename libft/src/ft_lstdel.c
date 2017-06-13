/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleveque <aleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 14:07:13 by aleveque          #+#    #+#             */
/*   Updated: 2017/06/13 19:17:24 by aleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <string.h>

void	ft_lstdel(t_dir **alst)
{
	t_dir	*list;
	t_dir	*old;

	while (*alst != NULL)
	{
		old = *alst;
		list = old->next;
		ft_lstdelone(alst);
		*alst = list;
	}
	*alst = NULL;
}
