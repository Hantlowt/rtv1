/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhote <alhote@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/21 16:25:42 by alhote            #+#    #+#             */
/*   Updated: 2016/04/21 16:29:04 by alhote           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"

t_camera			*init_camera(t_vector pos, t_vector pan)
{
	t_camera	*new;

	if (!(new = (t_camera*)malloc(sizeof(t_camera))))
		return (0);
	new->pos = pos;
	new->pan = pan;
	return (new);
}
