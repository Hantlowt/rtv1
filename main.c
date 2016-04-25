/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hantlowt <hantlowt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/19 14:44:17 by alhote            #+#    #+#             */
/*   Updated: 2016/04/25 19:58:52 by hantlowt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include "controller.h"
#include "maths.h"

int		main(void)
{
	t_world		*w;

	w = init_world(500, 500);
	t_vector t = transformation_vector(vect(0.5, 0.0, 1.0), vect(1.0, 0.0, 0.0));
	printf("%f %f %f\n", t.x, t.y, t.z);
	w->cam = init_camera(vect(0.0, 0.0, 0.0), vect(0.0, 0.0, 1.0));
	w->lights = init_light(vect(200, 100, 1), 10);
	w->spheres = init_sphere(vect(100.0, 100.0, 1.0), 100.0, 0xFFFFFF);
	mlx_key_hook(w->win, keyboard, w);
	mlx_loop(w->mlx);
	return (0);
}
