/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/05 05:17:27 by mmatime           #+#    #+#             */
/*   Updated: 2017/06/05 08:06:51 by mmatime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	line_a(t_env *a)
{
	a->cumul = a->dx / 2;
	while (a->i++ <= a->dx)
	{
		a->x += a->xinc;
		a->cumul += a->dy;
		if (a->cumul >= a->dx)
		{
			a->cumul -= a->dx;
			a->y += a->yinc;
		}
		fill_pixel(a->x, a->y, a);
	}
}

void	line_b(t_env *a)
{
	a->cumul = a->dy / 2;
	a->i = 1;
	while (a->i++ <= a->dy)
	{
		a->y += a->yinc;
		a->cumul += a->dx;
		if (a->cumul >= a->dy)
		{
			a->cumul -= a->dy;
			a->x += a->xinc;
		}
		fill_pixel(a->x, a->y, a);
	}
}

void	line(t_env *a)
{
	a->x = a->xi;
	a->y = a->yi;
	a->dx = a->xf - a->xi;
	a->dy = a->yf - a->yi;
	a->xinc = (a->dx > 0) ? 1 : -1;
	a->yinc = (a->dy > 0) ? 1 : -1;
	a->dx = abs(a->dx);
	a->dy = abs(a->dy);
	a->i = 1;
	if (a->dx > a->dy)
		line_a(a);
	else
		line_b(a);
}

void	hori(t_env *e, t_data *d)
{
	e->f = 0;
	while (e->f < d->line_count)
	{
		e->j = 0;
		while (e->j < d->intbyline_count)
		{
			e->xi = e->j * TILE_SIZE;
			e->yi = e->f * TILE_SIZE;
			e->xi -= 20 * d->tab[e->f][e->j];
			e->yi -= 20 * d->tab[e->f][e->j];
			if (e->j)
				line(e);
			e->xf = e->xi;
			e->yf = e->yi;
			e->j++;
		}
		e->f++;
	}
}

void	verti(t_env *e, t_data *d)
{
	e->j = 0;
	while (e->j < d->intbyline_count)
	{
		e->f = 0;
		while (e->f < d->line_count)
		{
			e->xi = e->j * TILE_SIZE;
			e->yi = e->f * TILE_SIZE;
			e->xi -= 20 * d->tab[e->f][e->j];
			e->yi -= 20 * d->tab[e->f][e->j];
			if (e->f)
				line(e);
			e->xf = e->xi;
			e->yf = e->yi;
			e->f++;
		}
		e->j++;
	}
}
