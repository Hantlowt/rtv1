/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hantlowt <hantlowt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/19 16:01:15 by alhote            #+#    #+#             */
/*   Updated: 2016/04/26 23:09:54 by hantlowt         ###   ########.fr       */
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

void			render(t_world *w)
{
	int			x;
	int			y;
	double		px;
	double		py;
	t_vector	i;
	t_vector	r;

	x = 0;
	y = 0;
	py = w->cam->pany + 22.5;
	px = w->cam->panx + 22.5;
	r = pan_to_vect(px, py);
	while (y < w->screen_y)
	{
		while (x < w->screen_x)
		{
			//printf("%f %f %f\n", r.x, r.y, r.z);
			if (!s_equa(r, w->cam->pos, w->spheres, &i))
				img_pxl(w->img, x, y, 0xFFFFFF - (dist(i, w->lights->pos)) / 2);
			else
				img_pxl(w->img, x, y, 0);
			++x;
			py = py - (45.0 / (double)w->screen_x);
			r = pan_to_vect(px, py);
		}
		x = 0;
		++y;
		py = w->cam->pany - 22.5;
		px = px - (45.0 / (double)w->screen_y);
	}
	mlx_put_image_to_window(w->mlx, w->win, w->img, 0, 0);
}
