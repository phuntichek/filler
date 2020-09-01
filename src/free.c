/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phuntik <phuntik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 16:15:19 by phuntik           #+#    #+#             */
/*   Updated: 2020/08/06 16:15:21 by phuntik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

static void		free_map(t_map *map)
{
	int			i;

	i = 0;
	while (i < map->height)
	{
		free(map->map[i]);
		map->map[i] = NULL;
		i++;
	}
	free(map->map);
}

static void		free_heatmap(t_map *map)
{
	int			i;

	i = 0;
	while (i < map->height)
	{
		free(map->heatmap[i]);
		map->heatmap[i] = NULL;
		i++;
	}
	free(map->heatmap);
}

static void		free_piece(t_piece *piece)
{
	int			i;

	i = 0;
	while (i < piece->height)
	{
		free(piece->map[i]);
		piece->map[i] = NULL;
		i++;
	}
	free(piece->map);
}

void			free_map_and_piece(t_filler *fill)
{
	free_heatmap(fill->map);
	free_map(fill->map);
	free(fill->map);
	fill->map = NULL;
	free_piece(fill->piece);
	free(fill->piece);
	fill->piece = NULL;
}
