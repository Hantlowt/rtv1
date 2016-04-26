/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhote <alhote@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/21 16:02:34 by alhote            #+#    #+#             */
/*   Updated: 2016/04/26 14:08:12 by alhote           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H
# include <stdlib.h>
# include "maths.h"

typedef struct		s_camera
{
	t_vector		pos;
	double			panx;
	double			pany;
}					t_camera;
t_camera			*init_camera(t_vector pos, double px, double py);
t_vector			pan_to_vect(double px, double py);
#endif
