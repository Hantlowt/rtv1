/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhote <alhote@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/19 14:44:17 by alhote            #+#    #+#             */
/*   Updated: 2016/05/24 16:51:16 by alhote           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include "controller.h"
#include "maths.h"
#include "object.h"
#include "sphere.h"
#include "plane.h"
#include "cylinder.h"
#include "cone.h"

int		main(void)
{
	t_world		*w;
	t_vector	pos;
	t_vector	dir;
	t_object	*o;
	t_hsl		color;

	w = init_world(hsl(0, 0, 37));
	w->cam = init_camera(vect(0.0, 5.0, -20.0), -5.0, 90.0 + 15.0);
	w->lights = init_light(vect(10.0, 5.0, 0.0), 2);
	add_light(w->lights, init_light(vect(0.0, 10.0, -10.0), 1));
	pos = vect(0.0, 0.0, 0.0);
	dir = vect(0.0, 1.0, 0.0);
	color = hsl(40, 10, 100);
	w->objects = init_plane(pos, dir, color);
	pos = vect(-10.0, 0.0, 0.0);
	dir = vect(1.0, 0.0, 0.0);
	add_obj(w->objects, init_plane(pos, dir, color));
	pos = vect(0.0, 0.0, 10.0);
	dir = vect(0.0, 0.0, -1.0);
	add_obj(w->objects, init_plane(pos, dir, color));
	o = add_obj(w->objects, init_cone(vect(0.0, 2.0, 0.0), vect(0, 1.0, 0.0), hsl(60, 50, 100)));
	o->specular = 50.0;
	o = add_obj(w->objects, init_cylinder(vect(-5.0, 0.0, 0.0), vect(0, 1.0, 1.0), hsl(10, 50, 100)));
	o->specular = 50.0;
	add_obj(w->objects, init_sphere(vect(-6.0, 1.0, 2.0), 1.0, hsl(50, 50, 100)));
	add_obj(w->objects, init_sphere(vect(-5.0, 4.0, 9.0), 1.0, hsl(205, 50, 100)));
	o = add_obj(w->objects, init_sphere(vect(0.0, 1.0, 0.0), 0.5, hsl(5, 100, 50)));
	o->specular = 50.0;
	mlx_key_hook(w->win, keyboard, w);
	render(w);
	mlx_loop(w->mlx);
	return (0);
}
