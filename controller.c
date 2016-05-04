/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controller.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhote <alhote@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/19 16:22:17 by alhote            #+#    #+#             */
/*   Updated: 2016/05/04 16:57:26 by alhote           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "controller.h"
#include "rt.h"

int			keyboard(int keycode, void *data)
{
	t_world	*w;
	static double angle = 0;

	w = data;
	if (keycode == ESC)
		exit(0);
	else if (keycode == LEFT)
		w->cam->pany += 5.0;
	else if (keycode == RIGHT)
		w->cam->pany -= 5.0;
	else if (keycode == UP)
		w->cam->pos = addition_vect(w->cam->pos, pan_to_vect(w->cam->panx, w->cam->pany));
	else if (keycode == DOWN)
		w->cam->pos = addition_vect(w->cam->pos, pan_to_vect(w->cam->panx, w->cam->pany - 180));
	else
		angle += 15.0;
	w->lights->pos.x = cosd(angle) * 20;
	w->lights->pos.z = sind(angle) * 20;
	//printf("%f\n", angle);
	//w->cam->pany = efmod(w->cam->pany + 5.0, 360.0);
	//w->cam->panx = efmod(w->cam->panx + 5.0, 360.0);
	render(w);
	return (0);
}
