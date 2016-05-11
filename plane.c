/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hantlowt <hantlowt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/02 18:44:29 by alhote            #+#    #+#             */
/*   Updated: 2016/05/06 07:18:56 by hantlowt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "plane.h"

int			plane_inter(t_ray r, t_object *s)
{
	double		t;
	//double		d;
	t_vector	*or;
	t_vector	norminv;
	//t_vector	temp;
	//double		denom;

	or = (t_vector*)s->data;
	/*denom = dot_vect(*or, r.pan);
	if (denom > 1e-6)
	{
		temp = sub_vect(s->pos, r.pos);
		t = dot_vect(temp, *or) / denom;
	}
	else
		return (1);*/
	//d = dot_vect(sub_vect(s->pos, r.pos), *or) / dot_vect(r.pan, *or);
	//t = -((or->x * r.pos.x + or->y * r.pos.y + or->z * r.pos.y + dist(*or, s->pos)) / (or->x * r.pan.x + or->y * r.pan.y + or->z * r.pan.z));
	norminv.x = -or->x;
	norminv.y = -or->y;
	norminv.z = -or->z;
	t = dot_vect(norminv, sub_vect(r.pos, s->pos)) / dot_vect(*or, r.pan);
	//t = -r.pos.y / r.pan.y;
	//d =
	//t =
	if (t < 0)
		return (1);
	s->i = vect(r.pos.x + r.pan.x * t, r.pos.y + r.pan.y * t, 0);
	s->i.z = r.pos.z + r.pan.z * t;
	return (0);
}

t_vector	plane_normal(t_object *s)
{
	t_vector	*n;

	n = s->data;
	return (norm_vect(*n));
}

t_object	*init_plane(t_vector pos, t_vector orientation, t_hsl color)
{
	t_vector	*or;
	t_object	*p;

	or = (t_vector*)malloc(sizeof(t_vector));
	*or = orientation;
	p = init_obj(pos, color);
	p->inter = &plane_inter;
	p->normal = &plane_normal;
	p->data = or;
	return (p);
}
