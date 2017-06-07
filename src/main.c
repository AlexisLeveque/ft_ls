/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleveque <aleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 13:44:05 by aleveque          #+#    #+#             */
/*   Updated: 2017/06/07 14:32:27 by aleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int main(void)
{
    DIR* rep = NULL;
	struct dirent* fichierLu = NULL;

    rep = opendir("/Users/aleveque");

    if (rep == NULL)
	{
		perror("Erreur ");
        exit(1);
	}
    puts("Le dossier a ete ouvert avec succes");

while ((fichierLu = readdir(rep)) != NULL)
{
	//if (fichierLu->d_name[0] != '.')
	printf("Le fichier lu s'appelle '%s'\n", fichierLu->d_name);
		printf("%d\n", telldir(rep));
}



    if (closedir(rep) == -1)
	{
		perror("Erreur ");
        exit(-1);
	}

    puts("Le dossier a ete ferme avec succes");

    return 0;
}
