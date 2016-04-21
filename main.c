/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhote <alhote@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/19 14:44:17 by alhote            #+#    #+#             */
/*   Updated: 2016/04/21 17:20:20 by alhote           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include "controller.h"
#include "maths.h"

int		main(void)
{
	t_world		*w;

	w = init_world(500, 500);
	w->cam = init_camera(vect(0.0, 0.0, 0.0), vect(0.0, 0.0, 1.0));
	w->spheres = init_sphere(vect(100.0, 100.0, 1.0), 100.0, 0xFFFFFF);
	mlx_key_hook(w->win, keyboard, w);
	mlx_loop(w->mlx);
	return (0);
}
