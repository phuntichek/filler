/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phuntik <phuntik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/20 18:31:07 by phuntik           #+#    #+#             */
/*   Updated: 2020/05/25 18:50:37 by phuntik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void		all_free(t_filler *fil)
{
	int		i;
	
	i = 0;
	while (i < fil->map->y)
	{
		free(fil->map->mapa[i]);
		free(fil->map->hmap[i]);
		i++;
	}
	i = 0;
	free(fil->map->mapa);
	free(fil->map->hmap);
	fil->map->mapa = NULL;
	fil->map->hmap = NULL;
	// free(fil->piece->score);
	// free(fil->piece->ii);
	// free(fil->piece->jj);
	// fil->piece->score = NULL;
	// fil->piece->ii = NULL;
	// fil->piece->jj = NULL;
	while (i < fil->piece->y)
	{
		free(fil->piece->detal[i]);
		// free(fil->piece->hdetal[i]);
		i++;
	}
	free(fil->piece->detal);
	// free(fil->piece->hdetal);
	fil->piece->detal = NULL;
	// fil->piece->hdetal = NULL;
	return ;
}