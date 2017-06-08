/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/05 05:19:22 by mmatime           #+#    #+#             */
/*   Updated: 2017/06/07 11:22:58 by mmatime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../minilibx/mlx.h"
# include "../libft/libft.h"
# include <unistd.h>
# include <fcntl.h>
# include <math.h>

# define TILE_SIZE 8

typedef struct	s_env
{
	void		*mlx;
	void		*win;
	void		*img;
	int			dx;
	int			dy;
	int			i;
	int			xinc;
	int			yinc;
	int			cumul;
	int			x;
	int			xi;
	int			yi;
	int			xf;
	int			yf;
	int			y;
	int			a;
	int			b;
	int			f;
	int			j;
	int			nb;
}				t_env;

typedef struct	s_data
{
	int			**tab;
	char		**tab3;
	char		*all;
	int			line_count;
	int			intbyline_count;
	int			full_count;
}				t_data;

int				printhook(int keycode);
int				count_inputs(char *str);
int				input_count(char *str);
int				**ft_tab_int(t_data *a);
char			*ft_bs_to_spaces(char *str);
void			fill_pixel(int x, int y, t_env *b);
void			line(t_env *a);
void			line_a(t_env *a);
void			line_b(t_env *a);
void			hori(t_env *e, t_data *d);
void			verti(t_env *e, t_data *d);
void			line_join(int fd, char *line, t_data *d, t_env *e);
int				file_error(int argc, char **argv, int fd, char *line);
void			init(t_env *e, t_data *d);
void			line_join(int fd, char *line, t_data *d, t_env *e);
int				ft_putstr_error(char *str);
void			ft_putchar_error(char c);

#endif
