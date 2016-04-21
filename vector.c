/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhote <alhote@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/20 15:49:23 by alhote            #+#    #+#             */
/*   Updated: 2016/04/21 15:34:12 by alhote           ###   ########.fr       */
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
