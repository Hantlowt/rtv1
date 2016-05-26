/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhote <alhote@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/19 15:14:06 by alhote            #+#    #+#             */
/*   Updated: 2016/05/26 14:15:17 by alhote           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_H
# define RT_H
# include <mlx.h>
# include <stdlib.h>
# include <stdio.h>
# include "object.h"
# include "camera.h"
# include "light.h"
# include "maths.h"
# include "libft.h"
# ifdef __APPLE__
#  define SCREEN_X (400.0)
#  define SCREEN_Y (400.0)
# elif defined __linux__
#  define SCREEN_X 400.0
#  define SCREEN_Y 300.0
# endif

typedef struct	s_world
{
	void		*mlx;
	void		*win;
	void		*img;
	t_camera	*cam;
	t_object	*objects;
	t_light		*lights;
}				t_world;
t_world			*init_world();
void			img_pxl(void *img, int x, int y, int color);
void			render(t_world *w);
t_object		*check_objects(t_ray r, t_world *w, t_object *ignore);
int				coloring(t_object *s, t_world *w);
#endif
