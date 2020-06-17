/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phuntik <phuntik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/20 18:31:07 by phuntik           #+#    #+#             */
/*   Updated: 2020/06/14 19:42:59 by phuntik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

// void		all_free(t_filler *fil)
// {
// 	int		i;
	
// 	i = 0;
// 	while (i < fil->map->y)
// 	{
// 		free(fil->map->mapa[i]);
// 		free(fil->map->hmap[i]);
// 		i++;
// 	}
// 	i = 0;
// 	free(fil->map->mapa);
// 	free(fil->map->hmap);
// 	fil->map->mapa = NULL;
// 	fil->map->hmap = NULL;
// 	// free(fil->piece->score);
// 	// free(fil->piece->ii);
// 	// free(fil->piece->jj);
// 	// fil->piece->score = NULL;
// 	// fil->piece->ii = NULL;
// 	// fil->piece->jj = NULL;
// 	while (i < fil->piece->y)
// 	{
// 		free(fil->piece->detal[i]);
// 		// free(fil->piece->hdetal[i]);
// 		i++;
// 	}
// 	free(fil->piece->detal);
// 	// free(fil->piece->hdetal);
// 	fil->piece->detal = NULL;
// 	// fil->piece->hdetal = NULL;
// 	return ;
// }

static void		free_map(t_map *map)
{
	int			i;

	i = 0;
	if (map->mapa)
	{
		while (i < map->y)
		{
			free(map->mapa[i]);
			map->mapa[i] = NULL;
			i++;
		}
	free(map->mapa);
	}
}

static void		free_heatmap(t_map *map)
{
	int			i;

	i = 0;
	if (map->hmap)
	{
		while (i < map->y)
		{
			free(map->hmap[i]);
			map->hmap[i] = NULL;
			i++;
		}
		free(map->hmap);
	}
}

static void		free_piece(t_piece *piece)
{
	int			i;

	i = 0;
	if (piece->detal)
	{
		while (i < piece->y)
		{
			free(piece->detal[i]);
			piece->detal[i] = NULL;
			i++;
		}
		free(piece->detal);
	}
}

static void		free_hpiece(t_piece *piece)
{
	int			i;

	i = 0;
	if (piece->hdetal)
	{
		while (i < piece->y)
		{
			free(piece->hdetal[i]);
			piece->hdetal[i] = NULL;
			i++;
		}
		free(piece->hdetal);
	}
	if (piece->ii)
		free(piece->ii);
	if (piece->jj)
		free(piece->jj);
	if (piece->score)
		free(piece->score);	
}

void			free_map_and_piece(t_filler *fil)
{
	free_heatmap(fil->map);
	free_map(fil->map);
	free(fil->map);
	fil->map = NULL;
	free_piece(fil->piece);
	free_hpiece(fil->piece);
	free(fil->piece);
	fil->piece = NULL;
}
