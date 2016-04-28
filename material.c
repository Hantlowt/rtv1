/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   material.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhote <alhote@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/27 15:32:31 by alhote            #+#    #+#             */
/*   Updated: 2016/04/28 13:16:45 by alhote           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int				draw_sphere(t_vector i, t_sphere *s, t_world *w)
{
	if (!s->material)
		return (hsvtorgb(s->color));
	if (s->material == 1)
		return (simple_diffuse(i, s, w));
	return (0);
}

int				simple_diffuse(t_vector i, t_sphere *s, t_world *w)
{
	t_hsv		f;
	t_light		*l;
	t_vector	t;
	t_ray		r;
	double		li;

	f = s->color;
	l = w->lights;
	li = l->intensity;
	while (l)
	{
		r.pan = vect(l->pos.x - i.x, l->pos.y - i.y, l->pos.z - i.z);
		r.pan = norm_vect(r.pan);
		r.pos = i;
		if (!checsp(r, w, &t, s))
		{
			if (get_cosangle(w->cam->pos, i, l->pos) <= 0)
			{
				f.value += fabs(li * dist(i, w->cam->pos) * dist(i, l->pos) * get_cosangle(w->cam->pos, i, l->pos));
				//final.saturation -= (final.value > 100 ? final.value - 100 : 0);
				f.value = (f.value > 100 ? 100 : f.value);
			}
		}
		l = l->next;
	}
	return (hsvtorgb(f));
}
