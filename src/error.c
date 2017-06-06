/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/05 08:06:05 by mmatime           #+#    #+#             */
/*   Updated: 2017/06/05 08:06:07 by mmatime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		file_error(int argc, char **argv, int fd, char *line)
{
	if (argc != 2)
	{
		ft_putstr("Usage : ./fdf <filename> [ case_size z_size ]\n");
		return (0);
	}
	else if (fd < 0)
	{
		ft_putstr("No file ");
		ft_putstr(argv[1]);
		ft_putchar('\n');
		return (0);
	}
	else if (!line)
	{
		ft_putstr("No data found.\n");
		return (0);
	}
	else
		return (1);
}
