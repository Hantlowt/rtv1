/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhote <alhote@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/20 14:37:43 by alhote            #+#    #+#             */
/*   Updated: 2016/05/01 18:54:26 by alhote           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPHERE_H
# define SPHERE_H
# include <stdlib.h>
# include "maths.h"
# include "hsl.h"
# include "ray.h"
# include "object.h"

int			sphere_inter(t_ray r, t_object *s);
t_vector	sphere_normal(t_object *s);
#endif
