/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleveque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 13:55:11 by aleveque          #+#    #+#             */
/*   Updated: 2017/03/19 20:27:25 by aleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <string.h>
#include <stdlib.h>

void	ft_lstdelone(t_list **alst)
{
	t_list *list;

	list = *alst;
	free(list);
	*alst = NULL;
}
