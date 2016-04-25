/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hantlowt <hantlowt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/20 15:49:23 by alhote            #+#    #+#             */
/*   Updated: 2016/04/25 19:58:03 by hantlowt         ###   ########.fr       */
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

t_vector		rotate(t_vector v, double o, char a)
{
	t_vector	n;

	if (a == 'x')
	{
		n.x = v.x;
		n.y = cosd(o) * v.y + (-sind(o)) * v.z;
		n.z = sind(o) * v.y + cosd(o) * v.z;
	}
	else if (a == 'y')
	{
		n.x = cosd(o) * v.x + sind(o) * v.z;
		n.y = v.y;
		n.z = -sind(o) * v.x + cosd(o) * v.z;
	}
	else if (a == 'z')
	{
		n.x = cosd(o) * v.x + (-sind(o)) * v.y;
		n.y = sind(o) * v.x + cosd(o) * v.y;
		n.z = v.z;
	}
	else
		return (v);
	return (n);
}

double			dist(t_vector A, t_vector B)
{
	return (sqrt(pow(A.x - B.x, 2) + pow(A.y - B.y, 2) + pow(A.z - B.z, 2)));
}

t_vector		cross_product(t_vector A, t_vector B)
{
	double	x;
	double	y;
	double	z;

	x = A.y * B.z - A.z * B.y;
	y = A.z * B.x - A.x * B.z;
	z = A.x * B.y - A.y * B.x;
	return (vect(x, y, z));
}

t_vector		transformation_vector(t_vector forward, t_vector B)
{
	return (cross_product(cross_product(forward, B), forward));
}
