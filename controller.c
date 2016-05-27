/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controller.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhote <alhote@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/19 16:22:17 by alhote            #+#    #+#             */
/*   Updated: 2016/05/27 22:51:56 by alhote           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "controller.h"
#include "rt.h"

int			keyboard(int keycode, void *data)
{
	t_world					*w;

	w = data;
	if (keycode == ESC)
		exit(0);
	else if (keycode == LEFT)
		w->cam->pany += 5.0;
	else if (keycode == RIGHT)
		w->cam->pany -= 5.0;
	else if (keycode == UP)
		w->cam->pos = add_vect(w->cam->pos, pan_to_vect(0, w->cam->pany));
	else if (keycode == DOWN)
		w->cam->pos = add_vect(w->cam->pos, pan_to_vect(0, w->cam->pany - 180));
	render(w);
	mlx_put_image_to_window(w->mlx, w->win, w->img, 0, 0);
	return (0);
}
