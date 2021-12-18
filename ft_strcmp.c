/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: foulare <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 22:03:57 by foulare           #+#    #+#             */
/*   Updated: 2021/12/18 00:25:24 by foulare          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned int	i;
	int				p;

	i = 0;
	p = 0;
	while ((s1[i] || s2[i]) && p == 0)
	{
		if (s1[i] != s2[i])
			p = (unsigned char)s1[i] - (unsigned char)s2[i];
		i++;
	}
	return (p);
}
