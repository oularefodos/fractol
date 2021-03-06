/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: foulare <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 14:22:05 by foulare           #+#    #+#             */
/*   Updated: 2021/12/18 00:31:28 by foulare          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fractol.h"

void	julia_info(float *c)
{
	float	n[2];

	n[0] = c[0];
	n[1] = n[1];
	if (!c[0] || !c[1])
	{
		c[0] = n[0] + 0.8;
		c[1] = n[1] + 0.8;
	}	
	c[0] *= 0.2;
	c[1] *= 0.7885;
	c[0] += 0.1;
	c[1] += -0.1;
}
