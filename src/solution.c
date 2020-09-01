/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phuntik <phuntik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 16:16:33 by phuntik           #+#    #+#             */
/*   Updated: 2020/08/06 16:16:35 by phuntik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int			count_coords(t_filler *fill, int x, int y)
{
	int		x1;
	int		y1;

	fill->count = 0;
	fill->sum = 0;
	x1 = -1;
	while (++x1 < fill->piece->height)
	{
		y1 = -1;
		while (++y1 < fill->piece->width)
		{
			if (fill->piece->map[x1][y1] == '*')
			{
				if ((x + x1) < 0 || (x + x1) >= fill->map->height ||
				(y + y1) < 0 || (y + y1) >= fill->map->width ||
				fill->map->heatmap[x + x1][y + y1] == fill->en_nu)
					return (-1);
				if (fill->map->heatmap[x + x1][y + y1] == fill->my_nu)
					fill->count++;
				fill->sum += fill->map->heatmap[x + x1][y + y1];
			}
		}
	}
	return (fill->count == 1 ? fill->sum : -1);
}

void		find_coords(t_filler *fill)
{
	int		x;
	int		y;
	int		max;
	int		sum;

	x = 0;
	max = INT_MAX;
	while (x < fill->map->height)
	{
		y = 0;
		while (y < fill->map->width)
		{
			sum = count_coords(fill, x, y);
			if (sum != -1 && sum < max)
			{
				fill->x = x;
				fill->y = y;
				max = sum;
			}
			y++;
		}
		x++;
	}
}
