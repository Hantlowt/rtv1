/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhote <alhote@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/19 14:44:17 by alhote            #+#    #+#             */
/*   Updated: 2016/04/28 13:18:39 by alhote           ###   ########.fr       */
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
	w->lights = init_light(vect(cosd(1) * 10, sind(1) * 10, 0.0), 5);
	w->spheres = init_sphere(vect(5.0, 0.0, 5.0), 1.0, hsv(205, 100, 50));
	//add_sphere(w->spheres, init_sphere(vect(1.0, 0.0, 5.0), 1.0, hsv(5, 100, 30)));
	mlx_key_hook(w->win, keyboard, w);
	render(w);
	mlx_loop(w->mlx);
	return (0);
}
