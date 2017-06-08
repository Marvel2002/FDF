/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_to_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/05 05:17:56 by mmatime           #+#    #+#             */
/*   Updated: 2017/06/07 11:11:49 by mmatime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	init(t_env *e, t_data *d)
{
	d->full_count = e->nb * d->line_count;
	d->intbyline_count = e->nb;
	d->all = ft_bs_to_spaces(d->all);
	d->tab3 = ft_strsplit(d->all, ' ');
	d->tab = ft_tab_int(d);
	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, 2400, 1200, "fdf");
	hori(e, d);
	verti(e, d);
}

void	line_join(int fd, char *line, t_data *d, t_env *e)
{
	while (get_next_line(fd, &line))
	{
		line = ft_epurspace(line);
		if (input_count(line) < (e->nb - 1))
		{
			ft_putstr("Found wrong line length. Exiting\n");
			free(d);
			free(e);
			exit(1);
		}
		if (input_count(line) > (e->nb - 1))
			line = ft_strdup_mod(line, e->nb, ' ');
		d->all = ft_strjoin_n(d->all, line);
		d->line_count++;
	}
}

int		**ft_tab_int(t_data *a)
{
	int i;
	int j;
	int k;

	i = 0;
	k = 0;
	a->tab = (int**)malloc(sizeof(int**) * (a->line_count));
	if (!a->tab)
		return (NULL);
	while (i < a->line_count)
	{
		j = 0;
		a->tab[i] = (int*)malloc(sizeof(int*) * (a->intbyline_count));
		if (!a->tab[i])
			return (NULL);
		while (j < a->intbyline_count)
		{
			a->tab[i][j] = ft_atoi(a->tab3[k]);
			j++;
			k++;
		}
		i++;
	}
	return (a->tab);
}

char	*ft_bs_to_spaces(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			str[i] = ' ';
		i++;
	}
	return (str);
}
