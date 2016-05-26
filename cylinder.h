/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhote <alhote@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/12 15:22:15 by alhote            #+#    #+#             */
/*   Updated: 2016/05/26 14:24:10 by alhote           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CYLINDER_H
# define CYLINDER_H
# include <stdlib.h>
# include "maths.h"
# include "hsl.h"
# include "ray.h"
# include "object.h"
# include "rt.h"

typedef struct	s_cylinder
{
	t_vector	dir;
	double		r;
}				t_cylinder;

int				cylinder_inter(t_ray r, t_object *s);
t_vector		cylinder_normal(t_object *s);
t_object		*init_cylinder(t_vector pos, t_vector orientation, t_hsl color);
#endif
