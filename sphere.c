/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhote <alhote@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/20 15:30:28 by alhote            #+#    #+#             */
/*   Updated: 2016/04/29 18:32:42 by alhote           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sphere.h"

int			sphere_inter(t_ray r, t_object *s)
{
	double	a;
	double	b;
	double	c;
	double	delta;
	double	t;

	a = (r.pan.x * r.pan.x) + (r.pan.y * r.pan.y) + (r.pan.z * r.pan.z);
	b = 2 * (r.pan.x * (r.pos.x - s->pos.x) + r.pan.y * (r.pos.y - s->pos.y)
	+ r.pan.z * (r.pos.z - s->pos.z));
	c = (((r.pos.x - s->pos.x) * (r.pos.x - s->pos.x)) + ((r.pos.y - s->pos.y)
	* (r.pos.y - s->pos.y)) + ((r.pos.z - s->pos.z) * (r.pos.z - s->pos.z))) -
	*(double*)(s->data) * *(double*)(s->data);
	delta = b * b - 4 * a * c;
	if (delta < 0)
		return (1);
	else if (delta == 0)
		t = (-b + sqrtf(delta)) / (2 * a);
	else
		t = ((-b + sqrtf(delta)) / (2 * a) < (-b - sqrtf(delta)) / (2 * a) ?
		(-b + sqrtf(delta)) / (2 * a) : (-b - sqrtf(delta)) / (2 * a));
	s->i = vect(r.pos.x + r.pan.x * t, r.pos.y + r.pan.y * t, 0);
	s->i.z = r.pos.z + r.pan.z * t;
	return (0);
}
