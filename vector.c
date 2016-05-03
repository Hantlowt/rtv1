/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hantlowt <hantlowt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/20 15:49:23 by alhote            #+#    #+#             */
/*   Updated: 2016/05/03 22:50:46 by hantlowt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "maths.h"

t_vector		vect(double x, double y, double z)
{
	t_vector	value;

	value.x = x;
	value.y = y;
	value.z = z;
	return (value);
}

double			dist(t_vector a, t_vector b)
{
	return (sqrtf(powf(a.x - b.x, 2) + powf(a.y - b.y, 2) + powf(a.z - b.z, 2)));
}

double			get_cosangle(t_vector a, t_vector b, t_vector c)
{
	double	AB;
	double	BC;
	double	AC;

	AB = dist(a, b);
	BC = dist(b, c);
	AC = dist(a, c);
	return ((powf(BC, 2) + powf(AB, 2) - powf(AC, 2)) / (2 * BC * AB));
}

t_vector		transformation_vector(t_vector forward, t_vector ref)
{
	return (cross_product(cross_product(forward, ref), forward));
}
