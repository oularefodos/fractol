/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: foulare <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 21:25:19 by foulare           #+#    #+#             */
/*   Updated: 2021/12/18 00:55:07 by foulare          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <math.h>
#include "fractol_bonus.h"

int	ft_get_color(int red, int green, int blue)
{
	int	rgb;

	rgb = red;
	rgb = (rgb << 8) + green;
	rgb = (rgb << 8) + blue;
	return (rgb);
}

void	ft_cal_color(int *red, int *blue, int *green, float *c)
{
	if (*c < 1)
	{
		*red = (int)255.0 * *c;
		*green = 0;
		*blue = 0;
	}
	else if (*c < 2)
	{
		*red = 255;
		*green = (int)255.0 * (*c - 1);
		*blue = 0;
	}
	else
	{
		*red = 255;
		*green = 255;
		*blue = (int)255.0 * (*c - 2.0);
	}
}

int	ft_color(int i, t_info *info)
{
	int		red;
	int		green;
	int		blue;
	float	c;
	int		n;

	if ((info->n % 2) == 0)
		n = 0;
	else
		n = 100;
	if (i == info->max)
	{
		red = 0;
		green = 0;
		blue = 0;
	}
	else
		c = 3.0 * log(i) / log(info->max);
	ft_cal_color(&red, &blue, &green, &c);
	return (ft_get_color(red, green, blue) + n);
}
