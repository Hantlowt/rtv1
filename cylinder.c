/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhote <alhote@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/12 15:36:59 by alhote            #+#    #+#             */
/*   Updated: 2016/05/26 14:30:44 by alhote           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cylinder.h"

int			cylinder_inter(t_ray r, t_object *s)
{
	t_cylinder	*cy;
	double		l[3];
	double		t[3];

	cy = s->data;
	l[0] = dot_vect(r.pan, r.pan)
	- (dot_vect(r.pan, cy->dir) * dot_vect(r.pan, cy->dir));
	l[1] = 2 * (dot_vect(r.pan, sub_vect(r.pos, s->pos))
	- (dot_vect(r.pan, cy->dir) * dot_vect(sub_vect(r.pos, s->pos), cy->dir)));
	l[2] = dot_vect(sub_vect(r.pos, s->pos), sub_vect(r.pos, s->pos))
	- (dot_vect(sub_vect(r.pos, s->pos), cy->dir) *
	dot_vect(sub_vect(r.pos, s->pos), cy->dir)) - powf(cy->r, 2);
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

t_vector	cylinder_normal(t_object *s)
{
	double		t;
	double		r[3];
	int			i;
	t_vector	n;
	t_cylinder	*cy;

	cy = s->data;
	i = 0;
	t = (-cy->dir.x * s->pos.x - cy->dir.y * s->pos.y - cy->dir.z * s->pos.z +
		s->i.x * cy->dir.x + s->i.y * cy->dir.y + s->i.z * cy->dir.z) /
		(powf(cy->dir.x, 2) + powf(cy->dir.y, 2) + powf(cy->dir.z, 2));
	r[0] = (s->i.x - (s->pos.x + cy->dir.x * t));
	r[1] = (s->i.y - (s->pos.y + cy->dir.y * t));
	r[2] = (s->i.z - (s->pos.z + cy->dir.z * t));
	n = vect(r[0], r[1], r[2]);
	return (norm_vect(n));
}

t_object	*init_cylinder(t_vector pos, t_vector orientation, t_hsl color)
{
	t_cylinder	*or;
	t_object	*p;

	or = (t_cylinder*)malloc(sizeof(t_cylinder));
	or->dir = norm_vect(orientation);
	or->r = 1.0;
	p = init_obj(pos, color);
	p->inter = &cylinder_inter;
	p->normal = &cylinder_normal;
	p->data = or;
	return (p);
}
