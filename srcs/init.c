/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastasiaseliseva <anastasiaseliseva@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/17 17:48:31 by phuntik           #+#    #+#             */
/*   Updated: 2020/06/11 22:15:18 by anastasiase      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

t_filler		*init_fil()
{
	t_filler	*fill;
	if (!(fill = (t_filler *)ft_memalloc(sizeof(t_filler))))
		exit(EXIT_FAILURE);
	fill->map = NULL;
	fill->piece = NULL;
	if (!(fill->player = (t_player *)ft_memalloc(sizeof(t_player))))
		exit(EXIT_FAILURE);
	fill->player->en = 0;
	fill->player->me = 0;
	return (fill);
}

t_piece			*init_piece()
{
	t_piece		*piece;
	if (!(piece = (t_piece *)ft_memalloc(sizeof(t_piece))))
		exit(EXIT_FAILURE);
	piece->detal = NULL;
	piece->x = 0;
	piece->y = 0;
	piece->win_x = 0;
	piece->win_y = 0;
	return (piece);
}

t_map			*init_map()
{
	t_map		*map;
	if (!(map = (t_map *)ft_memalloc(sizeof(t_map))))
		exit(EXIT_FAILURE);
	map->y = 0;
	map->x = 0;
	map->en = 0;
	map->mapa = NULL;
	return (map);
}

t_player		*init_player()
{
	t_player	*player;
	if (!(player = (t_player *)ft_memalloc(sizeof(t_player))))
		exit(EXIT_FAILURE);
	player->en = 0;
	player->me = 0;
	return (player);
}