/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phuntik <phuntik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 16:15:07 by phuntik           #+#    #+#             */
/*   Updated: 2020/08/06 16:15:10 by phuntik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void			print(t_filler *fill)
{
	ft_putnbr(fill->x);
	ft_putchar(' ');
	ft_putnbr(fill->y);
	ft_putchar('\n');
	fill->x = 0;
	fill->y = 0;
}

int				main(void)
{
	t_filler	*fill;

	fill = init_filler();
	if (!(parse_fighter(fill)))
		exit(0);
	while (true)
	{
		fill->map = init_map();
		parse_map(fill);
		init_heatmap(fill);
		fill->piece = init_piece();
		parse_piece(fill);
		math_heatmap(fill);
		find_coords(fill);
		print(fill);
		free_map_and_piece(fill);
	}
	free(fill);
	return (0);
}
