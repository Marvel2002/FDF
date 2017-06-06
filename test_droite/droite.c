/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   droite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 19:24:30 by mmatime           #+#    #+#             */
/*   Updated: 2017/06/06 19:49:18 by mmatime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx/mlx.h"

typedef struct t_struct
{
	void *mlx;
	void *win;
}		t_env;
	
void ligne(int xi,int yi,int xf,int yf, t_env *a) {
  int dx,dy,i,xinc,yinc,cumul,x,y ;
  x = xi ;
  y = yi ;
  dx = xf - xi ;
  dy = yf - yi ;
  xinc = ( dx > 0 ) ? 1 : -1 ;
  yinc = ( dy > 0 ) ? 1 : -1 ;
  dx = abs(dx) ;
  dy = abs(dy) ;
  mlx_pixel_put(a->mlx, a->win, x, y, 0xFFFFFF);
  if ( dx > dy ) {
    cumul = dx / 2 ;
    for ( i = 1 ; i <= dx ; i++ ) {
      x += xinc ;
      cumul += dy ;
      if ( cumul >= dx ) {
        cumul -= dx ;
        y += yinc ; }
  mlx_pixel_put(a->mlx, a->win, x, y, 0xFFFFFF); } }
    else {
    cumul = dy / 2 ;
    for ( i = 1 ; i <= dy ; i++ ) {
      y += yinc ;
      cumul += dx ;
      if ( cumul >= dy ) {
        cumul -= dy ;
        x += xinc ; }
  mlx_pixel_put(a->mlx, a->win, x, y, 0xFFFFFF); } }
}

int		main(void)
{
	t_env *a;

	a = malloc(sizeof(*a));
	a->mlx = mlx_init();
	a->win = mlx_new_window(a->mlx, 1000, 1200, "test");
	ligne(0, 0, 1000, 1000, a);
	mlx_loop(a->mlx);
	return (0);
}
