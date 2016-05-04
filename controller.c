/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controller.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhote <alhote@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/19 16:22:17 by alhote            #+#    #+#             */
/*   Updated: 2016/05/04 13:09:13 by alhote           ###   ########.fr       */
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
		w->cam->pos.x -= 0.5;
	else if (keycode == RIGHT)
		w->cam->pos.x += 0.5;
	else if (keycode == UP)
		w->cam->pos.z += 0.5;
	else if (keycode == DOWN)
		w->cam->pos.z -= 0.5;
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
