/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhote <alhote@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/20 15:30:28 by alhote            #+#    #+#             */
/*   Updated: 2016/04/28 11:28:14 by alhote           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sphere.h"

t_sphere	*init_sphere(t_vector pos, double rayon, t_hsv color)
{
	t_sphere	*new;

	if (!(new = (t_sphere*)malloc(sizeof(t_sphere))))
		return (0);
	new->pos = pos;
	new->rayon = rayon;
	new->color = color;
	new->material = 1;
	new->next = 0;
	return (new);
}

void		add_sphere(t_sphere *begin, t_sphere *new)
{
	while (begin->next)
		begin = begin->next;
	begin->next = new;
}

int			s_equa(t_ray r, t_sphere *s, t_vector *i)
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
	s->rayon * s->rayon;
	delta = b * b - 4 * a * c;
	if (delta < 0)
		return (1);
	else if (delta == 0)
		t = (-b + sqrtf(delta)) / (2 * a);
	else
		t = ((-b + sqrtf(delta)) / (2 * a) < (-b - sqrtf(delta)) / (2 * a) ?
		(-b + sqrtf(delta)) / (2 * a) : (-b - sqrtf(delta)) / (2 * a));
	*i = vect(r.pos.x + r.pan.x * t, r.pos.y + r.pan.y * t, r.pos.z + r.pan.z * t);
	return (0);
}
