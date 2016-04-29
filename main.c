/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhote <alhote@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/19 14:44:17 by alhote            #+#    #+#             */
/*   Updated: 2016/04/29 18:33:49 by alhote           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include "controller.h"
#include "maths.h"
#include "object.h"
#include "sphere.h"

int		main(void)
{
	t_world		*w;
	double		r;

	w = init_world();
	r = 1;
	w->cam = init_camera(vect(0.0, 0.0, -10.0), 0.0, 0.0);
	w->lights = init_light(vect(cosd(-45) * 10, 0.0, sind(-45) * 10), 2);
	//add_light(w->lights, init_light(vect(cosd(10) * 10, 0.0, sind(10) * 10), 1));
	w->objects = init_obj(vect(0.0, 0.0, 0.0), hsl(205, 100, 50));
	w->objects->inter = &sphere_inter;
	w->objects->data = &r;
	//add_sphere(w->spheres, init_sphere(vect(0.0, 1.0, 0.0), 1.0, hsl(5, 100, 50)));
	mlx_key_hook(w->win, keyboard, w);
	render(w);
	mlx_loop(w->mlx);
	return (0);
}
