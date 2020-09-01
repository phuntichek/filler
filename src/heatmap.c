/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heatmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phuntik <phuntik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 16:15:30 by phuntik           #+#    #+#             */
/*   Updated: 2020/08/06 16:15:32 by phuntik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void		find_position(t_filler *fill)
{
	int		x;
	int		y;

	x = 0;
	while (x < fill->map->height)
	{
		y = 0;
		while (y < fill->map->width)
		{
			if (ft_toupper(fill->map->map[x][y]) == fill->my_sy)
				fill->map->heatmap[x][y] = fill->my_nu;
			if (ft_toupper(fill->map->map[x][y]) == fill->en_sy)
				fill->map->heatmap[x][y] = fill->en_nu;
			y++;
		}
		x++;
	}
}

int			manhattan_dist(int x, int y, t_filler *fill)
{
	int		max;
	int		x1;
	int		y1;
	int		dist;

	max = INT_MAX;
	x1 = 0;
	while (x1 < fill->map->height)
	{
		y1 = 0;
		while (y1 < fill->map->width)
		{
			if (fill->map->heatmap[x1][y1] == fill->en_nu)
			{
				dist = abs(x - x1) + abs(y - y1);
				if (dist < max)
					max = dist;
			}
			y1++;
		}
		x1++;
	}
	return (max);
}

void		math_heatmap(t_filler *fill)
{
	int x;
	int y;

	x = 0;
	find_position(fill);
	while (x < fill->map->height)
	{
		y = 0;
		while (y < fill->map->width)
		{
			if (fill->map->heatmap[x][y] == 0)
				fill->map->heatmap[x][y] = manhattan_dist(x, y, fill);
			y++;
		}
		x++;
	}
}
