/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 09:22:09 by mmatime           #+#    #+#             */
/*   Updated: 2017/06/07 11:16:08 by mmatime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	fill_pixel(int x, int y, t_env *b)
{
	int iso_x;
	int iso_y;

	iso_x = x - y;
	iso_y = (x + y) / 2;
	mlx_pixel_put(b->mlx, b->win, iso_x + 1000, iso_y + 500, 0xFFFFFF);
}

int		printhook(int keycode)
{
	if (keycode == 53)
		exit(1);
	return (0);
}

int		main(int argc, char **argv)
{
	int		fd;
	char	*line;
	t_env	*e;
	t_data	*d;

	fd = open(argv[1], O_RDONLY);
	get_next_line(fd, &line);
	if (!file_error(argc, argv, fd, line))
		return (0);
	if (!(d = (t_data*)malloc(sizeof(t_data))))
		return (ft_putstr_error("Could not alloc\n"));
	if (!(e = (t_env*)malloc(sizeof(t_env))))
		return (ft_putstr_error("Could not alloc\n"));
	d->line_count = 1;
	line = ft_epurspace(line);
	d->all = ft_strdup_n(line);
	e->nb = input_count(d->all);
	line_join(fd, line, d, e);
	init(e, d);
	free(d);
	free(e);
	close(fd);
	mlx_key_hook(e->win, printhook, e);
	mlx_loop(e->mlx);
	return (0);
}
