/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhote <alhote@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/19 14:44:17 by alhote            #+#    #+#             */
/*   Updated: 2016/05/26 20:55:55 by alhote           ###   ########.fr       */
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

static int	parser(char *path, t_world *w)
{
	int			fd;
	char		*str;
	char		**sp;
	t_vector	v;
	t_object	*o;
	int			i;

	fd = open(path, O_RDONLY);
	while ((i = get_next_line(fd, &str)))
	{
		if (i < 0)
			return (1);
		//ft_putendl(str);
		sp = ft_strsplit(str, '\t');
		ft_putendl(sp[0]);
		if (!ft_strcmp(sp[0], "cam"))
		{
			w->cam->pos = vect(ft_atoi(sp[1]), ft_atoi(sp[2]), ft_atoi(sp[3]));
			w->cam->panx = ft_atoi(sp[4]);
			w->cam->pany = ft_atoi(sp[5]);
			ft_putstr("Cam position changed!");
		}
		ft_putnbr(ft_strcmp(sp[0], "light"));
		if (!ft_strcmp(sp[0], "light"))
		{
			v = vect(ft_atoi(sp[1]), ft_atoi(sp[2]), ft_atoi(sp[3]));
			if (!w->lights)
				w->lights = init_light(v, 2);
			else
				add_light(w->lights, init_light(v, 2));
			ft_putstr("light added!");
		}
		if (!ft_strcmp(sp[0], "sphere"))
		{
			v = vect(ft_atoi(sp[1]), ft_atoi(sp[2]), ft_atoi(sp[3]));
			o = init_sphere(v, ft_atoi(sp[4]), hsl(50, 50, 100));
			o->color = hsl(ft_atoi(sp[5]), ft_atoi(sp[6]), ft_atoi(sp[7]));
			o->specular = ft_atoi(sp[8]);
			if (!w->objects)
				w->objects = o;
			else
				add_obj(w->objects, o);
			ft_putstr("sphere added!");
		}
		if (!ft_strcmp(sp[0], "plane"))
		{
			v = vect(ft_atoi(sp[4]), ft_atoi(sp[5]), ft_atoi(sp[6]));
			o = init_plane(vect(0.0, 0.0, 0.0), v, hsl(50, 50, 100));
			v = vect(ft_atoi(sp[1]), ft_atoi(sp[2]), ft_atoi(sp[3]));
			o->pos = v;
			o->color = hsl(ft_atoi(sp[7]), ft_atoi(sp[8]), ft_atoi(sp[9]));
			o->specular = ft_atoi(sp[10]);
			if (!w->objects)
				w->objects = o;
			else
				add_obj(w->objects, o);
			ft_putstr("plane added!");
		}
		if (!ft_strcmp(sp[0], "cylinder"))
		{
			v = vect(ft_atoi(sp[4]), ft_atoi(sp[5]), ft_atoi(sp[6]));
			o = init_cylinder(vect(0.0, 0.0, 0.0), v, hsl(50, 50, 100));
			o->pos = vect(ft_atoi(sp[1]), ft_atoi(sp[2]), ft_atoi(sp[3]));
			*(double*)o->data = (double)ft_atoi(sp[7]);
			o->color = hsl(ft_atoi(sp[8]), ft_atoi(sp[9]), ft_atoi(sp[10]));
			o->specular = ft_atoi(sp[11]);
			if (!w->objects)
				w->objects = o;
			else
				add_obj(w->objects, o);
			ft_putstr("cylinder added!");
		}
	}
	close(fd);
	return (0);
}

int			main(int argc, char **argv)
{
	t_world		*w;
	/*t_vector	pos;
	t_vector	dir;
	t_object	*o;
	t_hsl		color;*/

	w = init_world();
	//w->cam = init_camera(vect(0.0, 5.0, -10.0), 0.0, 90.0);
	/*w->lights = init_light(vect(10.0, 5.0, 0.0), 2);
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
	o = add_obj(w->objects, init_cone(vect(0.0, 2.0, 0.0), vect(0.0, 1.0, 0), hsl(60, 50, 100)));
	o->specular = 50.0;
	o = add_obj(w->objects, init_cylinder(vect(-5.0, 0.0, 0.0), vect(0, 1.0, 1.0), hsl(10, 50, 100)));
	o->specular = 50.0;
	add_obj(w->objects, init_sphere(vect(-6.0, 1.0, 2.0), 1.0, hsl(50, 50, 100)));
	add_obj(w->objects, init_sphere(vect(-5.0, 4.0, 9.0), 1.0, hsl(205, 50, 100)));
	o = add_obj(w->objects, init_sphere(vect(0.0, 1.0, 0.0), 0.5, hsl(5, 100, 50)));
	o->specular = 50.0;*/
	if (argc > 1)
	{
		if (!parser(argv[1], w) && w->cam && w->lights)
		{
			mlx_key_hook(w->win, keyboard, w);
			render(w);
			mlx_put_image_to_window(w->mlx, w->win, w->img, 0, 0);
			mlx_loop(w->mlx);
		}
		else
			ft_putstr("Error\n");
	}
	else
		ft_putstr("Please, choose a file in argument !\n");
	return (0);
}
