/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleveque <aleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/20 16:47:15 by aleveque          #+#    #+#             */
/*   Updated: 2017/06/20 19:16:27 by aleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void		tri_basic(t_env *env)
{
	t_dir *tmp;

	ft_tria(&env->dir, &(tri_ascii));
	if (env->opt_r == 1)
		tri_inv(&env->dir);
	tmp = env->dir;
	while (tmp != NULL)
	{
		ft_tria(&tmp->in, &(tri_ascii));
		if (env->opt_r == 1)
			tri_inv(&tmp->in);
		tmp = tmp->next;
	}
}

void		aff_basic(t_env *env)
{
	t_dir *tmp1;
	t_dir *tmp2;

	tmp1 = env->dir;
	while (tmp1 != NULL)
	{
		if (tmp1 != env->dir)
			ft_printf("\n");
		if (env->nb_param > 1)
			ft_printf("%s:\n", tmp1->name);
		tmp2 = tmp1->in;
		while (tmp2 != NULL && tmp2->err == 0)
		{
			if (env->opt_a == 1 || tmp2->name[0] != '.')
				ft_printf("%s\n", tmp2->name);
			tmp2 = tmp2->next;
		}
		tmp1 = tmp1->next;
	}
}

void		readdir_basic(t_env *env)
{
	t_dir *tmp;

	tmp = env->dir;
	while (tmp != NULL)
	{
		while (tmp->err == 0)
		{
			if (tmp->rep != NULL && (tmp->dir = readdir(tmp->rep)) == NULL)
				tmp->err = 2;
			if (tmp->err == 0)
				ft_lstadd(&tmp->in, ft_lstnew(tmp->dir->d_name));
		}
		tmp = tmp->next;
	}
}
