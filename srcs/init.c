/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phuntik <phuntik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/17 17:48:31 by phuntik           #+#    #+#             */
/*   Updated: 2020/05/07 19:58:37 by phuntik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

t_filler		*init_fil()
{
	t_filler	*fill;
	if (!(fill = (t_filler *)ft_memalloc(sizeof(t_filler))))
		exit(0);
	fill->map = NULL;
	fill->piece = NULL;
	fill->player = NULL;
	return (fill);
}

t_piece			*init_piece()
{
	t_piece		*piece;
	if (!(piece = (t_piece *)ft_memalloc(sizeof(t_piece))))
		exit(0);
	piece->detal = NULL;
	piece->x = 0;
	piece->y = 0;
	return (piece);
}

t_map			*init_map()
{
	t_map		*map;
	if (!(map = (t_map *)ft_memalloc(sizeof(t_map))))
		exit(0);
	map->y = 0;
	map->x = 0;
	map->mapa = NULL;
	return (map);
}

t_player		*init_player()
{
	t_player	*player;
	if (!(player = (t_player *)ft_memalloc(sizeof(t_player))))
		exit(0);
	player->en = 0;
	player->me = 0;
	return (player);
}