/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controller.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hantlowt <hantlowt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/19 16:22:17 by alhote            #+#    #+#             */
/*   Updated: 2016/04/25 18:12:43 by hantlowt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "controller.h"
#include "rt.h"

int			keyboard(int keycode, void *data)
{
	t_world	*w;
	static double angle = 1;

	w = data;
	if (keycode == ESC)
		exit(0);
	angle += 10;
	w->lights->pos.x = 100 + cosd(angle) * 200;
	w->lights->pos.z = 100 + sind(angle) * 200;
	render(w);
	return (0);
}
