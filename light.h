/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhote <alhote@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/25 12:42:39 by hantlowt          #+#    #+#             */
/*   Updated: 2016/04/27 14:25:09 by alhote           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIGHT_H
# define LIGHT_H
# include <stdlib.h>
# include "maths.h"

typedef struct		s_light
{
	t_vector		pos;
	double			intensity;
	struct s_light	*next;
}					t_light;
t_light				*init_light(t_vector pos, double intensity);
void				add_light(t_light *begin, t_light *new);
#endif
