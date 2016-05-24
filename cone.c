/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhote <alhote@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/19 16:05:52 by alhote            #+#    #+#             */
/*   Updated: 2016/05/24 16:25:39 by alhote           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cone.h"

int			cone_inter(t_ray r, t_object *s)
{
	t_cone	*co;
	double		a;
	double		b;
	double		c;
	t_vector	tmp;
	double		delta;
	double		t[3];

	r.pan = norm_vect(r.pan);
	co = s->data;
	tmp = sub_vect(r.pos, s->pos);
	a = dot_vect(r.pan, r.pan) - ((1 + co->r * co->r)
			* dot_vect(r.pan, co->dir) * dot_vect(r.pan, co->dir));
	b = 2 * (dot_vect(r.pan, tmp)
			- ((1 + co->r * co->r) * dot_vect(r.pan, co->dir)
				* dot_vect(tmp, co->dir)));
	c = dot_vect(tmp, tmp) - ((1 + co->r * co->r)
			* dot_vect(tmp, co->dir)
			* dot_vect(tmp, co->dir));
	delta = b * b - 4 * a * c;
	if (delta < 0)
		return (1);
	else if (delta == 0)
		t[2] = (-b + sqrtf(delta)) / (2 * a);
	else
	{
		t[0] = (-b + sqrtf(delta)) / (2 * a);
		t[1] = (-b - sqrtf(delta)) / (2 * a);
		t[2] = (t[0] < t[1] ? t[0] : t[1]);
		t[2] = (t[2] < 0.0001 ? t[1] : t[2]);
	}
	if (t[2] < 0)
		return (1);
	s->i = vect(r.pos.x + r.pan.x * t[2], r.pos.y + r.pan.y * t[2], 0);
	s->i.z = r.pos.z + r.pan.z * t[2];
	return (0);
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
	a = addition_vect(s->pos, a);
	return (norm_vect(sub_vect(s->i, a)));
}

t_object	*init_cone(t_vector pos, t_vector orientation, t_hsl color)
{
	t_cone	*or;
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
