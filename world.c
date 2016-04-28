/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhote <alhote@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/19 16:01:15 by alhote            #+#    #+#             */
/*   Updated: 2016/04/28 13:19:43 by alhote           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_world			*init_world(int x, int y)
{
	t_world	*new;

	if (!(new = (t_world*)malloc(sizeof(t_world))))
		return (0);
	new->screen_x = x;
	new->screen_y = y;
	new->mlx = mlx_init();
	new->win = mlx_new_window(new->mlx, x, y, "RTv1");
	new->img = mlx_new_image(new->mlx, x, y);
	new->spheres = 0;
	new->cam = 0;
	return (new);
}

t_sphere		*checsp(t_ray r, t_world *w, t_vector *i, t_sphere *ignore)
{
	t_sphere	*s;
	t_vector	k;
	t_sphere	*out;
	double		distance;
	int			touched;

	touched = 0;
	s = w->spheres;
	while (s)
	{
		if (!s_equa(r, s, &k) && s != ignore)
		{
			if (!touched || distance > dist(r.pos, k))
			{
				*i = k;
				distance = dist(r.pos, k);
				out = s;
			}
			touched = 1;
		}
		s = s->next;
	}
	if (touched)
		return (out);
	return (0);
}

void			render(t_world *w)
{
	int			x;
	int			y;
	double		px;
	double		py;
	t_vector	i;
	t_ray		r;
	t_sphere	*s;

	x = 0;
	y = 0;
	py = w->cam->pany + (45.0) / 2;
	px = w->cam->panx + (w->screen_y * 45.0 / w->screen_x) / 2;
	r.pan = pan_to_vect(px, py);
	r.pos = w->cam->pos;
	while (y < w->screen_y)
	{
		while (x < w->screen_x)
		{
			if ((s = checsp(r, w, &i, 0)))
				img_pxl(w->img, x, y, draw_sphere(i, s, w));
			else
				img_pxl(w->img, x, y, hsvtorgb(hsv(1, 0, 50)));
			++x;
			py = py - (45.0 / (double)w->screen_x);
			r.pan = pan_to_vect(px, py);
		}
		x = 0;
		++y;
		py = w->cam->pany - (45.0) / 2;
		px = px - ((w->screen_y * 45.0 / w->screen_x) / (double)w->screen_y);
	}
	mlx_put_image_to_window(w->mlx, w->win, w->img, 0, 0);
}
