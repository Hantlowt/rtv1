/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhote <alhote@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/19 16:01:15 by alhote            #+#    #+#             */
/*   Updated: 2016/04/20 15:35:56 by alhote           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_world			*init_world(int x, int y)
{
	t_world	*new;

	new = (t_world*)malloc(sizeof(t_world));
	new->screen_x = x;
	new->screen_y = y;
	new->mlx = mlx_init();
	new->win = mlx_new_window(new->mlx, x, y, "RTv1");
	new->img = mlx_new_image(new->mlx, x, y);
	new->spheres = 0;
	return (new);
}

void			render(t_world *w)
{
	printf("%d %d\n", w->screen_x, w->screen_y);
}
