/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastasiaseliseva <anastasiaseliseva@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/11 21:41:05 by anastasiase       #+#    #+#             */
/*   Updated: 2020/06/11 22:11:37 by anastasiase      ###   ########.fr       */
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
		exit(0);
	while (true)
	{
		fil->map = init_map();
		parse_map(fil);
		fil->piece = init_piece();
		parse_piece(fil);
		build_map(fil);
		build_heap_map(fil);
		// math_heatmap(fil);
		// find_coords(fil);
		get_detal(fil);
		try_place_detal(fil);
		find_min_score(fil);
		print(fil);
		free_map_and_piece(fil);
	}
	free(fil);
	return (0);
}