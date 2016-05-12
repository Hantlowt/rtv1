/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhote <alhote@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/12 15:36:59 by alhote            #+#    #+#             */
/*   Updated: 2016/05/12 15:48:35 by alhote           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cylinder.h"

int			cylinder_inter(t_ray r, t_object *s)
{
	double		a;
	double		b;
	double		c;
	double		t[3];
	t_vector	*d;

	d = (t_cylinder*)s->data;
	t = dot_vect(norminv, sub_vect(r.pos, s->pos)) / dot_vect(*or, r.pan);
	if (t < 0)
		return (1);
	s->i = vect(r.pos.x + r.pan.x * t, r.pos.y + r.pan.y * t, 0);
	s->i.z = r.pos.z + r.pan.z * t;
	return (0);
}

t_vector	cylinder_normal(t_object *s)
{
	t_vector	*n;

	n = s->data;
	return (norm_vect(*n));
}

t_object	*init_cylinder(t_vector pos, t_vector orientation, t_hsl color)
{
	t_vector	*or;
	t_object	*p;

	or = (t_vector*)malloc(sizeof(t_vector));
	*or = orientation;
	p = init_obj(pos, color);
	p->inter = &cylinder_inter;
	p->normal = &cylinder_normal;
	p->data = or;
	return (p);
}
