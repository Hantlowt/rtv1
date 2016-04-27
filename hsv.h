/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hsv.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hantlowt <hantlowt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/27 09:32:52 by hantlowt          #+#    #+#             */
/*   Updated: 2016/04/27 11:40:30 by hantlowt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HSV_H
# define HSV_H
# include "maths.h"
# include <stdio.h>

typedef struct	s_hsv
{
	int			hue;
	int			saturation;
	int			value;
}				t_hsv;
t_hsv			hsv(int h, int s, int v);
int				hsvtorgb(t_hsv c);
#endif
