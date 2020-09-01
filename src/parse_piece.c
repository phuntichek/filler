/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_piece.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phuntik <phuntik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 16:16:25 by phuntik           #+#    #+#             */
/*   Updated: 2020/08/06 16:16:27 by phuntik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

bool		parse_size_piece(t_filler *fill)
{
	char	*line;
	char	**split;

	if ((get_next_line(0, &line) != 1))
	{
		ft_strdel(&line);
		return (false);
	}
	split = ft_strsplit(line, ' ');
	fill->piece->height = ft_atoi(split[1]);
	fill->piece->width = ft_atoi(split[2]);
	ft_strdel(&line);
	ft_free_arr(split);
	return (true);
}

bool		read_piece(t_filler *fill)
{
	char	*line;
	int		i;

	i = 0;
	while (i < fill->piece->height)
	{
		if ((get_next_line(0, &line) > 0))
		{
			fill->piece->map[i] = ft_strdup(line);
			ft_strdel(&line);
			i++;
		}
		else
		{
			ft_strdel(&line);
			return (false);
		}
	}
	return (true);
}

bool		parse_piece(t_filler *fill)
{
	if (!(parse_size_piece(fill)))
		return (false);
	if (!(fill->piece->map = (char **)ft_memalloc(sizeof(char *)
									* fill->piece->height + 1)))
		return (false);
	if (!(read_piece(fill)))
		return (false);
	return (true);
}
