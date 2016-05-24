/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhote <alhote@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/19 16:01:15 by alhote            #+#    #+#             */
/*   Updated: 2016/05/24 15:16:42 by alhote           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_world			*init_world(void)
{
	t_world	*new;

	if (!(new = (t_world*)malloc(sizeof(t_world))))
		return (0);
	new->mlx = mlx_init();
	new->win = mlx_new_window(new->mlx, SCREEN_X, SCREEN_Y, "RTv1");
	new->img = mlx_new_image(new->mlx, SCREEN_X, SCREEN_Y);
	new->objects = 0;
	new->cam = 0;
	return (new);
}

t_object		*check_objects(t_ray r, t_world *w, t_object *ignore)
{
	t_object	*s;
	t_object	*out;
	double		distance;
	int			touched;

	touched = 0;
	s = w->objects;
	out = 0;
	while (s)
	{
		if (!s->inter(r, s) && s != ignore)
		{
			if (!touched || distance > dist(r.pos, s->i))
			{
				distance = dist(r.pos, s->i);
				out = s;
				touched = 1;
			}
			//touched = 1;
		}
		s = s->next;
	}
	return (out);
}

void			render(t_world *w)
{
	int			xy[2];
	double		p[2];
	t_ray		r;
	t_object	*s;

	xy[0] = 0;
	xy[1] = 0;
	p[1] = w->cam->pany + (45.0) / 2;
	p[0] = w->cam->panx + (SCREEN_Y * 45.0 / SCREEN_X) / 2;
	r.pan = pan_to_vect(p[0], p[1]);
	r.pos = w->cam->pos;
	while (xy[1] < SCREEN_Y)
	{
		while (xy[0] < SCREEN_X)
		{
			r.pan = pan_to_vect(p[0], p[1]);
			if ((s = check_objects(r, w, 0)) && !coloring(s, w))
				img_pxl(w->img, xy[0], xy[1], hsltorgb(s->color));
			else
				img_pxl(w->img, xy[0], xy[1], 0);
			xy[0]++;
			p[1] -= (45.0 / SCREEN_X);
		}
		xy[0] = 0;
		xy[1]++;
		p[1] += 45.0;
		p[0] -= ((SCREEN_Y * 45.0 / SCREEN_X) / SCREEN_Y);
	}
	mlx_put_image_to_window(w->mlx, w->win, w->img, 0, 0);
}

int				coloring(t_object *s, t_world *w)
{
	t_vector	normal;
	t_vector	reflec;
	t_vector	light;
	t_ray		r;
	t_vector	viewer;
	t_light		*l;
	t_object	*o;

	normal = s->normal(s);
	r.pos = s->i;
	l = w->lights;
	s->color.l = 10;
	while (l)
	{
		r.pan = norm_vect(sub_vect(l->pos, s->i));
		light = norm_vect(sub_vect(l->pos, s->i));
		if (!(o = check_objects(r, w, s)) ||
		dist(s->i, o->i) > dist(s->i, l->pos))
		{
			viewer = norm_vect(sub_vect(s->i, w->cam->pos));
			reflec.x = light.x - 2.0 * dot_vect(light, normal) * normal.x;
			reflec.y = light.y - 2.0 * dot_vect(light, normal) * normal.y;
			reflec.z = light.z - 2.0 * dot_vect(light, normal) * normal.z;
			reflec = norm_vect(reflec);
			if (dot_vect(light, normal) > 0)
				s->color.l += s->diffuse * dot_vect(light, normal);
			if (dot_vect(viewer, reflec) > 0)
				s->color.l += s->specular * powf(dot_vect(viewer, reflec), 20);
		}
		l = l->next;
	}
	s->color.l /= 100;
	return (0);
}
