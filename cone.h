/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhote <alhote@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/19 16:06:35 by alhote            #+#    #+#             */
/*   Updated: 2016/05/19 16:07:25 by alhote           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONE_H
# define CONE_H
# include <stdlib.h>
# include "maths.h"
# include "hsl.h"
# include "ray.h"
# include "object.h"
# include "rt.h"

typedef struct	s_cone
{
	t_vector	dir;
	double		r;
}				t_cone;

int				cone_inter(t_ray r, t_object *s);
t_vector		cone_normal(t_object *s);
t_object		*init_cone(t_vector pos, t_vector orientation, t_hsl color);
#endif
