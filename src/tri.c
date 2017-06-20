/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tri.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleveque <aleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/14 17:29:53 by aleveque          #+#    #+#             */
/*   Updated: 2017/06/20 19:17:18 by aleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	tri_inv(t_dir **dir)
{
	t_dir *tmp1;
	t_dir *tmp2;

	tmp1 = *dir;
	*dir = NULL;
	while (tmp1 != NULL)
	{
		tmp2 = tmp1->next;
		tmp1->next = NULL;
		ft_lstadd(dir, tmp1);
		tmp1 = tmp2;
	}
}

int		tri_ascii(t_dir *tmp2, t_dir *tmp3)
{
	return (ft_strcmp(tmp2->name, tmp3->name) > 0 ? 1 : 0);
}

int		ft_tri(t_dir **dir, int (*tri_func)(t_dir*, t_dir*))
{
	t_dir	*tmp1;
	t_dir	*tmp2;
	t_dir	*tmp3;

	if ((tmp2 = *dir) == NULL)
		return (0);
	if ((tmp3 = tmp2->next) == NULL)
		return (0);
	if (tri_func(tmp2, tmp3) == 1)
	{
		tmp2->next = tmp3->next;
		tmp3->next = tmp2;
		*dir = tmp3;
		return (1);
	}
	tmp1 = *dir;
	tmp2 = tmp2->next;
	tmp3 = tmp3->next;
	while (tmp3 != NULL)
	{
		if (tri_func(tmp2, tmp3) == 1)
		{
			tmp1->next = tmp3;
			tmp2->next = tmp3->next;
			tmp3->next = tmp2;
			return (1);
		}
		tmp1 = tmp1->next;
		tmp2 = tmp2->next;
		tmp3 = tmp3->next;
	}
	return (0);
}

void	ft_tria(t_dir **dir, int (*tri_func)(t_dir*, t_dir*))
{
	int ret;

	ret = 1;
	while (ret != 0)
		ret = ft_tri(dir, tri_func);
}
