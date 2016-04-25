/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hantlowt <hantlowt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/19 15:14:06 by alhote            #+#    #+#             */
/*   Updated: 2016/04/25 12:56:15 by hantlowt         ###   ########.fr       */
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
#endif
