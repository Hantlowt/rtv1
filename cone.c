/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhote <alhote@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/19 16:05:52 by alhote            #+#    #+#             */
/*   Updated: 2016/05/26 14:50:47 by alhote           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cone.h"

int			cone_inter(t_ray r, t_object *s)
{
	t_cone		*co;
	double		l[3];
	t_vector	tmp;
	double		t[3];

	co = s->data;
	tmp = sub_vect(r.pos, s->pos);
	l[0] = dot_vect(r.pan, r.pan) - ((1 + powf(co->r, 2)) *
	dot_vect(r.pan, co->dir) * dot_vect(r.pan, co->dir));
	l[1] = 2 * (dot_vect(r.pan, tmp) - ((1 + powf(co->r, 2)) *
	dot_vect(r.pan, co->dir) * dot_vect(tmp, co->dir)));
	l[2] = dot_vect(tmp, tmp) - ((1 + powf(co->r, 2)) * dot_vect(tmp, co->dir) *
	dot_vect(tmp, co->dir));
	if (l[1] * l[1] - 4 * l[0] * l[2] == 0)
		t[2] = (-l[1] + sqrtf(l[1] * l[1] - 4 * l[0] * l[2])) / (2 * l[0]);
	else
	{
		t[0] = (-l[1] + sqrtf(l[1] * l[1] - 4 * l[0] * l[2])) / (2 * l[0]);
		t[1] = (-l[1] - sqrtf(l[1] * l[1] - 4 * l[0] * l[2])) / (2 * l[0]);
		t[2] = (t[0] < t[1] ? t[0] : t[1]);
		t[2] = (t[2] < 0 ? t[1] : t[2]);
	}
	s->i = vect(r.pos.x + r.pan.x * t[2], r.pos.y + r.pan.y * t[2], 0);
	s->i.z = r.pos.z + r.pan.z * t[2];
	return ((l[1] * l[1] - 4 * l[0] * l[2] < 0) || (t[2] < 0));
}

t_vector	cone_normal(t_object *s)
{
	t_vector	a;
	double		t;
	t_cone		*co;
	double		beta;

	co = s->data;
	a = co->dir;
	beta = dot_vect(norm_vect(sub_vect(s->i, s->pos)), a);
	if (acos(beta) * 180.0 / PI > 90.0)
	{
		a.x *= -1;
		a.y *= -1;
		a.z *= -1;
		beta = dot_vect(norm_vect(sub_vect(s->i, s->pos)), a);
	}
	t = (dist(s->pos, s->i) * sin(beta)) / sin(1.5708 + beta);
	a.x *= t;
	a.y *= t;
	a.z *= t;
	a = add_vect(s->pos, a);
	return (norm_vect(sub_vect(s->i, a)));
}

t_object	*init_cone(t_vector pos, t_vector orientation, t_hsl color)
{
	t_cone		*or;
	t_object	*p;

	or = (t_cone*)malloc(sizeof(t_cone));
	or->dir = norm_vect(orientation);
	or->r = 0.5;
	p = init_obj(pos, color);
	p->inter = &cone_inter;
	p->normal = &cone_normal;
	p->data = or;
	return (p);
}
