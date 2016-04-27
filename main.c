/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hantlowt <hantlowt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/19 14:44:17 by alhote            #+#    #+#             */
/*   Updated: 2016/04/27 12:51:50 by hantlowt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include "controller.h"
#include "maths.h"

int		main(void)
{
	t_world		*w;

	w = init_world(500, 500);
	w->cam = init_camera(vect(0.0, 0.0, 0.0), 0.0, 90.0);
	w->lights = init_light(vect(0.0, 0.0, 0.0), 10);
	w->spheres = init_sphere(vect(5.0, 0.0, 5.0), 1.0, 0xFFFFFF);
	mlx_key_hook(w->win, keyboard, w);
	render(w);
	mlx_loop(w->mlx);
	return (0);
}
