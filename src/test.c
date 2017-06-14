/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleveque <aleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 13:44:05 by aleveque          #+#    #+#             */
/*   Updated: 2017/06/14 16:00:34 by aleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int main(int argc, char **argv)
{
	DIR* rep = NULL;
	struct dirent* fichierLu = NULL;

	rep = opendir("..");


	if (rep == NULL)
	{
		perror("Erreur ");
		exit(1);
	}
	puts("Le dossier a ete ouvert avec succes");

while ((fichierLu = readdir(rep)) != NULL)
{
	if (fichierLu->d_name[0] != '.')
	{
		printf("Le fichier lu s'appelle '%s', de type : '%hhd'\n", fichierLu->d_name, fichierLu->d_type);
		printf("%ld\n", telldir(rep));
	}
}


	if (closedir(rep) == -1)
	{
		perror("Erreur ");
		exit(-1);
	}

    puts("Le dossier a ete ferme avec succes");

	printf("%s\n", argv[0]);
    return 0;
}
