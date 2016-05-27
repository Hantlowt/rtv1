/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhote <alhote@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/19 14:44:17 by alhote            #+#    #+#             */
/*   Updated: 2016/05/27 22:50:52 by alhote           ###   ########.fr       */
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
#include <fcntl.h>
#include <unistd.h>

static void	spawn_sphere(t_world *w)
{
	t_object	*o;
	t_hsl		color;

	color = hsl(50, 50, 100);
	add_obj(w->objects, init_sphere(vect(10.0, 4.0, 9.0), 5.0, color));
	color = hsl(205, 50, 100);
	o = add_obj(w->objects, init_sphere(vect(-10.0, 4.0, 9.0), 5.0, color));
	o->specular = 50.0;
	color = hsl(5, 100, 100);
	add_obj(w->objects, init_sphere(vect(0.0, 4.0, 0.0), 0.5, color));
}

static void	spawn_plane(t_world *w)
{
	t_vector	pos;
	t_vector	dir;
	t_hsl		color;

	pos = vect(0.0, 0.0, 0.0);
	dir = vect(0.0, 1.0, 0.0);
	color = hsl(50, 10, 100);
	w->objects = init_plane(pos, dir, color);
	pos = vect(-20.0, 0.0, 0.0);
	dir = vect(1.0, 0.0, 0.0);
	add_obj(w->objects, init_plane(pos, dir, color));
	pos = vect(0.0, 0.0, 20.0);
	dir = vect(0.0, 0.0, -1.0);
	add_obj(w->objects, init_plane(pos, dir, color));
	pos = vect(20.0, 0.0, 0.0);
	dir = vect(-1.0, 0.0, 0.0);
	add_obj(w->objects, init_plane(pos, dir, color));
}

static void	spawn_cy(t_world *w)
{
	t_vector	pos;
	t_vector	dir;
	t_object	*o;

	pos = vect(-20.0, 0.0, 20.0);
	dir = vect(0, 1.0, 0.0);
	o = add_obj(w->objects, init_cylinder(pos, dir, hsl(10, 50, 100)));
	o->specular = 50.0;
	pos = vect(20.0, 0.0, 20.0);
	dir = vect(0, 1.0, 0.0);
	o = add_obj(w->objects, init_cylinder(pos, dir, hsl(10, 50, 100)));
	o->specular = 50.0;
	pos = vect(-20.0, 0.0, 20.0);
	dir = vect(1.0, 0.0, 0.0);
	o = add_obj(w->objects, init_cylinder(pos, dir, hsl(10, 50, 100)));
	o->specular = 50.0;
	pos = vect(-20.0, 0.0, 20.0);
	dir = vect(0.0, 0.0, 1.0);
	o = add_obj(w->objects, init_cylinder(pos, dir, hsl(10, 50, 100)));
	o->specular = 50.0;
	pos = vect(20.0, 0.0, 20.0);
	dir = vect(0, 0.0, 1.0);
	o = add_obj(w->objects, init_cylinder(pos, dir, hsl(10, 50, 100)));
	o->specular = 50.0;
}

int			main(void)
{
	t_world		*w;
	t_vector	dir;
	t_object	*o;
	t_hsl		color;

	w = init_world();
	w->cam = init_camera(vect(2.0, 5.0, -19.0), 0.0, 95.0);
	w->lights = init_light(vect(15.0, 10.0, 0.0), 2);
	add_light(w->lights, init_light(vect(-15.0, 10.0, -10.0), 1));
	spawn_plane(w);
	dir = vect(0.0, 1.0, 0.0);
	color = hsl(60, 50, 100);
	o = add_obj(w->objects, init_cone(vect(0.0, 5.0, 0.0), dir, color));
	o->specular = 50.0;
	spawn_cy(w);
	spawn_sphere(w);
	mlx_key_hook(w->win, keyboard, w);
	render(w);
	mlx_put_image_to_window(w->mlx, w->win, w->img, 0, 0);
	mlx_loop(w->mlx);
	return (0);
}
