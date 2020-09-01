/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phuntik <phuntik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 16:16:15 by phuntik           #+#    #+#             */
/*   Updated: 2020/08/06 16:16:17 by phuntik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

bool		parse_size_map(t_filler *fill)
{
	char	*line;
	char	**split;

	if ((get_next_line(0, &line) == 1))
	{
		split = ft_strsplit(line, ' ');
		fill->map->height = ft_atoi(split[1]);
		fill->map->width = ft_atoi(split[2]);
		ft_strdel(&line);
		ft_free_arr(split);
	}
	else
	{
		ft_strdel(&line);
		return (false);
	}
	return (true);
}

bool		read_map(t_filler *fill)
{
	char	*line;
	char	**split;
	int		i;

	i = 0;
	if ((get_next_line(0, &line) != 1))
		return (false);
	ft_strdel(&line);
	while (i < fill->map->height)
	{
		if ((get_next_line(0, &line) == 1))
		{
			split = ft_strsplit(line, ' ');
			fill->map->map[i] = ft_strdup(split[1]);
			ft_strdel(&line);
			ft_free_arr(split);
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

bool		parse_map(t_filler *fill)
{
	if (!(parse_size_map(fill)))
		return (false);
	if (!(fill->map->map = (char **)ft_memalloc(sizeof(char *)
									* fill->map->height + 1)))
		return (false);
	if (!(read_map(fill)))
		return (false);
	return (true);
}
