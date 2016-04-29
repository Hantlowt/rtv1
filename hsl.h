/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hsl.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhote <alhote@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/27 09:32:52 by hantlowt          #+#    #+#             */
/*   Updated: 2016/04/29 17:38:18 by alhote           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HSL_H
# define HSL_H
# include "maths.h"
# include <stdio.h>

typedef struct	s_hsl
{
	int			h;
	double		s;
	double		l;
}				t_hsl;
t_hsl			hsl(int h, double s, double l);
int				hsltorgb(t_hsl c);
#endif
