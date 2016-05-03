/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhote <alhote@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/02 18:44:29 by alhote            #+#    #+#             */
/*   Updated: 2016/05/03 18:38:18 by alhote           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "plane.h"

int			plane_inter(t_ray r, t_object *s)
{
	double		t;
	//t_vector	d;
	t_vector	*or;

	or = (t_vector*)s->data;
	t = -((or->x * r.pos.x + or->y * r.pos.y + or->z * r.pos.y + dist(*or, s->pos)) / (or->x * r.pan.x + or->y * r.pan.y + or->z * r.pan.z));
	//t = -r.pos.y / r.pan.y;
	if (t < 0)
		return (1);
	s->i = vect(r.pos.x + r.pan.x * t, r.pos.y + r.pan.y * t, 0);
	s->i.z = r.pos.z + r.pan.z * t;
	return (0);
}

t_vector	plane_normal(t_object *s)
{
	t_vector	*n;

	n = s->data;
	return (*n);
}

t_object	*init_plane(t_vector pos, t_vector orientation, t_hsl color)
{
	t_vector	*or;
	t_object	*p;

	or = (t_vector*)malloc(sizeof(t_vector));
	*or = orientation;
	p = init_obj(pos, color);
	p->inter = &plane_inter;
	p->normal = &plane_normal;
	p->data = or;
	return (p);
}
