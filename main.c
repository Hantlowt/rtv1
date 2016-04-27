/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhote <alhote@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/19 14:44:17 by alhote            #+#    #+#             */
/*   Updated: 2016/04/27 19:37:25 by alhote           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include "controller.h"
#include "maths.h"

int		main(void)
{
	t_world		*w;

	w = init_world(SCREEN_X, SCREEN_Y);
	w->cam = init_camera(vect(0.0, 0.0, 0.0), 0.0, 90.0);
	w->lights = init_light(vect(cosd(1) * 10, sind(1) * 10, 0.0), 200);
	w->spheres = init_sphere(vect(5.0, 0.0, 5.0), 1.0, hsv(5, 100, 30));
	//add_sphere(w->spheres, init_sphere(vect(6.0, 0.0, 5.5), 1.0, hsv(210, 100, 50)));
	mlx_key_hook(w->win, keyboard, w);
	render(w);
	mlx_loop(w->mlx);
	return (0);
}
