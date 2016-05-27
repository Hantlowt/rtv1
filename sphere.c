/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhote <alhote@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/20 15:30:28 by alhote            #+#    #+#             */
/*   Updated: 2016/05/27 18:59:44 by alhote           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sphere.h"

int			sphere_inter(t_ray r, t_object *s)
{
	double	l[3];
	double	delta;
	double	t[3];

	l[0] = (r.pan.x * r.pan.x) + (r.pan.y * r.pan.y) + (r.pan.z * r.pan.z);
	l[1] = 2 * (r.pan.x * (r.pos.x - s->pos.x) + r.pan.y * (r.pos.y - s->pos.y)
	+ r.pan.z * (r.pos.z - s->pos.z));
	l[2] = (((r.pos.x - s->pos.x) * (r.pos.x - s->pos.x)) +
	((r.pos.y - s->pos.y) * (r.pos.y - s->pos.y)) + ((r.pos.z - s->pos.z) *
	(r.pos.z - s->pos.z))) - *(double*)(s->data) * *(double*)(s->data);
	if ((delta = l[1] * l[1] - 4 * l[0] * l[2]) < 0)
		return (1);
	else if (delta == 0)
		t[2] = (-l[1] + sqrtf(delta)) / (2 * l[0]);
	else
	{
		t[0] = (-l[1] + sqrtf(delta)) / (2 * l[0]);
		t[1] = (-l[1] - sqrtf(delta)) / (2 * l[0]);
		t[2] = (t[0] < t[1] ? t[0] : t[1]);
		t[2] = (t[2] < 0 ? t[1] : t[2]);
	}
	s->i = vect(r.pos.x + r.pan.x * t[2], r.pos.y + r.pan.y * t[2], 0);
	s->i.z = r.pos.z + r.pan.z * t[2];
	return ((t[2] < 0));
}

t_vector	sphere_normal(t_object *s)
{
	t_vector	n;

	n = vect(s->i.x - s->pos.x, s->i.y - s->pos.y, s->i.z - s->pos.z);
	return (norm_vect(n));
}

t_object	*init_sphere(t_vector pos, double rayon, t_hsl color)
{
	double		*r;
	t_object	*p;

	r = (double*)malloc(sizeof(double));
	*r = rayon;
	p = init_obj(pos, color);
	p->inter = &sphere_inter;
	p->normal = &sphere_normal;
	p->data = r;
	return (p);
}
