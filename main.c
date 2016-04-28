/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhote <alhote@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/19 14:44:17 by alhote            #+#    #+#             */
/*   Updated: 2016/04/28 15:04:22 by alhote           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include "controller.h"
#include "maths.h"

int		main(void)
{
	t_world		*w;

	w = init_world(SCREEN_X, SCREEN_Y);
	w->cam = init_camera(vect(0.0, 0.0, -10.0), 0.0, 0.0);
	w->lights = init_light(vect(cosd(-45) * 10, 0.0, sind(-45) * 10), 2);
	add_light(w->lights, init_light(vect(cosd(10) * 10, 0.0, sind(10) * 10), 1));
	w->spheres = init_sphere(vect(0.0, 0.0, 0.0), 1.0, hsv(205, 100, 50));
	//add_sphere(w->spheres, init_sphere(vect(0.0, 1.0, 0.0), 1.0, hsv(5, 100, 50)));
	mlx_key_hook(w->win, keyboard, w);
	render(w);
	mlx_loop(w->mlx);
	return (0);
}
