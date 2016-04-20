/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhote <alhote@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/20 15:49:23 by alhote            #+#    #+#             */
/*   Updated: 2016/04/20 18:29:55 by alhote           ###   ########.fr       */
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

t_vector		rotate(t_vector v, char a)
{
	t_vector	n;

	if (a == 'x')
	{
		n.x = 5.0;
		n.y = 5.0;
		n.z = 5.0;
	}
	return (n);
}
