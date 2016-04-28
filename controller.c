/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controller.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhote <alhote@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/19 16:22:17 by alhote            #+#    #+#             */
/*   Updated: 2016/04/28 14:50:53 by alhote           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "controller.h"
#include "rt.h"

int			keyboard(int keycode, void *data)
{
	t_world	*w;
	static double angle = -45;

	w = data;
	if (keycode == ESC)
		exit(0);
	if (keycode == LEFT)
		angle = efmod(angle + 10.0, 360);
	if (keycode == RIGHT)
		angle = efmod(angle - 10.0, 360);
	if (keycode == UP)
		w->spheres->pos.z += 0.5;
	if (keycode == DOWN)
		w->spheres->pos.z -= 0.5;
	w->lights->pos.x = cosd(angle) * 10;
	w->lights->pos.z = sind(angle) * 10;
	//printf("%f\n", angle);
	//w->cam->pany = efmod(w->cam->pany + 5.0, 360.0);
	//w->cam->panx = efmod(w->cam->panx + 5.0, 360.0);
	render(w);
	return (0);
}
