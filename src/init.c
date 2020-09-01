/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phuntik <phuntik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 16:15:52 by phuntik           #+#    #+#             */
/*   Updated: 2020/08/06 16:15:54 by phuntik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

t_filler		*init_filler(void)
{
	t_filler	*fill;

	if ((fill = (t_filler *)ft_memalloc(sizeof(t_filler))))
	{
		fill->my_sy = 0;
		fill->en_sy = 0;
		fill->my_nu = -1;
		fill->en_nu = -2;
		fill->piece = NULL;
		fill->map = NULL;
		fill->sum = 0;
		fill->count = 0;
	}
	return (fill);
}

t_map			*init_map(void)
{
	t_map		*map;

	if ((map = (t_map *)ft_memalloc(sizeof(t_map))))
	{
		map->height = 0;
		map->width = 0;
		map->map = NULL;
		map->heatmap = NULL;
	}
	return (map);
}

t_piece			*init_piece(void)
{
	t_piece		*piece;

	if ((piece = (t_piece *)ft_memalloc(sizeof(t_piece))))
	{
		piece->height = 0;
		piece->width = 0;
		piece->map = NULL;
	}
	return (piece);
}

void			init_heatmap(t_filler *fill)
{
	int			y;

	y = 0;
	if ((fill->map->heatmap = (int **)ft_memalloc(sizeof(int *)
										* fill->map->height)))
	{
		while (y < fill->map->height)
		{
			if (!(fill->map->heatmap[y] = (int *)ft_memalloc(sizeof(int)
												* fill->map->width)))
				exit(0);
			y++;
		}
	}
}
