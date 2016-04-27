/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhote <alhote@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/25 12:47:43 by hantlowt          #+#    #+#             */
/*   Updated: 2016/04/27 14:25:10 by alhote           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "light.h"

t_light	*init_light(t_vector pos, double intensity)
{
	t_light	*new;

	if (!(new = (t_light*)malloc(sizeof(t_light))))
		return (0);
	new->pos = pos;
	new->intensity = intensity;
	new->next = 0;
	return (new);
}

void		add_light(t_light *begin, t_light *new)
{
	while (begin->next)
		begin = begin->next;
	begin->next = new;
}
