/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phuntik <phuntik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/21 19:12:10 by phuntik           #+#    #+#             */
/*   Updated: 2020/06/15 15:24:54 by phuntik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void		build_map(t_filler *fil)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	fil->map->en = 0;
	fil->map->hmap = (int **)malloc(sizeof(int *) * fil->map->y);
	while (i < fil->map->y)
	{
		fil->map->hmap[i] = (int *)ft_memalloc(sizeof(int) * fil->map->x);
		// ft_bzero(fil->map->hmap[i], fil->map->x);
		i++;
	}
	// printf("noliki:\n");
	// i = 0;
	// j = 0;
	// while (i < fil->map->y)
	// {
	// 	j = 0;
	// 	while (j < fil->map->x)
	// 	{
	// 		printf("|%d", fil->map->hmap[i][j]);
	// 		// if(fil->map->hmap[k][n] <= 9 && fil->map->hmap[k][n] >= 0)
	// 			// printf(" ");
	// 		j++;
	// 	}
	// 	printf("\n");
	// 	i++;	
	// }
	i = 0;
	j = 0;
	while (i < fil->map->y)
	{
		j = 0;
		while (j < fil->map->x)
		{
			if (fil->map->mapa[i][j] == fil->player->me || fil->map->mapa[i][j] == (fil->player->me + 32))
				fil->map->hmap[i][j] = -3;
			else if (fil->map->mapa[i][j] == fil->player->en || fil->map->mapa[i][j] == fil->player-> en + 32)
			{
				fil->map->hmap[i][j] = -2;
				fil->map->en++;
			}
			j++;
		}
		i++;
	}
}

void		build_heap_map(t_filler *fil)
{
	int		i;
	int		j;
	int		k;
	int		n;
	
	i = 0;
	j = 0;
	while (i < fil->map->y)
	{
		j = 0;
		while (j < fil->map->x)
		{
			if (fil->map->hmap[i][j] == 0)
			{
				fil->map->hmap[i][j] = ft_coord(fil, i, j);
			}
			j++;
		}
		i++;
	}
	k = 0;
	n = 0;
	print_in_file(0, "heap map\n", -1);
	while (k < fil->map->y)
	{
		n = 0;
		while (n < fil->map->x)
		{
			print_in_file(0, "|", fil->map->hmap[k][n]);
			if(fil->map->hmap[k][n] <= 9 && fil->map->hmap[k][n] >= 0)
				print_in_file(0, " ", -1);
			n++;
		}
		print_in_file(0, "\n", -1);
		k++;	
	}
	return ;
}

int		ft_coord(t_filler *fil, int i, int j)
{
	int		k;
	int		n;
	int		z;
	int		min;
	int		*x;
	int		*y;
	int		*res;

	k = 0;
	n = 0;
	z = 0;
	min = 0;
	x = (int *)malloc(sizeof(int) * fil->map->en);
	y = (int *)malloc(sizeof(int) * fil->map->en);
	res = (int *)malloc(sizeof(int) * fil->map->en);
	while (k < fil->map->y)
	{
		n = 0;
		while (n < fil->map->x)
		{
			if (fil->map->hmap[k][n] == -2)
			{
				x[z] = n;
				y[z] = k;
				z++;
			}
			n++;
		}
		k++;
	}
	z = 0;
	// printf("vozmozhnue resultatu:\n");
	while (z < fil->map->en)
	{
		res[z] = abs(i - y[z]) + abs(j - x[z]);
		// printf("%d\n", res[z]);
		z++;
	}
	z = 0;
	n = 0;
	min = res[0];
	while (z < fil->map->en)
	{
		if (min >= res[n])
		{
			min = res[n];
		}
		z++;
		n++;
	}
	if (x)
		free(x);
	if (y)
		free(y);
	if (res)
		free(res);
	return (min);
}