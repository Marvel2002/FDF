/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   droite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 19:24:30 by mmatime           #+#    #+#             */
/*   Updated: 2017/06/07 15:58:01 by mmatime          ###   ########.fr       */
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
  printf("je trace de (%d, %d) a (%d, %d)\n", xi, yi, xf, yf);
  x = xi ;
  y = yi ;
  printf("x = %d, y = %d\n", x, y);
  dx = xf - xi ;
  dy = yf - yi ;
  printf("la distance entre les deux x = %d, la distance entre les deux y = %d\n", dx, dy);
  xinc = ( dx > 0 ) ? 1 : -1 ;
  yinc = ( dy > 0 ) ? 1 : -1 ;
  printf("xinc = %d, yinc = %d\n", xinc, yinc);
  dx = abs(dx) ;
  dy = abs(dy) ;
  printf("la distance entre les deux x (ABS)= %d, la distance entre les deux y (ABS) = %d\n", dx, dy);
  mlx_pixel_put(a->mlx, a->win, x, y, 0xFFFFFF);
  if ( dx > dy ) {
	printf("if\n");
    cumul = dx / 2 ;
	printf("cumul (dx/2 = %d\n", cumul);
    for ( i = 1 ; i <= dx ; i++ ) {
	printf("dx = %d\n", dx);
      x += xinc ;
	printf("x += xinc %d\n", x);
      cumul += dy ;
	printf("dy = %d, cumul += dy %d\n", dy, cumul);
      if ( cumul >= dx ) {
        printf("cumul (%d) >= dx (%d)\n", cumul, dx); 
		  cumul -= dx ;
		  printf("cumul -= dx (%d) = %d\n", dx, cumul); 
        y += yinc ; 
		  printf("y += yinc (%d) = %d\n", y, yinc); }
  mlx_pixel_put(a->mlx, a->win, x, y, 0xFFFFFF);
   printf("point tracee au coordonees %d %d\n", x, y);	} }
    else {
	printf("else\n");
    cumul = dy / 2 ;
    for ( i = 1 ; i <= dy ; i++ ) {
      y += yinc ;
      cumul += dx ;
      if ( cumul >= dy ) {
        cumul -= dy ;
        x += xinc ; }
  mlx_pixel_put(a->mlx, a->win, x, y, 0xFFFFFF); } }
}

int		printhook(int keycode)
{
	if (keycode == 53)
		exit(1);
	return (0);
}

int		main(void)
{
	t_env *a;

	a = malloc(sizeof(*a));
	a->mlx = mlx_init();
	a->win = mlx_new_window(a->mlx, 100, 100, "test");
	ligne(10, 10, 20, 11, a);
	mlx_key_hook(a->win, printhook, a);
	mlx_loop(a->mlx);
	return (0);
}
