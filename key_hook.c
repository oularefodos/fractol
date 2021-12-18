/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: foulare <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 21:49:03 by foulare           #+#    #+#             */
/*   Updated: 2021/12/18 01:49:24 by foulare          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fractol.h"
#include "mlx.h"
#include <stdlib.h>

void	ft_callfractol(t_info *info, int keycode)
{
	if (keycode == 53)
	{
		mlx_destroy_image(info->mlx, info->image);
		mlx_destroy_image(info->mlx, info->win);
		exit(0);
	}
	if (keycode == 32)
		info->n++;
	if (info->status == 1)
		mandelbrot(info);
	else
		julia(info);
}

int	key_hook(int keycode, t_info *info)
{
	if (keycode == 123)
	{
		info->pmin.x += 0.01;
		info->pmax.x += 0.01;
	}
	if (keycode == 124)
	{
		info->pmin.x -= 0.01;
		info->pmax.x -= 0.01;
	}
	if (keycode == 126)
	{
		info->pmin.y += 0.01;
		info->pmax.y += 0.01;
	}
	if (keycode == 125)
	{
		info->pmin.y -= 0.1;
		info->pmax.y -= 0.1;
	}
	ft_callfractol(info, keycode);
	return (0);
}
