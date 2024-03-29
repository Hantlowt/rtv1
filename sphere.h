/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhote <alhote@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/20 14:37:43 by alhote            #+#    #+#             */
/*   Updated: 2016/05/02 18:21:23 by alhote           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPHERE_H
# define SPHERE_H
# include <stdlib.h>
# include "maths.h"
# include "hsl.h"
# include "ray.h"
# include "object.h"
# include "rt.h"

int			sphere_inter(t_ray r, t_object *s);
t_vector	sphere_normal(t_object *s);
t_object	*init_sphere(t_vector pos, double rayon, t_hsl color);
#endif
