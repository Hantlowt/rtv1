/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhote <alhote@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/12 15:36:59 by alhote            #+#    #+#             */
/*   Updated: 2016/05/18 15:45:28 by alhote           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cylinder.h"

int			cylinder_inter(t_ray r, t_object *s)
{
	t_cylinder	*cy;
	double		a;
	double		b;
	double		c;
	double		delta;
	double		t[3];

	r.pan = norm_vect(r.pan);
	cy = s->data;
	a = dot_vect(r.pan, r.pan)
		- (dot_vect(r.pan, cy->dir) * dot_vect(r.pan, cy->dir));
	b = 2 * (dot_vect(r.pan, sub_vect(r.pos, s->pos))
			- (dot_vect(r.pan, cy->dir)
				* dot_vect(sub_vect(r.pos, s->pos), cy->dir)));
	c = dot_vect(sub_vect(r.pos, s->pos), sub_vect(r.pos, s->pos))
		- (dot_vect(sub_vect(r.pos, s->pos), cy->dir)
		* dot_vect(sub_vect(r.pos, s->pos), cy->dir)) - cy->r * cy->r;
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
		t[2] = (t[2] < 0 ? t[1] : t[2]);
	}
	if (t[2] < 0)
		return (1);
	s->i = vect(r.pos.x + r.pan.x * t[2], r.pos.y + r.pan.y * t[2], 0);
	s->i.z = r.pos.z + r.pan.z * t[2];
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
