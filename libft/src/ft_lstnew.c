/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleveque <aleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 12:40:09 by aleveque          #+#    #+#             */
/*   Updated: 2017/06/20 15:37:06 by aleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <string.h>
#include <stdlib.h>

t_dir	*ft_lstnew(char *name)
{
	t_dir *new;

	if (!(new = (t_dir*)malloc(sizeof(t_dir))))
	{
		write(1, "Erreur malloc\n", 14);
		exit(0);
	}
	if (!(new->name = ft_strdup(name)))
	{
		write(1, "Erreur malloc\n", 14);
		exit(0);
	}
	new->err = 0;
	new->rep = NULL;
	new->dir = NULL;
	new->in = NULL;
	new->next = NULL;
	return (new);
}
