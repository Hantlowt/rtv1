/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_operation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hantlowt <hantlowt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/26 10:11:13 by alhote            #+#    #+#             */
/*   Updated: 2016/04/26 23:04:42 by hantlowt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "maths.h"

t_vector		cross_product(t_vector a, t_vector b)
{
	double	x;
	double	y;
	double	z;

	x = a.y * b.z - a.z * b.y;
	y = a.z * b.x - a.x * b.z;
	z = a.x * b.y - a.y * b.x;
	return (vect(x, y, z));
}

t_vector		norm_vect(t_vector v)
{
	double	size;

	size = sqrtf(powf(v.x, 2) + powf(v.y, 2) + powf(v.z, 2));
	v.x /= size;
	v.y /= size;
	v.z /= size;
	return (v);
}

t_vector		transformation_vector(t_vector forward, t_vector ref)
{
	return (cross_product(cross_product(forward, ref), forward));
}

t_vector		rotate(t_vector v, t_vector a, double r)
{
	t_vector	n;
	double		c;
	double		s;
	double		t;

	c = cosd(r);
	s = sind(r);
	t = 1.0 - cosd(r);
	v = norm_vect(v);
	a = norm_vect(a);
	n.x = v.x * (t * a.x * a.x + c) + v.y * (t * a.x * a.y - s * a.z)
	+ v.z * (t * a.x * a.z + s * a.y);
	n.y = v.x * (t * a.x * a.y + s * a.z) + v.y * (t * a.y * a.y + c)
	+ v.z * (t * a.y * a.z - s * a.x);
	n.z = v.x * (t * a.x * a.z - s * a.y) + v.y * (t * a.y * a.z + s * a.x)
	+ v.z * (t * a.z * a.z + c);
	return (n);
}
