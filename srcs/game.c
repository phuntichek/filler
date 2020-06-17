/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phuntik <phuntik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/25 19:02:42 by phuntik           #+#    #+#             */
/*   Updated: 2020/06/17 18:06:54 by phuntik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void		get_detal(t_filler *fil)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	print_in_file(0, "step 1.0\n", -1);
	fil->piece->hdetal = (int **)malloc(sizeof(int *) * fil->piece->y);
	while (i < fil->piece->y)
	{
		fil->piece->hdetal[i] = (int *)ft_memalloc(sizeof(int) * (fil->piece->x));
		i++;
	}
	i = 0;
	while (i < fil->piece->y)
	{
		j = 0;
		while (j < fil->piece->x)
		{
			if (fil->piece->detal[i][j] == '*')
			{
				fil->piece->hdetal[i][j] = -4;
			}
			else
			{
				fil->piece->hdetal[i][j] = 0;
			}
			
			j++;
		}
		i++;
	}
	print_in_file(0, "after while\n", -1);
	// i = 0;
	// j = 0;
	// printf("kusochek: \n");
	// while (i < fil->piece->y)
	// {
	// 	j = 0;
	// 	while (j < fil->piece->x)
	// 	{
	// 		printf("%d", fil->piece->hdetal[i][j]);
	// 		j++;
	// 	}
	// 	printf("\n");
	// 	i++;
	// }
	fil->piece->score = (int *)ft_memalloc(sizeof(int) * (fil->map->x * fil->map->y));
	fil->piece->ii = (int *)ft_memalloc(sizeof(int) * (fil->map->x * fil->map->y));
	fil->piece->jj = (int *)ft_memalloc(sizeof(int) * (fil->map->x * fil->map->y));
}

void		try_place_detal(t_filler *fil)
{
	print_in_file(0, "step 2.0\n", -1);
	int		i;
	int		j;
	
	i = 0;
	j = 0;
	while (i < fil->map->y)
	{
		j = 0;
		while (j < fil->map->x)
		{
			if ((i + fil->piece->y <= fil->map->y) && (j + fil->piece->x <= fil->map->x))
			{
				score_detali(fil, i, j);				
			}
			j++;
		}
		i++;
	}
	return ;
}

void		score_detali(t_filler *fil, int i, int j)
{
	int		k;
	int		n;
	int		c;
	int		e;
	int		**kusok;
	

	k = 0;
	n = 0;
	c = 0;
	e = 0;
	kusok = (int **)malloc(sizeof(int *) * fil->piece->y);
	while (k < fil->piece->y)
	{
		kusok[k] = (int *)ft_memalloc(sizeof(int) * fil->piece->x);
		k++;
	}
	k = 0;
	while (k < fil->piece->y)
	{
		n = 0;
		while (n < fil->piece->x)
		{
			if ((fil->piece->hdetal[k][n] == -4) && (k + i <= fil->map->y) && (n + j <= fil->map->x))
			{
				kusok[k][n] = fil->map->hmap[k + i][n + j];
			}
			n++;
		}
		k++;
	}
	k = 0;
	n = 0;
	while (k < fil->piece->y)
	{
		n = 0;
		while (n < fil->piece->x)
		{
			if (kusok[k][n] == -3)
				c++;
			if (kusok[k][n] == -2)
				e++;
			n++;
		}
		k++;
	}
	if (c == 1 && e == 0)
	{
		note_min_score_lst(fil, kusok, i, j);
	}
	k = 0;
	n = 0;
	if (kusok)
	{
		while (k < fil->piece->y)
		{
			free(kusok[k]);
			k++;
		}
	}
	return ;
}

void		note_min_score(t_filler *fil, int **kusok, int i, int j)
{
	int		k;
	int		n;
	int		sum;

	k = 0;
	n = 0;
	sum = 0;
	while (k < fil->piece->y)
	{
		n = 0;
		while (n < fil->piece->x)
		{
			sum = sum + kusok[k][n];
			n++;
		}
		k++;
	}
	k = 0;
	n = 0;
	while (fil->piece->score[n] != 0)
	{
		n++;
	}
	fil->piece->score[n] = sum;
	fil->piece->ii[n] = i;
	fil->piece->jj[n] = j;
}

void		find_min_score(t_filler *fil)
{
	int		i;
	int		tmp;

	i = 0;
	tmp = fil->piece->score[0];
	while (fil->piece->score[i] != 0)
	{
		if (tmp > fil->piece->score[i])
		{
			tmp = fil->piece->score[i];
		}
		i++;
	}
	i = 0;
	while (fil->piece->score[i] != tmp)
	{
		i++;
	}
	fil->piece->win_x = fil->piece->ii[i];
	fil->piece->win_y = fil->piece->jj[i];
	// printf("x = %d\n", fil->piece->win_x);
	// printf("y = %d\n", fil->piece->win_y);
	// printf("summa kuska = %d\n", fil->piece->score[i]);
	return ;
}