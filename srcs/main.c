/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phuntik <phuntik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/14 17:40:23 by phuntik           #+#    #+#             */
/*   Updated: 2020/06/10 00:44:41 by phuntik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void		parse_player(t_filler *fil)
{
	int		i;
	char	*str;

	i = 0;
	if (get_next_line(0, &str) > 0)
	{
		while (str[i] != 'p')
			i++;
		if (str[++i] == '1')
		{
			fil->player->me = 'O';
			fil->player->en = 'X';
		}
		else
		{
			fil->player->me = 'X';
			fil->player->en = 'O';
		}
		free(str);
	}
	print_in_file(0, str, -1);
	// print_in_file(0, "player:", -1);
	// print_in_file(fil->player->me, "", -1);
	// printf("player: ");
	// printf("%c\n", fil->player->me);
	print_in_file(0, "parse player success", -1);
	return ;
	
}

bool		parse_map_size(t_filler *fil)
{
	char	**split;
	char	*str;

	if (get_next_line(0, &str) > 0)
	{
		// print_in_file(0, "first", -1);
		split = ft_strsplit(str, ' ');
		// print_in_file(0, "second", -1);
		fil->map->y = ft_atoi(split[1]);
		// print_in_file(0, "third", -1);
		fil->map->x = ft_atoi(split[2]);
		// print_in_file(0, "fourth", -1);
		// printf("%s\n", str);
		print_in_file(0, str, -1);
		print_in_file(0, "parse map size success", -1);
		ft_free_arr(split);
		free(str);
	}
	return (true);
}

bool		parse_map(t_filler *fil)
{
	int		i;
	char	*str;
	char	**split;

	i = 0;
	if (get_next_line(0, &str) > 0)
	print_in_file(0, str, -1);
	{
		fil->map->mapa = (char **)malloc(sizeof(char *) * fil->map->y);
		while (i < fil->map->y)
		{
			if (get_next_line(0, &str) > 0)
			{
				print_in_file(0, str, -1);
				split = ft_strsplit(str, ' ');
				fil->map->mapa[i] = ft_strdup(split[1]);
				// printf("%s\n", fil->map->mapa[i]);
				i++;
			}
			free(str);
			ft_free_arr(split);
		}
	}
	print_in_file(0, "parse map success", -1);
	return (true);
}

bool		parse_piece_size(t_filler *fil)
{
	char	**split;
	char	*str;
	
	if (get_next_line(0, &str) > 0)
	{
		print_in_file(0, str, -1);
		split = ft_strsplit(str, ' ');
		fil->piece->y = ft_atoi(split[1]);
		fil->piece->x = ft_atoi(split[2]);
		// printf("%s\n", str);
		ft_free_arr(split);
		free(str);
	}
	print_in_file(0, "parse piece size success", -1);
	return (true);
}

bool		parse_piece(t_filler *fil)
{
	int		i;
	char	*str;
	
	i = 0;
	fil->piece->detal = (char **)malloc(sizeof(char *) * fil->piece->y);
	while (i < fil->piece->y)
	{
		if (get_next_line(0, &str) > 0)
		{
			print_in_file(0, str, -1);
			fil->piece->detal[i] = ft_strdup(str);
				// printf("%s\n", fil->piece->detal[i]);
			i++;
			free(str);
		}
	}
	print_in_file(0, "parse piece success", -1);
	return (true);
}

int		main()
{
	int			i;
	t_filler	*fil;

	i = 0;
	fil = init_fil();
	fil->map = init_map();
	fil->player = init_player();
	fil->piece = init_piece();
	// get_nex)t_line(0, &str);
	open_file();
	parse_player(fil);
	while (true)
	{	
		print_in_file(0, "zashlo", -1);
		parse_map_size(fil);
		print_in_file(0, "prohod 1", -1);
		parse_map(fil);
		print_in_file(0, "prohod 2", -1);
		parse_piece_size(fil);
		print_in_file(0, "prohod 3", -1);
		parse_piece(fil);
		print_in_file(0, "prohod 4", -1);
		build_map(fil);
		print_in_file(0, "prohod 5", -1);
		build_heap_map(fil);
		print_in_file(0, "prohod 6", -1);
		get_detal(fil);
		print_in_file(0, "prohod 7", -1);
		try_place_detal(fil);
		print_in_file(0, "prohod 8", -1);
		find_min_score(fil);
		print_in_file(0, "prohod 9", -1);
		printf("%d %d\n", fil->piece->win_x, fil->piece->win_y);
		print_in_file(0, "x:", fil->piece->win_x);
		print_in_file(0, "y:", fil->piece->win_y);
		fil->piece->win_x = 0;
		fil->piece->win_y = 0;
		all_free(fil);
		print_in_file(0, "proshlo", -1);
	} 
	// while (parse_map_size(fil) == true
	// && parse_map(fil) == true
 	// && parse_piece_size(fil) == true
	// && parse_piece(fil) == true)
	// {
	// 	print_in_file(0, "proshlo vse usloviya tcikla", -1);
	// 	build_map(fil);
	// 	build_heap_map(fil);
	// 	get_detal(fil);
	// 	try_place_detal(fil);
	// 	find_min_score(fil);
	// 	printf("%d %d\n", fil->piece->win_x, fil->piece->win_y);
	// 	print_in_file(0, "x:", fil->piece->win_x);
	// 	print_in_file(0, "y:", fil->piece->win_y);
	// 	fil->piece->win_x = 0;
	// 	fil->piece->win_y = 0;
	// 	all_free(fil);
	// }

			// game(fil, str);
	// free(str);
	// free(fil);
	return(0);
}