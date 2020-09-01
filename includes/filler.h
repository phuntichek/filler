/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phuntik <phuntik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 16:16:50 by phuntik           #+#    #+#             */
/*   Updated: 2020/08/06 16:16:52 by phuntik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# include <stdlib.h>
# include <math.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/_types/_o_sync.h>
# include <stdbool.h>
# include "../libft/libft.h"

# define INT_MAX	2147483647

typedef struct	s_piece
{
	int			height;
	int			width;
	char		**map;
}				t_piece;

typedef struct	s_map
{
	int			height;
	int			width;
	char		**map;
	int			**heatmap;
}				t_map;

typedef struct	s_filler
{
	int			sum;
	int			count;
	int			x;
	int			y;
	char		my_sy;
	int			my_nu;
	char		en_sy;
	int			en_nu;
	t_map		*map;
	t_piece		*piece;
}				t_filler;

t_filler		*init_filler();
t_map			*init_map();
t_piece			*init_piece();
void			init_heatmap(t_filler *fill);
void			print_in_file(char c, char *str, int value);
bool			parse_fighter(t_filler *fill);
bool			parse_map(t_filler *fill);
bool			parse_piece(t_filler *fill);
void			find_coords(t_filler *fill);
void			math_heatmap(t_filler *fill);
void			free_map_and_piece(t_filler *fill);
void			reset(t_filler *fill);

#endif
