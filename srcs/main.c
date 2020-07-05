/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phuntik <phuntik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/11 21:41:05 by anastasiase       #+#    #+#             */
/*   Updated: 2020/06/17 21:04:09 by phuntik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int				main(void)
{
	t_filler	*fil;
	int			fd;

	open_file();
	fil = init_fil();
	if (!(parse_fighter(fil)))
		exit(EXIT_FAILURE);
	while (true)
	{
		fil->score = init_score();
		fil->map = init_map();
		parse_map(fil);
		fil->piece = init_piece();
		parse_piece(fil);
		build_map(fil);
		build_heap_map(fil);
		print_in_file(0, "step 0\n", -1);
		get_detal(fil);
		print_in_file(0, "step 1\n", -1);
		try_place_detal(fil);
		print_in_file(0, "step 2\n", -1);
		find_min_score_lst(fil);
		print_in_file(0, "step 3\n", -1);
		print(fil);
		free_map_and_piece(fil);
		print_in_file(0, "The End\n", -1);
	}
	free(fil);
	return (0);
}