/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   note_min_score_lst.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phuntik <phuntik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/15 18:29:02 by phuntik           #+#    #+#             */
/*   Updated: 2020/06/17 18:09:53 by phuntik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/filler.h"

void		note_min_score_lst(t_filler *fil, int **kusok, int i, int j)
{
	int			k;
	int			n;
	int			sum;

	k = 0;
	n = 0;
	sum = 0;
	printf("zashlo");
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
	printf("first");
	fil->score->sum = sum;
	fil->score->ii = i;
	fil->score->jj = j;
	fil->score->next = (t_score *)malloc(sizeof(t_score));
	fil->score = fil->score->next;
}

void		find_min_score_lst(t_filler *fil)
{
	int		tmp;
	int		i;
	
	tmp = 0;
	i = 0;
	fil->score = fil->score->head;
	tmp = fil->score->sum;
	while (fil->score->next)
	{
		if (tmp > fil->score->sum)
		{
			tmp = fil->score->sum;
		}
		fil->score = fil->score->next;
		i++;
	}
	printf("second");
	fil->score = fil->score->head;
	while (fil->score->next)
	{
		if (fil->score->sum == tmp)
		{
			fil->piece->win_x = fil->score->ii;
			fil->piece->win_y = fil->score->jj;
			break ;
		}
	}
	printf("end");
	return ;
}