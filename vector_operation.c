/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_operation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhote <alhote@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/26 10:11:13 by alhote            #+#    #+#             */
/*   Updated: 2016/05/26 14:51:37 by alhote           ###   ########.fr       */
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

t_vector		add_vect(t_vector a, t_vector b)
{
	double	x;
	double	y;
	double	z;

	x = a.x + b.x;
	y = a.y + b.y;
	z = a.z + b.z;
	return (vect(x, y, z));
}

t_vector		sub_vect(t_vector a, t_vector b)
{
	double	x;
	double	y;
	double	z;

	x = a.x - b.x;
	y = a.y - b.y;
	z = a.z - b.z;
	return (vect(x, y, z));
}

t_vector		norm_vect(t_vector v)
{
	double	size;

	size = sqrtf(powf(v.x, 2.0) + powf(v.y, 2.0) + powf(v.z, 2.0));
	v.x /= size;
	v.y /= size;
	v.z /= size;
	return (v);
}

double			dot_vect(t_vector a, t_vector b)
{
	return (a.x * b.x + a.y * b.y + a.z * b.z);
}
