/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_dir.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleveque <aleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/14 16:28:46 by aleveque          #+#    #+#             */
/*   Updated: 2017/06/20 17:11:45 by aleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void		open_dir(t_env *env)
{
	t_dir *tmp;

	tmp = env->dir;
	while (tmp != NULL && tmp->err == 0)
	{
		if ((tmp->rep = opendir(tmp->name)) == NULL)
			tmp->err = 1;
		tmp = tmp->next;
	}
	if (env->opt_R == 0)
	{
		readdir_basic(env);
		tri_basic(env);
		aff_basic(env);
	}
	// tmp = env->dir;
	// while (tmp != NULL && tmp->err == 0)
	// {
	// 	if (tmp->rep != NULL && (tmp->dir = readdir(tmp->rep)) == NULL)
	// 		tmp->err = 2;
	// 	if (tmp->err == 0 && tmp->dir->d_name[0] != '.')
	// 		ft_lstadd(&tmp->in, ft_lstnew(tmp->dir->d_name));
	// 	// tmp = tmp->next;
	// }
	// // t_dir *tmp1 = env->dir->in;
	// // while (tmp1 != NULL)
	// // {
	// // 	printf("name: %s\n", tmp1->name);
	// // 	tmp1 = tmp1->next;
	// // }
	// ft_tria(&env->dir->in);
	// tmp = tmp->in;
	// while (tmp != NULL && tmp->err == 0)
	// {
	// 	printf("%s\n", tmp->name);
	// 	tmp = tmp->next;
	// }
	// if (tmp->err != 0)
	// 	perror("Erreur ");
}
