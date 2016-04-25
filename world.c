/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hantlowt <hantlowt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/19 16:01:15 by alhote            #+#    #+#             */
/*   Updated: 2016/04/25 13:16:47 by hantlowt         ###   ########.fr       */
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
	t_vector	i;

	x = 0;
	y = 0;
	while (y < w->screen_y)
	{
		while (x < w->screen_x)
		{
			if (!s_equa(w->cam->pan, vect(x, y, 0), w->spheres, &i))
				img_pxl(w->img, x, y, 0xFFFFFF - (dist(i, w->lights->pos)) / 2);
			++x;
		}
		x = 0;
		++y;
	}
	mlx_put_image_to_window(w->mlx, w->win, w->img, 0, 0);
}
