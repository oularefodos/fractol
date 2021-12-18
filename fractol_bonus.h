/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: foulare <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 20:57:43 by foulare           #+#    #+#             */
/*   Updated: 2021/12/18 01:15:24 by foulare          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_BONUS_H
# define FRACTOL_BONUS_H
# define WIDTH 1000
# define HEIGHT 1000
#include <stddef.h>
#include <stdio.h>

typedef struct s_complex{
	float	x;
	float	y;
}	t_complex;

typedef struct info
{
	int				pix;
	int				lin;
	int				d;
	int				n;
	void			*mlx;
	float			c[2];
	void			*win;
	unsigned int	*buffer;
	void			*image;
	int				status;
	float			x;
	float			y;
	int				posx;
	int				posy;
	int				max;
	t_complex		pmin;
	t_complex		pmax;
}	t_info;

typedef struct zinit
{
	int			x;
	int			y;
	float		xo;
	float		yo;
	long double	iter;
	int			coul;
}	t_init;
int		ft_strcmp(const char *s1, const char *s2);
int		ft_color(int i, t_info *info);
void	ft_error(void);
void	ft_zoom_mouse(t_info *e, int mouse_x, int mouse_y, int invert);
void	burning_ship(t_info *info);
int	key_hook(int keycode, t_info *info);
#endif
