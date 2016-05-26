/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhote <alhote@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/21 16:25:42 by alhote            #+#    #+#             */
/*   Updated: 2016/05/26 14:23:49 by alhote           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"

t_camera			*init_camera(t_vector pos, double px, double py)
{
	t_camera	*new;

	if (!(new = (t_camera*)malloc(sizeof(t_camera))))
		return (0);
	new->pos = pos;
	new->panx = px;
	new->pany = py;
	return (new);
}

t_vector			pan_to_vect(double px, double py)
{
	t_vector	n;

	px = efmod(px, 360.0);
	py = efmod(py, 360.0);
	n = vect(cosd(py) * cosd(px), sind(px), sind(py) * cosd(px));
	return (norm_vect(n));
}
