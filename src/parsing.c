/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleveque <aleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 13:44:05 by aleveque          #+#    #+#             */
/*   Updated: 2017/06/13 20:12:17 by aleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	init_env(t_env *env)
{
	env->opt_l = 0;
	env->opt_R = 0;
	env->opt_a = 0;
	env->opt_r = 0;
	env->opt_t = 0;
}

void	parsing2(t_env *env, int i, int argc, char **argv)
{ // recupérer la pos de la ou on est pour l'ajouter a l'elem ou qqpart avec la liste;
	// if (i >= argc)
	// 	ft_lstadd(".");
	// else
	// {
	// 	while (i < argc)
	// 		ft_lstadd(argv[i++]);
	// }
	printf("opt_l= %d\nopt_R= %d\nopt_a= %d\nopt_r= %d\nopt_t= %d\n", env->opt_l, env->opt_R, env->opt_a,
	env->opt_r, env->opt_t);
}

void	parsing(t_env *env, int argc, char **argv)
{
	int i;
	int y;

	init_env(env);
	i = 1;
	while (i < argc && argv[i][0] == '-' && argv[i][1] != 0)
	{
		y = 0;
		while (argv[i][++y])
			if (argv[i][y] == 'l')
				env->opt_l = 1;
			else if (argv[i][y] == 'R')
				env->opt_R = 1;
			else if (argv[i][y] == 'a')
				env->opt_a = 1;
			else if (argv[i][y] == 'r')
				env->opt_r = 1;
			else if (argv[i][y] == 't')
				env->opt_t = 1;
			else
				error_opt(argv[i][y]);
		i++;
	}
	parsing2(env, i, argc, argv);
}
