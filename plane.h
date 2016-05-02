/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhote <alhote@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/02 18:45:21 by alhote            #+#    #+#             */
/*   Updated: 2016/05/02 19:14:36 by alhote           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLANE_H
# define PLANE_H
# include <stdlib.h>
# include "maths.h"
# include "hsl.h"
# include "ray.h"
# include "object.h"
# include "rt.h"

int			plane_inter(t_ray r, t_object *s);
t_vector	plane_normal(t_object *s);
t_object	*init_plane(t_vector pos, t_vector orientation, t_hsl color);
#endif
