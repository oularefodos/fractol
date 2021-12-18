/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: foulare <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 19:00:54 by foulare           #+#    #+#             */
/*   Updated: 2021/12/17 19:08:49 by foulare          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>
#include <stdlib.h>

void	ft_error(void)
{
	printf("passez en parametre mandelbrot ou julia\n");
	exit(1);
}
