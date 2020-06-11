#include "../includes/filler.h"

bool		parse_fighter(t_filler *fil)
{
	char	*line;
	char	**split;

	if ((get_next_line(0, &line) == 1))
	{
		print_in_file(0, line, -1);
		split = ft_strsplit(line, ' ');
		if (ft_strcmp(split[2], "p1") == 0)
		{
			fil->player->me = 'O';
			fil->player->en = 'X';
		}
		else if (ft_strcmp(split[2], "p2") == 0)
		{
			fil->player->me = 'X';
			fil->player->en = 'O';
		}
		ft_strdel(&line);
		ft_free_arr(split);
		return (true);
	}
	else
	{
		ft_strdel(&line);
		return (false);
	}
}

bool		parse_size_map(t_filler *fil)
{
	char	*line;
	char	**split;

	if ((get_next_line(0, &line) == 1))
	{
		print_in_file(0, line, -1);
		split = ft_strsplit(line, ' ');
		fil->map->y = ft_atoi(split[1]);
		fil->map->x = ft_atoi(split[2]);
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

bool		read_map(t_filler *fil)
{
	char	*line;
	char	**split;
	int		i;

	i = 0;
	if ((get_next_line(0, &line) != 1))
		return (false);
	// print_in_file(0, "hello", -1);
	print_in_file(0, line, -1);
	ft_strdel(&line);
	while (i < fil->map->y)
	{
		if ((get_next_line(0, &line) == 1))
		{
			print_in_file(0, line, -1);
			split = ft_strsplit(line, ' ');
			fil->map->mapa[i] = ft_strdup(split[1]);
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

bool		parse_map(t_filler *fil)
{
	if (!(parse_size_map(fil)))
		return (false);
	if (!(fil->map->mapa = (char **)ft_memalloc(sizeof(char *)
									* fil->map->y + 1)))
		return (false);
	if (!(read_map(fil)))
		return (false);
	return (true);
}

void			print(t_filler *fil)
{
	ft_putnbr(fil->piece->win_x);
	print_in_file(0, "\0", fil->piece->win_x);
	ft_putchar(' ');
	ft_putnbr(fil->piece->win_y);
	print_in_file(0, "\0", fil->piece->win_y);
	ft_putchar('\n');
	fil->piece->win_x = 0;
	fil->piece->win_y = 0;
}

bool		parse_size_piece(t_filler *fil)
{
	char	*line;
	char	**split;

	if ((get_next_line(0, &line) != 1))
	{
		ft_strdel(&line);
		return (false);
	}
	print_in_file(0, line, -1);
	split = ft_strsplit(line, ' ');
	fil->piece->y = ft_atoi(split[1]);
	fil->piece->x = ft_atoi(split[2]);
	ft_strdel(&line);
	ft_free_arr(split);
	return (true);
}

bool		read_piece(t_filler *fil)
{
	char	*line;
	int		i;

	i = 0;
	while (i < fil->piece->y)
	{
		if ((get_next_line(0, &line) > 0))
		{
			print_in_file(0, line, -1);
			fil->piece->detal[i] = ft_strdup(line);
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

bool		parse_piece(t_filler *fil)
{
	if (!(parse_size_piece(fil)))
		return (false);
	if (!(fil->piece->detal = (char **)ft_memalloc(sizeof(char *)
									* fil->piece->y + 1)))
		return (false);
	if (!(read_piece(fil)))
		return (false);
	return (true);
}
