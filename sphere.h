/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhote <alhote@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/20 14:37:43 by alhote            #+#    #+#             */
/*   Updated: 2016/04/28 11:26:50 by alhote           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPHERE_H
# define SPHERE_H
# include <stdlib.h>
# include "maths.h"
# include "hsv.h"
# include "ray.h"

typedef struct		s_sphere
{
	t_vector		pos;
	double			rayon;
	t_hsv			color;
	int				material;
	struct s_sphere	*next;
}					t_sphere;
t_sphere			*init_sphere(t_vector pos, double rayon, t_hsv color);
void				add_sphere(t_sphere *begin, t_sphere *new);
int					s_equa(t_ray r, t_sphere *s, t_vector *i);
#endif
