/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhote <alhote@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/29 10:47:51 by alhote            #+#    #+#             */
/*   Updated: 2016/05/24 16:48:36 by alhote           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_H
# define OBJECT_H
# include "maths.h"
# include "ray.h"
# include "hsl.h"
# include <stdlib.h>

typedef struct		s_object
{
	t_vector		pos;
	t_hsl			color;
	t_vector		i;
	double			diffuse;
	double			specular;
	void			*data;
	int				(*inter)(t_ray, struct s_object*);
	t_vector		(*normal)(struct s_object*);
	struct s_object	*next;
}					t_object;
t_object			*init_obj(t_vector pos, t_hsl color);
t_object			*add_obj(t_object *begin, t_object *new);
#endif
