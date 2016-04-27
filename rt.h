/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhote <alhote@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/19 15:14:06 by alhote            #+#    #+#             */
/*   Updated: 2016/04/27 17:16:46 by alhote           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_H
# define RT_H
# include <mlx.h>
# include <stdlib.h>
# include <stdio.h>
# include "sphere.h"
# include "camera.h"
# include "light.h"
# include "hsv.h"
# include "maths.h"
# ifdef __APPLE__
#  define SCREEN_X 1920
#  define SCREEN_Y 1080
# elif defined __linux__
#  define SCREEN_X 500
#  define SCREEN_Y 500
# endif

typedef struct	s_world
{
	void		*mlx;
	void		*win;
	void		*img;
	int			screen_x;
	int			screen_y;
	t_camera	*cam;
	t_sphere	*spheres;
	t_light		*lights;
}				t_world;
t_world			*init_world(int x, int y);
void			img_pxl(void *img, int x, int y, int color);
void			render(t_world *w);
t_sphere		*checsp(t_vector r, t_world *w, t_vector *i, t_sphere *ignore);
int				simple_diffuse(t_vector i, t_sphere *s, t_world *w);
int				draw_sphere(t_vector i, t_sphere *s, t_world *w);
#endif
