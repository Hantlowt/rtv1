/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhote <alhote@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/20 15:30:28 by alhote            #+#    #+#             */
/*   Updated: 2016/04/20 18:44:09 by alhote           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sphere.h"

t_sphere			*init_sphere(t_vector pos, double rayon, int color)
{
	t_sphere	*new;

	new = (t_sphere*)malloc(sizeof(t_sphere));
	new->pos = pos;
	new->rayon = rayon;
	new->color = color;
	new->next = 0;
	return (new);
}

void				add_sphere(t_sphere *begin, t_sphere *new)
{
	while (begin->next)
		begin = begin->next;
	begin->next = new;
}

t_vector			sphere_equation(t_vector d, t_vector p, t_sphere *s)
{
	double	a;
	double	b;
	double	c;
	double	delta;
	double	t;

	a = (d.x * d.x) + (d.y * d.y) + (d.z * d.z);
	b = 2 * (d.x * (p.x - s->pos.x) + d.y * (p.y - s->pos.y)
	+ d.z * (p.z - s->pos.z));
	c = (((p.x - s->pos.x) * (p.x - s->pos.x)) + ((p.y - s->pos.y)
	* (p.y - s->pos.y)) + ((p.z - s->pos.z) * (p.z - s->pos.z))) -
	s->rayon * s->rayon;
	delta = b * b - 4 * a * c;
	if (delta < 0)
		return (0);
	else if (delta == 0)
		t = (-b + sqrt(delta)) / (2 * a);
	else
		t = ((-b + sqrt(delta)) / (2 * a) < (-b - sqrt(delta)) / (2 * a) ?
		(-b + sqrt(delta)) / (2 * a) : (-b - sqrt(delta)) / (2 * a));
	return (vect(p.x + d.x * t, p.y + d.y * t, p.z + d.z * t));
}
