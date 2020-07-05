/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   note_min_score_lst.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phuntik <phuntik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/15 18:29:02 by phuntik           #+#    #+#             */
/*   Updated: 2020/06/18 18:38:19 by phuntik          ###   ########.fr       */
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
	print_in_file(0, "zashlo\n", -1);
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
	print_in_file(0, "first\n", -1);
	if (fil->head == NULL)
		fil->head = fil->score;
	fil->score->sum = sum;
	fil->score->ii = i;
	fil->score->jj = j;
	fil->score->next = NULL;
	print_in_file(0, "sum = ", fil->score->sum);
	print_in_file(0, "\n", -1);
	print_in_file(0, "i = ", fil->score->ii);
	print_in_file(0, "\n", -1);
	print_in_file(0, "j = ", fil->score->jj);
	print_in_file(0, "\n", -1);
	print_in_file(0, "konets func\n", -1);
}

void		find_min_score_lst(t_filler *fil)
{
	int		tmp;
	int		i;
	
	i = 0;
	fil->score = fil->head;
	tmp = fil->score->sum;
	print_in_file(0, "pered ciklom\n", -1);
	while (fil->score->next != NULL)
	{
		if (tmp > fil->score->sum && fil->score->sum != 0)
		{
			tmp = fil->score->sum;
		}
		fil->score = fil->score->next;
		i++;
		print_in_file(0, "tmp = ", tmp);
		print_in_file(0, "\n", -1);
		print_in_file(0, "sum: ", fil->score->sum);
		print_in_file(0, "\n", -1);
	}
	print_in_file(0, "second\n", -1);
	fil->score = fil->head;
	while (fil->score->next)
	{
		if (fil->score->sum == tmp)
		{
			fil->piece->win_x = fil->score->ii;
			fil->piece->win_y = fil->score->jj;
		}
		fil->score = fil->score->next;
	}
	print_in_file(0, "end\n", -1);
	return ;
}