/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastasiaseliseva <anastasiaseliseva@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/14 17:34:17 by phuntik           #+#    #+#             */
/*   Updated: 2020/06/11 22:09:56 by anastasiase      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FILLER_H
# define FILLER_H
# include <stdio.h>
# include <unistd.h>
# include <math.h>
# include <stdbool.h>
# include <stdlib.h>
# include "../libft/libft.h"

typedef struct	s_player
{
	char		me;
	char		en;
}				t_player;

typedef struct	s_map
{
	int			x;
	int			y;
	int			en;
	int			**hmap;
	char		**mapa;
}				t_map;

typedef struct	s_piece
{
	int			x;
	int			y;
	int			win_x;
	int			win_y;
	int			*score;
	int			*ii;
	int			*jj;
	int			**hdetal;
	char		**detal;
}				t_piece;

typedef struct	s_filler
{
	t_player	*player;
	t_map		*map;
	t_piece		*piece;
}				t_filler;

t_filler		*init_fil();
t_player		*init_player();
t_map			*init_map();
t_piece			*init_piece();
void			build_map(t_filler *fil);
void			build_heap_map(t_filler *fil);
int				ft_coord(t_filler *fil, int i, int j);
void			get_detal(t_filler *fil);
void			try_place_detal(t_filler *fil);
void			score_detali(t_filler *fil, int i, int j);
void			get_detal(t_filler *fil);
void			try_place_detal(t_filler *fil);
void			score_detali(t_filler *fil, int i, int j);
void			note_min_score(t_filler *fil, int **kusok, int i, int j);
void			find_min_score(t_filler *fil);
void			open_file();
void			print_in_file(char c, char *str, int value);
void			all_free(t_filler *fil);
bool			parse_fighter(t_filler *fil);
bool			parse_map(t_filler *fil);
void			print(t_filler *fil);
void			free_map_and_piece(t_filler *fil);
bool			parse_piece(t_filler *fil);

#endif