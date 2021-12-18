/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: foulare <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 21:14:10 by foulare           #+#    #+#             */
/*   Updated: 2021/12/18 00:49:15 by foulare          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fractol.h"

double	interpolate(double start, double end, double interpolation)
{
	return (start + ((end - start) * interpolation));
}

void	applyzoom(t_info *e, float mouseRe, float mouseIm, float zoomFactor)
{
	t_complex	pmin;
	t_complex	pmax;
	float		interpolation;

	pmin = e->pmin;
	pmax = e->pmax;
	interpolation = 1.0 / zoomFactor;
	pmin.x = interpolate(mouseRe, pmin.x, interpolation);
	pmin.y = interpolate(mouseIm, pmin.y, interpolation);
	pmax.x = interpolate(mouseRe, pmax.x, interpolation);
	pmax.y = interpolate(mouseIm, pmax.y, interpolation);
	e->pmin = pmin;
	e->pmax = pmax;
}

void	ft_zoom_mouse(t_info *e, int mouse_x, int mouse_y, int invert)
{
	t_complex	pmin;
	t_complex	pmax;
	float		mousere;
	float		mouseim;

	pmin = e->pmin;
	pmax = e->pmax;
	mousere = (float)mouse_x / (WIDTH / (pmax.x - pmin.x)) + pmin.x;
	mouseim = (float)mouse_y / (HEIGHT / (pmax.y - pmin.y)) + pmin.y;
	if (invert)
		applyzoom(e, mousere, mouseim, 1 / 0.9);
	else
		applyzoom(e, mousere, mouseim, 0.9);
}
