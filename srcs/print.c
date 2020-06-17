/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phuntik <phuntik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/18 18:45:19 by anastasiase       #+#    #+#             */
/*   Updated: 2020/06/14 17:17:31 by phuntik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int fd;

void		open_file()
{
	remove("debug.txt");
	fd = open("debug.txt", O_CREAT);
	system("chmod 777 debug.txt");
	fd = open("debug.txt", O_WRONLY);
}

void		print_in_file(char c, char *str, int value)
{
	if (c)
	{
		ft_putchar_fd(c, fd);
		// ft_putchar_fd('\n', fd);
	}
	if (str)
	{
		ft_putstr_fd(str, fd);
		// ft_putchar_fd('\n', fd);
	}
	if (value != -1)
	{
		ft_putnbr_fd(value, fd);
		// ft_putchar_fd('\n', fd);
	}
}