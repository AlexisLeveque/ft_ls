/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleveque <aleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 18:26:30 by aleveque          #+#    #+#             */
/*   Updated: 2017/06/14 19:13:31 by aleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "../libft/libft.h"
# include "../ft_printf/ft_printf.h"
# include <stdlib.h>
# include <stdio.h>
# include <dirent.h>
# include <sys/types.h>

typedef struct	s_env
{
	int				opt_l;
	int				opt_R;
	int				opt_a;
	int				opt_r;
	int				opt_t;
	struct s_dir	*dir;
}				t_env;

void	ft_tria(t_dir **dir);
void	open_dir(t_env *env);
void	error_opt(int opt);
void	error(int err);
void	parsing(t_env *env, int argc, char **argv);

#endif
