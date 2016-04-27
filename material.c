/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   material.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhote <alhote@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/27 15:32:31 by alhote            #+#    #+#             */
/*   Updated: 2016/04/27 19:32:39 by alhote           ###   ########.fr       */
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
	t_hsv		final;
	t_light		*light;
	t_vector	t;
	t_vector	r;
	double		li;

	final = s->color;
	light = w->lights;
	li = light->intensity;
	while (light)
	{
		r = vect(light->pos.x - i.x, light->pos.y - i.y, light->pos.z - i.z);
		if (!checsp(r, w, &t, s))
		{
			if (get_cosangle(w->cam->pos, i, light->pos) <= 0)
			{
				final.value += fabs(li * get_cosangle(w->cam->pos, i, light->pos));
				//final.saturation -= (final.value > 100 ? 100 - final.value : 0);
				final.value = (final.value > 100 ? 100 : final.value);
			}
		}
		light = light->next;
	}
	return (hsvtorgb(final));
}
